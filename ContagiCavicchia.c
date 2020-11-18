#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_stato 3
#define MAX_lat 100
#define MAX_long 100
#define MAX_reg 50
#define MAX_codice_reg 50
#define MAX_num_reg 60000000
#define MAX_file 2000

typedef struct s_data{
    int secondi, minuti, ora, giorno, mese, anno;
}data;

typedef struct s_regione{
    data data_oggi;
    char stato[MAX_stato];
    char cod_regione[MAX_codice_reg];
    char den_reg[MAX_reg];
    char lat[MAX_lat];
    char lon[MAX_long];
    int ric_wsintomi, ter_int,tot_osp,iso_dom,tot_pos,var_tot_pos, new_pos, dimessi_g, deceduti, sos_diag, screening, tot, tamponi, casi_test;
    struct s_regione* prossima_regione;
}regione;

int get_data(regione* regione_in, FILE* file_csv);
void reg_ric(regione* regione_in, int num_regioni);
void num_ric(regione* regione_in, int num_regioni);
void reg_meno_con(regione* regione_in, int num_regioni);

int main(){
    bool* stato_op;
    bool var=true;
    stato_op=&var;
    FILE* fp;
    fp = fopen("coronavirus.csv", "r");

    if(fp==NULL){
        printf("\nErrore nell'apertura del file\n");
        return -1;
    }

    regione* regione_in = (regione*)malloc(sizeof(regione));
    int num_regioni=get_data(regione_in, fp);
    reg_ric(regione_in, num_regioni);
    num_ric(regione_in, num_regioni);
    reg_meno_con(regione_in, num_regioni);
    return 0;
}

int get_data(regione* regione_in, FILE* file_csv){
    regione *reg;
    reg=regione_in;
    char* string_define;
    int num_regioni=0;

    char file_line [MAX_file];
    }
    fgets(file_line, MAX_file, file_csv) ;

    for(num_regioni=0; fgets(file_line, MAX_file, file_csv)!=NULL; num_regioni++){

        string_define=strtok(file_line, "-");
        reg->data_oggi.anno=atoi(string_define);

        string_define=strtok(file_line, "-");
        reg->data_oggi.mese=atoi(string_define);

        string_define=strtok(file_line, "T");
        reg->data_oggi.giorno=atoi(string_define);

        string_define=strtok(file_line, ":");
        reg->data_oggi.ora=atoi(string_define);

        string_define=strtok(file_line, ":");
        reg->data_oggi.minuti=atoi(string_define);

        string_define=strtok(file_line, ",");
        reg->data_oggi.secondi=atoi(string_define);

        string_define=strtok(file_line, ",");
        strcpy(reg->stato, string_define);

        string_define=strtok(file_line, ",");
        strcpy(reg->cod_reg, string_define);

        string_define=strtok(file_line, ",");
        strcpy(reg->den_reg, string_define);

        string_define=strtok(file_line, ",");
        strcpy(reg->lat, string_define);

        string_define=strtok(file_line, ",");
        strcpy(reg->lon, string_define);

        string_define=strtok(file_line, ",");
        reg->ric_wsintomi=atoi(string_define);

        string_define=strtok(file_line, ",");
        reg->ric_wsintomi=atoi(string_define);

        string_define=strtok(file_line, ",");
        reg->tot_osp=atoi(string_define);

        string_define=strtok(file_line, ",");
        reg->iso_dom=atoi(string_define);

        string_define=strtok(file_line, ",");
        reg->tot_pos=atoi(string_define);

        string_define=strtok(file_line, ",");
        reg->var_tot_pos=atoi(string_define);

        string_define=strtok(file_line, ",");
        reg->new_pos=atoi(string_define);

        string_define=strtok(file_line, ",");
        reg->dimessi_g=atoi(string_define);

        string_define=strtok(file_line, ",");
        reg->deceduti=atoi(string_define);

        string_define=strtok(file_line, ",");
        reg->sos_diag=atoi(string_define);

        string_define=strtok(file_line, ",");
        reg->screening=atoi(string_define);

        string_define=strtok(file_line, ",");
        reg->tot=atoi(string_define);

        string_define=strtok(file_line, ",");
        reg->tamponi=atoi(string_define);

        string_define=strtok(file_line, ",");
        reg->casi_test=atoi(string_define);

        reg->prossima_regione=(regione*)malloc(sizeof(regione));
        reg=reg->prossima_regione;
        }
         return num_regioni;
}

void reg_ric(regione* regione_in, int num_regioni){
    regione *reg;
    reg=regione_in;

    for(int k=0; k<3; k++){
    int max=regione_in->ter_int;
    for(int i=0; i<num_regioni; i++){

        if(reg->ter_int>max){
            max=reg->ter_int;
        }else if(reg->ter_int==max){
            reg->ter_int=-1;
        }else{

        }
        reg=reg->prossima_regione;
    }
    reg=regione_in;
    for(int i=0; i<num_regioni; i++){
        if(reg->ter_int==max){
            printf("\nLa regione %d è al %d posto di persone contagiate ( %d ) \n", k, reg->den_reg,max);
            reg->ter_int=-1;
        }
        reg=reg->prossima_regione;
    }
    }

    printf("\n\n");

}

void num_ric(regione* regione_in, int num_regioni){
    regione *reg;
    reg=regione_in;
    int somma=0;
    for(int i=0; i<num_regioni; i++){
        somma=somma+reg->ter_int;
        reg=reg->prossima_regione;
    }

    printf("\nPersone in terapia intensiva: %d ", somma);
}

void reg_meno_con(regione* regione_in, int num_regioni){
    regione *reg;
    reg=regione_in;

    for(int k=0; k<3; k++){
    int min=reg->tot_pos;
    for(int i=0; i<num_regioni; i++){

        if(reg->tot_pos<min){
            min=reg->tot_pos;
        }else if(reg->tot_pos==min){
            reg->tot_pos=MAX_reg;
        }else{
        }
        reg=reg->prossima_regione;
    }

    reg=regione_in;

    for(int i=0; i<num_regioni; i++){
        if(reg->tot_pos==min){
            printf("\nLa regione numero %d è al %d posto per numero di contagiati ( %d )", k, reg->den_reg, min);
            reg->tot_pos=MAX_reg;
        }
        reg=reg->prossima_regione;
    }
    }

    printf("\n\n");
}