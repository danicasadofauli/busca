/*****************************************************************************************************
*
*@Propósito: Analizar el movimiento de una pieza de ajedrez (en este caso una torre) a partir de las coordenadas iniciales
* que introduce el usuario y el nº de casillas que dicha pieza se desplaza tanto en horizontal como vertical 
*@Autor: Daniel Casado Faulí 
*@Fecha creación: 23/10/2017
*@Fecha última modificiación: 30/10/2017
*
******************************************************************************************************/

#include <conio.h>
#include <stdio.h>

int fila, aux_fila; 				// Crearemos una variable auxiliar tanto para la fila como la columna
char columna, aux_columna;          // para poder asi mantener guardado el valor inicial
int opcion;
int mov_vertical, mov_horizontal;

void main(){
	printf("Bienvenido\n");
	do{

	//Pedimos al usuario la coordenada horizontal en la que se encuentra la pieza (coordenada literal) 
	printf("Donde se encuentra actualmente la pieza?\n");
	printf("Columna (Letra):");
	scanf("%c", &columna);
	if (columna >= 'a' && columna <= 'z'){	// Transformamos valor de caracter en caso de minúsculas a mayúsculas para poder así operar más
		columna = columna -('a' - 'A');		// fácilmente con los valores y para poder mostrar posteriormente estas coordenadas como mayúsculas
	}

	//Pedimos al usuario coordenada vertical (valor numérico)
	printf("Fila (Numero):");
	scanf("%d", &fila);
	fflushnou();
	
	//Excepción coordenadas ficha no se encuentren dentro del rango de tablero limitado o se hayan introducido símbolos incorrectos en vez de valores reales
	//(deberá de volver a introducir datos en este caso)
	if (!(columna >= 'A' && columna <= 'H') || !(fila >= 1 && fila <= 8)){
		printf("\nError, esta posición no se encuentra dentro del tablero\n");
	}
	} while(!(columna >= 'A' && columna <= 'H') || !(fila >= 1 && fila <=8));
	printf("\nPieza introducida correctamente!");
	
	// Presentación del menú de opciones para el usuario: se muestran posibles opciones de movimiento de ficha
	do {
		printf("\n\nEscoja la opcion que desea:\n");
		printf("1- Mover verticalmente:\n");
		printf("2- Mover horizontalmente:\n");
		printf("3- Salir:\n\n");
		printf("Opcion:");
		scanf("%d", &opcion);
		
		switch(opcion){
			
			// Caso movimiento vertical (movimiento por filas)
			case 1: 
				aux_fila = fila;	// Aux_fila guarda el valor inicial de fila al necesitarlo como comparador para ver la trayectoria de la ficha,
									// ya que la variable fila será la que modificaremos en el movimiento
				do{
					printf("\n\n¿Cuantas posiciones quieres moverte verticalmente? ");
					scanf("%d", &mov_vertical);
					
					// Caso movimiento se encuentre dentro de los limites del tablero
					if(fila + mov_vertical >= 1 && fila + mov_vertical <= 8){
						fila = fila + mov_vertical;
						// La pieza es desplazada, mostrando tanto la posición final como el punto donde se inicio el movimiento
						printf("\n\n La pieza se ha movido de la posicion %c%d a la %c%d", columna, aux_fila, columna, fila);
					}

					// Caso movimiento fuera del rango limite de movimiento
					else {
						printf("\n\nError, se está moviendo la pieza fuera del tablero");
					}
				} while(!(aux_fila + mov_vertical >= 1 && aux_fila + mov_vertical <= 8));
				break;

			// Caso movimiento horizontal (movimiento por columnas)
			case 2:					
				aux_columna = columna;	// Aux_columna guarda el valor inicial de columna (mismo uso que aux_fila)
				do{
					printf("\n\n¿Cuantas posiciones quieres moverte horizontalmente? ");
					scanf("%d", &mov_horizontal);
					
					// Caso movimiento se encuentre dentro de los límites del tablero
					if(columna + mov_horizontal >= 'A' && columna + mov_horizontal <= 'H'){
						columna = columna + mov_horizontal;
						printf("\n\n La pieza se ha movido de la posicion %c%d a la %c%d", aux_columna, fila, columna, fila);
					}

					// Caso movimiento fuera del rango límite de movimiento
					else {
						printf("\n\nError, se está moviendo la pieza fuera del tablero");
					}
				} while(!(aux_columna + mov_horizontal >= 'A' && aux_columna + mov_horizontal <= 'H'));
				break;
			
			// Caso salir del programa
			case 3:
				printf("\n\nGracias por utilizar nuestro programa\n\n");
				break;
			
			// Caso se introduce opcion erronea
			default: 
				printf("\n\nError. Opcion incorrecta.");
		}
	} while(opcion != 3);	// La tarea del menú de opciones se sigue ejecutando hasta que el usuario pulse el botón 3 para salir del programa definitivamente
}
