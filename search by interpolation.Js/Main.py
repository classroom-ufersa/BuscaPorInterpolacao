from aluno import Aluno
from alunos import cria_aluno, busca_nome, libera_aluno, lertxt, criatxt, imprime_aluno, busca_por_matricula

alunos = [None] * 100
quantidade_alunos = 0
escolha = 0

while True:
    print('1 - Cadastrar Aluno')
    print('2 - Buscar Aluno pela Matricula')
    print('3 - Buscar Aluno pelo Nome')
    print('4 - Imprimir Lista de Alunos')
    print('5 - Salvar Lista de Alunos')
    print('6 - Carregar Lista de Alunos')
    print('0 - Sair')

    opcao = int(input('Digite a opcao desejada: '))

    if opcao == 1:
        quantidade_alunos += 1
        cria_aluno(alunos, quantidade_alunos)
        
    elif opcao == 2:
        matricula = int(input('Digite a matricula do aluno: '))
        indice = busca_por_matricula(alunos, quantidade_alunos, matricula)
        if indice == -1:
            print('Aluno nao encontrado')
        else:
            print('Nome:', alunos[indice].nome)
            print('Documento:', alunos[indice].documento)
            print('Matricula:', alunos[indice].matricula)
    elif opcao == 3:
        nome = input('Digite o nome do aluno: ')
        indices = busca_nome(alunos, quantidade_alunos, nome)
        if len(indices) == 0:
            print('Aluno nao encontrado')
        else:
            for indice in indices:
                print('Nome:', alunos[indice].nome)
                print('Documento:', alunos[indice].documento)
                print('Matricula:', alunos[indice].matricula)
    elif opcao == 4:
        imprime_aluno(alunos, quantidade_alunos)
    elif opcao == 5:
        criatxt(alunos, quantidade_alunos)
    elif opcao == 6:
        lertxt(alunos)
        quantidade_alunos = len(alunos)
    elif opcao == 0:
        break
    else:
        print('Opcao invalida')

libera_aluno(alunos)
