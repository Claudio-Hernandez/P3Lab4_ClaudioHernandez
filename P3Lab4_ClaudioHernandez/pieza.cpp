#include "pieza.h"

pieza::pieza()
{
}
pieza::pieza(bool v, bool m)
{
	tipo = v;
	reina = m;
}
string pieza::toString(){
	string men;
	if(tipo==true){
		if(reina==true){
			men= "RX";
		}else{
			men= "X";
		}
	}else if(tipo ==false){
		if(reina==true){
			men= "RO";
		}else{
			men= "O";
		}
	}
	return men;
}
bool pieza::getTipo(){
	return tipo;
}
void pieza::setTipo(bool g){
	tipo =g;
}

pieza::~pieza()
{
}