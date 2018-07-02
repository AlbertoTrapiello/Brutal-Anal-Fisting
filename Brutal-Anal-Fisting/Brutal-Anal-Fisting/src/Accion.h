#pragma once
#include <iostream>
#include <string>
#include "glut.h"
#include "ETSIDI.h"
#include "Jugadores.h"

using namespace std;
using ETSIDI::SpriteSequence;
using namespace ETSIDI;
static int idr;


class IAccion
{
public:
	int id;//id de la accion elegida
	bool right;//operacion realizada con exito
	bool fin;
	bool error_click = false;//HAZLO BIEN
public:
	IAccion();
	IAccion(int id, bool right) :id(id), right(right) {}
	virtual ostream& print_options(ostream &o = cout) = 0;//parte logica
	virtual int get_option(istream &i=cin) = 0;//gestiona la opcion elegida por el usuario, parte logica
	virtual bool check(int id) = 0;//comprueba la viabilidad de la accion, parte logica de momento
	virtual void draw( int )=0;//dibuja el menu/los menus, parte grafica
	virtual void update_id() = 0;
	virtual bool gestion_acc(Jugadores & j) = 0;//parte logica
	virtual void set_num(int num) = 0;
	virtual void set_opcion(int num) = 0;
	//virtual void gestion_acc( ) = 0;//parte grafica
};

class Accion :public IAccion
{
public:
	Accion() { id = 0; right = false; }
	Accion(int id, bool right) :IAccion(id, right){}
	ostream & print_options(ostream &o = cout);//parte logica
	int get_option(istream &i=cin);//parte logica
	bool check(int id);//parte logica de momento (deben ser ambas)
	//void gestion_acc( );//parte logica
	void draw( int id);//parte grafica
	friend void onMenu(int opcion);//parte grafica
	void update_id() { id = idr; }//Cuando estamos utilizando el menu gráfico y no la entrada por teclado necesitamos actualizar el valor de id a idr.
	bool gestion_acc(Jugadores & j);//parte logica
	void set_num(int num);
	void set_opcion(int num) {}
};



class Gestion_tropas :public Accion //relacion de herencia publica (es)
{
	int tropas;
	int opcion;
	SpriteSequence my_menu;
public:
	Gestion_tropas(): my_menu("images/Troops.png", 1) { id = 0; right = false; tropas = 0; opcion = 0; 	my_menu.setCenter(1, 0);	my_menu.setSize(7, 7);	}
	Gestion_tropas(int id, bool right, int tropas, int opcion) :Accion(id, right), tropas(tropas), opcion(opcion), my_menu("images/Troops.png", 1) { my_menu.setCenter(1, 0);	my_menu.setSize(7, 7); }
	ostream & print_options(ostream &o = cout);
	int get_option(istream &i=cin);
	bool check(int id);
	bool gestion_acc(Jugadores & j);//parte logica
	void draw( int id);
	void update_id() { id = idr; }//Cuando estamos utilizando el menu gráfico y no la entrada por teclado necesitamos actualizar el valor de id a idr.	
	void menu_hide();
	void menu_pop();
	void set_num(int num);
	void set_opcion(int num) { opcion = num; }
};

class Comercio :public Accion
{
	int opcion;
	int cantidad;
	SpriteSequence my_menu;
public:
	Comercio(): my_menu("images/Comercio.png", 1) { id = 0; right = false; opcion = 0; cantidad = 0; my_menu.setCenter(1, 0);	my_menu.setSize(7, 7);	}
	Comercio(int id, bool right, int opcion, int cantidad) :Accion(id, right),opcion(opcion), cantidad(cantidad), my_menu("images/Comercio.png", 1) { my_menu.setCenter(1, 0);	my_menu.setSize(7, 7); }
	ostream & print_options(ostream &o = cout);
	int get_option(istream &i=cin);
	bool check(int id);
	bool gestion_acc(Jugadores & j);//parte logica
	void update_id() { id = idr; }//Cuando estamos utilizando el menu gráfico y no la entrada por teclado necesitamos actualizar el valor de id a idr.
	void draw( int id);
	void menu_hide();
	void menu_pop();
	void set_num(int num);
	void set_opcion(int num) { opcion = num; }
};

class Diplomacia :public Accion
{
	int amistad;
	int opcion;
	SpriteSequence my_menu;
public:
	Diplomacia():my_menu("images/Diplomacia.png", 1) { id = 0; right = false; my_menu.setCenter(1, 0);	my_menu.setSize(7, 7);	}
	Diplomacia(int id, bool right, int amistad, int opcion) :Accion(id, right), amistad(amistad), opcion(opcion), my_menu("images/Diplomacia.png", 1) { my_menu.setCenter(1, 0);	my_menu.setSize(7, 7); }
	ostream & print_options(ostream &o = cout);
	int get_option(istream &i=cin);
	bool check(int id);
	bool gestion_acc(Jugadores & j);//parte logica
	void draw( int id);
	void update_id() { id = idr; }//Cuando estamos utilizando el menu gráfico y no la entrada por teclado necesitamos actualizar el valor de id a idr.
	void menu_hide();
	void menu_pop();
	void set_num(int num);
	void set_opcion(int num) { opcion = num; }
};

class Mejorar :public Accion 
{
	int opcion;
	int cantidad;
	SpriteSequence my_menu;
public:
	Mejorar():my_menu("images/Mejorar.png", 1) { id = 0; right = false; my_menu.setCenter(1, 0);	my_menu.setSize(7, 7);	}
	Mejorar(int id, bool right) :Accion(id, right), my_menu("images/Mejorar.png", 1) { my_menu.setCenter(1, 0);	my_menu.setSize(7, 7); }
	ostream & print_options(ostream &o = cout);
	int get_option(istream &i=cin);
	bool check(int id);
	bool gestion_acc(Jugadores & j);//parte logica
	void draw( int id);
	void update_id() { id = idr; }//Cuando estamos utilizando el menu gráfico y no la entrada por teclado necesitamos actualizar el valor de id a idr.
	void menu_hide();
	void menu_pop();
	void set_num(int num);
	void set_opcion(int num) { opcion = num; }
};

class Accion_Engine
{
	IAccion *a;
public:
	Accion_Engine() { a = NULL; }
	Accion_Engine(IAccion *a) :a(a) {}
	~Accion_Engine() { if (a != NULL)	delete a; }
	ostream & print_options(ostream &o = cout);
	int get_option(istream &i=cin);
	bool check(int option);
	void draw(int id);
	void update_id() { a->id = idr; }//Cuando estamos utilizando el menu gráfico y no la entrada por teclado necesitamos actualizar el valor de id a idr.
	//friend ostream& operator<<(ostream&, IAccion &);
	bool gestion_acc(Jugadores & j);//parte logica
	void delete_() { delete a; }
	void switch_puntero(IAccion *);
	void set_num(int num);
	void set_opcion(int num) { a->set_opcion(num); }
};

/*ostream & operator<<(ostream &o, IAccion& b)//obligatorio sobrecargar << como funcion independiente
{
	b.print_options(o);
	return o;
}*/

