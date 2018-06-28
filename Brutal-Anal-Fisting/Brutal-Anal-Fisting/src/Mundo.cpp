#include "ETSIDI.h"
#include "glut.h"
#include "Mundo.h"

#define START_X_MIN 151
#define START_X_MAX 311
#define START_Y_MIN 415
#define START_Y_MAX 438
/*#define CHARACTER_X_MIN 151
#define CHARACTER_X_MAX 311
#define CHARACTER_Y_MIN 415
#define CHARACTER_Y_MAX 438*/
#define ARROW_RIGHT_X_MIN 543
#define ARROW_RIGHT_X_MAX 594
#define ARROW_RIGHT_Y_MIN 412
#define ARROW_RIGHT_Y_MAX 449
#define ARROW_LEFT_X_MIN 212
#define ARROW_LEFT_X_MAX 257
#define ARROW_LEFT_Y_MIN 412
#define ARROW_LEFT_Y_MAX 449
#define CHARACTER_X_MIN 325
#define CHARACTER_X_MAX 500
#define CHARACTER_Y_MIN 111
#define CHARACTER_Y_MAX 339

using namespace ETSIDI;

bool check = true;

//float x_draw, y_draw;

void Mundo::seleccion_personaje()
{
	int prev = pos - 1, next = pos + 1;
	if (pos - 1 < 0)
		prev = 8;
	if (pos + 1 > 8)
		next = 0;
	player[pos].dibuja(player[prev].getindex(),player[next].getindex(), player[prev].getcasas(), player[next].getcasas());
	check = !check;
}

bool Mundo::check_click(float x, float y)
{
	for (int i = 0; i < 10; i++)
		if (player[i].check_region(x, y))
		{
			cout << "Está en la región ";
			player[i].print();
			return true;
		}

	return false;
}

void Mundo::dibuja()//TODOS LOS NÚMEROS QUE ESTÁN SUELTOS PODRÍAN ESTAR EN DEFINE'S	
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
		0.0, y_ojo, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

							 //aqui es donde hay que poner el codigo de dibujo
	glEnable(GL_TEXTURE_2D);
	switch (menu)
	{
	case 1:
	{
		glBindTexture(GL_TEXTURE_2D, getTexture("images/Pantalla inicial.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(1, 0); glVertex3f(10, 10, 0);
		glTexCoord2d(1, 1); glVertex3f(10, -10, 0);
		glTexCoord2d(0, 1); glVertex3f(-10, -10, 0);
		glTexCoord2d(0, 0); glVertex3f(-10, 10, 0);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

		setTextColor(1, 1, 1);
		setFont("fuentes/Game of Thrones.ttf", 16);
		printxy("NEW GAME", -9.5, -5);

		setTextColor(1, 1, 1);
		setFont("fuentes/Game of Thrones.ttf", 8);
		printxy("By Trapiello Y Perea Vanguelov", 1, -9.5);

		break;
	}
	case 2:
	{
		seleccion_personaje();
		break;
	}
	case 3:
	{
		glBindTexture(GL_TEXTURE_2D, getTexture("images/Fondo definitivo.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(1, 0); glVertex3f(10, 10, 0);
		glTexCoord2d(1, 1); glVertex3f(10, -10, 0);
		glTexCoord2d(0, 1); glVertex3f(-10, -10, 0);
		glTexCoord2d(0, 0); glVertex3f(-10, 10, 0);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

/*		setTextColor(1, 1, 1);
		setFont("fuentes/Game of Thrones.ttf", 16);
		printxy("Yep", x_draw, y_draw);*/

		break;
	}

	}

}

/*
void draw_text(int x, int y)
{
	x_draw = 10.0 - ((667 - x) / 539.0 * 20.0);
	y_draw = -10.0 + ((577 - y) / 550.0 * 20.0);
}*/

void Mundo::raton(int button, int x, int y)
{
	switch (menu)
	{
	case 1:
	{
		if(button== GLUT_LEFT_BUTTON)
			if ((x <= START_X_MAX && x >= START_X_MIN)&&(y <= START_Y_MAX && y >= START_Y_MIN))
				menu++;
		//resto de opciones a discutir
		break;
	}
	case 2:
	{
		if(check)
			if ((x <= ARROW_RIGHT_X_MAX && x >= ARROW_RIGHT_X_MIN) && (y <= ARROW_RIGHT_Y_MAX && y >= ARROW_RIGHT_Y_MIN))
			{
				pos++;
				if (pos > 8)
					pos = 0;
			}
		if (check)
			if ((x <= ARROW_LEFT_X_MAX && x >= ARROW_LEFT_X_MIN) && (y <= ARROW_LEFT_Y_MAX && y >= ARROW_LEFT_Y_MIN))
			{
				pos--;
				if (pos < 0)
					pos = 8;
			}
		if ((x <= CHARACTER_X_MAX && x >= CHARACTER_X_MIN) && (y <= CHARACTER_Y_MAX && y >= CHARACTER_Y_MIN))
		{
			menu++;
			pos = 0;
		}
		break;
	}
	case 3:
	{
		// identificación de las zonas, puede mostrar una serie de aspectos clave de la zona
		//salvo cuando es el turno del jugador que pasa a relizar la llamada a las acciones
		
		check_click(x, y);
		Turno();
		//draw_text(x, y);
		break;
	}
	}
}

void Mundo::Turno()//gestiona el turno así como los eventos dentro de cada turno->pasar de un jugador a otro
{
	player[pos].set_turno();
	if (player[pos].is_IA())
		//gestion de las decisiones que ha de tomar la IA
		player[pos].pseudo_IA();

	else
	{
		//gestion de las accciones a tomar po parte del jugador
		if (player[pos].mi_turno())
			if (player[pos].Turno())
				pos++;
	}
}


void Mundo::inicializa()
{
	x_ojo = 0;
	y_ojo = 0.1;
	z_ojo = 30;
	menu = 1;
	turno = 0;
	pos = 0;
	if (!player[0].read_file(player))
		cout << "ERROR" << endl;//gestionar el error si no se abre el fichero
	player[0].set_turno();
}

Mundo::Mundo()
{
}

void Mundo::tecla(unsigned char key)//CHEATS
{

}
void Mundo::teclaEspecial(unsigned char key)//CHEATS
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		
		break;
	case GLUT_KEY_RIGHT:
		
		break;
	}
}

