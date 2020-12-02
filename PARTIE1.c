#include "PARTIE1.h"
#include <stdlib.h>



void convertir_binaire(int* tableau, char* caract_a_convertir)
{
    int i;

    //tableau qui permettra de stocker la valeur du caractère en binaire
    int* tableau2;
    tableau2 = (int*)malloc(100 * sizeof(int));

    //on prend la valeur du caractère et on le met dans un entier
    int nb = *caract_a_convertir;

    //convertie en binaire le nombre
    for(i=0; nb > 0; i++){
        *(tableau2+i) = nb % 2;
        nb = nb / 2;
    }

    //le nombre binaire étant été fait à l'envers on inverse le contenu et on le met dans le bon tableau
    for(i=0;i<8;i++){
        *(tableau+i) = *(tableau2+7-i);
    }
}




void equivalent_fichier_texte()
{
    int* tab;
    int i;
    char caractere;
    int caractere2;
    //char lettre;

    FILE* fichier = NULL;
    FILE* fichier_binaire = NULL;

    tab = (int*)malloc(100 * sizeof(int));
    /*
    printf("Quelle est le caractere? \n");
    scanf("%c",&lettre);

    convertir_binaire(tab,&lettre);

    for(i=0;i<8;i++){
        printf("%d ",*(tab+i));
    }

    */

    // on lit uniquement le fichier Alice
    fichier = fopen("Alice.txt", "r");

    //on écrit dans le fichier AliceBinaire
    fichier_binaire = fopen("AliceBinaire.txt", "r+");

    if(fichier == NULL)
    {
        printf("ERREUR DE LECTURE DE FICHIER");
    }
    else
    {
        do
        {
            fseek(fichier,0,SEEK_CUR);
            caractere = fgetc(fichier);
            convertir_binaire(tab,&caractere);
          /*  for(i=0;i<8;i++)
            {
                printf("%d ",*(tab+i));
            }
            printf("\n");*/

            if(caractere!=EOF)
            {
                for(i=0;i<8;i++)
                {
                    caractere2 = *(tab+i);
                    fprintf(fichier_binaire,"%d",caractere2);
                    //printf("%d ", caractere2);
                }
               // printf("\n");
            }
        } while (caractere!=EOF);

    }

    fclose(fichier);
    fclose(fichier_binaire);
}




int compter_carac_txt()
{
    int c;
    int nb_carac = 0;

    FILE* fichier = NULL;
    fichier = fopen("Alice.txt", "r");

    if(fichier != NULL){
        while((c = fgetc(fichier)) != EOF){
            nb_carac++;
        }
    }

    fclose(fichier);
    return nb_carac;
}
 


int compter_carac_txt_bin()
{
    int c;
    int nb_carac = 0;

    FILE* fichier_binaire = NULL;
    fichier_binaire = fopen("AliceBinaire.txt", "r");

    if(fichier_binaire != NULL){
        while((c = fgetc(fichier_binaire)) != EOF){
            nb_carac++;
        }
    }

    fclose(fichier_binaire);

    return nb_carac;
}
