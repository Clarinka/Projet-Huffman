#include "PARTIE1.h"
#include <stdlib.h>



void convertir_binaire(int* tableau, char* caract_a_convertir)
{
    int i;

    
    int* tableau2;
    tableau2 = (int*)malloc(100 * sizeof(int));

    
    int nb = *caract_a_convertir;

    
    for(i=0; nb > 0; i++){
        *(tableau2+i) = nb % 2;
        nb = nb / 2;
    }

    
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
    

    FILE* fichier = NULL;
    FILE* fichier_binaire = NULL;

    tab = (int*)malloc(100 * sizeof(int));
   

    
    fichier = fopen("Alice.txt", "r");

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
          

            if(caractere!=EOF)
            {
                for(i=0;i<8;i++)
                {
                    caractere2 = *(tab+i);
                    fprintf(fichier_binaire,"%d",caractere2);
             
                }
              
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
