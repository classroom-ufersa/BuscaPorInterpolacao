# Busca por Interpolacao
## Video explicando como nosso algoritmo em c funciona
[explicação sobre busca por interpolação](https://www.youtube.com/watch?v=TDV7jLZBS28)
## O que é?
O algoritmo de busca por interpolação como o nome sugere, é um tipo de algoritmo de busca que tem intuito de buscar determinado elemento de um vetor, funciona como um algoritmo de busca binária, a unica diferença entre os dois é o calculo feito para achar o elemento
## Vantagem e desvantagem
 - Vantagem:
 A vantagem desse tipo de algoritmo é que se o vetor estiver ordenado e com seus elementos bem distriubuios é possivel reduzir rasticamente a quantidade de operações feitas pela cpu.
 - Desvantagem:
 A desvantagem desse tipo de algoritmo é que quando o vetor está desordenado, dependendo de onde o elemento está no vetor, o metodo pode acabar invadindo espaço de memória, que acaba acessando indices negativos,quando as entradas crescem exponencialmente a complexidade pode chegar a O(n),sendo o mesmo que uma busca sequencial.
## Complexidade
Casos | Notação Big-O
:---:| :---:
Melhor| O(1)
Médio | O(log2(log2(n)))
Pior | O(n)

## Complexidade de espaço 

A complexidade do espaço auxiliar é representada por O(1)

## Representação de codigo em c e análise de complexidade(pior caso)
```c
int busca_por_interpolacao(int *vetor, int tamanho, int valor){

    int inicio = 0;//c1, 1 vez
    int fim = tamanho - 1;//c2, 1 vez
    int meio;//c3, 1 vez

    while (inicio  <= fim){//c4, n vezes
        
        meio = inicio + ((valor - vetor[inicio]) * (fim - inicio)) / (vetor[fim] - vetor[inicio]);//c5, n vezes
        
        if(vetor[meio] == valor){//c6, n vezes

            return meio;//c7,1 vez

        }else if (vetor[meio] < valor){//c8, n vezes

            inicio = meio + 1;//c9, n vezes

        }else {//c10, n vezes

            fim = meio - 1;//c11, n vezes

        }
    }

    return -1;//c12, 1 vez

}
//T(n)=c1+c2+c3+n*(c4+c5+c6+c8+c9+c10+c11)+c7+c12
//T(n)=c1+c2+c3+n*a+c7+c12
//T(n)=a*n
//T(n)=n
//notação Big-O:
//O(n)

```
