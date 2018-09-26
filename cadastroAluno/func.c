#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tipos.h"
#include "decl.h"

void inicializarVet(aluno *vetAlunos[]){
    int i;
    for (i=0; i < MAX_ALUNOS; i++) {
        vetAlunos[i] = NULL;
    }
}



int posicaoLivre(aluno *vetaluno[]){
    int i=0;
    while((vetaluno[i] != NULL) && (i<=MAX_ALUNOS-1) && (i != -1)){
        i++;
        if(vetaluno[i] != NULL && (i>=MAX_ALUNOS-1)){
            i = -1;
        }
    }

    return i;
}

void cadastro(aluno *vetaluno[],int pos){

    aluno *pa = (aluno *)malloc (1*sizeof(aluno));
    char *str = (char *)malloc(100*sizeof(char));
    fflush(stdin);

    printf("\nNome: ");
    fgets(str,20,stdin);
    limparNewLine(str);
    strcpy(pa->dadosPessoa.nome,str);
    fflush(stdin);

    printf("\nidade: ");
    scanf("%u",&pa->dadosPessoa.idade);
    fflush(stdin);

    printf("\nnacionalidade: ");
    fgets(str,20,stdin);
    limparNewLine(str);
    strcpy(pa->dadosPessoa.nacionalidade,str);
    fflush(stdin);

    printf("\nra: ");
    fgets(str,20,stdin);
    limparNewLine(str);
    verificaRa(str);
    strcpy(pa->ra,str);
    fflush(stdin);

    printf("\nnota: ");
    scanf("%f",&pa->nota);
    fflush(stdin);

    printf("\nNome curso: ");
    fgets(str,20,stdin);
    limparNewLine(str);
    strcpy(pa->nomeCurso,str);
    fflush(stdin);

    vetaluno[pos] = (aluno *)malloc (1*sizeof(aluno));
    vetaluno[pos] = pa;
}

/*
** Imprime dados de um aluno
**
** Parâmetros:
**      aluno a - variavel do tipo aluno
**
** Retorno:
**      nenhum
*/
void imprimirDados (aluno a) {
    printf("\n======================================");
    printf("\n=========== Dados do Aluno ===========");
    printf("\n======================================");
    printf("\nNome          : %s", a.dadosPessoa.nome);
    printf("\nIdade         : %u", a.dadosPessoa.idade);
    printf("\nNacionalidade : %s", a.dadosPessoa.nacionalidade);
    printf("\nRA            : %s", a.ra);
    printf("\nNota          : %.2f", a.nota);
    printf("\nNome do curso : %s", a.nomeCurso);
    printf("\n======================================\n");
}

/*
** Imprime dados de todos os alunos do cadastro
**
** Parâmetros:
**      aluno *vetAlunos[] - vetor de ponteiros para aluno
**
** Retorno:
**      nenhum
*/
void imprimirTodos(aluno *vetAlunos[]){
    int i;
    for (i=0; i < MAX_ALUNOS; i++) {
        if(vetAlunos[i] != NULL) {
            imprimirDados(*vetAlunos[i]);
        }
    }
}

int buscarRA(aluno *vetaluno[]){
    int i=0;
    char *ra = (char *)malloc(10*sizeof(char));

    printf("\nDigite o RA do aluno a ser removido:");
    fflush(stdin);
    fgets(ra,10,stdin);

    while( (strcmp(vetaluno[i]->ra,ra) != 0) && (i<=MAX_ALUNOS-1) && (i != -1) ){
        i++;
        if((strcmp(vetaluno[i]->ra,ra) != 0) && (i>=MAX_ALUNOS-1)){
            i = -1;
        }
    }
    return i;
}

void removerAluno(aluno *vetaluno[],int ra){
    free(vetaluno[ra]);
    vetaluno[ra] = NULL;
    printf("\nRemovido com Sucesso!");
}

void limparNewLine(char *str){
    int i;
    for(i=0;str[i] != '\0'; i++){
        if(str[i] == '\n'){
            str[i] = '\0';
        }
    }
}
void verificaRa(char *ra){
    int tam=0;
    if( (ra[0] != 'R' || ra[0]=='r') || (ra[1] != 'A' || ra[1]=='a') ){
         for(tam=strlen(ra)-1;tam>1;tam--){
            ra[tam+2] = ra[tam];
         }
         ra[0] = 'R';
         ra[1] = 'A';
    }
}

void gravarArquivo(aluno *vetaluno[]){
    int num;
    char nomearq[] = "alunos.txt";
    FILE *arq;
    arq =fopen(nomearq,"w+");
    if(arq == NULL){
        printf("Erro ao gravar arquivos");
        exit(-1);
    }else{
        for(num=0;num<=MAX_ALUNOS-1; num++){
            if(vetaluno[num] != NULL){
                fprintf(arq,"NovaLinha\n");
                fprintf(arq,"%s\n",vetaluno[num]->dadosPessoa.nome);
                fprintf(arq,"%d\n",vetaluno[num]->dadosPessoa.idade);
                fprintf(arq,"%s\n",vetaluno[num]->dadosPessoa.nacionalidade);
                fprintf(arq,"%s\n",vetaluno[num]->ra);
                fprintf(arq,"%f\n",vetaluno[num]->nota);
                fprintf(arq,"%s\n",vetaluno[num]->nomeCurso);
            }
        }
    }
    fclose(arq);
    printf("\nArquivo gerado com sucesso!!\n\n");
}
