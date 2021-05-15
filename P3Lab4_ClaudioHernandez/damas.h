#ifndef DAMAS_H
#define DAMAS_H
#include "casilla.h"
class damas
{
	casilla*** tablero =  new casilla**[8];
	int blancas=11;
	int negras=12;
	public:
		damas();
		void prepararTablero();
		void imprimirTablero();
		void capturar(int posxn,int posyn,int posx,int posy);
		bool validarMovimiento(int posx,int posy,int posxn,int posyn);
		bool comprobar();
		void jugar();
		~damas();
	protected:
};

#endif