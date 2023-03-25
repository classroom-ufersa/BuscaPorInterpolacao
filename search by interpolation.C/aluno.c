#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct alunos{

    char nome[50];
    int matricula;
    int documento;

} Alunos;

void cria_aluno(Alunos *alunos, int quantidadealunos){ 
    quantidadealunos--;
    
    //system("cls");
       
       printf("Digite o nome do aluno: \n");
       scanf(" %[^\n]", alunos[quantidadealunos].nome);
       printf("Digite o documento do aluno: \n");
       scanf("%d", &alunos[quantidadealunos].documento);
       printf("Digite a matricula do aluno: \n");
       scanf("%d", &alunos[quantidadealunos].matricula);

}

void imprime_aluno(Alunos *alunos, int quantidadealunos){
   int i;

    for(i = 0; i < quantidadealunos; i++){

       printf("\n\nDados do aluno (%d)\n", i+1);
       printf("Nome do aluno: %s\n", alunos[i].nome);
       printf("Documento do aluno: %d\n", alunos[i].documento);
       printf("Matricula do aluno: %d\n", alunos[i].matricula);

    }

    if(quantidadealunos==0){
            printf("\nainda nao tem alunos para listar");
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


void lertxt(Alunos *alunos){

    int quantidadealunos;

    FILE *ArquivoAlunos;

    ArquivoAlunos = fopen("ArquivoAlunos.txt", "r");


        fscanf(ArquivoAlunos, "%d", &quantidadealunos);
        for (int i = 0; i < quantidadealunos; i++){
            
            fscanf(ArquivoAlunos, " %[^\n] %d %d ", alunos[i].nome, &alunos[i].documento, &alunos[i].matricula);

        }
    
    fclose(ArquivoAlunos);
    
}

int busca_por_matricula(Alunos *alunos, int quantidadealunos, int matricula){

    bubbleSort(alunos,quantidadealunos);

    int inicio = 0;
    int fim = quantidadealunos - 1;
    int meio;

    while (inicio  <= fim && matricula >= alunos[inicio ].matricula && matricula <= alunos[fim].matricula) {
        
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

int busca_por_nome(Alunos *alunos, int quantidadealunos, char *nome){

    int inicio = 0;
    int fim = quantidadealunos - 1;
    int meio;

    while (inicio  <= fim){
        
        meio = inicio + (strcmp(nome, alunos[inicio].nome) * (fim - inicio)) / strcmp(alunos[fim].nome,alunos[inicio].nome);
        
        if (strcmp(alunos[meio].nome,nome)==0){

            return meio;

        }else if (strcmp(alunos[meio].nome,nome) == -1){

            inicio = meio + 1;

        }else {

            fim = meio - 1;

        }
    }

    return -1;

}

void libera_aluno(Alunos *aluno)
{
    free(aluno);
}

//ordenar alunos pela matricula ja que temos a funçao cadastrar alunos, para a busca ser eficiente o vetor tem que estar ordenado.
void bubbleSort(Alunos *vetor, int tamanho){ 
    int i, j;
    Alunos aux;
    for(i = 0; i<tamanho; i++){        
      for(j=0; j<tamanho-1; j++){ 
         if(vetor[j].matricula > vetor[j+1].matricula){ 
 
            strcpy(aux.nome,vetor[j].nome);
            aux.documento = vetor[j].documento;
            aux.matricula  = vetor[j].matricula;
 
            strcpy(vetor[j].nome,vetor[j+1].nome);
            vetor[j].documento = vetor[j+1].documento;
            vetor[j].matricula = vetor[j+1].matricula;
 
            strcpy(vetor[j+1].nome,aux.nome);
            vetor[j+1].documento = aux.documento;
            vetor[j+1].matricula = aux.matricula; 
         } 
      }         
    }  
}