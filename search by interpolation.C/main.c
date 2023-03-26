#include <stdio.h>
#include "aluno.c"
#include<time.h>

int main(){
   
    system("cls");
    double tempo;
    int Escolha_busca, opcao = 0, matricula, quantidadealunos = 0, posicao_do_aluno,recebe_busca;
    char nome[50];

    Alunos *Vetor_alunos = (Alunos*) malloc(1 * sizeof(Alunos));


    FILE *ArquivoAlunos;

    ArquivoAlunos = fopen("ArquivoAlunos.txt", "r");

    if (ArquivoAlunos == NULL)
    {
        printf("\n\nNenhum aluno cadrastaodo.\n");
    }
    else {    
        fscanf(ArquivoAlunos, "%d", &quantidadealunos);
        Vetor_alunos = realloc(Vetor_alunos, quantidadealunos * (sizeof(Alunos)));
        lertxt(Vetor_alunos);       
    }

    fclose(ArquivoAlunos);

  while (opcao != 4)
  {
    printf("\nAlunos cadrastados: %d\n", quantidadealunos);
    printf("\nMenu\n\n(1)Para cadrastar um aluno\n(2)Para Buscar um aluno\n(3)Listar alunos\n(4)Para sair\nescolha: ");
    scanf("%d", &opcao);
    switch(opcao){
    case 1:

    quantidadealunos++;
    Vetor_alunos = realloc(Vetor_alunos, quantidadealunos * (sizeof(Alunos)));
    cria_aluno(Vetor_alunos, quantidadealunos);   
    break;
    case 2:

     printf("\n\nDigite como deseja buscar o aluno\n(1 para buscar por nome)\n(2 para buscar por matricula)\nEscolha: ");
     scanf("%d", &Escolha_busca);

       if (Escolha_busca == 1){
        printf("digite o nome do aluno que deseja buscar: ");
        scanf(" %[^\n]s",nome);
       
       clock_t inicio = clock();
        recebe_busca=busca_por_nome(Vetor_alunos,quantidadealunos,nome);
       clock_t fim = clock();

       tempo = (double) (fim - inicio) / (CLOCKS_PER_SEC/1000);

       printf("tempo : %lf\n",tempo);
        if(recebe_busca == -1){

           printf("Aluno nao encontrado.\n");
        
        }else{

        printf("\n\nDados do aluno Buscado\n");
        printf("Nome do aluno: %s\n", Vetor_alunos[recebe_busca].nome);
        printf("Documento do aluno: %d\n", Vetor_alunos[recebe_busca].documento);
        printf("Matricula do aluno: %d\n", Vetor_alunos[recebe_busca].matricula);

        }
        
       }else if (Escolha_busca == 2) {

        printf("Digite o numero da matricula do aluno: \n");
        scanf("%d", &matricula);
        
        clock_t inicio = clock();
       
        posicao_do_aluno = busca_por_matricula(Vetor_alunos, quantidadealunos, matricula);
        
        clock_t fim = clock();

        tempo = (double) (fim - inicio) / (CLOCKS_PER_SEC/1000);

        printf("tempo: %lf",tempo);

        if(posicao_do_aluno == -1){

           printf("Aluno nao encontrado.\n");
        
        }else{

        printf("\n\nDados do aluno Buscado\n");

        printf("Nome do aluno: %s\n", Vetor_alunos[posicao_do_aluno].nome);
        printf("Documento do aluno: %d\n", Vetor_alunos[posicao_do_aluno].documento);
        printf("Matricula do aluno: %d\n", Vetor_alunos[posicao_do_aluno].matricula);

        }
        
      }
    break;
    case 3:

      imprime_aluno(Vetor_alunos, quantidadealunos);
    break;
    }

  }

  criatxt(Vetor_alunos, quantidadealunos);
   
  libera_aluno(Vetor_alunos);
       
    return 0;
}