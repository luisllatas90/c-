#include <iostream>
using namespace std;
//Autor: Luis Llatas

void merge(int *arrayPrincipal, int indiceIzquierda, int indiceCentro, int indiceDerecha){
	
	int tamanio_array = indiceDerecha - indiceIzquierda + 1;
	int arrayAuxiliar[tamanio_array];
	int p = indiceIzquierda; //indice para el vector de la izquierda
	int q = indiceCentro + 1 ; //indice para el vector de la derecha
	int r = 0; //indice para reemplazar el array auxiliar
	
	//compara elemento por el elemento de la porción izquierda y la porción derecha del array
	while (p <= indiceCentro and q <= indiceDerecha){
		
		if(arrayPrincipal[p] <= arrayPrincipal[q] ){
			arrayAuxiliar[r] = arrayPrincipal[p];
			++p;
		}else{
			arrayAuxiliar[r] =  arrayPrincipal[q];
			++q;
		}
		++r;
		
	}
	 
	//obtiene todos los elementos de la porción izquierda del array, en caso sea menores a la porción derecha del array
	while (p <= indiceCentro){
			arrayAuxiliar[r] = arrayPrincipal[p];
			++r;
			++p;
	}
	
	//obtiene todos los elementos de la porción derecha del array, en caso sea menores a la porción izquierda del array
	while (q <= indiceDerecha){
			arrayAuxiliar[r] = arrayPrincipal[q];
			++r;
			++q;
	}
	
	//finalmente reemplaza todos los elementros ya ordenados en el array principal
	for (r = 0; r < tamanio_array; ++r){
		arrayPrincipal[indiceIzquierda + r] = arrayAuxiliar[r];
	}
	 
}

void merge_sort(int *arrayPrincipal, int indiceIzquierda, int indiceDerecha){
	if(indiceIzquierda < indiceDerecha){
		int indiceCentro = (indiceIzquierda + indiceDerecha) / 2; //obtiene la posición del centro
		
		merge_sort(arrayPrincipal, indiceIzquierda, indiceCentro); //ordena la primera mitad del array
		merge_sort(arrayPrincipal, indiceCentro + 1, indiceDerecha); //ordena la segunda mitad del array
		merge(arrayPrincipal, indiceIzquierda, indiceCentro, indiceDerecha);
		
	}
}

// Función principal
int main() {
    int arrayPrincipal[] = {4,6,10,22,34,1,3,11,21,23};
    int tamanio_array = sizeof(arrayPrincipal) / sizeof(arrayPrincipal[0]);
    cout << "ARREGLO ORIGINAL: ";
    for (int i = 0; i < tamanio_array; i++) {
        cout << arrayPrincipal[i] << " ";
    }
    
    merge_sort(arrayPrincipal, 0, tamanio_array - 1);
    cout << "\nARRREGLO ORDENADO: ";
    for (int i = 0; i < tamanio_array; i++) {
        cout << arrayPrincipal[i] << " ";
    }
    return 0;
}


