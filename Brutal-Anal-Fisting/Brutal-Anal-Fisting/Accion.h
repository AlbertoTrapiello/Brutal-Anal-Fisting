#pragma once
#include <iostream>


using namespace std;

class IAcci�n
{
public:
	int id;
	int submenu;
	virtual ostream& print_options (ostream& o = cout)=0;
	virtual int get_option(istream& i) = 0;//gestiona la oci�n elegida por elusuario. Inicialmente por teclado posteriormente con rat�n
	virtual bool check(int option) = 0;//checkea la viabilidad de la acci�n

};


class Gesti�n_tropas : public  IAcci�n
{
public:
	ostream& print_options(ostream& o = cout);
	int get_option(istream& i);
	bool check(int option);
};

class Comercio : protected IAcci�n
{
public:
	ostream& print_options(ostream& o = cout);
	int get_option(istream& i);
	bool check(int option);
};

class Diplomacia : protected IAcci�n
{
public:
	ostream& print_options(ostream& o = cout);
	int get_option(istream& i);
	bool check(int option);
};
class Acci�n_Engine
{
	IAcci�n* a;
public:
	Acci�n_Engine(IAcci�n* a): a(a) {}
	ostream & operator<<(ostream& o);
	ostream& print_options(ostream& o = cout);
	int get_option(istream& i = cin);
	bool check(int option);
};