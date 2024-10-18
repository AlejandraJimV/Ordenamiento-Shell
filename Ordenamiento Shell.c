/*
Elaborado por Alejandra Jiménez Venegas 
Estructuras de Datos
Este programa es un ejemplo educativo que ilustra el uso de estructuras de datos y algoritmos de ordenamiento
(en este caso el método de ordenamiento Shell), así como la manipulación de la consola en C. 
Además, permite al usuario observar el proceso de ordenamiento a medida que se realizan las comparaciones e intercambios.*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define MAX 30

//Funciones aux.
void gotoxy(int x, int y);
int margen(int a, int b, int c, int d);
void encabezado();
void final();
//Funcionalidad
void aleatorios(int arreglo[], int n);
void ordenarShell(int x, int y, int arreglo[], int n, int val);
//Rep. visual
void realizarInter(int x, int y, int cont, int in, int num1, int num2, int val);
void apuntar(int x, int y, int z, int in, int n);
void cuadros(int x, int y, int n, int val);
void datos(int x, int y, int vector[], int n, int val);


int main() {
    int vector[MAX];
    int n, i;
	encabezado();
    do {
        gotoxy(40, 6);
        printf("Elementos (menor o igual a 30): ");
        gotoxy(74, 6);
        scanf("%d", &n);
		//limite de 30 elem.
        if (n>30) {
            gotoxy(40, 7);
            printf("Por favor, ingrese un valor menor o igual a 30");
            Sleep(3000);
            gotoxy(40, 7);
            printf("                                               ");
            gotoxy(74, 6);
            printf("  ");
        }
    } while (n > 30);
		srand(time(NULL));
        cuadros(5, 15, n, 2);
        aleatorios(vector, n);
        gotoxy(5,7);
        printf("Vector Original: "); //mostrar vector proporcionado
    	datos(5, 8, vector, n, 2);
        ordenarShell(5, 15, vector, n, 2);
        final();
}

void encabezado() {
    margen(2,1,110,25);
	margen(40, 2, 67, 4);
    gotoxy(40, 3);
    printf("METODO DE ORDENAMIENTO SHELL");
}

void final() {
    gotoxy(5, 23);
    printf("El ordenamiento ha finalizado");
    gotoxy(5, 25);
    printf("Presione una tecla para finalizar...");
    getch();
    system("cls");
}


void aleatorios(int arreglo[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        arreglo[i] = rand() % 90 + 10;
    }
}

void ordenarShell(int x, int y, int arreglo[], int n, int digitos) {
    int intervalo = n;
    int bandera = 0, indice = 0, auxiliar = 0, contador = 0, k;

    while (intervalo > 0) {
        intervalo = intervalo / 2;
        bandera = 1;

        while (bandera == 1) {
            bandera = 0;
            indice = 0;
            contador = x + 1;
            datos(x + 1, y, arreglo,n, digitos);

            while ((indice + intervalo) < n) {
                contador = contador + (indice * 3);

                for (k = 0; k <= 100; k++) {
                    gotoxy(x + k, y + 5);
                    printf(" ");
                }

                apuntar(x, y, indice, intervalo, n);
                Sleep(1000);

                if (arreglo[indice] > arreglo[indice + intervalo]) {
                	realizarInter(x, y, contador, intervalo, arreglo[indice], arreglo[indice + intervalo], digitos);
                    auxiliar = arreglo[indice];
                    arreglo[indice] = arreglo[indice + intervalo];
                    arreglo[indice + intervalo] = auxiliar;
                    bandera = 1;
                    datos(x + 1, y, arreglo, n, digitos);
                }

                indice++;
                contador = x + 1;
            }
        }
    }
}

void realizarInter(int x, int y, int cont, int in, int num1, int num2, int val) {
    int i, j;

	//Subir posiciones
    for (i = 0; i < 4; i++) {
        if (i == 2) {
            gotoxy(cont, (y + 1) - i + 1);
            printf("%c%c", 196, 196);
            gotoxy(cont + (in * 3), (y + 1) + i - 1);
            printf("%c%c", 196, 196);
        }

        gotoxy(cont, (y + 1) - i);
        printf("\033[1;32m%02d\033[0m", num1);// verde
        gotoxy(cont + (in * 3), (y + 1) + i);
        printf("\033[1;32m%02d\033[0m", num2);//verde

        Sleep(200);

        for (j = 0; j < val; j++) {
            gotoxy(cont + j, (y + 1) - i);
            printf(" ");
            gotoxy(cont + j + (in * 3), (y + 1) + i);
            printf(" ");
        }
    }

	//Lados
    for (i = 0; i < in* 3; i++) {
        gotoxy(cont + i, y - 2);
        printf("\033[1;32m%02d\033[0m", num1);//verde
        gotoxy((cont + (in * 3)) - i, y + 4);
        printf("\033[1;32m%02d\033[0m", num2);//verde

        Sleep(200);

        for (j = 0; j <= val; j++) {
            gotoxy(cont + i + j, y - 2);
            printf(" ");
            gotoxy(((cont + (in * 3)) - i) + j, y + 4);
            printf(" ");
        }
    }
	//Bajar posiciones
    for (i = 0; i < 4; i++) {
        if (i == 3) {
            gotoxy(cont + (in * 3), (y - 2) + i - 1);
            printf("%c%c", 196, 196);
            gotoxy(cont, (y + 4) - i + 1);
            printf("%c%c", 196, 196);
        }

        gotoxy(cont + (in * 3), (y - 2) + i);
        printf("\033[1;32m%02d\033[0m", num1);//verde
        gotoxy(cont, (y + 4) - i);
        printf("\033[1;32m%02d\033[0m", num2);//verde

        Sleep(200);

        for (j = 0; j < val; j++) {
            gotoxy(cont + j + (in * 3), (y - 2) + i);
            printf(" ");
            gotoxy(cont + j, (y + 4) - i);
            printf(" ");
        }
    }
}

//mostrar datos/valores
void datos(int x, int y, int vector[], int n, int val) {
    int i;
    for (i = 0; i < n; i++) {
        gotoxy(x + ((val + 1) * i), y + 1);
        printf("%d", vector[i]);
    }
}

void gotoxy(int x, int y) {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

//Para indicar las comparaciones
void apuntar(int x, int y, int z, int in, int n) {
    int ax = x + 1;

    gotoxy(ax + (z * 3) - 3, y + 5);
    printf(" ");
    gotoxy(ax + (z * 3), y + 5);
    printf("^");//Simb indicador
    gotoxy(ax + (z * 3) + (in * 3) - 3, y + 5);
    printf(" ");
    gotoxy(ax + (z * 3) + (in * 3), y + 5);
    printf("^");
}


void cuadros(int x, int y, int n, int val) {
    int i, j;

    gotoxy(x, y);
    printf("%c", 218);
    gotoxy(x, y + 2);
    printf("%c", 192);

for (i = 0; i < n; i++) {
    for (j = 1; j <= val; j++) {
        gotoxy(x + ((val + 1) * i) + j, y);
        printf("%c", 196);
        gotoxy(x + ((val + 1) * i) + j, y + 2);
        printf("%c", 196);
    }

        gotoxy(x + ((val + 1) * i) + j, y);
        printf("%c", 194);
        gotoxy(x + ((val + 1) * i) + j, y + 2);
        printf("%c", 193);
    }

    for (i = 0; i <= n; i++) {
        gotoxy(x + ((val + 1) * i), y + 1);
        printf("%c", 179);
    }

    gotoxy(x + ((val + 1) * i) - (val + 1), y);
    printf("%c", 191);
    gotoxy(x + ((val + 1) * i) - (val + 1), y + 2);
    printf("%c", 217);
}

int margen(int a, int b, int c, int d) {
    int j, k, i;
    j = a;
    gotoxy(a - 1, b);
    printf("%c", 201);
    gotoxy(a - 1, d);
    printf("%c", 200);
    for (a; a <= c; a++) {
        gotoxy(a, b);
        printf("%c", 205);
        gotoxy(a, d);
        printf("%c", 205);
    }
    gotoxy(a, b);
    printf("%c", 187);
    gotoxy(a, d);
    printf("%c", 188);
    k = b + 1;
    for (k; k <= (d - 1); k++) {
        gotoxy(j - 1, k);
        printf("%c", 186);
        gotoxy(a, k);
        printf("%c", 186);
    }
}

