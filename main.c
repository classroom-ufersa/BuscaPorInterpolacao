#include <stdio.h>
#include "aluno.c"

int main()
{
    int Sair = 0;

  
    
    system("cls");


  while (Sair != 2)
  {
    
    FILE *arquivo_alunos;

    int Escolha, matricula, matricula_buscada;

    arquivo_alunos = fopen("entrada.txt", "rt");

    if (arquivo_alunos == NULL)
    {
        printf("\nNenhum aluno foi cadastrado ainda.\n\n");
        
    }else {

           
    }

    Alunos *novo_aluno = cria_aluno(arquivo_alunos, 5);
    printf("Digite como deseja buscar o aluno?\n(Digite 1 para busca por nome)\n(Digite 2 para busca por matricula)\nEscolha: ");
    scanf("%d", &Escolha);

    if (Escolha == 1)
    {
    }

    else if (Escolha == 2)
    {

        printf("digite a matricula que deseja buscar: \n");
        scanf("%d", &matricula);
        busca_matricula(novo_aluno, 5, matricula);
    }
    else
    {
        printf("opcao invalida\n");
    }
     fclose(arquivo_alunos);


     printf("Continuar busca de alunos?\nDigite 1 (Sim)\nDigite 2 (Nao)\nEscolha:");
     scanf("%d", &Sair);


  }
  
    
   
   
    
   
   
    return 0;
}