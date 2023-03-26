class Aluno:
    def __init__(self, nome, documento, matricula):
        self.nome = nome
        self.documento = documento
        self.matricula = matricula

def cria_aluno(alunos, quantidade_alunos):
    nome = input('Digite o nome do aluno: ')
    documento = input('Digite o documento do aluno: ')
    matricula = int(input('Digite a matricula do aluno: '))
    aluno = Aluno(nome, documento, matricula)
    alunos[quantidade_alunos] = aluno
    print('Aluno cadastrado com sucesso')

def busca_por_matricula(alunos, quantidade_alunos, matricula):
    for i in range(quantidade_alunos):
        if alunos[i].matricula == matricula:
            return i
    return -1

def busca_nome(alunos, quantidade_alunos, nome):
    indices = []
    for i in range(quantidade_alunos):
        if alunos[i].nome == nome:
            indices.append(i)
    return indices

def busca_por_matricula(alunos, quantidade_alunos, matricula):
    for i in range(quantidade_alunos):
        if alunos[i].matricula == matricula:
            return i
    return -1


def libera_aluno(aluno):
    del aluno

def imprime_aluno(alunos, quantidade_alunos):
    for i in range(quantidade_alunos):
        print('Nome:', alunos[i].nome)
        print('Documento:', alunos[i].documento)
        print('Matricula:', alunos[i].matricula)

def criatxt(alunos, quantidade_alunos):
    with open('alunos.txt', 'w') as arquivo:
        for i in range(quantidade_alunos):
            arquivo.write(alunos[i].nome + ',' + alunos[i].documento + ',' + str(alunos[i].matricula) + '\n')
    print('Dados salvos com sucesso no arquivo alunos.txt')

def lertxt(alunos):
    with open('alunos.txt', 'r') as arquivo:
        quantidade_alunos = 0
        for linha in arquivo:
            campos = linha.strip().split(',')
            nome = campos[0]
            documento = campos[1]
            matricula = int(campos[2])
            aluno = Aluno(nome, documento, matricula)
            alunos[quantidade_alunos] = aluno
            quantidade_alunos += 1
    print('Dados carregados com sucesso do arquivo alunos.txt')
    return quantidade_alunos
