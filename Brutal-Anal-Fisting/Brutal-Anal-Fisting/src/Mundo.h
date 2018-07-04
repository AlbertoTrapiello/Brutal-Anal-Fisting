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
	int menu;
	int pos;
	Jugadores player[10];
	SpriteSequence sprite;
	bool check = true;//PONER EN CONDICIONES EN EL CONSTRUCTOR
	bool click = false;//PONER EN CONDICIONES EN EL CONSTRUCTOR
	bool error_region = false;
	int idr = 0;//PONER EN CONDICIONES EN EL CONSTRUCTOR
	bool ok = false;//PONER EN CONDICIONES EN EL CONSTRUCTOR
	char *numero = new char[5];
	const char *resultado = " ";
	int contador;
	int region = -1;
	int num;//guarda el varo introducido por teclado
	bool borrar = false;
	bool save;//1 si hay partida guardada, 0 si no la hay
	Accion_Engine action;

public:
	Mundo();
	void tecla(unsigned char key);
	void teclaEspecial(unsigned char key);
	void inicializa();
	void dibuja();
	void raton(int button, int x, int y);
	int check_click(float x, float y);
	void seleccion_personaje();
	void menu_sure();
	void menu_hide();
	int get_menu() { return menu; }
	void turn();
	bool check_action();
	bool draw_menus(const int & id);
	bool guardar_partida();//guarda la partida en un fichero de texto
	bool cargar_partida();//carga la partida guardada en caso de que haya
	void reiniciar_partida();//reinicia la partida
	bool fin_partida();//gestiona el final de partida

	friend class Turno;
	friend void onMenu(int opcion);
};