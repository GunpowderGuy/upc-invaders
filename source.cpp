/*
| 38 | (Arriba) |
| 40 | (Abajo) |
| 37 | (Izqierda) |
| 39 | (Derecha) |
*/

#define arriba 'w'
#define abajo 's'
#define derecha 'd'
#define izquierda 'a'

#include <iostream>
#include <conio.h>

using namespace System; // sin esto console no funciona

struct personaje { // no necesariamente el principal , si es que lo usara , podria ser el enemigo 
	int x;
	int y;
};

char ** Crear_Matriz(int filas, int columnas)
{
	char **tablero;
	tablero = new char*[filas];
	for (int i = 0; i < filas; i++)
		tablero[i] = new char[columnas];

	return tablero;
}

void genera_y_muestra_matriz(char** matriz, int filas, int columnas) { // la llena y la muestra
	for (size_t i = 0; i < filas; i++) {
		for (size_t j = 0; j < columnas; j++) { // 20 es un guardaespacios
			matriz[i][j] = 0;
			if (i == 0 || i == (filas - 1)) matriz[i][j] = 1;
			if (j == 0 || j == (columnas - 1)) matriz[i][j] = 1;
		}
	}


	for (size_t i = 0; i < filas; i++) {
		for (size_t j = 0; j < columnas; j++) { // 20 es un guardaespacios
			Console::SetCursorPosition(j, i);
			if (matriz[i][j] == 0) std::cout << " ";
			if (matriz[i][j] == 1) std::cout << char(219);
		}
	}

}

void dibujar(int x, int y) {
	Console::SetCursorPosition(x, y);
	std::cout << char(219);
}

void borrar(int x, int y) {
	Console::SetCursorPosition(x, y);
	std::cout << " ";
}

void desplazar_movil(personaje yo, char** arreglo, int filas, int columnas, char tecla) {
	if ((yo.x - 1 >= 0) && tecla == izquierda && arreglo[yo.x - 1][yo.y] == 0) borrar(yo.x, yo.y); yo.x = yo.x - 1; dibujar(yo.x, yo.y);
	if ((yo.x - 1 >= 0) && tecla == derecha && arreglo[yo.x + 1][yo.y] == 0) borrar(yo.x, yo.y); yo.x = yo.x + 1; dibujar(yo.x, yo.y);

	if ((yo.x - 1 >= 0) && tecla == arriba && arreglo[yo.x][yo.y - 1] == 0)borrar(yo.x, yo.y); yo.y = yo.y - 1; dibujar(yo.x, yo.y);
	if ((yo.x - 1 >= 0) && tecla == abajo && arreglo[yo.x][yo.y + 1] == 0) borrar(yo.x, yo.y); yo.y = yo.y + 1; dibujar(yo.x, yo.y);
}

int main () {
	int numfilas = 20; int numcolumnas = 20;
	
	char** tablero = Crear_Matriz(numfilas,numcolumnas);

	genera_y_muestra_matriz(tablero, numfilas, numcolumnas);
	char *input = new char;

	// int *movilx = new int; int *movily = new int;
	personaje *yo = new personaje;
    //*movily = 5;*movilx = 5;
	yo -> x = 5; yo -> y = 5;


	while (true)
	{
		*input = getch();
		desplazar_movil(*yo, tablero, numfilas, numcolumnas, *input);
	}

	return 0;
}
