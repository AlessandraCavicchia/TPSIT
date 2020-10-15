#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int main(){
    int answer, count; //implemento la risposta e il contatore
    char s[20]; //implemento l'array per la stringa
     printf("Scrivi 1 per fare encoding o scrivi 2 per fare decoding:");
    scanf("%s", &answer); //chiedo all'utente l'opzione

    if(answer=1){ //se la risposta è uguale a 1 allora entro nell'if per l'encoding
        printf ("inserisci la stringa: " );
        scanf("%s", s); //chiedo di inserire la stringa
        count=1; //inizializzo il contatore
        for(int i=0; i<strlen(s); i++){ //entro nel ciclo for per tutta la lunghezza della stringa

            if(s[i]== s[i+1]){ //se il carattere attuale è uguale al carattere successivo, allora entro nell'if
                count=count+1; //incremento il count
            }
            else{
                printf("%d%c",count, s[i]); //altrimenti stampo il numero seguito dalla lettera corrente
                count=1; //resetto il count per le lettere successive
            }
        }
    }
    return 0;
}
