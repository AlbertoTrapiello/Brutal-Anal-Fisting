#pragma once
#include "Jugadores.h"

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

public:
	Mundo();
	void tecla(unsigned char key);
	void teclaEspecial(unsigned char key);
	void inicializa();
	void dibuja();
	void raton(int button, int x, int y);
	void Turno();
	bool check_click(float x, float y);
	void seleccion_personaje();
	void menu_sure();
	void menu_hide();
};