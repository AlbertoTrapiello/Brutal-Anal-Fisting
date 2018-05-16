#include "Recursos.h"


Recursos::Recursos()
{
	ataque=0;
	comida=0;
	oro=0;
	diplomacia=0;
	defensa=0;
}

ostream & Recursos::print(ostream & o=cout)
 {
	o<<"ataque:"<<ataque<<" comida:"<<comida<<" oro:"<<oro;
	o<<" diplomacia:"<<diplomacia<<" defensa:"<<defensa<<endl;
	return o;
 }

void Recursos::read_file()
{
	ifstream g("Recursos.txt", istream::in);
	if(!g)
	{
		cout<<"el fichero no se ha abierto correctamente"<<endl;
		return;
	}
	ostream &o=cout;
	g>>ataque;
	g>>comida;
	g>>oro;
	g>>diplomacia;
	g>>defensa;
	print(o);
	g.close();
}