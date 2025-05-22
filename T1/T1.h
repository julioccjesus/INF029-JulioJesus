#define TAM 100
#define MAX_CHARS 256
#define MAX 10
typedef struct{
    int qtdDias;
    int qtdMeses;
    int qtdAnos;
    int retorno;
}DiasMesesAnos;
int q1(char calendario[]);
void testQ1();
DiasMesesAnos q2(char datainicial[], char datafinal[]);
void testQ2();
int convertStringInInt(char str[]);
int diaNoMes(int imes);
int q3(char palavra[252], char letra, int vof);
void testQ3();
void testQ4();
int q4(char strTexto[252], char strBusca[52], int posicoes[30]);
int q5(int N);
void testQ5();
int q6(int natural, int vezes);
void testQ6();
void testQ7();
int q7(char mat[MAX][MAX], char palavra[]);
char acento(char c);
