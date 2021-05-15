#include <iostream>
#include "damas.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	damas* v =  new damas();
	v->prepararTablero();
	v->jugar();
	delete v;
	return 0;
}