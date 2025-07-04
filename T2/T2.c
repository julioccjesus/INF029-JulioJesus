#include <stdio.h>
#include <stdlib.h>
#include "EstruturaVetores.h"
#include <stdbool.h>
typedef struct prime
{
    int *auxiliar;
    int valor;
    int tamanho;
} prime;

prime central[10];
No lista;
int retorno;

void SelectionSort(int valor, int auxiliar[])
{
    for (int i = 0; i < valor - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < valor; j++)
        {
            if (auxiliar[j] < auxiliar[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            int temp = auxiliar[i];
            auxiliar[i] = auxiliar[min];
            auxiliar[min] = temp;
        }
    }
}

void inicializar()
{
        for (int i = 0; i < 10; i++)
    {
        central[i].auxiliar = NULL;
        central[i].tamanho = 0;
        central[i].valor = 0;
        lista.head = NULL;
    }
}
void finalizar()
{
    for (int i = 0; i < 10; i++)
    {
        if (central[i].auxiliar != NULL)
        {
            free(central[i].auxiliar);
        }
    }
}

int aux(int posicao, int tamanho)
{
    if (central[posicao].auxiliar != NULL)
    {
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }
    if (posicao <= 0 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    if (tamanho < 1)
    {
        retorno = TAMANHO_INVALIDO;
    }
    else
    {
        central[posicao].auxiliar = malloc(tamanho * sizeof(int));
        if (central[posicao].auxiliar == NULL)
        {
            retorno = SEM_ESPACO_DE_MEMORIA;
        }
        central[posicao].tamanho = tamanho;
        central[posicao].valor = 0;
        retorno = SUCESSO;
    }
    return retorno;
}

int criarEstruturaAuxiliar(int posicaoCentral, int quatosIndices)
{

    retorno = 0;
    posicaoCentral = posicaoCentral - 1;
    if (posicaoCentral < 0 || posicaoCentral > 9)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
    {
        if (central[posicaoCentral].auxiliar != NULL)
        {
            retorno = JA_TEM_ESTRUTURA_AUXILIAR;
        }
        else
        {
            if (quatosIndices < 1)
            {
                retorno = TAMANHO_INVALIDO;
            }
            else
            {
                if (quatosIndices > 10)
                {
                    retorno = SEM_ESPACO_DE_MEMORIA;
                }
                else
                {
                    central[posicaoCentral].auxiliar = malloc(quatosIndices * sizeof(int));
                    central[posicaoCentral].valor = 0;
                    central[posicaoCentral].tamanho = quatosIndices;
                    retorno = SUCESSO;
                }
            }
        }
    }

    return retorno;
}

int inserirNumeroEmEstrutura(int posicao, int valor)
{
    int retorno = 0;

    posicao = posicao - 1;
    if (posicao < 0 || posicao >= 10)
        retorno = POSICAO_INVALIDA;
    else
    {

        if (central[posicao].auxiliar != NULL)
        {

            if (central[posicao].valor < central[posicao].tamanho)
            {
                central[posicao].auxiliar[central[posicao].valor] = valor;
                central[posicao].valor++;
                return SUCESSO;
            }
            else
            {
                retorno = SEM_ESPACO;
            }
        }
        else
        {
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }
    return retorno;
}

int excluirNumeroDoFinaldaEstrutura(int posicao)
{

    posicao = posicao - 1;
    if (posicao >= 0 && posicao < 10)
    {
        if (central[posicao].auxiliar != NULL)
        {
            if (central[posicao].valor != 0)
            {
                central[posicao].valor--;
                return SUCESSO;
            }
            else
            {
                return ESTRUTURA_AUXILIAR_VAZIA;
            }
        }
        else
        {
            return SEM_ESTRUTURA_AUXILIAR;
        }
    }
    else
    {
        return POSICAO_INVALIDA;
    }
}
int excluirNumeroEspecificoDeEstrutura(int posicao, int numero)
{
    posicao = posicao - 1; // ajuste de índice do usuário

    if (posicao < 0 || posicao >= 10)
        return POSICAO_INVALIDA;

    if (central[posicao].auxiliar == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    if (central[posicao].valor == 0)
        return ESTRUTURA_AUXILIAR_VAZIA;

    int i;
    int encontrado = 0;

    // Procurar o número
    for (i = 0; i < central[posicao].valor; i++)
    {
        if (central[posicao].auxiliar[i] == numero)
        {
            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
        return NUMERO_INEXISTENTE;

    // Desloca os elementos para a esquerda
    for (int j = i; j < central[posicao].valor - 1; j++)
    {
        central[posicao].auxiliar[j] = central[posicao].auxiliar[j + 1];
    }

    central[posicao].valor--;

    return SUCESSO;
}

int getDadosEstruturaAuxiliar(int posicao, int vector[])
{
    posicao = posicao - 1;
    if (posicao >= 0 && posicao < 10)
    {
        if (central[posicao].auxiliar != NULL)
        {
            if (central[posicao].valor != 0)
            {
                for (int i = 0; i < central[posicao].valor; i++)
                {
                    vector[i] = central[posicao].auxiliar[i];
                }
                return SUCESSO;
            }
            return ESTRUTURA_AUXILIAR_VAZIA;
        }
        return SEM_ESTRUTURA_AUXILIAR;
    }
    else
    {
        return POSICAO_INVALIDA;
    }
}

int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetor[])
{

    posicao = posicao - 1;
    if (posicao >= 0 && posicao < 10)
    {
        if (central[posicao].auxiliar != NULL)
        {
            if (central[posicao].valor != 0)
            {
                for (int i = 0; i < central[posicao].valor; i++)
                {
                    vetor[i] = central[posicao].auxiliar[i];
                }

                if (!estaOrdenado(vetor, central[posicao].valor))
                {
                    SelectionSort(central[posicao].valor, vetor);
                }
                if (estaOrdenado(vetor, central[posicao].valor))
                {
                    for (int i = 0; i < central[posicao].valor; i++)

                        return SUCESSO;
                }
            }
            return ESTRUTURA_AUXILIAR_VAZIA;
        }
        return SEM_ESTRUTURA_AUXILIAR;
    }
    else
    {
        return POSICAO_INVALIDA;
    }
}
bool estaOrdenado(int vetor[], int tamanho)
{
    for (int i = 0; i < tamanho - 1; i++)
    {
        if (vetor[i] > vetor[i + 1])
            return false;
    }
    return true;
}

int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
    int retorno = 0;
    posicao--;
    if (posicao >= 0 && posicao < 10)
    {
        if (central[posicao].auxiliar != NULL)
        {
            if (novoTamanho > 0)
            {
                int *temp = realloc(central[posicao].auxiliar, novoTamanho * sizeof(int));
                if (temp != NULL)
                {
                    central[posicao].auxiliar = temp;
                }
                else
                {
                    return SEM_ESPACO_DE_MEMORIA;
                }
                return SUCESSO;
            }
            else
            {
                return NOVO_TAMANHO_INVALIDO;
            }
        }
        else
        {
            return SEM_ESTRUTURA_AUXILIAR;
        }
    }
    else
    {
        return POSICAO_INVALIDA;
    }
}

int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
    posicao--;
    if (posicao >= 0 && posicao < 10)
    {
        if (central[posicao].auxiliar != NULL)
        {
            if (central[posicao].valor != 0)
            {
                for(int i = 0; i < central[posicao].valor; i++){
                    return central[posicao].valor;
                }
            }
            else
            {
                return ESTRUTURA_AUXILIAR_VAZIA;
            }
        }
        else
        {
            return SEM_ESTRUTURA_AUXILIAR;
        }
    }
    else
    {
        return POSICAO_INVALIDA;
    }

    return retorno;
}


