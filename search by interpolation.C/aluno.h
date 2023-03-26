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

void bubbleSort(Alunos *vetor, int tamanho);