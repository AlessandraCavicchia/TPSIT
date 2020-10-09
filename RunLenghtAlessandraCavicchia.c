#include <stdio.h>
#include <stdlib.h>

int main(){
    char ch, nch; //implemento il carattere c e il carattere successivo nch(nextchar)
    int answer, count;
    str s[20];
     printf("Scrivi 1 per fare encoding o scrivi 2 per fare decoding:");
    scanf("%s", & answer ); //risposta per sapere se fare decoding o encoding, in più un contatore
    if (answer=1){
    printf("inserisci la stringa”);
    scanf("%s”,s); 
    for(int i=0;i<30;i++)
    printf(”%c”,s[i]);
    printf(“\n”);
    printf(“%s”,s);
        count=1;
        ch=nch; //il carattere deve essere uguale al carattere successivo per entrare nel while ed incrementare il numero di volte scritto
        while(nch=ch){
            count=count+1;
            scanf("%s", &nch); //se il carattere successivo è uguale al carattere, allora aumento il count e stampo
            }  
            if (count>1){
            scanf("%d %s", &count , &ch);
        }
         else
        {
    printf("%s", ch);} //altrimenti stampo la lettera senza il numero
        }
    return 0;
}