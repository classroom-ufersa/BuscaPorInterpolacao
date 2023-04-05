#include"aluno.c"

typedef struct alunos Alunos;

void cria_aluno(Alunos *alunos, int quantidadealunos);

int busca_por_matricula(Alunos *alunos, int quantidadealunos, int matricula);

int busca_por_nome(Alunos *alunos, int quantidadealunos, char *nome);

void libera_aluno(Alunos *aluno);

void lertxt(Alunos *alunos);

void criatxt(Alunos *alunos, int quantidadealunos);

void imprime_aluno(Alunos *alunos, int quantidadealunos);

int busca_por_matricula(Alunos *alunos, int quantidadealunos, int matricula);

void merge(Alunos *Vetor_alunos, int ini, int meio, int fim);

void mergesort(Alunos *Vetor_alunos, int ini, int fim);

void minuscula(Alunos* Vetor_alunos, int qtd_alunos);