#include "Regiones.h"
#include "glut.h"
#include "ETSIDI.h"

using namespace ETSIDI;
using ETSIDI::getTexture;

Regiones::Regiones()
{
	reg = Zonas::North;
}

Zonas Regiones::stringtoRegion(string aux)
{
	stringstream sstr;
	int r;
	sstr << aux << endl;
	sstr >> r;
	Zonas res = static_cast<Zonas>(r);
	return res;
}

void Regiones::draw()
{
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("images/fondo.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);

	glTexCoord2d(0, 1);		glVertex3f(-10, 0, -0.1);
	glTexCoord2d(1, 1);		glVertex3f(10, 0, -0.1);
	glTexCoord2d(1, 0);		glVertex3f(10, 15, -0.1);
	glTexCoord2d(0, 0);		glVertex3f(-10, 15, -0.1);
	glEnd();

	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}