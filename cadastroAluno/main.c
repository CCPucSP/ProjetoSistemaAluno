#include <stdio.h>
#include <stdlib.h>
#include "tipos.h"
#include "decl.h"
int main()
{
    aluno *vetalunos[MAX_ALUNOS];
    inicializarVet(vetalunos);

    int sair =0, menu=0, pos = 0, ra = 0;

    while(sair == 0){
        printf("================= Sistema ===============");
        printf("\n\t1- Cadastrar");
        printf("\n\t2- Visualizar");
        printf("\n\t3- Remover");
        printf("\n\t4- Gravar em arquivo");
        printf("\n\t5- Ler um arquivo");
        printf("\nSua escolha: ");
        scanf("%d",&menu);
        switch(menu){
            case 1:
                system("cls");
                printf("Cadastro de Aluno");
                pos = posicaoLivre(vetalunos);
                if(pos != -1){
                    cadastro(vetalunos,pos);
                }else{
                    printf("\n==========Memoria cheia==========\n");
                }

            break;
            case 2:
                system("cls");
                printf("Dados no sistema");
                imprimirTodos(vetalunos);
            break;
            case 3:
                system("cls");
                printf("Remover de Aluno");
                ra = buscarRA(vetalunos);
                if(ra != -1){
                    removerAluno(vetalunos,ra);
                }else{
                    printf("\n==========RA Nao encontrado ==========\n");
                }
            break;
            case 4:
                gravarArquivo(vetalunos);
            break;
            case 5:

            break;
            default:
                printf("\t Voce digitou um opcao invalida!");
            break;
        }
}
}
