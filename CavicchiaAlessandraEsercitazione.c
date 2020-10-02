#include <stdio.h>
#include <stdlib.h>

int main()
{
    float R, N, C;
    int I;
    float x[50];
    printf("Inserisci il numero di persone contagiate per ogni persona:");
    scanf("%f", & R );
    printf("Inserisci il numero di alunni:");
    scanf("%f", & N );
    x[0] = 1;
        for(I=1, C=1; C<N; I++){
        x[I] = R * x[I-1];
		C= x[I];
		printf("\nI contagiati giornalieri sono: %d", I, C);}
	printf("\nPer contagiare il numero di persone inserite ci vogliono: %d giorni", I-1);
    return 0;
}
