#pragma once
#include <iostream>


using namespace std;

class IAcción
{
public:
	int id;
	int submenu;
	virtual ostream& print_options (ostream& o = cout)=0;
	virtual int get_option(istream& i) = 0;//gestiona la oción elegida por elusuario. Inicialmente por teclado posteriormente con ratón
	virtual void objetivo(int id)=0;
};


class Gestión_tropas : public IAcción
{
	ostream& print_options(ostream& o = cout);
	int get_option(istream& i);

};


class Acción_Engine
{
	IAcción *a;
public:
	ostream & operator<<(ostream& o);
};