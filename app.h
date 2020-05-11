#ifndef APP_H_INCLUDED
#define APP_H_INCLUDED

#include <gtk/gtk.h>

#define TAILLE_MAX 1000
#define nombre_element 11
#define db_client ""
#define db_server "pool/db_server.db"
#define SERVER_FOLDER "pool"

/*
    0 - Novetat
    1 - Update
    2 - vlc
    3 - zip
    4 - notepad++
    5 - gimp
	6 - libreoffice
	7 - FileZilla
	8 - OpenShot
	9 - InnoSetup
   10 - Git
*/

typedef struct
{
    GtkWidget* window;

    GtkWidget* box_principale;
    GtkWidget* box_un;
    GtkWidget* box_deux;
    GtkWidget* box_bouton;

    GtkWidget* entry_version;
    GtkWidget* entry_registre_key;

    GtkWidget* bouton_fichier;
    GtkWidget* bouton_update;
    GtkWidget* bouton_quitter;

    GtkWidget* combo_box;

    GtkWidget* label;
    GtkWidget* label_version;
    GtkWidget* label_registre;

    char version_server[nombre_element][TAILLE_MAX];
    char md5sum_server[nombre_element][TAILLE_MAX];
}app;

static char tableau_id[nombre_element][TAILLE_MAX] = {"Novetat","Update","VLC","7zip", "Notepad++", "Gimp", "LibreOffice", "FileZilla", "OpenShot", "InnoSetup", "Git"};
static char pool_id[nombre_element][TAILLE_MAX] = {"pool/Novetat.exe","pool/update.exe", "pool/vlc_x64.exe", "pool/zip_x64.exe", "pool/note_x64.exe", "pool/gimp_x64.exe", "pool/libreoffice_x64.msi", "pool/filezilLa_x64.exe", "pool/openshot_x64.exe", "pool/innosetup_x64.exe", "pool/git_x64.exe"};

app application;

#endif // APP_H_INCLUDED
