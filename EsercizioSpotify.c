#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5000
#define WRD 10

int main(){
    char canzone;
    int num, aut, tit;
    int i=0, j=0, k=0, h=0, l=0, o=0;
    int canzpr, canznum, canzatt; //canzone precedente , numero canzone, canzone attuale
    char indice[MAX];
    char titolo[MAX];
    char autore[MAX];
    char stringa[MAX];
    int ita[MAX][WRD]; //i=indice, t= titolo, a=autore per abbrevviare
    int pos=0;
    FILE *fp;
     fp = fopen ("playlist.csv", "r");
    if (fp != NULL){
          while (fgets(stringa, MAX, fp)){
            printf("%s", stringa);
             i=0;
               while (stringa[i] != ','){   
                if (i==0){
                    indice[l]=stringa[i]; }
                i++;
               }
               i++;
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
        ita[h][4]=(char)offsetautore;
        l++;
        h++;
        }

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
                }
                else{
    printf("Errore nella lettura");
       fclose(fp);}
 
    return 0;
}
