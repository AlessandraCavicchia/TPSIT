#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 100
#define wrd 5

int main(){
    char canzone;
    int num, aut, tit;
    int i=0, j=0, k=0, h=0, l=0, o=0;
    int canzpr, canznum, canzatt; //canzone precedente , numero canzone, canzone attuale
    char indice[max];
    char titolo[max];
    char autore[max];
    char stringa[max];
    int ita[max][wrd]; //i=indice, t= titolo, a=autore per abbrevviare
    int pos=0;
    FILE *fp;
    fp = fopen ("playlist.csv", "r");
    if (fp != NULL){
        while (!feof(fp)){
             fgets(stringa, max, fp);
               while (stringa[i] != ','){   
                if (i==0){
                    indice[l]=stringa[i];
                }
            int offsettitolo=0;
            tit=k;
        while (stringa[i] != ','){
        titolo[k] = stringa[i];
        i++; k++;
        offsettitolo++;}
        i++;
        int offsetautore=0;
        aut=j;
        while (stringa[i] !='\n'){                
                autore[j] = stringa[i];
                i++;j++;
                offsetautore++;}

            ita[h][0]=indice[l];      
            ita[h][1]=titolo[tit];
            ita[h][2]=(char)offsettitolo;
            ita[h][3]=autore[aut];
            ita[h][4]=(char)offsetautore;}

              do{
                canzatt= rand() % canznum;}                                     
            while (canzatt == canzpr);
            printf("\nIndice: %c", ita[canzatt][0]);
            printf("\nTitolo:");
            for (int e=0; e<ita[canzatt][2]; e++){
                num = ita[canzatt][1];
                printf("%c", titolo[num+e]);}
                printf("\n Autore:");
                for (int e=0; e<ita[canzatt][4]; e++){
                num = ita[canzatt][3];
                printf("%c", titolo[num+e]);}
                }}
                else{
    printf("Errore nella lettura");}
    return 0;
}