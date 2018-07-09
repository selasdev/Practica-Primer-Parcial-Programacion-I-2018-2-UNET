#include "Datos.h"
#include <string.h>

Datos::Datos()
{
	
	char *texto = "Esto es una prueba para el parcial de programacion I de la Unet.";
	int codigo[17] = { 1869902661, 544433440, 543256181, 1702195824, 169894242, 1634886000,
                       543974688, 1668440432, 543973737, 1881171300, 1919381362, 1667329377,
					   544142185, 1701055049, 543255584, 1952804437, 2606 };
					   
	for(int i=0; i < 17; i++){
		this->codigo[i] = codigo[i];
	}
	
	strcpy(this->texto, texto);
	
}

char* Datos::getTexto()
{
	return this->texto;
}

int* Datos::getCodigo()
{
	return this->codigo;
}


Datos::~Datos()
{
}
