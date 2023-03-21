#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

#define QTD_ALUNOS 3

int main(void) {
  int i;
    FILE* file = fopen("entrada.txt", "rt");
      if(file == NULL){
          printf("erro no arquivo!\n");
              exit(1);
                }
                  Aluno** alunos = (Aluno**)malloc(QTD_ALUNOS * sizeof(Aluno*));
                    if(alunos == NULL){
                        printf("erro!");
                            exit(1);
                              }
                                for(i=0; i<QTD_ALUNOS; i++){
                                    alunos[i] = cria_aluno();
                                      }
                                        
                                          preenche_aluno(alunos,file);

                                            imprime_alunos(alunos,QTD_ALUNOS );
                                              bubbleSort(alunos,QTD_ALUNOS); 
                                                
                                                  imprime_alunos(alunos,QTD_ALUNOS );
                                                    int r = BuscaInterpolacao(alunos,QTD_ALUNOS,3);
                                                      if(r == -1){
                                                         printf("Elemento não está no vetor");
                                                           }else{
                                                               printf("se encontra na posição: %d\n",r);
                                                                 }


                                                                   libera_aluno(alunos,QTD_ALUNOS);
                                                                     fclose(file);
                                                                       return 0;
                                                                       }