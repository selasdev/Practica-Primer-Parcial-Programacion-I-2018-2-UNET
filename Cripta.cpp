#include "Cripta.h"
#include <string.h>
#include <stdlib.h>
#include <iostream>

int* Cripta::Encriptar(char *texto)
{
	int tamVector;
	
	// --- DEFINIR EL TAMAÑO DEL VECTOR ---
	
	if( strlen(texto) > 4){
		
		tamVector = strlen(texto) / 4;
		
		if ( (strlen(texto) % 4) != 0) tamVector++;
		
	}else tamVector = 1;
	
	// --- DECLARAR EL VECTOR ---
	
	int *vector = (int *) malloc (sizeof(int)*tamVector);
	
	for(int i = 0; i < tamVector; i++){
		vector[i] = 0;
	}
	
	
	// --- PROCESO DE ENCRIPTADO ---
	
	
	for(int i = 0; i < tamVector; i++){
		
		if( ( 3 + (i*4) < strlen(texto) ) ){
			
			vector[i] |= texto[3 + (i*4)];
			vector[i] <<= 8;
			
		}
		if( ( 2 + (i*4) < strlen(texto) ) ){
			
			vector[i] |= texto[2 + (i*4)];
			vector[i] <<= 8;
			
			
		}
		if( ( 1 + (i*4) < strlen(texto) ) ){
			
			vector[i] |= texto[1 + (i*4)];
			vector[i] <<= 8;
			
		}
		if( ( (i*4) < strlen(texto) ) ){
			
			vector[i] |= texto[(i*4)];
			
		}
		
	}
	
	
	return vector;
}

char* Cripta::Desencriptar(int *vector, int tamVector){
	
	int tamCadena;
	
	tamCadena = tamVector*4;
	tamCadena += 1;
	
	char *texto = (char * ) malloc (sizeof(char)* tamCadena);
	
	int mascara = 255;
	int auxiliar;
	
	for(int i = 0; i < tamVector; i++){
		
		auxiliar = vector[i] & mascara;
		texto[i*4] = auxiliar | 0;
		vector[i] >>= 8;
		std::cout << texto[i*4];
		
		
		auxiliar = vector[i] & mascara;
		texto[i*4 + 1] = auxiliar | 0;
		vector[i] >>= 8;
		std::cout << texto[i*4 + 1];
		
		auxiliar = vector[i] & mascara;
		texto[i*4 + 2] = auxiliar | 0;
		vector[i] >>= 8;
		std::cout << texto[i*4 + 2];
		
		auxiliar = vector[i] & mascara;
		texto[i*4 + 3] = auxiliar | 0;
		std::cout << texto[i*4 + 3];
		
	}
	
	
	
	return texto;
}
