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
#define MENU_CHECK_OK_X_MIN 550
#define MENU_CHECK_OK_X_MAX 619
#define MENU_CHECK_OK_Y_MIN 131
#define MENU_CHECK_OK_Y_MAX 161
#define MENU_CHECK_NO_X_MIN 550
#define MENU_CHECK_NO_X_MAX 619
#define MENU_CHECK_NO_Y_MIN 167
#define MENU_CHECK_NO_Y_MAX 199

using namespace ETSIDI;

bool check = true;
bool click;
int idr=0;
bool ok;
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

void Mundo::menu_hide()
{
	glPushMatrix();
	glTranslatef(20.0, 20.0, 0.5);
	glColor3f(1.0f, 1.0f, 1.0f);
	sprite.setState(1);
	sprite.draw();
	glPopMatrix();
}

void Mundo::menu_sure()
{
	glPushMatrix();
	glTranslatef(4.0, 3.0, 0.5);
	glColor3f(1.0f, 1.0f, 1.0f);
	sprite.setState(1);
	sprite.draw();
	glPopMatrix();
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
		if (click)
		{
			//Sacar
			menu_sure();
		}
		if (ok)
		{
			menu_hide();
			Turno();//no estoy seguro de esto pero no cuadra en ningún otro sitio
		}
		else
			menu_hide();
		
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



void onMenu(int opcion) {
	switch (opcion) {
	case gest_tropas:
	{
		idr = 1;
		break;
	}

	case comercio:
	{
		idr = 2;
		//pensar algo que haga que Accion Engine no apunte a una Accion si no que apunte a un Comercio
		break;
	}
	case Diplom:
	{
		idr = 3;
		break;
	}
	case mejorar:
	{
		idr = 4;
		break;
	}
	case Atacar:
	{
		idr = 5;
		break;
	}
	case Defender:
	{
		idr = 6;
		break;
	}
	case Generar_tropas:
	{
		idr = 7;
		break;
	}
	case Alianza:
	{
		idr = 8;
		break;
	}
	case Guerra:
	{
		idr = 9;
		break;
	}
	case Ataque:
	{
		idr = 10;
		break;
	}
	case Defensa:
	{
		idr = 11;
		break;
	}
	case Agricultura:
	{
		idr = 12;
		break;
	}
	}
	glutPostRedisplay();
	click = true;
}



void creacionMenu(void) 
{
	int menuPrincipal, menutropas, menudiplomacia, menumejoras;

	menutropas = glutCreateMenu(onMenu);
	glutAddMenuEntry("Atacar", Atacar);//si se pulsa Atacar, idr será igual a 5, conociendo esta informacion, podemos gestionar las distintas acciones
	glutAddMenuEntry("Defender",Defender);
	glutAddMenuEntry("Generar", Generar_tropas);
	menudiplomacia = glutCreateMenu(onMenu);
	glutAddMenuEntry("Alianza",Alianza);
	glutAddMenuEntry("Guerra",Guerra);
	menumejoras = glutCreateMenu(onMenu);
	glutAddMenuEntry("Ataque",Ataque);
	glutAddMenuEntry("Defensa",Defensa);
	glutAddMenuEntry("Agricultura",Agricultura);
	menuPrincipal = glutCreateMenu(onMenu);
	glutAddSubMenu("Gestion de Tropas", menutropas);
	glutAddMenuEntry("Comercio", comercio);
	glutAddSubMenu("Diplomacia", menudiplomacia);
	glutAddSubMenu("Mejoras", menumejoras);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
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
		creacionMenu();
		if (click)
		{
			if ((x <= MENU_CHECK_OK_X_MAX && x >= MENU_CHECK_OK_X_MIN) && (y <= MENU_CHECK_OK_Y_MAX && y >= MENU_CHECK_OK_Y_MIN))
			{
				click = false;
				ok = true;
				cout << "Vale JAJAJA" << endl;
			}
			if ((x <= MENU_CHECK_NO_X_MAX && x >= MENU_CHECK_NO_X_MIN) && (y <= MENU_CHECK_NO_Y_MAX && y >= MENU_CHECK_NO_Y_MIN))
			{
				click = false;
				cout << "No vale JAJAJA" << endl;
				ok = false;
			}
		}
		cout << "Soy IDR" << idr << endl;
		//draw_text(x, y);
		break;
	}
	}
}

void Mundo::Turno()//gestiona el turno así como los eventos dentro de cada turno->pasar de un jugador a otro
{
	player[pos].set_turno();
	if (player[pos].is_IA())
	{
		if (player[pos].pseudo_IA())
			pos++;
	}
	else
	{
		//gestion de las accciones a tomar po parte del jugador
		if (player[pos].mi_turno())
			if (player[pos].Turno(idr))
				pos++;
	}
}


void Mundo::inicializa()
{
	x_ojo = 0;
	y_ojo = 0.1;
	z_ojo = 30;
	menu = 3;
	turno = 0;
	pos = 0;
	if (!player[0].read_file(player))
		cout << "ERROR" << endl;//gestionar el error si no se abre el fichero
	player[0].set_turno();
}

Mundo::Mundo():sprite("images/sprite_menu_sure.png",1)
{
	sprite.setCenter(1, 0);
	sprite.setSize(7, 7);
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

