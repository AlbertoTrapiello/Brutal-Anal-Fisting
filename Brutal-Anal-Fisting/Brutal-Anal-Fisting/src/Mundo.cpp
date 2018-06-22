

#include "ETSIDI.h"
#include "glut.h"
#include "Mundo.h"




void Mundo::dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
		0.0, y_ojo, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

							 //aqui es donde hay que poner el codigo de dibujo
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, getTexture("imagenes/fondo.png").id);
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

	setTextColor(0, 0, 0);
	setFont("fuentes/Game of Thrones.ttf", 16);
	printxy("GAME OF THRONES", -9.5, -9.5);

	setTextColor(0, 0, 0);
	setFont("fuentes/Game of Thrones.ttf", 8);
	printxy("Trapiello Y Perea Vanguelov", 1, -9.5);

}

void Mundo::mueve()
{

}

void Mundo::inicializa()
{
	x_ojo = 0;
	y_ojo = 0.1;
	z_ojo = 30;

}

void Mundo::tecla(unsigned char key)
{

}
void Mundo::teclaEspecial(unsigned char key)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		
		break;
	case GLUT_KEY_RIGHT:
		
		break;
	}
}