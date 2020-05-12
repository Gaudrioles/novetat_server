#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "app.h"
#include "fonction.h"
#include "sql.h"

int main(int argc, char *argv[])
{
    int compteur = 0;

    app application;

    /* Initialisation de la librairie GTK. */
    gtk_init(&argc, &argv);

    /* Window  */
    application.window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(application.window), "Novetat Server");
    gtk_window_set_position(GTK_WINDOW(application.window), GTK_WIN_POS_CENTER);
    gtk_widget_set_size_request(application.window, 450, 350);
    gtk_window_set_resizable (GTK_WINDOW(application.window), FALSE);
    gtk_container_set_border_width(GTK_CONTAINER(application.window), 10);
    gtk_window_set_icon_from_file(GTK_WINDOW(application.window),"icons/novetat_server.png", NULL);
    g_object_set(gtk_settings_get_default(),"gtk-application-prefer-dark-theme", TRUE, NULL);

    /* Box  */
    application.box_principale   = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    application.box_un           = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    application.box_deux         = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    application.box_bouton       = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);

    gtk_box_set_homogeneous(GTK_BOX(application.box_principale), TRUE);
    gtk_box_set_homogeneous(GTK_BOX(application.box_un), FALSE);
    gtk_box_set_homogeneous(GTK_BOX(application.box_deux), FALSE);

    /* Label */
    application.label = gtk_label_new("");
    application.label_version = gtk_label_new("");
    application.label_registre = gtk_label_new("");

    label_en_blanc(application.label, "Merci de choisir un fichier");
    label_en_blanc(application.label_version, "Version :");
    label_en_blanc(application.label_registre, "Registre Cle :");

    /* Bouton  */
    application.bouton_fichier  = gtk_file_chooser_button_new("Selection", GTK_FILE_CHOOSER_ACTION_OPEN);
    application.bouton_update   = gtk_button_new_with_label("Update");
    application.bouton_quitter  = gtk_button_new_with_label("Quitter");

    /* ComboBox */

    application.combo_box = gtk_combo_box_text_new();

    for(compteur = 0 ; compteur < nombre_element ; compteur++)
    {
        gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(application.combo_box), tableau_id[compteur]);
    }

    /* Entry */
    application.entry_version = gtk_entry_new();
    application.entry_registre_key = gtk_entry_new();

    gtk_entry_set_alignment(GTK_ENTRY(application.entry_version), 0.5);
    gtk_entry_set_alignment(GTK_ENTRY(application.entry_registre_key), 0.5);

    /* Box_pack  */
    gtk_container_add(GTK_CONTAINER(application.window), application.box_principale);

    gtk_box_pack_start(GTK_BOX(application.box_principale), application.label, TRUE, TRUE, 5);
    gtk_box_pack_start(GTK_BOX(application.box_principale), application.box_un, FALSE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(application.box_principale), application.box_deux, TRUE, FALSE, 5);
    gtk_box_pack_end(GTK_BOX(application.box_principale), application.box_bouton, FALSE, FALSE, 10);

    gtk_box_pack_start(GTK_BOX(application.box_un), application.bouton_fichier, TRUE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(application.box_un), application.label_version, TRUE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(application.box_un), application.entry_version, FALSE, FALSE, 5);


    gtk_box_pack_start(GTK_BOX(application.box_deux), application.combo_box, TRUE, TRUE, 5);
    gtk_box_pack_start(GTK_BOX(application.box_deux), application.label_registre, TRUE, TRUE, 5);
    gtk_box_pack_start(GTK_BOX(application.box_deux), application.entry_registre_key, FALSE, FALSE, 5);

    gtk_box_pack_start(GTK_BOX(application.box_bouton), application.bouton_quitter, FALSE, FALSE, 10);
    gtk_box_pack_end(GTK_BOX(application.box_bouton), application.bouton_update, FALSE, FALSE, 10);

    /* Signaux  */
    g_signal_connect(application.window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(application.bouton_quitter, "clicked", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(application.bouton_update, "clicked", G_CALLBACK(update_fonction), &application);

    g_signal_connect(G_OBJECT(application.entry_version), "insert-text", G_CALLBACK(insert_text_event), NULL);

    gtk_widget_show_all(application.window);

    gtk_main();

    return 0;
}
