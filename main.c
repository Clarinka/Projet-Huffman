#include <stdio.h>
#include <stdlib.h>
#include "PARTIE2.h"
#include "PARTIE1.h"

int main()
{
    FILE* fichier = NULL;
    FILE* fichier_binaire = NULL;
    Element* Liste_caractere;

    equivalent_fichier_texte();
    printf("nb de carac Alice.txt : %d \n",compter_carac_txt(fichier));
    printf("nb de carac AliceBinaire.txt : %d \n",compter_carac_txt_bin(fichier_binaire));

    Liste_caractere = occurrence_caractere();
    afficher_Liste(Liste_caractere);

    fclose(fichier);
    fclose(fichier_binaire);
    liberer_liste(&Liste_caractere);

    return 0;
}
