#pragma once
#include "Jugadores.h"

class Mundo
{
	float x_ojo;
	float y_ojo;
	float z_ojo;
	int turno;//lleva la cuenta del número de turnos que se llevan jugados
	int menu;
	int pos;
	Jugadores player[10];

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
};