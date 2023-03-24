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

void imprime_aluno(Alunos *alunos, int quantidadealunos)
{

   int i;

    

      for(i = 0; i < quantidadealunos; i++){

       printf("\n\nDados do aluno (%d)\n", i+1);
       printf("Nome do aluno: %s\n", alunos[i].nome);
       printf("Documento do aluno: %d\n", alunos[i].documento);
       printf("Matricula do aluno: %d\n", alunos[i].matricula);

      }
 
    
    
}

void criatxt(Alunos *alunos, int quantidadealunos){

    int i;

    FILE *arquivo;

    arquivo = fopen("ArquivoAlunos.txt", "w");

    fprintf(arquivo, "%d\n", quantidadealunos);

    for(i = 0; i < quantidadealunos; i++){

     fprintf(arquivo, "%s\n %d %d\n", alunos[i].nome, alunos[i].documento, alunos[i].matricula);

    }
    
    fclose(arquivo);
}


void lertxt(Alunos *alunos)
{


    int quantidadealunos;

    FILE *ArquivoAlunos;

    ArquivoAlunos = fopen("ArquivoAlunos.txt", "r");


        fscanf(ArquivoAlunos, "%d", &quantidadealunos);
        for (int i = 0; i < quantidadealunos; i++)
        {
            

            fscanf(ArquivoAlunos, " %[^\n] %d %d ", alunos[i].nome, &alunos[i].documento, &alunos[i].matricula);

            
        }
    

    fclose(ArquivoAlunos);

    
}

int busca_por_matricula(Alunos *alunos, int quantidadealunos, int matricula){


    int inicio = 0;
    int fim = quantidadealunos - 1;
    int meio;

    while (inicio  <= fim && matricula >= alunos[inicio ].matricula && matricula <= alunos[fim].matricula) 
    {
        
        meio = inicio + ((matricula - alunos[inicio].matricula) * (fim - inicio)) / (alunos[fim].matricula - alunos[inicio].matricula);
        
        if(alunos[meio].matricula == matricula){

            return meio;

        }else if (alunos[meio].matricula < matricula){

            inicio = meio + 1;

        }else {

            fim = meio - 1;

        }
    }
    
    

    return -1;

}


//ordenar alunos pela matricula ja que temos a funçao cadastrar alunos para a busca ser eficiente o vetor tem que estar ordenado.
// ainda falta aplicala
// sugestão colocar ela assim que a funçao busca for chamada.
void libera_aluno(Alunos *aluno)
{
    free(aluno);
}


void bubbleSort(Alunos *vetor, int tamanho){ 
    int i, j;
    Alunos *aux =(Alunos*)malloc(sizeof(Alunos)); 
    if(aux == NULL){
    printf("erro!");
    exit(1);
    }
    for(i = 0; i<tamanho; i++){        
      for(j=0; j<tamanho-1; j++){ 
         if(vetor[j].matricula > vetor[j+1].matricula){ 
 //================================
            strcpy(aux->nome,vetor[j].nome);
            strcpy(aux->documento,vetor[j].documento);
            aux->matricula  = vetor[j].matricula;
 //================================
            strcpy(vetor[j].nome,vetor[j+1].nome);
            strcpy(vetor[j].documento,vetor[j+1].documento);
            vetor[j].matricula = vetor[j+1].matricula;
 //================================
            strcpy(vetor[j+1].nome,aux->nome);
            strcpy(vetor[j+1].documento,aux->documento);
            vetor[j+1].matricula = aux->matricula; 
         } 

      }
      free(aux);
    }
}