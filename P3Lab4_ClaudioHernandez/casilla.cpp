#include "casilla.h"
#include "pieza.h"

casilla::casilla()
{
}
casilla::casilla(bool v,bool m)
{
	piezaAsignada = new pieza(v,m);
}
casilla::setPieza(bool v,bool m)
{
	piezaAsignada = new pieza(v,m);
}
pieza* casilla::getpieza()
{
return piezaAsignada;	
}

casilla::~casilla()
{
	delete piezaAsignada;
}