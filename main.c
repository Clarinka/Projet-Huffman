#include <stdio.h>
#include <stdlib.h>
#include "partie2.h"
#include "texte.h"

int main()
{
    int min, position;
    FILE* fichier = NULL;
    FILE* fichier_binaire = NULL;



    Noeud* Arbre = NULL;
    Element* Liste_caractere = NULL;


    equivalent_fichier_texte();
    printf("nb de carac Alice.txt : %d \n",compter_carac_txt(fichier));
    printf("nb de carac AliceBinaire.txt : %d \n",compter_carac_txt_bin(fichier_binaire));

    printf("\n\n");
    Liste_caractere = occurrence_caractere();
    afficher_Liste(Liste_caractere);


    Arbre = creation_liste_de_noeud(Liste_caractere,0);

    printf("\n\n");
    inverser_liste(&Arbre);
    afficher_Liste_de_noeuds(Arbre);
    fichier_texte_arbre_Huffman(Arbre);

    trad_text_bin_huffman();

    fclose(fichier);
    fclose(fichier_binaire);
    liberer_liste(&Liste_caractere);

    return 0;
}
