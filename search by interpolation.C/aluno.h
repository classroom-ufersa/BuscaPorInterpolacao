#include"aluno.c"

typedef struct alunos Alunos;

void cria_aluno(FILE *e, int qtd_alunos);

void busca_matricula(Alunos *aluno, int tamanho, int valor);

char *busca_nome(Alunos *aluno, int tamanho, char *nome);

void libera_aluno(Alunos *aluno);

void lertxt(Alunos *l, int quantidadealunos);

void criatxt(Alunos *alunos, int quantidadealunos);

void imprime_aluno(Alunos *alunos, int quantidadealunos);

int busca_por_matricula(Alunos *alunos, int quantidadealunos, int matricula);

void merge(Aluno *v, int ini, int meio, int fim);

void mergesort(Aluno *v, int ini, int fim);