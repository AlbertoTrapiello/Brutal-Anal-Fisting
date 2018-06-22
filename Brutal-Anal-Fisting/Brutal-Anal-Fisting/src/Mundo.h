#pragma once


class Mundo
{
	float x_ojo;
	float y_ojo;
	float z_ojo;
public:
	void tecla(unsigned char key);
	void teclaEspecial(unsigned char key);
	void inicializa();
	void rotarOjo();
	void mueve();
	void dibuja();
};