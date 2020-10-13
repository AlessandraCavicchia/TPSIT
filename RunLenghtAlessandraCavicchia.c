#include <stdio.h>
#include <stdlib.h>

int main(){
    char ch, nch; //implemento il carattere c e il carattere successivo nch(nextchar)
    int answer, count; //implemento la risposta composta da un numero e il counter per le lettere
    char s[20]; //creo l'array 
     printf("Scrivi 1 per fare encoding o scrivi 2 per fare decoding:");
    scanf("%s", &answer); //risposta per sapere se fare decoding o encoding, in più un contatore
    if (answer=1){ //se la risposta è 1 entro nel if per encoding
    printf ("inserisci la stringa" );
    scanf("%s", s); //chiedo e scrivo la mia stringa di decoding e la memorizzo nel'array
    for(int i=0;i<20;i++){
    printf("%c",s[i]); //stampo  la cella dell'array
    printf("\n"); //a capo
        count=1; //inizializzo il count a 1
        ch=nch; //il carattere deve essere uguale al carattere successivo per entrare nel while ed incrementare il numero di volte scritto
        while(nch=ch){
            count=count+1; //incremento il count finchè il carattere successivo non è più uguale al carattere presente
            scanf("%s", &nch);
            }
            if (count>1){ //se il contatore diventa maggiore di uno, entro nell'if per stampare il numero seguito dalla lettera
            scanf("%d" "%s", &count , &ch);
            printf(" %d %s", count,ch); //memorizzo e stampo il numero delle volte che la lettera compare, e la lettera
            }
            else{
                printf("%s", ch);} //altrimenti stampo la lettera senza il numero
        }
    }
         else {
             if (answer=2){ } 
             }//DECODING DA FARE
    return 0;
}
