#ifndef DATOS_H
#define DATOS_H

class Datos
{
	
	char texto[65];
	int codigo[17];
	
	public:
		Datos();
		char* getTexto();
		int* getCodigo();
		~Datos();
	protected:
};

#endif
