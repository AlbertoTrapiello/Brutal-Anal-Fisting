#pragma once
#include <iostream>

using namespace std;

static int idr;

class IAccion
{
public:
	int id;//id de la accion elegida
	int submenu;
	IAccion();
	//IAccion(int id, int submenu) :id(id), submenu(submenu) {}
	virtual ostream& print_options(ostream &o = cout) = 0;
	//virtual int get_option(istream &i) = 0;//gestiona la opcion elegida por el usuario
	//virtual bool check(int id) = 0;//comprueba la viabilidad de la accion
	virtual void draw()=0;//dibuja el menu/los menus
	//virtual void onMenu(int opcion) = 0;
};

class Accion :protected IAccion
{
public:
	Accion() { id = 0; submenu = 0; }
	//Accion(int id, int submenu) :IAccion(id, submenu){}
	ostream & print_options(ostream &o = cout);
	//int get_option(istream &i);
	//bool check(int id);
	void draw();
	int get_id() { return id; }
	friend void onMenu(int opcion);
	enum opc_menu { gest_tropas = 1, comercio = 2, diplomacia = 3, mejorar = 4 };
};



class Gestion_tropas :public Accion //relacion de herencia publica (es)
{
public:
	Gestion_tropas() { id = 0; submenu = 0; }
	//Gestion_tropas(int id, int submenu) :Accion(id, submenu) {}
	ostream & print_options(ostream &o = cout);
	//int get_option(istream &i);
	//bool check(int id);
	//void draw();
	//void onMenu(int opcion);
	enum opcion_gest {Atacar=5, Defender=6, Generar_tropas=7};
};

class Comercio :public Accion
{
public:
	Comercio() { id = 0; submenu = 0; }
	//Comercio(int id, int submenu) :Accion(id, submenu) {}
	ostream & print_options(ostream &o = cout);
	//int get_option(istream &i);
	//bool check(int id);
	//void draw();
};

class Diplomacia :public Accion
{
public:
	Diplomacia() { id = 0; submenu = 0; }
	//Diplomacia(int id, int submenu) :Accion(id, submenu) {}
	ostream & print_options(ostream &o = cout);
	//int get_option(istream &i);
	//bool check(int id);
	//void draw();
	//void onMenu(int opcion);
	enum opcion_dip{Alianza=8, Guerra=9};
};

class Mejorar :public Accion 
{
public:
	Mejorar() { id = 0; submenu = 0; }
	//Mejorar(int id, int submenu) :Accion(id, submenu) {}
	ostream & print_options(ostream &o = cout);
	//int get_option(istream &i);
	//bool check(int id);
	//void draw();
	//void onMenu(int opcion);
	enum opcion_mej {Ataque=10, Defensa=11, Agricultura=12};
};

class Accion_Engine
{
	IAccion *a;
public:
	Accion_Engine(IAccion *a) :a(a) {}
	ostream & print_options(ostream &o = cout);
	//int get_option(istream &i=cin);
	//bool check(int option);
	//void draw();
	//friend ostream& operator<<(ostream&, IAccion &);
};

/*ostream & operator<<(ostream &o, IAccion& b)//obligatorio sobrecargar << como funcion independiente
{
	b.print_options(o);
	return o;
}*/

