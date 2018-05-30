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
	virtual bool check(int option) = 0;//checkea la viabilidad de la acción

};


class Gestión_tropas : public  IAcción
{
public:
	ostream& print_options(ostream& o = cout);
	int get_option(istream& i);
	bool check(int option);
};

class Comercio : protected IAcción
{
public:
	ostream& print_options(ostream& o = cout);
	int get_option(istream& i);
	bool check(int option);
};

class Diplomacia : protected IAcción
{
public:
	ostream& print_options(ostream& o = cout);
	int get_option(istream& i);
	bool check(int option);
};
class Acción_Engine
{
	IAcción* a;
public:
	Acción_Engine(IAcción* a): a(a) {}
	ostream & operator<<(ostream& o);
	ostream& print_options(ostream& o = cout);
	int get_option(istream& i = cin);
	bool check(int option);
};