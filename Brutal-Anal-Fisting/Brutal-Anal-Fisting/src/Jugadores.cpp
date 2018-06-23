#include "Jugadores.h"
#define N_jug 10



Jugadores::Jugadores():region("Robb")
{
	casa=Casas::Stark;
	nombre="Robb";
	titulo="King in the North";

}

Jugadores::Jugadores (const Jugadores &j):region(j.nombre)
{
	turno = false;
	ataque=j.ataque;
	comida=j.comida;
	oro=j.oro;
	diplomacia=j.diplomacia;
	defensa=j.defensa;
	casa=j.casa;
	nombre=j.nombre;
	titulo=j.titulo;
}


Casas Jugadores::stringtoCasas(string e)
{
	stringstream sstr;
	int r;
	sstr<<e<<endl;
	sstr>>r;
	Casas res=static_cast<Casas>(r);
	return res;
}

ostream& Jugadores::print(ostream& o = cout)
{
	o<<"Casa:"<<casa<<endl;
	o<<"Nombre:"<<nombre<<endl;
	o<<"Titulo:"<<titulo<<endl;
	return o;
}

bool Jugadores::read_file(Jugadores *p)
{
	ifstream f("Jugadores.txt", istream::in);
	if(!f)
	{
		cout<<"el fichero no se ha abierto correctamente"<<endl;
		return false;
	}
	for(int i=0;i<10;i++)
	{
		string aux;
		ostream &o=cout;
		getline(f,aux,'\n');
		p[i].casa = stringtoCasas(aux);
		getline(f,p[i].nombre,'\n');//getline(f,nombre);
		getline(f,p[i].titulo,'\n');
		p[i].print(o);
		p[i].Recursos::read_file();
	}
	f.close();
	return true;
}

//tengo problemas con el destructor si lo defino yo.
/*Jugadores::~Jugadores()
{
	delete[]p;
}
*/