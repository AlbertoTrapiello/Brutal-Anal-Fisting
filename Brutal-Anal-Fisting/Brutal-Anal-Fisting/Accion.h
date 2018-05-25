#pragma once
#include <iostream>


using namespace std;

class IAcción
{

	IAcción(){}
	int id;
	int submenu;
	friend Acción_Engine;
public:
	virtual ostream& print_options (ostream& o = cout)=0;
	virtual int get_option(istream& i) = 0;//gestiona la oción elegida por elusuario. Inicialmente por teclado posteriormente con ratón
	virtual void check(int option);//checkea la viabilidad de la acción

};


class Gestión_tropas : public  IAcción
{
	ostream& print_options(ostream& o = cout);
	int get_option(istream& i);
	void check(int option);
};

class Comercio : protected IAcción
{
	ostream& print_options(ostream& o = cout);
	int get_option(istream& i);
	void check(int option);
};

class Diplomacia : protected IAcción
{
	ostream& print_options(ostream& o = cout);
	int get_option(istream& i);
	void check(int option);
};
class Acción_Engine
{
	IAcción *a;
public:
	ostream & operator<<(ostream& o);
};