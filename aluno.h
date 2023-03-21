#include"aluno.c"

typedef struct alunos Alunos;

Alunos *cria_aluno(FILE *e, int qtd_alunos);

void busca_matricula(Alunos *aluno, int tamanho, int valor);

char *busca_nome(Alunos *aluno, int tamanho, char *nome);

void libera_aluno(Alunos *aluno);
