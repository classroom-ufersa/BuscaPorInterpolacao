#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct alunos
{

    char nome[50];
    int matricula;
    int documento;

} Alunos;

void cria_aluno(Alunos *alunos, int quantidadealunos)
{

    quantidadealunos--;

    system("cls");

       printf("Digite o nome do aluno: \n");
       scanf(" %[^\n]", alunos[quantidadealunos].nome);
       printf("Digite o documento do aluno: \n");
       scanf("%d", &alunos[quantidadealunos].documento);
       printf("Digite a matricula do aluno: \n");
       scanf("%d", &alunos[quantidadealunos].matricula);
    
    
}

void criatxt(Alunos *alunos, int quantidadealunos){
    int i;

    quantidadealunos--;
    
    printf("Quantidade: %d", quantidadealunos);

    FILE *arquivo;

    arquivo = fopen("ArquivoAlunos.txt", "a");

    fprintf(arquivo, "%d\n", quantidadealunos);

    for(i = 0; i < quantidadealunos; i++){

     fprintf(arquivo, "%s %d %d\n", alunos[i].nome, alunos[i].documento, alunos[i].matricula);
    }
    
    

    fclose(arquivo);
}


void libera_aluno(Alunos *aluno)
{
    free(aluno);
}