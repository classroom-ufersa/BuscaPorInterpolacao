#include <stdio.h>
#include "aluno.c"

int main()
{
 

  
    
    system("cls");

    int Escolha, Escolha2 = 0, matricula, matricula_buscada, quantidadealunos = 1;
    Alunos *Vetor_alunos = (Alunos*) malloc(1 * sizeof(Alunos));
    


  while (Escolha2 != 3)
  {

    

    printf("\n\nMenu\n\nPara cadrastar um aluno digite (1)\nPara Buscar um aluno digite (2)\nPara sair digite (3)\nescolha: ");
    scanf("%d", &Escolha2);
    
    

    if(Escolha2 == 1){

    
    cria_aluno(Vetor_alunos, quantidadealunos);
    quantidadealunos++;
    Vetor_alunos = realloc(Vetor_alunos, quantidadealunos * (sizeof(Alunos)));

    }else if(Escolha2 == 2 ){

    printf("\n\nDigite como deseja buscar o aluno?\n(Digite 1 para busca por nome)\n(Digite 2 para busca por matricula)\nEscolha: ");
    scanf("%d", &Escolha);

    if (Escolha == 1)
    {

      

    }

    else if (Escolha == 2)
    {

        
    }
    else
    {
        
    }
     
    }


  }

  criatxt(Vetor_alunos, quantidadealunos);
  
    
   
   
    
   
   
    return 0;
}