#pragma once
#include <iostream>


using namespace std;

class IAcci�n
{

	IAcci�n(){}
	int id;
	int submenu;
	friend Acci�n_Engine;
public:
	virtual ostream& print_options (ostream& o = cout)=0;
	virtual int get_option(istream& i) = 0;//gestiona la oci�n elegida por elusuario. Inicialmente por teclado posteriormente con rat�n
	virtual void check(int option);//checkea la viabilidad de la acci�n

};


class Gesti�n_tropas : public  IAcci�n
{
	ostream& print_options(ostream& o = cout);
	int get_option(istream& i);
	void check(int option);
};

class Comercio : protected IAcci�n
{
	ostream& print_options(ostream& o = cout);
	int get_option(istream& i);
	void check(int option);
};

class Diplomacia : protected IAcci�n
{
	ostream& print_options(ostream& o = cout);
	int get_option(istream& i);
	void check(int option);
};
class Acci�n_Engine
{
	IAcci�n *a;
public:
	ostream & operator<<(ostream& o);
};