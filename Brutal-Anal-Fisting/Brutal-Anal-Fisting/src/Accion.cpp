#include "Accion.h"
Jugadores j;

IAccion::IAccion()
{
	id = 0;
	right = false;
}

ostream & Accion::print_options(ostream &o)//modo por teclado
{
	o << "Gestionar Tropas" << endl;
	o << "Comercio" << endl;
	o << "Diplomacia" << endl;
	o << "Mejorar" << endl;
	return o;
}

ostream & Gestion_tropas::print_options(ostream &o)
{
	o << "Atacar" << endl;
	o << "Defender" << endl;
	o << "Crear tropas" << endl;
	return o;
}

ostream & Comercio::print_options(ostream &o)
{
	o << "Comerciar" << endl;
	return o;
}

ostream & Diplomacia::print_options(ostream &o) 
{
	o << "Alianza" << endl;
	o << "Guerra" << endl;
	return o;
}

ostream & Mejorar::print_options(ostream &o)
{
	o << "Mejorar ataque" << endl;
	o << "Mejorar defensa" << endl;
	o << "Mejora agricultura" << endl;
	return o;
}

int Accion::get_option(istream&i)//modo por teclado
{
	string name;
	getline(i, name);
	if (name == "Generar_tropas")
	{
		idr = 1;
	}
	if (name == "Diplomacia")
	{
		idr = 3;
	}
	if (name == "Comercio")
	{
		idr = 2;
	}
	if (name == "Mejorar")
	{
		idr = 4;
	}
	id = idr;
	return id;
}

int Gestion_tropas::get_option(istream &i)
{
	idr = Accion::get_option(i);
	if (idr == 1)
	{
		string name;
		getline(i, name);
		if (name == "Atacar")
		{
			idr = 5;
		}
		if (name == "Defender")
		{
			idr = 6;
		}
		if (name == "Generar")
		{
			idr = 7;
		}
	}
	id = idr;
	return id;
}

int Comercio::get_option(istream &i)
{
	idr = Accion::get_option(i);
	id = idr;
	return id;
}

int Diplomacia::get_option(istream &i)
{
	idr = Accion::get_option(i);
	if (idr == 3)
	{
		string name;
		getline(i, name);
		if (name=="Alianza")
		{
			idr = 8;
		}
		if (name=="Guerra")
		{
			idr = 9;
		}
	}
	id = idr;
	return id;
}

int Mejorar::get_option(istream &i)
{
	idr = Accion::get_option(i);
	if (idr == 3)
	{
		string name;
		getline(i, name);
		if (name=="Ataque")
		{
			idr = 10;
		}
		if (name=="Defensa")
		{
			idr = 11;
		}
		if (name=="Agricultura")
		{
			idr = 12;
		}
	}
	id = idr;
	return id;
}

bool Accion::check(int id)
{
	id = Accion::get_option(cin);
	if (id = 0)
		right = false;
	else
		right = true;
	return right;
}

bool Gestion_tropas::check(int id)//falta añadir que si se selecciona la propia region en acciones determinadas no funciona
{
	id = Gestion_tropas::get_option(cin);
	if (id = 0)
		right=false;
	else
		right=true;
	return right;
}

bool Comercio::check(int id)
{
	id = Comercio::get_option(cin);
	if (id = 0)
		right = false;
	else
		right = true;
	return right;
}

bool Diplomacia::check(int id)
{
	id = Diplomacia::get_option(cin);
	if (id = 0)
		right = false;
	else
		right = true;
	return right;
}


bool Mejorar::check(int id)
{
	id = Mejorar::get_option(cin);
	if (id = 0)
		right = false;
	else
		right = true;
	return right;
}


ostream & Accion_Engine::print_options(ostream &o)
{
	a->print_options(o);
	return o;
}

int Accion_Engine::get_option(istream &i)
{
	int id;
	a->get_option(i);
	id = a->id;
	return id;
}

bool Accion_Engine::check(int option)
{
	bool right;
	a->check(option);
	right = a->right;
	return right;
}

/*void Accion_Engine::draw()
{
	a->draw();
}*/

void onMenu(int opcion) {
	switch (opcion) {
	case Accion::opc_menu::gest_tropas:
		idr = 1;
		break;
	case Accion::opc_menu::comercio:
		idr=2;
		break;
	case Accion::opc_menu::diplomacia:
		idr=3;
		break;
	case Accion::opc_menu::mejorar:
		idr=4;
		break;
	case Gestion_tropas::opcion_gest::Atacar:
		idr = 5;
		break;
	case Gestion_tropas::opcion_gest::Defender:
		idr = 6;
		break;
	case Gestion_tropas::opcion_gest::Generar_tropas:
		idr = 7;
		break;
	case Diplomacia::opcion_dip::Alianza:
		idr = 8;
		break;
	case Diplomacia::opcion_dip::Guerra:
		idr = 9;
		break;
	case Mejorar::opcion_mej::Ataque:
		idr = 10;
		break;
	case Mejorar::opcion_mej::Defensa:
		idr = 11;
		break;
	case Mejorar::opcion_mej::Agricultura:
		idr = 12;
		break;
	default:
		idr = 0;
	}
	glutPostRedisplay();
}

void Accion::draw(void) {
	int menuPrincipal, menutropas, menudiplomacia, menumejoras;

	menutropas = glutCreateMenu(onMenu);
	glutAddMenuEntry("Atacar", Gestion_tropas::opcion_gest::Atacar);//si se pulsa Atacar, idr será igual a 5, conociendo esta informacion, podemos gestionar las distintas acciones
	glutAddMenuEntry("Defender", Gestion_tropas::opcion_gest::Defender);
	glutAddMenuEntry("Generar", Gestion_tropas::opcion_gest::Generar_tropas);
	menudiplomacia = glutCreateMenu(onMenu);
	glutAddMenuEntry("Alianza", Diplomacia::opcion_dip::Alianza);
	glutAddMenuEntry("Guerra", Diplomacia::opcion_dip::Guerra);
	menumejoras = glutCreateMenu(onMenu);
	glutAddMenuEntry("Ataque", Mejorar::opcion_mej::Ataque);
	glutAddMenuEntry("Defensa", Mejorar::opcion_mej::Defensa);
	glutAddMenuEntry("Agricultura", Mejorar::opcion_mej::Agricultura);
	menuPrincipal = glutCreateMenu(onMenu);
	glutAddSubMenu("Gestion de Tropas", menutropas);
	glutAddMenuEntry("Comercio", opc_menu::comercio);
	glutAddSubMenu("Diplomacia", menudiplomacia);
	glutAddSubMenu("Mejoras", menumejoras);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

}

void Gestion_tropas::draw()
{
	if (idr == 5)//Atacar
	{
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("Seleccione la region que desea atacar", -4.5, 4.5);
		//aqui guardar la region que se desea atacar en un atributo de las clase y llamar a check_option para determinar si es válida la elección.
		while (right == false)
		{
			ETSIDI::setTextColor(1, 1, 0);
			ETSIDI::setFont("fuentes/Bitwise.ttf", 16);//poner fuente de GOT
			ETSIDI::printxy("Opcion no válida", -4.5, 4.5);
			ETSIDI::printxy("Seleccione la region que desea atacar", -4.5, 3.5);
		}
		if (right == true)
		{
			glDisable(GL_LIGHTING);
			glBegin(GL_POLYGON);
			glVertex3f(-5.0f, 0, -5.0f);
			glVertex3f(-5.0f, 0, 5.0f);
			glVertex3f(5.0f, 0, 5.0f);
			glVertex3f(5.0f, 0, -5.0f);
			glEnd();
			glEnable(GL_LIGHTING);
			ETSIDI::printxy("Introduzca por teclado el numero de tropas", -4.5, 3.5);//posteriormente lo cambiaremos con las coord correctas del raton
			cin >> tropas;
			if (tropas < j.ataque)
			{
				ETSIDI::printxy("No hay tropas suficientes", -4.5, 2.5);
			}
			else
			{
				//mandar tropas al ataque
				ETSIDI::printxy("Operacion realizada con exito", -4.5, 2.5);
				//que las tropas lleguen a la region en x turnos y calcular el numero de tropas necesarias para conquistar
				//eliminar poligono--> como?
			}
		}
		
	}

	if (idr == 6)//Defender
	{
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glVertex3f(-5.0f, 0, -5.0f);
		glVertex3f(-5.0f, 0, 5.0f);
		glVertex3f(5.0f, 0, 5.0f);
		glVertex3f(5.0f, 0, -5.0f);
		glEnd();
		glEnable(GL_LIGHTING);
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("Seleccione el numero de tropas con las que defender su region", -4.5, 4.5);
		cin >> tropas;
		if (tropas < j.ataque)
		{
			ETSIDI::printxy("No hay tropas suficientes", -4.5, 2.5);
		}
		else
		{
			//mandar tropas a la defensa
			ETSIDI::printxy("Operacion realizada con exito", -4.5, 2.5);
			//las tropas seleccionadas defienden
			//eliminar poligono--> como?
		}
	}

	if (idr == 7)//Generar
	{
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glVertex3f(-5.0f, 0, -5.0f);
		glVertex3f(-5.0f, 0, 5.0f);
		glVertex3f(5.0f, 0, 5.0f);
		glVertex3f(5.0f, 0, -5.0f);
		glEnd();
		glEnable(GL_LIGHTING);
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("Seleccione el numero de tropas a generarar", -4.5, 4.5);
		ETSIDI::printxy("Generar 10 cuesta 10 de oro", -4.5, 4.5);
		cin >> tropas;
		if (tropas < j.oro)
		{
			ETSIDI::printxy("No hay oro suficiente", -4.5, 2.5);
		}
		else
		{
			j.oro -= tropas;//se gasta x oro
			j.ataque += tropas;//el jugador tiene x tropas mas
			ETSIDI::printxy("Operacion realizada con exito", -4.5, 2.5);
			//eliminar poligono--> como?
		}
	}
}

void Comercio::draw()
{
	if (idr == 2)
	{
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glVertex3f(-5.0f, 0, -5.0f);
		glVertex3f(-5.0f, 0, 5.0f);
		glVertex3f(5.0f, 0, 5.0f);
		glVertex3f(5.0f, 0, -5.0f);
		glEnd();
		glEnable(GL_LIGHTING);
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("Seleccione la opcion", -4.5, 4.5);
		cin >> opcion;
		switch (opcion)
		{
		case 1:
			ETSIDI::printxy("2 de agricultura por cada moneda de oro", -4.5, 4.5);
			cin >> cantidad;
			if (j.oro < 0.5*cantidad)
			{
				ETSIDI::printxy("No hay oro suficiente", -4.5, 2.5);
			}
			else
			{
				j.comida += cantidad;
				j.oro -= 0.5*cantidad;
				ETSIDI::printxy("Operacion realizada con exito", -4.5, 2.5);
				//eliminar poligono--> como?
			}
			break;
		case 2:
			ETSIDI::printxy("2 de agricultura por cada moneda de oro", -4.5, 4.5);
			cin >> cantidad;
			if (j.comida < 2 * cantidad)
			{
				ETSIDI::printxy("No hay comida suficiente", -4.5, 2.5);
			}
			else
			{
				j.oro += cantidad;
				j.comida -= 2*cantidad;
				ETSIDI::printxy("Operacion realizada con exito", -4.5, 2.5);
				//eliminar poligono--> como?
			}
			break;
		case 3:
			ETSIDI::printxy("1 de diplomacia por cada moneda de oro", -4.5, 4.5);
			cin >> cantidad;
			if (j.oro < cantidad)
			{
				ETSIDI::printxy("No hay oro suficiente", -4.5, 2.5);
			}
			else
			{
				j.oro -= cantidad;
				j.diplomacia += cantidad;
				ETSIDI::printxy("Operacion realizada con exito", -4.5, 2.5);
				//eliminar poligono--> como?
			}
			break;
		case 4:
			ETSIDI::printxy("1 de diplomacia por cada moneda de oro", -4.5, 4.5);
			cin >> cantidad;
			if (j.diplomacia < cantidad)
			{
				ETSIDI::printxy("No hay oro suficiente", -4.5, 2.5);
			}
			else
			{
				j.diplomacia -= cantidad;
				j.oro += cantidad;
				ETSIDI::printxy("Operacion realizada con exito", -4.5, 2.5);
				//eliminar poligono--> como?
			}
			break;
		default:
			ETSIDI::printxy("Opcion incorrecta", -4.5, 2.5);
			break;
		}
		
	}

}

void Diplomacia::draw()
{
	if (idr == 8)//Diplomacia
	{
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("Seleccione la region con la que quiere aliarse", -4.5, 4.5);
		//aqui guardar la region que se desea atacar en un atributo de las clase y llamar a check_option para determinar si es válida la elección.
		while (right == false)
		{
			ETSIDI::setTextColor(1, 1, 0);
			ETSIDI::setFont("fuentes/Bitwise.ttf", 16);//poner fuente de GOT
			ETSIDI::printxy("Opcion no válida", -4.5, 4.5);
			ETSIDI::printxy("Seleccione la region con la que desee aliarse", -4.5, 3.5);
		}
		if (right == true)
		{
			glDisable(GL_LIGHTING);
			glBegin(GL_POLYGON);
			glVertex3f(-5.0f, 0, -5.0f);
			glVertex3f(-5.0f, 0, 5.0f);
			glVertex3f(5.0f, 0, 5.0f);
			glVertex3f(5.0f, 0, -5.0f);
			glEnd();
			glEnable(GL_LIGHTING);
			ETSIDI::printxy("Introduzca por teclado el numero de tropas", -4.5, 3.5);//posteriormente lo cambiaremos con las coord correctas del raton
			cin >> cantidad;
			if (j.diplomacia < 50)
			{
				ETSIDI::printxy("No hay diplomacia suficiente", -4.5, 2.5);
			}
			else
			{
				//mandar tropas al ataque
				ETSIDI::printxy("Operacion realizada con exito", -4.5, 2.5);
				//que las tropas lleguen a la region en x turnos y calcular el numero de tropas necesarias para conquistar
				//eliminar poligono--> como?
			}
	}
		if (idr == 9)
		{
			ETSIDI::setTextColor(1, 1, 0);
			ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
			ETSIDI::printxy("Seleccione la region a la que quiere declarar la guerra", -4.5, 4.5);
			//aqui guardar la region que se desea atacar en un atributo de las clase y llamar a check_option para determinar si es válida la elección.
			//continuar prox dia
		}
}