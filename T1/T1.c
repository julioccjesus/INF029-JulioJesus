#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "T1.h"
#ifndef T1_H
#define T1_H
#define matricula_invalida -1
#define m 3
#define n 5
#define MAX 10
int main()
{
    testQ1();
    testQ2();   
    testQ3();
    testQ4();
    testQ5();
    testQ6();
    testQ7();

    return 0;
}

int q1(char calendario[])
{
    char celula[m][n];
    int i = 0, j = 0, k = 0;
    int binary = 1;
    int barras_encontradas = 0;
    while (calendario[i] != '\0' && j < m && barras_encontradas < 2)
    {
        if (calendario[i] == '/')
        {
            celula[j][k] = '\0';
            j++;
            k = 0;
            barras_encontradas++;
        }
        else if (calendario[i] != '\n')
        {
            if (k < m - 1)
            {
                celula[j][k] = calendario[i];
                k++;
            }
        }
        i++;
    }
    while (calendario[i] != '\0' && calendario[i] != '\n' && j < m)
    {
        if (k < m - 1)
        {
            celula[j][k] = calendario[i];
            k++;
        }
        i++;
    }
    celula[j][k] = '\0';
    int dia = convertStringInInt(celula[0]);
    int mes = convertStringInInt(celula[1]);
    int ano = convertStringInInt(celula[2]);
    if (mes < 1 || mes > 12)
        binary = 0;
    if (dia < 1 || dia > 31)
        binary = 0;
    switch (mes)
    {
    case 4:
    case 6:
    case 9:
    case 11:
        if (dia > 30)
            binary = 0;
        break;

    case 2:
        if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))
        {
            if (dia > 29)
                binary = 0;
        }
        else
        {
            if (dia > 28)
                binary = 0;
        }
        break;
    }
    return binary;
}

DiasMesesAnos q2(char datainicial[], char datafinal[])
{
    DiasMesesAnos resultado;
    resultado.retorno = 0;

    int i = 0, j = 0, k = 0;
    int barras_encontradas = 0;
    char celula1[3][5];
    while (datainicial[i] != '\0' && j < 3 && barras_encontradas < 2)
    {
        if (datainicial[i] == '/')
        {
            celula1[j][k] = '\0';
            j++;
            k = 0;
            barras_encontradas++;
        }
        else
        {
            if (k < 4)
            {
                celula1[j][k] = datainicial[i];
                k++;
            }
        }
        i++;
    }
    while (datainicial[i] != '\0' && j < 3)
    {
        if (k < 4)
        {
            celula1[j][k] = datainicial[i];
            k++;
        }
        i++;
    }
    celula1[j][k] = '\0';

    int dia1 = convertStringInInt(celula1[0]);
    int mes1 = convertStringInInt(celula1[1]);
    int ano1 = convertStringInInt(celula1[2]);

    i = 0;
    j = 0;
    k = 0;
    barras_encontradas = 0;
    char celula2[3][5];

    while (datafinal[i] != '\0' && j < 3 && barras_encontradas < 2)
    {
        if (datafinal[i] == '/')
        {
            celula2[j][k] = '\0';
            j++;
            k = 0;
            barras_encontradas++;
        }
        else
        {
            if (k < 4)
            {
                celula2[j][k] = datafinal[i];
                k++;
            }
        }
        i++;
    }
    while (datafinal[i] != '\0' && j < 3)
    {
        if (k < 4)
        {
            celula2[j][k] = datafinal[i];
            k++;
        }
        i++;
    }
    celula2[j][k] = '\0';

    int dia2 = convertStringInInt(celula2[0]);
    int mes2 = convertStringInInt(celula2[1]);
    int ano2 = convertStringInInt(celula2[2]);
    if (mes1 < 1 || mes1 > 12 || dia1 < 1 || dia1 > diaNoMes(mes1))
    {
        resultado.retorno = 2;
        return resultado;
    }
    if (mes2 < 1 || mes2 > 12 || dia2 < 1 || dia2 > diaNoMes(mes2))
    {
        resultado.retorno = 3;
        return resultado;
    }
    if (ano1 > ano2 || (ano1 == ano2 && mes1 > mes2) || (ano1 == ano2 && mes1 == mes2 && dia1 > dia2))
    {
        resultado.retorno = 4;
        return resultado;
    }
    resultado.qtdAnos = ano2 - ano1;
    resultado.qtdMeses = mes2 - mes1;
    resultado.qtdDias = dia2 - dia1;

    if (resultado.qtdDias < 0)
    {
        resultado.qtdMeses--;
        int mesAnterior = mes2 - 1;
        if (mesAnterior < 1)
            mesAnterior = 12;
        resultado.qtdDias += diaNoMes(mesAnterior);
    }

    if (resultado.qtdMeses < 0)
    {
        resultado.qtdAnos--;
        resultado.qtdMeses += 12;
    }
    resultado.retorno = 1;
 

    return resultado;
}

int q3(char texto[252], char letra, int isCaseSensitive) {
    int contador = 0;
    int i = 0;
    char caractere;

    if (!isCaseSensitive && letra >= 'A' && letra <= 'Z') {
        letra += 32;
    }

    while (texto[i] != '\0') {
        caractere = texto[i];
        
        if (!isCaseSensitive && caractere >= 'A' && caractere <= 'Z') {
            caractere += 32;
        }
        
        if (caractere == letra) {
            contador++;
        }
        
        i++;
    }
    
    return contador;
}

int q4(char strTexto[], char strBusca[], int posicoes[30]){

	int qtdOcorrencias = 0;
	int i, j, k = 0;
	int decrementar = 0;
	int contadorLetras;
	int tamanhoBusca = strlen(strBusca); 

	char copia_strTexto[250];
    char copia_strBusca[50];

	strncpy(copia_strTexto, strTexto, 250);
    strncpy(copia_strBusca, strBusca, 50);

    for(i = 0; copia_strTexto[i] !='\0'; i++){
        j = 0;
        contadorLetras = 0;
        
		if(copia_strTexto[i] < -61){
			decrementar--;
        }
		
        if(copia_strTexto[i] == copia_strBusca[j]){
            for(j = 1; copia_strBusca[j] != '\0'; j++){
                if(copia_strBusca[j] != copia_strTexto[i + j]){ 
                    contadorLetras++; 
                }
            }
            if(contadorLetras == 0){
                posicoes[k] = i + 1 + decrementar; 
                posicoes[k+1] = i + tamanhoBusca + decrementar; 
                k += 2;
                qtdOcorrencias++;
                i += 1;
            }
        }
    }
    return qtdOcorrencias;
}


int q5(int numero){
     int invertido = 0;
    
    while (numero % 10 == 0 && numero != 0) {
        numero /= 10;
    }
    
    while (numero != 0) {
        invertido = invertido * 10 + numero % 10;
        numero /= 10;
    }
    
    return invertido;
}

int q6(int numero, int pesq)
{
  int qtd = 0;

  while (numero > 0)
  {
    if (pesq == numero % 10)
    {
      qtd++;
    } 
    else if (pesq == numero % 100)
    {
      qtd++;
    }

    numero /= 10;
  }

  return qtd;
}

int convertStringInInt(char str[])
{
    int res = 0;
    int i = 0;
    int sign = 1;

    if (str[0] == '-')
    {
        sign = -1;
        i = 1;
    }

    for (; str[i] != '\0'; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            res = res * 10 + (str[i] - '0');
        }
        else
        {
            return 0;
        }
    }

    return sign * res;
}

int diaNoMes(int imes)
{
    int ano;
    if (imes == 2)
    {
        if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))
        {
            return 29;
        }
        return 28;
    }
    if (imes == 4 || imes == 6 || imes == 9 || imes == 11)
    {
        return 30;
    }
    return 31;
}

int q7(char matriz[8][10], char palavra[]) {
    int len = 0;
    while (palavra[len] != '\0') {
        len++;
    }
    int dir[8][2] = {
        {-1, 0},  
        {1, 0},   
        {0, -1},  
        {0, 1},   
        {-1, -1}, 
        {-1, 1},  
        {1, -1},  
        {1, 1}    
    };

    int i, j, d, k;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 10; j++) {
            if (matriz[i][j] == palavra[0]) {
                for (d = 0; d < 8; d++) {
                    int x = i, y = j;
                    for (k = 1; k < len; k++) {
                        x += dir[d][0];
                        y += dir[d][1];

                        if (x < 0 || x >= 8 || y < 0 || y >= 10)
                            break;

                        if (matriz[x][y] != palavra[k])
                            break;
                    }
                    if (k == len)
                        return 1;
                }
            }
        }
    }

    return 0;
}

#endif