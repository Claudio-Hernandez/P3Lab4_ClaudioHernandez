#include "damas.h"
#include <iostream>
#include "pieza.h"
using std::cout;
using std::cin;
damas::damas() {
}
void damas::prepararTablero() {
	for(int i=0; i<8; i++) {
		tablero[i] = new casilla*[8];
	}
	//negras
	for(int i =0; i<3; i++) {
		for(int j=0; j<8; j++) {
			if(i%2==0) {
				if(j%2==0) {
					//	cout<<"c";
					tablero[i][j]= new casilla(true,false);

				} else if(j%2==1) {
					//	cout<<"v";
					tablero[i][j]= new casilla();

				}


			}
			if(i%2==1) {
				if(j%2==1) {
					//	cout<<"v";

					tablero[i][j]= new casilla(true,false);

				} else {

					tablero[i][j]= new casilla();

				}

			}
		}
		//	cout<<"\n";

	}
	//blancas
	for(int i =5; i<8; i++) {
		for(int j=0; j<8; j++) {
			if(i%2==0) {
				if(j%2==0) {
					tablero[i][j]= new casilla(false,false);

				} else {
					tablero[i][j]= new casilla();

				}


			}
			if(i%2==1) {
				if(j%2==1) {
					tablero[i][j]= new casilla(false,false);

				} else {
					tablero[i][j]= new casilla();

				}

			}
		}

	}
	for(int i =3; i<5; i++) {
		for(int j=0; j<8; j++) {
			tablero[i][j] = new casilla();
		}
	}
	/*
	tablero[0][0]= new casilla(true,false);
	tablero[0][2]= new casilla(true,false);
	tablero[0][4]= new casilla(true,false);
	tablero[0][6]= new casilla(true,false);
	tablero[1][1]= new casilla(true,false);
	tablero[1][3]= new casilla(true,false);
	tablero[1][5]= new casilla(true,false);
	tablero[1][7]= new casilla(true,false);
	tablero[2][0] = new casilla(true,false);
	tablero[2][0] = new casilla(true,false);
	tablero[2][2] = new casilla(true,false);
	tablero[2][4] = new casilla(true,false);
	tablero[2][6] = new casilla(true,false);
	// blancas
	tablero[7][1] =  new casilla(false,false);
	tablero[7][3] =  new casilla(false,false);
	tablero[7][5] =  new casilla(false,false);
	tablero[7][7] =  new casilla(false,false);
	tablero[6][0] =  new casilla(false,false);
	tablero[6][2] =  new casilla(false,false);
	tablero[6][4] =  new casilla(false,false);
	tablero[6][6] =  new casilla(false,false);
	tablero[5][0] =  new casilla(false,false);
	tablero[5][2] =  new casilla(false,false);
	tablero[5][4] =  new casilla(false,false);
	tablero[5][6] =  new casilla(false,false);
	*/
	imprimirTablero();

}
void damas::imprimirTablero() {
	for(int i = 0; i<8; i++) {
		for(int j = 0; j<8; j++) {
			if(tablero[i][j]->getpieza()==0) {
				cout<<"[ ]";
			} else {

				cout<<"["<<tablero[i][j]->getpieza()->toString()<<"]";
			}
		}
		cout<<"\n";
	}
}

bool damas::comprobar() {
	int negr=0;
	bool seguir=true;
	int blancas =0;
	for(int i =0; i<8; i++) {
		for(int j=0; j<8; j++) {
			if(tablero[i][j]->getpieza()->getTipo()==true) {
				negr++;
				cout<<negr;
			} else if(tablero[i][j]->getpieza()->getTipo()==false){
				blancas++;
				cout<<blancas<<"blancas";
			}
		}
	}
	if(negr==0) {
		seguir=false;
	}
	if(blancas==0) {
		seguir = false;
	}
	return seguir;
}
bool damas::validarMovimiento(int posx,int posy,int posxn,int posyn){
	bool puede =false;
		if(tablero[posx][posy]->getpieza()->getTipo()==true&&(tablero[posxn][posyn]->getpieza()->getTipo()==false||tablero[posx][posy]->getpieza()==0)){
			if(posxn<8&&posyn<8){
				puede = true;
			}
		}else if(tablero[posx][posy]->getpieza()->getTipo()==false&&(tablero[posxn][posyn]->getpieza()->getTipo()==true||tablero[posx][posy]->getpieza()==0)){
			if(posxn<8&&posyn<8){
				puede = true;
			}
		}
		return puede;
	
}
void damas::jugar() {
//	while(comprobar()) {
		int posx=0;
		int posy =0;
		int posxn =0;
		int posyn=0;
		cout<<"Ingrese la pos x de la pieza a mover:";
		cin>> posx;
		cout<<"Ingrese la pos Y de la pieza a mover:";
		cin>>posy;
		cout<<"Ingrese la pos x a mover la pieza:";
		cin>> posxn;
		cout<<"Ingrese la pos Y a mover la pieza";
		cin>>posyn;
		imprimirTablero();
		
		//if(validarMovimiento(posx,posy,posxn,posyn)){
			capturar(posxn,posyn,posx,posy);
	//	}else{
		//	cout<<"No se puede mover a ese lugar!\n";
	//	}
		


//	}


}
void damas::capturar(int posxn,int posyn,int posx,int posy){
	//	if(tablero[posx][posy]->getpieza()->getTipo()==true){
			if(tablero[posxn][posyn]->getpieza()==0){
				tablero[posxn][posyn]->setPieza(true,false);
			}else{
				tablero[posxn][posyn]->getpieza()->setTipo(true);	
			}
	//	}
	//	if(!tablero[posx][posy]->getpieza()->getTipo()==false){
	//		tablero[posxn][posyn]->getpieza()->setTipo(false);
	//	}	
	}
damas::~damas() {
	if(tablero!=NULL) {
		for(int i = 0; i<8; i++) {
			delete[] tablero[i];
		}

		delete[] tablero;

		tablero=NULL;
		//columnas=filas=0;
	}
}
