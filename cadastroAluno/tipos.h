// define tipo de dado pessoa
typedef struct _pessoa
{
    char nome[50]; 		// vetor de caracteres
    unsigned int idade; 	// inteiro sem sinal
    char nacionalidade[20]; // vetor de caracteres
    //...
} pessoa;

// define tipo de dado aluno
typedef struct _aluno
{
    pessoa dadosPessoa;// Dados do aluno como pessoa
    char ra[15]; 		// Registro academico
    float nota;		// Nota do aluno
    char nomeCurso[50];	// Nome do curso
    //...
} aluno;

// Inclui constantes do programa
#include "const.h"
