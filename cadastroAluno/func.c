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

    fflush(stdin);
    printf("\nNome: ");
    fgets(pa->dadosPessoa.nome,20,stdin);
    fflush(stdin);

    printf("\nidade: ");
    scanf("%u",&pa->dadosPessoa.idade);
    fflush(stdin);

    printf("\nnacionalidade: ");
    fgets(pa->dadosPessoa.nacionalidade,20,stdin);
    fflush(stdin);

    printf("\nra: ");
    fgets(pa->ra,20,stdin);
    fflush(stdin);

    printf("\nnota: ");
    scanf("%f",&pa->nota);
    fflush(stdin);

    printf("\nNome curso: ");
    fgets(pa->nomeCurso,20,stdin);
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
