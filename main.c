#include<stdio.h>
#include"aluno.c"

int main(){
    FILE *e;
    int decisao,matricula,matricula_buscada;
    e=fopen("entrada.txt","rt");
    if (e==NULL){
        printf("o arquivo nao foi aberto corretamente");
    }
    Alunos *novo_aluno=cria_aluno(e,5);
    printf("digite como quer buscar o aluno(1 para buscar pelo nome e 2 para buscar pela matricula): ");
    scanf("%d",&decisao);
    if(decisao==1){

    }
    else if(decisao==2){
        printf("digite a matricula que deseja buscar: ");
        scanf("%d",&matricula);
        printf("posicao do aluno referente a matricula buscada:%d",matricula_buscada=busca_matricula(novo_aluno,5,matricula));

    }
    else{
        printf("opcao invalida");
    }
    fclose(e);
    libera_aluno(novo_aluno);
    return 0;
}