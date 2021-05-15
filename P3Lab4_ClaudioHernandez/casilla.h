#ifndef CASILLA_H
#define CASILLA_H
#include "pieza.h"
#include <string>
using std::string;
class casilla
{
	private:
		pieza* piezaAsignada =0;
	public:
		casilla();
		casilla(bool,bool);
		setPieza(bool,bool);
		pieza* getpieza();

		~casilla();
	protected:
};

#endif