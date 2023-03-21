#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct alunos
{

    char nome[50];
    int matricula;
    int documento;

} Alunos;

Alunos *cria_aluno(FILE *e, int qtd_alunos)
{

    char linhas[100];

    Alunos *aluno = (Alunos *)malloc(qtd_alunos * sizeof(Alunos));
    if (aluno == NULL)
    {
        printf("memoria insuficiente para alocacao");
        exit(1);
    }

    while (fgets(linhas, 100, e) != NULL)
    {

        sscanf(linhas, "%[^;]s", "%[^;]d", "%[^;]d", aluno->nome, &aluno->matricula, &aluno->documento);
    }

    return aluno;
}

void busca_matricula(Alunos *aluno, int tamanho, int valor)
{

    int inicio = 0;
    int fim = tamanho - 1;
    int meio, verifica = 0;

    while (inicio <= fim)
    {

        meio = inicio + ((valor - aluno[inicio].matricula) * (fim - inicio)) / (aluno[fim].matricula - aluno[inicio].matricula);
        if (aluno[meio].matricula == valor)
        {

            printf("\n(Informacoes do aluno buscado)\n\n");
            printf("Nome do aluno: %s\n", aluno[meio].nome);
            printf("Nome do aluno: %s\n", aluno[meio].documento);
            printf("Nome do aluno: %s\n", aluno[meio].matricula);
            verifica++;
            
        }
        else if (aluno[meio].matricula < valor)
        {
            inicio = meio + 1;
        }
        else
        {
            fim = meio - 1;
        }
    }

    if (verifica == 0)
    {

        printf("Aluno nao encontrao\n");
    }
}

char *busca_nome(Alunos *aluno, int tamanho, char *nome)
{
    int inicio = 0;
    int fim = tamanho - 1;
    int meio;
    while (inicio <= fim)
    {
        meio = inicio + ((strcmp(nome, aluno[inicio].nome)) * (fim - inicio)) / (strcmp(aluno[fim].nome, aluno[inicio].nome));
        if (strcmp(aluno[meio].nome, nome) == 0)
        {
            return aluno[meio].nome;
        }
        else
        {
            inicio = meio + 1;
        }
    }
    return "nome invalido";
}

void libera_aluno(Alunos *aluno)
{
    free(aluno);
}