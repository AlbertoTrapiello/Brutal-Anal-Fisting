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
protected:
	int id;//id de la accion elegida
	bool right;//operacion realizada con exito
	bool fin;
	bool error_click = false;//HAZLO BIEN
	int opcion;//valor de la opción que se ha elegido
	int cantidad;//cantidad de cada recurso que requieren las acciones seleccionadas pro el jugador
public:
	IAccion();
	IAccion(int id, bool right, int opcion) :id(id), right(right), opcion(opcion) {}
	virtual ostream& print_options(ostream &o = cout) = 0;//parte logica
	virtual int get_option(istream &i=cin) = 0;//gestiona la opcion elegida por el usuario, parte logica
	virtual bool check(int id) = 0;//comprueba la viabilidad de la accion, parte logica de momento
	virtual void draw( int )=0;//dibuja el menu/los menus, parte grafica
	virtual void update_id() = 0;
	virtual bool gestion_acc(Jugadores & j1, Jugadores & j2) = 0;//parte logica
	virtual void set_cantidad(int num) = 0;
	virtual void set_opcion(int num) = 0;
	//virtual void gestion_acc( ) = 0;//parte grafica
};

class Gestion_tropas :public IAccion //relacion de herencia publica (es)
{
	SpriteSequence my_menu;
public:
	Gestion_tropas(): my_menu("images/Troops.png", 1) { id = 0; right = false; opcion = 0; 	my_menu.setCenter(1, 0);	my_menu.setSize(7, 7);	}
	Gestion_tropas(int id, bool right, int opcion) :IAccion(id, right,opcion), my_menu("images/Troops.png", 1) { my_menu.setCenter(1, 0);	my_menu.setSize(7, 7); }
	ostream & print_options(ostream &o = cout);
	int get_option(istream &i=cin);
	bool check(int id);
	bool gestion_acc(Jugadores & j1, Jugadores &j2);//parte logica
	void draw( int id);
	void update_id() { id = idr; }//Cuando estamos utilizando el menu gráfico y no la entrada por teclado necesitamos actualizar el valor de id a idr.	
	void menu_hide();
	void menu_pop();
	void set_cantidad(int num) { cantidad = num; }
	void set_opcion(int num) { opcion = num; }
};

class Comercio :public IAccion
{
	SpriteSequence my_menu;
public:
	Comercio(): my_menu("images/Comercio.png", 1) { id = 0; right = false; opcion = 0; cantidad = 0; my_menu.setCenter(1, 0);	my_menu.setSize(7, 7);	}
	Comercio(int id, bool right, int opcion) :IAccion(id, right,opcion), my_menu("images/Comercio.png", 1) { my_menu.setCenter(1, 0);	my_menu.setSize(7, 7); }
	ostream & print_options(ostream &o = cout);
	int get_option(istream &i=cin);
	bool check(int id);
	bool gestion_acc(Jugadores & j1, Jugadores &j2);//parte logica
	void update_id() { id = idr; }//Cuando estamos utilizando el menu gráfico y no la entrada por teclado necesitamos actualizar el valor de id a idr.
	void draw( int id);
	void menu_hide();
	void menu_pop();
	void set_cantidad(int num) { cantidad = num; }
	void set_opcion(int num) { opcion = num; }
};

class Diplomacia :public IAccion
{
	SpriteSequence my_menu;
public:
	Diplomacia():my_menu("images/Diplomacia.png", 1) { id = 0; right = false; my_menu.setCenter(1, 0);	my_menu.setSize(7, 7);	}
	Diplomacia(int id, bool right, int opcion) :IAccion(id, right,opcion), my_menu("images/Diplomacia.png", 1) { my_menu.setCenter(1, 0);	my_menu.setSize(7, 7); }
	ostream & print_options(ostream &o = cout);
	int get_option(istream &i=cin);
	bool check(int id);
	bool gestion_acc(Jugadores & j1, Jugadores &j2);//parte logica
	void draw( int id);
	void update_id() { id = idr; }//Cuando estamos utilizando el menu gráfico y no la entrada por teclado necesitamos actualizar el valor de id a idr.
	void menu_hide();
	void menu_pop();
	void set_cantidad(int num) { cantidad = num; }
	void set_opcion(int num) { opcion = num; }
};

class Mejorar :public IAccion 
{
	int cantidad;
	SpriteSequence my_menu;
public:
	Mejorar():my_menu("images/Mejorar.png", 1) { id = 0; right = false; my_menu.setCenter(1, 0);	my_menu.setSize(7, 7);	}
	Mejorar(int id, bool right, int opcion) :IAccion(id, right,opcion), my_menu("images/Mejorar.png", 1) { my_menu.setCenter(1, 0);	my_menu.setSize(7, 7); }
	ostream & print_options(ostream &o = cout);
	int get_option(istream &i=cin);
	bool check(int id);
	bool gestion_acc(Jugadores & j1, Jugadores &j2);//parte logica
	void draw( int id);
	void update_id() { id = idr; }//Cuando estamos utilizando el menu gráfico y no la entrada por teclado necesitamos actualizar el valor de id a idr.
	void menu_hide();
	void menu_pop();
	void set_cantidad(int num) { cantidad = num; }
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
	int get_option();
	void draw(int id);
	//friend ostream& operator<<(ostream&, IAccion &);
	bool gestion_acc(Jugadores & j1, Jugadores &j2);//parte logica
	void delete_() { delete a; }
	void switch_puntero(IAccion *);
	void set_cantidad(int num) { if(a!=NULL) a->set_cantidad(num); }
	void set_opcion(int num) { if(a!=NULL) a->set_opcion(num); }
};

/*ostream & operator<<(ostream &o, IAccion& b)//obligatorio sobrecargar << como funcion independiente
{
	b.print_options(o);
	return o;
}*/

