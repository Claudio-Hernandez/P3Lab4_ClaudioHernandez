#ifndef PIEZA_H
#define PIEZA_H
#include <string>
using std::string;
class pieza
{
		private :
			bool tipo=false;
			bool reina=false;
	public:
		pieza();
		string toString();
		bool getTipo();
		void setTipo(bool);
		pieza(bool,bool);
		~pieza();
	protected:
};

#endif