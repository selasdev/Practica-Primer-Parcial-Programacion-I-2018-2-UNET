#include <iostream>
#include <string.h>
#include "Cripta.h"
#include "Datos.h"

int main(int argc, char** argv) {
	
	Cripta interprete; // Se instancia el objeto que maneja los bits y realiza las encriptaciones/desencriptaciones.
	Datos datos; // Se instancia el objeto que contiene los datos a manejar.
	
	char texto[65]; //Se declara la cadena de caracteres que contendr� los datos iniciales.
	int *vector; //Se declara el vector que contendr� la encriptaci�n de la cadena de caracteres.
	char cadena[65]; //Se declara la cadena de caracteres que contendr� la desencriptaci�n del vector.
	
	strcpy(texto, datos.getTexto()); // Obtenemos los datos del objeto.
	
	std::cout << "Cadena de texto a convertir:" << std::endl << std::endl <<
			  texto << std::endl << std::endl << std::endl; // Mostramos que cadena vamos a convertir.
	
	vector = interprete.Encriptar(texto); // Se realiza la conversi�n o encriptaci�n.
	
	std::cout << "Datos Convertidos: " << std::endl << std::endl; // - - - - - - - |
								//                                 Ense�amos el vector que ahora contiene
	for(int i = 0; i < 16; i++) //                                    los datos de la cadena de caracteres.
		std::cout << vector[i] << " "; //  - - - - - - - - - - -- - - - -- - - - - |
		
		
	std::cout  << std::endl << std::endl << std::endl 
			   << "Convertido nuevamente a cadena de texto:" << std::endl << std::endl; // Decimos que mostraremos la conversi�n nuevamente a cadena de caracteres.
	
	strcpy(cadena, interprete.Desencriptar(vector,16)); // Aqu� copiamos en la cadena de caracteres la desencriptaci�n del vector.
	
	std::cout << cadena << std::endl << std::endl  << std::endl; // Mostramos finalmente la conversi�n.
	
	std::cout << "Realizado por Carlos Rosales."; //Autor :)
	
	return 0;
}
