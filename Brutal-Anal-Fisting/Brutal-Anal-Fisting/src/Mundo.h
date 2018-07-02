#pragma once
#include "Jugadores.h"
#include "Accion.h"

using namespace std;
using ETSIDI::SpriteSequence;
using namespace ETSIDI;

class Mundo
{

	float x_ojo;
	float y_ojo;
	float z_ojo;
	int turno;//lleva la cuenta del número de turnos que se llevan jugados
	int menu;//indica el menu en el que se encuentra (1,2,3)
	int pos;//gestiona el jugador del vector player que está jugando
	Jugadores player[10];
	SpriteSequence sprite;
	bool check = true;//PONER EN CONDICIONES EN EL CONSTRUCTOR 
	bool click = false;//PONER EN CONDICIONES EN EL CONSTRUCTOR 
	int idr = 0;//PONER EN CONDICIONES EN EL CONSTRUCTOR el indicador de los menús que se elige
	bool ok = false;//PONER EN CONDICIONES EN EL CONSTRUCTOR
	char *numero = new char[5];
	const char *resultado = " ";
	int contador;
	int region = -1;
	int num;//guarda el varo introducido por teclado
	Accion_Engine action;

public:
	Mundo();
	void tecla(unsigned char key);
	void teclaEspecial(unsigned char key);
	void inicializa();
	void dibuja();
	void raton(int button, int x, int y);
	int check_click(float x, float y);//te devuelve el número del player usado 
	void seleccion_personaje();//función que gestiona la selección del personaje 
	void menu_sure();//Saca el menu que comprueba que el juagdor quiere hacer la acción
	void menu_hide();//Esconde el menu que comprueba que el juagdor quiere hacer la acción
	int get_menu() { return menu; }//Devuelve el menú en el que te encuentras
	void turn();//gestiona los evento de cada turno 
	bool check_action();//Devuelve un bool que indica si la acción es válida o no
	bool draw_menus(const int & id);//Función que gestiona el dibujo del los menús

	friend class Turno;
	friend void onMenu(int opcion);
};