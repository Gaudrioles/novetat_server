#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED

void cleaner();
void update_fonction();
void insert_text_event(GtkEditable *editable, const gchar* texte, int longueur);
void label_en_blanc(GtkWidget* label, char* texte);

gboolean copy_to_tmp_db();
gboolean creation_folder_conf();
gboolean creation_fichier_conf();
gboolean initialisation();

#endif // FONCTION_H_INCLUDED
