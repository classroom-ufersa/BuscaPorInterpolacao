#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

typedef struct aluno {
  char nome[50];
    int  mat;
      char documento[20];
      }Aluno;

      Aluno* cria_aluno(void){
        Aluno* novo_aluno = (Aluno*)malloc(sizeof(Aluno));
          if(novo_aluno == NULL){
              printf("erro!");
                  exit(1);
                    } 
                      printf("Aluno criado!\n");
                        return(novo_aluno);
                        }

                        void preenche_aluno(Aluno** alunos, FILE* file){
                          char linha[100];
                            int i=0;
                              while(fgets(linha, 100, file) != NULL){
                                sscanf(linha, "%[^;];%[^;];%d", alunos[i]->nome, alunos[i]->documento, &alunos[i]->mat);
                                    i++;
                                      }
                                        printf("alunos preenchidos!\n");
                                        } 

                                        void imprime_alunos(Aluno** a, int n){
                                          int i;
                                            for(i=0; i<n; i++){
                                                printf("%s\t%s\t%d\n", a[i]->nome, a[i]->documento, a[i]->mat);
                                                  }
                                                  }

                                                  void libera_aluno(Aluno** alunos,int n){
                                                    int i;
                                                      for(i=0; i<n; i++){
                                                          free(alunos[i]);
                                                            }
                                                              free(alunos);
                                                                printf("memory freedom!\n");
                                                                }

                                                                int BuscaInterpolacao(Aluno** a, int n, int chave){
                                                                   int inicio = 0; 
                                                                      int fim = n - 1; 
                                                                         int meio; 
                                                                         while (inicio <= fim) {     meio = inicio + ((chave - a[inicio]->mat) * (fim - inicio)) / (a[fim]->mat - a[inicio]->mat); 
                                                                          if (a[meio]->mat == chave){ 
                                                                              return meio; 
                                                                            } else if (a[meio]->mat < chave) { 
                                                                                inicio = meio + 1; 
                                                                              } else { 
                                                                                 fim = meio - 1; 
                                                                                    } 
                                                                                    } 
                                                                                     return -1;
                                                                                     }

                                                                                     void bubbleSort(Aluno **vetor, int tamanho){ 
                                                                                      int i, j;
                                                                                        Aluno *aux = cria_aluno(); 
                                                                                          if(aux == NULL){
                                                                                              printf("erro!");
                                                                                                  exit(1);
                                                                                                    }
                                                                                                      for(i = 0; i<tamanho; i++){        for(j=0; j<tamanho-1; j++){ 
                                                                                                          if(vetor[j]->mat > vetor[j+1]->mat){ 
                                                                                                          //================================
                                                                                                                strcpy(aux->nome,vetor[j]->nome);
                                                                                                                      strcpy(aux->documento,vetor[j]->documento);
                                                                                                                            aux->mat = vetor[j]->mat;
                                                                                                                            //================================
                                                                                                                                  strcpy(vetor[j]->nome,vetor[j+1]->nome);
                                                                                                                                        strcpy(vetor[j]->documento,vetor[j+1]->documento);
                                                                                                                                              vetor[j]->mat = vetor[j+1]->mat;
                                                                                                                                              //================================
                                                                                                                                                    strcpy(vetor[j+1]->nome,aux->nome);
                                                                                                                                                          strcpy(vetor[j+1]->documento,aux->documento);
                                                                                                                                                                vetor[j+1]->mat = aux->mat; 
                                                                                                                                                                    } 
                                                                                                                                                                       } 
                                                                                                                                                                        }
                                                                                                                                                                          printf("alunos ordenados!\n");
                                                                                                                                                                            free(aux);
                                                                                                                                                                            }

                                                                                                                                                                            // void ordena_aluno(Aluno** alunos,int n){  
                                                                                                                                                                            // }

                                                                                                                                                                            // void BuscaInterpolacao(Aluno** alunos, int n, char* chave){
                                                                                                                                                                              
                                                                                                                                                                              // }