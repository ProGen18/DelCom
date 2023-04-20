#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int main()
{
    FILE *f_in, *f_out;
    char in_file_name[50], out_file_name[50], line[MAX_LINE_LENGTH];

    // Demander le nom du fichier d'entrée
    printf("Nom du fichier d'entrée : ");
    scanf("%s", in_file_name);

    // Ouvrir le fichier d'entrée en mode lecture
    f_in = fopen(in_file_name, "r");
    if (f_in == NULL) {
        printf("Impossible d'ouvrir le fichier d'entrée %s\n", in_file_name);
        exit(1);
    }

    // Demander le nom du fichier de sortie
    printf("Nom du fichier de sortie : ");
    scanf("%s", out_file_name);

    // Ouvrir le fichier de sortie en mode écriture
    f_out = fopen(out_file_name, "w");
    if (f_out == NULL) {
        printf("Impossible d'ouvrir le fichier de sortie %s\n", out_file_name);
        exit(1);
    }

    // Lire le fichier d'entrée ligne par ligne et supprimer les commentaires
    while (fgets(line, MAX_LINE_LENGTH, f_in) != NULL) {
        char *pos = strstr(line, "//"); // Recherche de la chaîne "//"
        if (pos != NULL) {
            *pos = '\n'; // Remplacement du commentaire par un saut de ligne
            *(pos+1) = '\0'; // Ajout d'un caractère de fin de chaîne après le saut de ligne
        }
        fprintf(f_out, "%s", line); // Écriture de la ligne modifiée dans le fichier de sortie
    }

    // Fermeture des fichiers
    fclose(f_in);
    fclose(f_out);

    printf("Fichier modifié avec succès.\n");

    return 0;
}
