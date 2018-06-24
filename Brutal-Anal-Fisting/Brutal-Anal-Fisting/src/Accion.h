#pragma once
#include <iostream>
#include <string>
#include "glut.h"
#include "ETSIDI.h"
#include "Jugadores.h"

using namespace std;

static int idr;

class IAccion
{
public:
	int id;//id de la accion elegida
	bool right;//operacion realizada con exito
public:
	IAccion();
	IAccion(int id, bool right) :id(id), right(right) {}
	virtual ostream& print_options(ostream &o = cout) = 0;//parte logica
	virtual int get_option(istream &i=cin) = 0;//gestiona la opcion elegida por el usuario, parte logica
	virtual bool check(int id) = 0;//comprueba la viabilidad de la accion, parte logica de momento
	virtual void draw(Jugadores j)=0;//dibuja el menu/los menus, parte grafica
	virtual void update_id() = 0;
	//virtual void gestion_acc(Jugadores j) = 0;//parte grafica
};

class Accion :public IAccion
{
public:
	Accion() { id = 0; right = false; }
	Accion(int id, bool right) :IAccion(id, right){}
	ostream & print_options(ostream &o = cout);//parte logica
	int get_option(istream &i=cin);//parte logica
	bool check(int id);//parte logica de momento (deben ser ambas)
	//void gestion_acc(Jugadores j);//parte logica
	void draw(Jugadores j);//parte grafica
	friend void onMenu(int opcion);//parte grafica
	void update_id() { id = idr; }//Cuando estamos utilizando el menu gráfico y no la entrada por teclado necesitamos actualizar el valor de id a idr.
	enum opc_menu { gest_tropas = 1, comercio = 2, diplomacia = 3, mejorar = 4 };
};



class Gestion_tropas :public Accion //relacion de herencia publica (es)
{
	int tropas;
	int opcion;//numero de region
public:
	Gestion_tropas() { id = 0; right = false; tropas = 0; opcion = 0; }
	Gestion_tropas(int id, bool right, int tropas, int opcion) :Accion(id, right), tropas(tropas), opcion(opcion) {}
	ostream & print_options(ostream &o = cout);
	int get_option(istream &i=cin);
	bool check(int id);
	void gestion_acc(Jugadores j);//parte logica
	void draw(Jugadores j);
	void update_id() { id = idr; }//Cuando estamos utilizando el menu gráfico y no la entrada por teclado necesitamos actualizar el valor de id a idr.
	enum opcion_gest {Atacar=5, Defender=6, Generar_tropas=7};
};

class Comercio :public Accion
{
	int opcion;
	int cantidad;
public:
	Comercio() { id = 0; right = false; opcion = 0; cantidad = 0; }
	Comercio(int id, bool right, int opcion, int cantidad) :Accion(id, right),opcion(opcion), cantidad(cantidad) {}
	ostream & print_options(ostream &o = cout);
	int get_option(istream &i=cin);
	bool check(int id);
	void gestion_acc(Jugadores j);//parte logica
	void update_id() { id = idr; }//Cuando estamos utilizando el menu gráfico y no la entrada por teclado necesitamos actualizar el valor de id a idr.
	void draw(Jugadores j);
};

class Diplomacia :public Accion
{
	int amistad;
	int opcion;
public:
	Diplomacia() { id = 0; right = false; }
	Diplomacia(int id, bool right, int amistad, int opcion) :Accion(id, right), amistad(amistad), opcion(opcion) {}
	ostream & print_options(ostream &o = cout);
	int get_option(istream &i=cin);
	bool check(int id);
	void gestion_acc(Jugadores j);//parte logica
	void draw(Jugadores j);
	void update_id() { id = idr; }//Cuando estamos utilizando el menu gráfico y no la entrada por teclado necesitamos actualizar el valor de id a idr.
	enum opcion_dip{Alianza=8, Guerra=9};
};

class Mejorar :public Accion 
{
	int cantidad;
public:
	Mejorar() { id = 0; right = false; }
	Mejorar(int id, bool right) :Accion(id, right) {}
	ostream & print_options(ostream &o = cout);
	int get_option(istream &i=cin);
	bool check(int id);
	void gestion_acc(Jugadores j);//parte logica
	void draw(Jugadores j);
	void update_id() { id = idr; }//Cuando estamos utilizando el menu gráfico y no la entrada por teclado necesitamos actualizar el valor de id a idr.
	enum opcion_mej {Ataque=10, Defensa=11, Agricultura=12};
};

class Accion_Engine
{
	IAccion *a;
public:
	Accion_Engine() { a = NULL; }
	Accion_Engine(IAccion *a) :a(a) {}
	ostream & print_options(ostream &o = cout);
	int get_option(istream &i=cin);
	bool check(int option);
	void draw(Jugadores j);
	void update_id() { a->id = idr; }//Cuando estamos utilizando el menu gráfico y no la entrada por teclado necesitamos actualizar el valor de id a idr.
	//friend ostream& operator<<(ostream&, IAccion &);
};

/*ostream & operator<<(ostream &o, IAccion& b)//obligatorio sobrecargar << como funcion independiente
{
	b.print_options(o);
	return o;
}*/

