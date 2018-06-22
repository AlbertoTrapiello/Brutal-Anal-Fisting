#include "Accion.h"
#include "glut.h"

IAccion::IAccion()
{
	id = 0;
	submenu = 0;
}

ostream & Accion::print_options(ostream &o)
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

/*int Gestion_tropas::get_option(istream &i=cin)
{
	id = 0;
	if ()
	{
		id = static_cast<int>(opcion_gest::Atacar);
	}
	if ()
	{
		id = static_cast<int>(opcion_gest::Defender);
	}
	if ()
	{
		id = static_cast<int>(opcion_gest::Defender);
	}
	return id;
}

int Comercio::get_option(istream &i=cin)
{
	id = 0;
	if ()
	{
		id = 1;
	}
	return id;
}

int Diplomacia::get_option(istream &i=cin)
{
	id = 0;
	if ()
	{
		id = static_cast<int>(opcion_dip::Alianza);
	}
	if ()
	{
		id = static_cast<int>(opcion_dip::Guerra);
	}
	return id;
}

int Mejorar::get_option(istream &i=cin)
{
	id = 0;
	if ()
	{
		id = static_cast<int>(opcion_mej::Ataque);
	}
	if ()
	{
		id = static_cast<int>(opcion_mej::Defensa);
	}
	if ()
	{
		id = static_cast<int>(opcion_mej::Agricultura);
	}
	return id;
}

bool Gestion_tropas::check(int id)//falta añadir que si se selecciona la propia region en acciones determinadas no funciona
{
	id = Gestion_tropas::get_option(cin);
	if (id = 0)
		return false;
	else
		return true;
}

bool Comercio::check(int id)
{
	id = Comercio::get_option(cin);
	if (id = 0)
		return false;
	else
		return true;
}

bool Diplomacia::check(int id)
{
	id = Diplomacia::get_option(cin);
	if (id = 0)
		return false;
	else
		return true;
}


bool Mejorar::check(int id)
{
	id = Mejorar::get_option(cin);
	if (id = 0)
		return false;
	else
		return true;
}

void Gestion_tropas::draw()
{

}

void Comercio::draw()
{

}

void Diplomacia::draw()
{

}

void Mejorar::draw()
{

}*/

ostream & Accion_Engine::print_options(ostream &o)
{
	a->print_options(o);
	return o;
}
/*
int Accion_Engine::get_option(istream &i = cin)
{
	a->get_option(i);
}

bool Accion_Engine::check(int option)
{
	a->check(option);
}

void Accion_Engine::draw()
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
	}
	glutPostRedisplay();
}

void Accion::draw(void) {
	int menuPrincipal, menutropas, menudiplomacia, menumejoras;

	menutropas = glutCreateMenu(onMenu);
	glutAddMenuEntry("Atacar", Gestion_tropas::opcion_gest::Atacar);//si se pulsa Atacar, idr será igual a 5
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