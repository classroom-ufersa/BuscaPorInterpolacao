from aluno import Aluno


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


def busca_por_matricula(alunos, quantidade_alunos, matricula):
    
    # Define o início e o fim da busca
    inicio = 0
    fim = quantidade_alunos - 1
    
    # Executa a busca por interpolação
    while inicio <= fim and matricula >= alunos[inicio ].matricula and matricula <= alunos[fim].matricula:
        posicao = inicio + int(((fim - inicio) / (alunos[fim].matricula - alunos[inicio].matricula)) * (matricula - alunos[inicio].matricula))
        if alunos[posicao].matricula == matricula:
            return posicao
        elif alunos[posicao].matricula < matricula:
            inicio = posicao + 1
        else:
            fim = posicao - 1
            
    return -1


def busca_nome(alunos, quantidade_alunos, nome):
    
    # Define o início e o fim da busca
    inicio = 0
    fim = quantidade_alunos - 1
    
    # Executa a busca por interpolação
    while inicio <= fim:
        posicao = inicio + int(((fim - inicio) / (ord(alunos[fim].nome[0]) - ord(alunos[inicio].nome[0]))) * (ord(nome[0]) - ord(alunos[inicio].nome[0])))
        if alunos[posicao].nome == nome:
            # Encontrou o nome procurado, agora percorre a lista para encontrar os outros alunos com o mesmo nome
            indices = [posicao]
            i = posicao - 1
            while i >= 0 and alunos[i].nome == nome:
                indices.insert(0, i)
                i -= 1
            i = posicao + 1
            while i < quantidade_alunos and alunos[i].nome == nome:
                indices.append(i)
                i += 1
            return indices
        elif ord(alunos[posicao].nome[0]) < ord(nome[0]):
            inicio = posicao + 1
        else:
            fim = posicao - 1
            
    return []


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
