typedef struct aluno Aluno;

Aluno* cria_aluno(void);


void preenche_aluno(Aluno** alunos, FILE* file);

void imprime_alunos(Aluno** a, int n);

void libera_aluno(Aluno** alunos,int n);

int BuscaInterpolacao(Aluno** a, int n, int chave);

void bubbleSort(Aluno **vetor, int tamanho);


// void ordena_aluno(Aluno** alunos, n){  
// }

// void BuscaInterpolacao(Aluno** alunos, int n, char* chave){
  
  // }
