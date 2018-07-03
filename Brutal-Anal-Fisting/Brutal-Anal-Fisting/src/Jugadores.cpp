#include "Jugadores.h"
#include "Accion.h"
#define N_jug 10


const char * Get_tit(int casa)
{
	switch (casa)
	{
	case Stark:
	{
		return "images/Iconos/Icono Stark.png";
		break;
	}
	case Tully:
	{
		return "images/Iconos/Icono Tully.png";
		break;
	}
	case Arryn:
	{
		return "images/Iconos/Icono Arryn.png";
		break;
	}
	case Targaryen:
	{
		return "images/Iconos/Icono Targaryen.png";
		break;
	}
	case Greyjoy:
	{
		return "images/Iconos/Icono Greyjoy.png";
		break;
	}
	case Lannister:
	{
		return "images/Iconos/Icono Lannister.png";
		break;
	}
	case Tyrrel:
	{
		return "images/Iconos/Icono Tyrell.png";
		break;
	}
	case Baratheon:
	{
		return "images/Iconos/Icono Baratheon.png";
		break;
	}
	case Martell:
	{
		return "images/Iconos/Icono Martell.png";
		break;
	}
	}
	return NULL;
}

void Jugadores::Icon_hide()
{
	glPushMatrix();
	glTranslatef(20.0, 20.0, 0.5);
	glColor3f(1.0f, 1.0f, 1.0f);
	icono.setState(1);
	icono.draw();
	glPopMatrix();
}
void Jugadores::Icon()
{
	glPushMatrix();
	glTranslatef(4.0, 3.0, 0.5);
	glColor3f(1.0f, 1.0f, 1.0f);
	icono.setState(1);
	icono.draw();
	glPopMatrix();

	stringstream sstr;
	char aux[5]="    ";
	const char *attack;
	sstr << ataque;
	sstr >> aux;
	attack = aux;
	setTextColor(1, 1, 1);
	setFont("fuentes/Bitwise.ttf", 8);
	printxy(attack, 4.0, 5);
	sstr.clear();
	const char *food;
	sstr << comida;
	sstr >> aux;
	food = aux;
	printxy(food, 4.0, 4);
	sstr.clear();
	const char *gold;
	sstr << oro;
	sstr >> aux;
	gold = aux;
	printxy(gold, 6, 5);
	sstr.clear();
	const char *diplomacy;
	sstr << diplomacia;
	sstr >> aux;
	diplomacy = aux;
	printxy(diplomacy, 6.0, 4);
	sstr.clear();
	const char *defense;
	sstr << defensa;
	sstr >> aux;
	defense = aux;
	printxy(defense, 8.0, 5);

}

Jugadores::Jugadores():casa(Casas::Stark), sprite("images/sprite_GoT_recortado.png", 5, 7), sprite_izq("images/sprite_GoT_recortado.png", 5, 7), sprite_dcha("images/sprite_GoT_recortado.png", 5, 7), arrow("images/arrow.png", 1), arrow1("images/arrow_.png", 1), icono(Get_tit(casa), 1)
{
	nombre="Robb";
	titulo="King in the North";
	sprite.setCenter(1, 0);
	sprite.setSize(7, 7);
	sprite_izq.setCenter(1, 0);
	sprite_izq.setSize(5, 5);
	sprite_dcha.setCenter(1, 0);
	sprite_dcha.setSize(5, 5);
	arrow.setCenter(1, 0);
	arrow.setSize(2, 2);
	arrow1.setCenter(1, 0);
	arrow1.setSize(2, 2);
	icono.setCenter(1, 0);
	icono.setSize(7, 7);
	for (int i = 0; i < 25; i++)
		aux[i] = ' ';
	index = 0;
}

Jugadores::Jugadores (const Jugadores &j):casa(j.casa), sprite("images/sprite_GoT_recortado.png", 5, 7), sprite_izq("images/sprite_GoT_recortado.png", 5, 7), sprite_dcha("images/sprite_GoT_recortado.png", 5, 7), arrow("images/arrow.png", 1), arrow1("images/arrow_.png", 1), icono(Get_tit(casa), 1)
{
	turno = false;
	ataque=j.ataque;
	comida=j.comida;
	oro=j.oro;
	diplomacia=j.diplomacia;
	defensa = j.defensa;
	nombre=j.nombre;
	titulo=j.titulo;
	sprite.setCenter(1, 0);
	sprite.setSize(7, 7);
	sprite_izq.setCenter(1, 0);
	sprite_izq.setSize(5, 5);
	sprite_dcha.setCenter(1, 0);
	sprite_dcha.setSize(5, 5);
	arrow.setCenter(1, 0);
	arrow.setSize(2, 2);
	arrow1.setCenter(1, 0);
	arrow1.setSize(2, 2);
	index = 0;
}


Casas Jugadores::stringtoCasas(string e)
{
	stringstream sstr;
	int r;
	sstr<<e<<endl;
	sstr>>r;
	Casas res=static_cast<Casas>(r);
	return res;
}

char * Jugadores::get_nombre()
{
	stringstream sstr;
	sstr << nombre ;
	sstr >> aux;
	return aux;
}

bool Jugadores::check_region(float x, float y)
{
	return region.is_in(x, y);
}

void Jugadores::dibuja(int dcha, int izq, Casas casa_izq, Casas casa_dcha)
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(S).id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);

	glTexCoord2d(0, 1);		glVertex3f(-10.0, -10.0, -0.1);
	glTexCoord2d(1, 1);		glVertex3f(10.0, -10.0, -0.1);
	glTexCoord2d(1, 0);		glVertex3f(10.0, 10.0, -0.1);
	glTexCoord2d(0, 0);		glVertex3f(-10.0, 10.0, -0.1);
	glEnd();

	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	glPushMatrix();
	glTranslatef(-2.0, -0.5, 0.5);
	glColor3f(1.0f, 1.0f, 1.0f);
	sprite.setState(index);
	sprite.draw();
	glPopMatrix();

	setTextColor(1, 1, 0);
	setFont("fuentes/Game of Thrones.ttf", 16);
	switch (casa)
	{
	case Stark:
	{
		printxy("Stark", -2.0, -1.5);
		break;
	}
	case Tully:
	{
		printxy("Tully", -2.0, -1.5);
		break;
	}
	case Arryn:
	{
		printxy("Arryn", -2.0, -1.5);
		break;
	}
	case Targaryen:
	{
		printxy("Targaryen", -2.0, -1.5);
		break;
	}
	case Greyjoy:
	{
		printxy("Greyjoy", -2.0, -1.5);
		break;
	}
	case Lannister:
	{
		printxy("Lannister", -2.0, -1.5);
		break;
	}
	case Tyrrel:
	{
		printxy("Tyrrel", -2.0, -1.5);
		break;
	}
	case Baratheon:
	{
		printxy("Baratheon", -2.0, -1.5);
		break;
	}
	case Martell:
	{
		printxy("Martell", -2.0, -1.5);
		break;
	}
	}

	glPushMatrix();
	glTranslatef(-7.0, -1.5, 0.5);
	glColor3f(1.0f, 1.0f, 1.0f);
	sprite_izq.setState(dcha);
	sprite_izq.draw();
	glPopMatrix();

	setTextColor(1, 1, 0);
	setFont("fuentes/Game of Thrones.ttf", 12);
	switch (casa_dcha)
	{
	case Stark:
	{
		printxy("Stark", 6.0, -2.5);
		break;
	}
	case Tully:
	{
		printxy("Tully", 6.0, -2.5);
		break;
	}
	case Arryn:
	{
		printxy("Arryn", 6.0, -2.5);
		break;
	}
	case Targaryen:
	{
		printxy("Targaryen", 6.0, -2.5);
		break;
	}
	case Greyjoy:
	{
		printxy("Greyjoy", 6.0, -2.5);
		break;
	}
	case Lannister:
	{
		printxy("Lannister", 6.0, -2.5);
		break;
	}
	case Tyrrel:
	{
		printxy("Tyrrel", 6.0, -2.5);
		break;
	}
	case Baratheon:
	{
		printxy("Baratheon", 6.0, -2.5);
		break;
	}
	case Martell:
	{
		printxy("Martell", 6.0, -2.5);
		break;
	}
	}

	glPushMatrix();
	glTranslatef(5.0, -1.5, 0.5);
	glColor3f(1.0f, 1.0f, 1.0f);
	sprite_dcha.setState(izq);
	sprite_dcha.draw();
	glPopMatrix();

	setTextColor(1, 1, 0);
	setFont("fuentes/Game of Thrones.ttf", 12);
	switch (casa_izq)
	{
	case Stark:
	{
		printxy("Stark", -8.0, -2.5);
		break;
	}
	case Tully:
	{
		printxy("Tully", -8.0, -2.5);
		break;
	}
	case Arryn:
	{
		printxy("Arryn", -8.0, -2.5);
		break;
	}
	case Targaryen:
	{
		printxy("Targaryen", -8.0, -2.5);
		break;
	}
	case Greyjoy:
	{
		printxy("Greyjoy", -8.0, -2.5);
		break;
	}
	case Lannister:
	{
		printxy("Lannister", -8.0, -2.5);
		break;
	}
	case Tyrrel:
	{
		printxy("Tyrrel", -8.0, -2.5);
		break;
	}
	case Baratheon:
	{
		printxy("Baratheon", -8.0, -2.5);
		break;
	}
	case Martell:
	{
		printxy("Martell", -8.0, -2.5);
		break;
	}
	}
	
	glPushMatrix();
	glTranslatef(6.0, -5.5, 0.5);
	glColor3f(1.0f, 1.0f, 1.0f);
	arrow.setState(0);
	arrow.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-6.0, -5.5, 0.5);
	glColor3f(1.0f, 1.0f, 1.0f);
	arrow1.setState(0);
	arrow1.draw();
	glPopMatrix();

}



bool Jugadores::pseudo_IA()
{
	

	return false;
}

ostream& Jugadores::print(ostream& o )
{
	o<<"Casa:"<<casa<<endl;
	o<<"Nombre:"<<nombre<<endl;
	o<<"Titulo:"<<titulo<<endl;
	return o;
}

bool Jugadores::read_file(Jugadores *p)
{
	ifstream f("Jugadores.txt", istream::in);
	if(!f)
	{
		cout<<"el fichero no se ha abierto correctamente"<<endl;
		return false;
	}
	for(int i=0;i<10;i++)
	{
		string aux;
		ostream &o=cout;
		getline(f,aux,'\n');
		p[i].casa = stringtoCasas(aux);
		getline(f,p[i].nombre,'\n');//getline(f,nombre);
		getline(f,p[i].titulo,'\n');
		p[i].print(o);
		p[i].Recursos::read_file();
		p[i].region.read_file(p[i].nombre);

		switch (p[i].casa)
		{
		case Stark:
		{
			p[i].S = "images/Stark.png";
			p[i].index = 1;
			break;
		}
		case Tully:
		{
			p[i].S = "images/Tully.png";
			p[i].index = 7;
			break;
		}
		case Arryn:
		{
			p[i].S = "images/Arryn.png";
			p[i].index = 10;
			break;
		}
		case Targaryen:
		{
			p[i].S = "images/Targaryen.png";
			p[i].index = 19;
			break;
		}
		case Greyjoy:
		{
			p[i].S = "images/Greyjoy.png";
			p[i].index = 23;
			break;
		}
		case Lannister:
		{
			p[i].S = "images/Lannister.png";
			p[i].index = 29;
			break;
		}
		case Tyrrel:
		{
			p[i].S = "images/Tyrrel.png";
			p[i].index = 17;
			break;
		}
		case Baratheon:
		{
			p[i].S = "images/Baratheon.png";
			p[i].index = 16;
			break;
		}
		case Martell:
		{
			p[i].S = "images/Martell.png";
			p[i].index = 21;
			break;
		}
		}
		p[i].sprite.setCenter(1, 0);
		p[i].sprite.setSize(7, 7);
		p[i].sprite_izq.setCenter(1, 0);
		p[i].sprite_izq.setSize(5, 5);
		p[i].sprite_dcha.setCenter(1, 0);
		p[i].sprite_dcha.setSize(5, 5);
		p[i].arrow.setCenter(1, 0);
		p[i].arrow.setSize(2, 2);
		p[i].arrow1.setCenter(1, 0);
		p[i].arrow1.setSize(2, 2);
	}
	f.close();
	return true;
}

//tengo problemas con el destructor si lo defino yo.
/*Jugadores::~Jugadores()
{
	delete[]p;
}
*/