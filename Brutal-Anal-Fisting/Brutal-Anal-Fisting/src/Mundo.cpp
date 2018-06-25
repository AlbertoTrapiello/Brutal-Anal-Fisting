#include "ETSIDI.h"
#include "glut.h"
#include "Mundo.h"

#define START_X_MIN 151
#define START_X_MAX 311
#define START_Y_MIN 415
#define START_Y_MAX 438

using namespace ETSIDI;


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
		glBindTexture(GL_TEXTURE_2D, getTexture("imagenes/Pantalla inicial.png").id);
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
	/*case 2:
	{
		glBindTexture(GL_TEXTURE_2D, getTexture("imagenes/Personajes.png").id);
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
		printxy("Stark", -9.5, -5);

		setTextColor(1, 1, 1);
		setFont("fuentes/Game of Thrones.ttf", 8);
		printxy("By Trapiello Y Perea Vanguelov", 1, -9.5);

		break;
	}*/
	case 2:
	{
		glBindTexture(GL_TEXTURE_2D, getTexture("imagenes/Fondo definitivo.png").id);
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

		break;
	}

	}

}

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
		// identificación de las zonas, puede mostrar una serie de aspectos clave de la zona
		//salvo cuando es el turno del jugador que pasa a relizar la llamada a las acciones
		check_click(x, y);
	}
	}
}

void Mundo::Turno()//gestiona el turno así como los eventos dentro de cada turno->pasar de un jugador a otro
{
	for(int i=0;i < 10;i++)
		do
		{
			//eventos a evaluar durante el turno de cada jugador
			//gestion de las acciones

			//if(turno_terminado)
			//	{player[i+1].mi_turno=true; player[i].mi_turno=false;}
		} while (player[i].mi_turno());
	
}


void Mundo::inicializa()
{
	x_ojo = 0;
	y_ojo = 0.1;
	z_ojo = 30;
	menu = 1;
	turno = 0;
	
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

