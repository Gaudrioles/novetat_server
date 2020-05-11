#include <gtk/gtk.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#include "app.h"
#include "md5.h"
#include "sql.h"
#include "log.h"
#include "fonction.h"

void label_en_rouge(GtkWidget* label, char* texte)
{
    gchar* tampon = NULL;

    tampon = g_strdup_printf("<span font_family=\"Verdana\" font=\"8\" color=\"red\"><b>%s</b></span>", texte);
    if(tampon == NULL)
        return;

    gtk_label_set_markup(GTK_LABEL(label), tampon);
    g_free(tampon);
}

void label_en_blanc(GtkWidget* label, char* texte)
{
    gchar* tampon = NULL;

    tampon = g_strdup_printf("<span font_family=\"Verdana\" font=\"8\" color=\"white\"><b>%s</b></span>", texte);
    if(tampon == NULL)
        return;

    gtk_label_set_markup(GTK_LABEL(label), tampon);
    g_free(tampon);
}

int id_to_name(char* nom)
{
    int compteur = 0;

    for(compteur = 0; compteur < nombre_element; compteur++)
    {
        if(strcmp(nom, tableau_id[compteur]) == 0)
        {
            return compteur;
            break;
        }
    }
    return -1;
}

void cleaner()
{
    gtk_entry_set_text(GTK_ENTRY(application.entry_version), "");
    gtk_file_chooser_unselect_all(GTK_FILE_CHOOSER(application.bouton_fichier));
    gtk_combo_box_set_active(GTK_COMBO_BOX(application.combo_box), -1);
}

gboolean creation_folder_conf()
{
    if(g_mkdir_with_parents("pool", 0777) != 0)
    {
        return FALSE;
    }
    return TRUE;
}

gboolean creation_fichier_conf()
{
    int compteur = 0;

    if(creation_db_server() != 0)
    {
        return FALSE;
    }
    for(compteur = 0; compteur < nombre_element; compteur++)
    {
        if(initialisation_db_server(compteur) != 0)
        {
            return FALSE;
        }
    }
    return TRUE;
}

void update_fonction()
{
    gchar* tampon_fichier = NULL;
    gchar* tampon_application = NULL;
    gchar* tampon_sha = NULL;
    gchar* tampon_exe = NULL;
    const gchar* tampon_entry_version;
    const gchar* tampon_entry_registre;

    int id = 0;

    if(initialisation() != TRUE)
    {
        return;
    }

    tampon_fichier          = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(application.bouton_fichier));
    tampon_entry_version    = gtk_entry_get_text(GTK_ENTRY(application.entry_version));
    tampon_entry_registre   = gtk_entry_get_text(GTK_ENTRY(application.entry_registre_key));
    tampon_application      = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(application.combo_box));

    if(tampon_fichier == NULL)
    {
        label_en_rouge(application.label, "Merci de choisir un fichier");
        return;
    }
    else if(strcmp(tampon_entry_version,"") == 0)
    {
        label_en_rouge(application.label, "Merci de saisir une version");
        return;
    }
    else if(strcmp(tampon_entry_registre,"") == 0)
    {
        label_en_rouge(application.label, "Merci de saisir une cle de registre");
        return;
    }
    else if(tampon_application == NULL)
    {
        label_en_rouge(application.label, "Merci de choisir une application");
        return;
    }

    tampon_sha = sha256_fichier(tampon_fichier);

    id =  id_to_name(tampon_application);

    if(strstr((strupr(tampon_fichier)), ".EXE") != NULL)
    {
        tampon_exe =  g_strdup("EXE");
    }
    if(strstr((strupr(tampon_fichier)), ".MSI") != NULL)
    {
        tampon_exe =  g_strdup("MSI");
    }

    remove(pool_id[id]);
    rename(tampon_fichier, pool_id[id]);

    update_db_server_version(id, (gchar*)tampon_entry_version);
    update_db_server_sha(id, tampon_sha);
    update_db_server_exe(id, tampon_exe);
    update_db_server_reg(id, (gchar*)tampon_entry_registre);

    cleaner();

    g_free(tampon_fichier);
    g_free(tampon_application);
    g_free(tampon_sha);
    g_free(tampon_exe);
}

void insert_text_event(GtkEditable *editable, const gchar* texte, int longueur)
{
    int i = 0;

    for (i = 0; i < longueur; i++)
    {
        if(!isdigit(texte[i]) && texte[i] != '.')
        {
            g_signal_stop_emission_by_name(G_OBJECT(editable), "insert-text");
            return;
        }
    }
}

gboolean initialisation()
{
    if(repertoire_existe(SERVER_FOLDER)!= TRUE)
    {
        if(creation_folder_conf() != TRUE)
        {
            return FALSE;
        }
    }

    if(fichier_existe(db_server) != TRUE)
    {
        if(creation_fichier_conf() != TRUE)
        {
            return FALSE;
        }
    }

    return TRUE;
}
