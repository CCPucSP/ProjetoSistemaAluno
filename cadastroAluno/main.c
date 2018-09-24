#include <stdio.h>
#include <stdlib.h>
#include "tipos.h"
#include "decl.h"
int main()
{
    aluno *vetalunos[MAX_ALUNOS];
    inicializarVet(vetalunos);

    int sair =0, menu=0;
    while(sair == 0){
        printf("================= Sistema ===============");
        printf("\n\t1- Cadastrar");
        printf("\n\t2- Visualizar");
        printf("\n\t3- Remover");
        printf("\n\t3- Gravar em arquivo");
        printf("\n\t3- Ler um arquivo");
        printf("\nSua escolha: ");
        scanf("%d",&menu);
        switch(menu){
            case 1:
                system("cls");
                printf("Cadastro de Aluno");
                cadastro(vetalunos);
            break;
            case 2:
                system("cls");
                printf("Dados no sistema");
                imprimirTodos(vetalunos);
            break;
            case 3:
                sair=1;
            break;
            default:
                printf("\t Voce digitou um opcao invalida!");
            break;
        }
}
}
