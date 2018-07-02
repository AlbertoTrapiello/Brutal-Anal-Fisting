#include "ETSIDI.h"
#include "glut.h"
#include "Mundo.h"
#include "Turno.h"

#define START_X_MIN 151
#define START_X_MAX 311
#define START_Y_MIN 415
#define START_Y_MAX 438
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
#define MENU_CHECK_OK_Y_MIN 121
#define MENU_CHECK_OK_Y_MAX 137
#define MENU_CHECK_NO_X_MIN 550
#define MENU_CHECK_NO_X_MAX 619
#define MENU_CHECK_NO_Y_MIN 149
#define MENU_CHECK_NO_Y_MAX 167

using namespace ETSIDI;



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

void Mundo::turn()
{
	if (menu == 3)
	{
		Turno::acciones(this);
	}
}

bool Mundo::check_action()
{
	switch (idr)
	{
	case Atacar:
	{
		if (region == pos)
		{
			cout << "La region vale, Soy " << player[pos].getcasas() << "y has elgido " << player[region].getcasas() << endl;
			return false;
		}
		return true;
		break;
	}
	case Defender:
	{
		if (region == pos)
			return true;
		return false;
		break;
	}
	case Generar_tropas:
	{
		if ((num >= 0) && (num < 99999))
			return true;
		else
			return false;
			
		break;
	}
	case comercio:
	{
		if ((num >= 0) && (num < 99999))
			return true;
		else
			return false;
		break;
	}
	case Guerra:
	{
		if (region == pos)
			return false;
		return true;
		break;
	}
	case Alianza:
	{
		if (region == pos)
			return false;
		return true;

		break;
	}
	//case Ataque:
	//{

	//	break;
	//}
	//case Agricultura:
	//{

	//	break;
	//}
	//case Defensa:
	//{
	//	break;
	//}
	}
	return false;
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

int Mundo::check_click(float x, float y)
{
	for (int i = 0; i < 10; i++)
		if (player[i].check_region(x, y))
		{
			//cout << "Está en la región ";
			player[i].print();
			//cout << "soy la region nº: " << region << endl;
			return i;
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
		
		setTextColor(1, 1, 1);
		setFont("fuentes/Bitwise.ttf", 8);
		printxy(Turno::dibuja(this), 4.0, 5);


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
		//cout << "Soy IDR" << idr << endl;
		region=check_click(x,y);
		Turno::raton(this,x,y);
		//draw_text(x, y);
		break;
	}
	}
}




void Mundo::inicializa()
{
	x_ojo = 0;
	y_ojo = 0.1;
	z_ojo = 30;
	menu = 3;
	this->turno = 0;
	pos = 0;
	if (!player[0].read_file(player))
		cout << "ERROR" << endl;//gestionar el error si no se abre el fichero
	player[0].set_turno();
}

Mundo::Mundo():sprite("images/sprite_menu_sure.png",1)
{
	sprite.setCenter(1, 0);
	sprite.setSize(7, 7);
	for (int i = 0; i < 5; i++)
		numero[i] = ' ';
	numero[5] = '\0';
}

bool teclas = false;

void Mundo::tecla(unsigned char key)//CHEATS
{
	if(menu==3)
		if (idr == 7 || (idr < 13 && idr>9))
		{
			Turno::teclado(this, key);
		}
		
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


bool Mundo::draw_menus(const int & id)
{
	switch (id)
	{
	case gest_tropas:
	{

		break;
	}

	case comercio:
	{
		idr = 2;
		//pensar algo que haga que Accion Engine no apunte a una Accion si no que apunte a un Comercio

		action.switch_puntero(new Comercio);

		break;
	}
	case Diplom:
	{

		break;
	}
	case mejorar:
	{

		break;
	}
	case Atacar:
	{

		action.switch_puntero(new Gestion_tropas);
		break;
	}
	case Defender:
	{

		action.switch_puntero(new Gestion_tropas);
		break;
	}
	case Generar_tropas:
	{

		action.switch_puntero(new Gestion_tropas);
		break;
	}
	case Alianza:
	{

		action.switch_puntero(new Diplomacia);
		break;
	}
	case Guerra:
	{

		action.switch_puntero(new Diplomacia);
		break;
	}
	case Ataque:
	{

		action.switch_puntero(new Mejorar);
		break;
	}
	case Defensa:
	{

		action.switch_puntero(new Mejorar);
		break;
	}
	case Agricultura:
	{

		action.switch_puntero(new Mejorar);
		break;
	}
	default:
		idr = 0;
	}

	action.draw(id);

	return false;
}