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
	virtual void objetivo(int id)=0;
};


class Gesti�n_tropas : public IAcci�n
{
	ostream& print_options(ostream& o = cout);
	int get_option(istream& i);

};


class Acci�n_Engine
{
	IAcci�n *a;
public:
	ostream & operator<<(ostream& o);
};