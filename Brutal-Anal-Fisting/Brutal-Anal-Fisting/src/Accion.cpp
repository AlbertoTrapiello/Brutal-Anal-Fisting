#include "Accion.h"



void Gestion_tropas::menu_hide()
{
	glPushMatrix();
	glTranslatef(20.0, 20.0, 0.5);
	glColor3f(1.0f, 1.0f, 1.0f);
	my_menu.setState(1);
	my_menu.draw();
	glPopMatrix();
}

void Gestion_tropas::menu_pop()
{
	glPushMatrix();
	glTranslatef(4.0, 3.0, 0.5);
	glColor3f(1.0f, 1.0f, 1.0f);
	my_menu.setState(1);
	my_menu.draw();
	glPopMatrix();
}
void Comercio::menu_hide()
{
	glPushMatrix();
	glTranslatef(20.0, 20.0, 0.5);
	glColor3f(1.0f, 1.0f, 1.0f);
	my_menu.setState(1);
	my_menu.draw();
	glPopMatrix();
}

void Comercio::menu_pop()
{
	glPushMatrix();
	glTranslatef(4.0, 3.0, 0.5);
	glColor3f(1.0f, 1.0f, 1.0f);
	my_menu.setState(1);
	my_menu.draw();
	glPopMatrix();
}
void Mejorar::menu_hide()
{
	glPushMatrix();
	glTranslatef(20.0, 20.0, 0.5);
	glColor3f(1.0f, 1.0f, 1.0f);
	my_menu.setState(1);
	my_menu.draw();
	glPopMatrix();
}

void Mejorar::menu_pop()
{
	glPushMatrix();
	glTranslatef(4.0, 3.0, 0.5);
	glColor3f(1.0f, 1.0f, 1.0f);
	my_menu.setState(1);
	my_menu.draw();
	glPopMatrix();
}

void Diplomacia::menu_hide()
{
	glPushMatrix();
	glTranslatef(20.0, 20.0, 0.5);
	glColor3f(1.0f, 1.0f, 1.0f);
	my_menu.setState(1);
	my_menu.draw();
	glPopMatrix();
}

void Diplomacia::menu_pop()
{
	glPushMatrix();
	glTranslatef(4.0, 3.0, 0.5);
	glColor3f(1.0f, 1.0f, 1.0f);
	my_menu.setState(1);
	my_menu.draw();
	glPopMatrix();
}

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
	if (id == 0)
		right=false;
	else
		right=true;
	return right;
}

bool Comercio::check(int id)
{
	id = Comercio::get_option(cin);
	if (id == 0)
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
	if (id == 0)
		right = false;
	else
		right = true;
	return right;
}

int Gestion_tropas::gestion_acc()
{
	right = Gestion_tropas::check(id);
	switch (idr)
	{
	case 5://Atacar
	{
		cout << "Escriba el numero de la region que desea atacar" << endl;
		cin >> opcion;
		while (right == false)//gestionar que la region sea valida con check
		{
			cout << "Opcion no valida" << endl;
			cout << "Escriba el numero de la region que desea atacar" << endl;
			cin >> opcion;
		}
		if (right == true)
		{
			cout << "Introduzca el numero de tropas con las que desea atacar" << endl;
			cin >> tropas;
			return tropas;
		}
		return -1;
	}
	break;
	case 6://poner condicion de que esten en guerra con la region, sino es ilogico 
	{
		cout << "Introduzca el numero de tropas con las que desea defender su region" << endl;
		cin >> tropas;
		return tropas;
	}
	break;
	case 7://Generar
	{
		cout << "Introduzca el numero de tropas que quiere generar" << endl;
		cin >> tropas;
		return tropas;
	}
	break;
	default:
		return -1;
		break;
	}
	return -1;
}


int Comercio::gestion_acc()
{
	cout << "Seleccione la opcion de comercio: 1. Comida a cambio de oro 2. Oro a cambio de comida 3. Diplomacia a cambio de oro 4. Oro a cambio de diplomacia" << endl;
	cin >> opcion;
	switch (opcion)
	{
	case 1:
		cout << "2 de agricultura por cada moneda de oro" << endl;
		cin >> cantidad;
		return cantidad;
		break;
	case 2:
		cout << "2 de agricultura por cada moneda de oro" << endl;
		cin >> cantidad;
		return cantidad;
		break;
	case 3:
		cout << "1 de diplomacia por cada moneda de oro" << endl;
		cin >> cantidad;
		return cantidad;
		break;
	case 4:
		cout << "1 de diplomacia por cada moneda de oro" << endl;
		cin >> cantidad;
		return cantidad;
		break;
	default:
		cout << "Opcion incorrecta" << endl;
		return 0;
		break;
	}
}

int Diplomacia :: gestion_acc()
{
	right = Diplomacia::check(id);
	if (idr == 8)//Diplomacia
	{
		cout << "Seleccione la region con la que quiere aliarse" << endl;
		cin >> opcion;
		if (right == false)//gestionar segun el numero de la region si es posible--> region del 1 al 9...
		{
			cout << "Opcion no válida" << endl;
			cout << "Seleccione la region con la que desee aliarse" << endl;
			cin >> opcion;
		}
		else
		{
			return opcion;
		}
	}
	if (idr == 9)
	{
		cout << "Seleccione la region a la que quiere declarar la guerra" << endl;
		cin >> opcion;
		//aqui guardar la region que se desea atacar en un atributo de las clase y llamar a check_option para determinar si es válida la elección.
		if (right == false)
		{
			cout << "Opcion no válida" << endl;
			cout << "Seleccione la region a la que quiere declarar la guerra" << endl;
			cin >> opcion;
			return opcion;
		}
		else
		{
			
			amistad = 2;//enemistad
			cout << "Operacion realizada con exito" << endl;//aqui habria que cambiar la relacion con esa region en el grafo de relaciones
			return -10;//el jugador se va haciendo menos diplomático
		}
	}
	return 0;
}

int Mejorar::gestion_acc()
{

	right = Mejorar::check(id);
	if (idr == 10)//Mejorar ataque, gestionar cantidad de ataque que se aumenta por turno
	{
		cout << "Seleccione la cantidad de ataque que quiere mejorar" << endl;
		cin >> cantidad;
		return cantidad;
	}
	if (idr == 11)//Mejorar defensa, gestionar cantidad de defensa que se aumenta por turno
	{
		cout << "Seleccione la cantidad de defensa que quiere mejorar" << endl;
		cin >> cantidad;
		return cantidad;
	}
	if (idr == 12)//mejorar agricultura
	{
		//gestionar cantidad de comida que se consigue por turno.
		cout << "Seleccione la cantidad de aricultura que quiere mejorar" << endl;
		cin >> cantidad;
		return cantidad;
	}
	return -1;
}

/*void Accion::gestion_acc( )
{
	
}*/

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



void Accion::draw(Jugadores * j, int id) {

}

int Accion::gestion_acc( )
{
	//en principio esta no hace nada
	return 0;
}

void Gestion_tropas::draw(Jugadores * j, int id)//opcion tiene que guardar el numero de la region en funcion de las coordenadas del raton en el click de x region--> crear funcion de region (idea)
{
	menu_pop();
	if (id == 5)//Atacar
	{
		
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Game of thrones.ttf", 12);
		ETSIDI::printxy("Seleccione   la   region", -6.0, 5.0);
		//aqui guardar la region que se desea atacar en un atributo de las clase y llamar a check_option para determinar si es válida la elección.
		//condicion de haber declarado la guerra previamente-->diplomacia
		/*
		if (right == false)
		{
			ETSIDI::setTextColor(1, 1, 0);
			ETSIDI::setFont("fuentes/Game of thrones.ttf", 12);//poner fuente de GOT
			ETSIDI::printxy("Opcion no válida", -4.5, 4.5);
			ETSIDI::printxy("Seleccione la region que desea atacar", -4.5, 3.5);
		}
		else
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
			//cin >> tropas;
		}*/
		
	}

	if (id == 6)//Defender
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
		ETSIDI::setFont("fuentes/Game of thrones.ttf", 12);
		ETSIDI::printxy("Seleccione el numero de tropas con las que defender su region", -4.5, 4.5);
		cin >> tropas;
	}

	if (id == 7)//Generar
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
		ETSIDI::setFont("fuentes/Game of thrones.ttf", 12);
		ETSIDI::printxy("Seleccione el numero de tropas a generarar", -4.5, 4.5);
		ETSIDI::printxy("Generar 10 cuesta 10 de oro", -4.5, 4.5);
		cin >> tropas;
	}
}

void Comercio::draw(Jugadores * j, int id)
{
	menu_pop();
	if (id == 2)
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
		ETSIDI::setFont("fuentes/Game of thrones.ttf", 12);
		ETSIDI::printxy("Seleccione la opcion", -4.5, 4.5);
		ETSIDI::printxy("1. Comida a cambio de oro 2. Oro a cambio de comida 3. Diplomacia a cambio de oro 4. Oro a cambio de diplomacia" , -4.5, 2.5);
	
		switch (opcion)
		{
		case 1:
		{
			ETSIDI::printxy("2 de agricultura por cada moneda de oro", -4.5, 4.5);

		}
			break;
		case 2:
		{
			ETSIDI::printxy("2 de agricultura por cada moneda de oro", -4.5, 4.5);
			
		}
			break;
		case 3:
		{
			ETSIDI::printxy("1 de diplomacia por cada moneda de oro", -4.5, 4.5);
			
		}
			break;
		case 4:
		{
			ETSIDI::printxy("1 de diplomacia por cada moneda de oro", -4.5, 4.5);
			
		}
			break;
		default:
			ETSIDI::printxy("Opcion incorrecta", -4.5, 2.5);
			break;
		}
		
	}

}

void Diplomacia::draw(Jugadores * j, int id)
{
	menu_pop();
	if (id == 8)//Diplomacia
	{
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Game of thrones.ttf", 12);
		ETSIDI::printxy("Seleccione la region con la que quiere aliarse", -4.5, 4.5);
		//aqui guardar la region que se desea atacar en un atributo de las clase y llamar a check_option para determinar si es válida la elección.
		if (right == false)
		{
			ETSIDI::setTextColor(1, 1, 0);
			ETSIDI::setFont("fuentes/Game of thrones.ttf", 12);//poner fuente de GOT
			ETSIDI::printxy("Opcion no válida", -4.5, 4.5);
			ETSIDI::printxy("Seleccione la region con la que desee aliarse", -4.5, 3.5);
		}
		else
		{
		}
	}
		if (id == 9)
		{
			ETSIDI::setTextColor(1, 1, 0);
			ETSIDI::setFont("fuentes/Game of thrones.ttf", 12);
			ETSIDI::printxy("Seleccione la region a la que quiere declarar la guerra", -4.5, 4.5);
			//aqui guardar la region que se desea atacar en un atributo de las clase y llamar a check_option para determinar si es válida la elección.
			if (right == false)
			{
				ETSIDI::setTextColor(1, 1, 0);
				ETSIDI::setFont("fuentes/Game of thrones.ttf", 12);//poner fuente de GOT
				ETSIDI::printxy("Opcion no válida", -4.5, 4.5);
				ETSIDI::printxy("Seleccione la region a la que quiere declarar la guerra", -4.5, 3.5);
			}
			else
			{
			
				amistad = 2;//enemistad
				ETSIDI::printxy("Operacion realizada con exito", -4.5, 2.5);//aqui habria que cambiar la relacion con esa region en el grafo de relaciones
				//el jugador se va haciendo menos diplomático
			}
		}
}

void Mejorar::draw(Jugadores * j, int id)
{
	menu_pop();
	if (id == 10)//Mejorar ataque, gestionar cantidad de ataque que se aumenta por turno
	{
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Game of thrones.ttf", 12);
		ETSIDI::printxy("Seleccione la cantidad de ataque que quiere mejorar", -4.5, 4.5);
	}
	if (id == 11)//Mejorar defensa, gestionar cantidad de defensa que se aumenta por turno
	{
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Game of thrones.ttf", 12);
		ETSIDI::printxy("Seleccione la cantidad de defensa que quiere mejorar", -4.5, 4.5);
	}
	if (id == 12)//mejorar agricultura
	{
		//gestionar cantidad de comida que se consigue por turno.
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Game of thrones.ttf", 12);
		ETSIDI::printxy("Seleccione la cantidad de agricultura que quiere mejorar", -4.5, 4.5);
	}
}

void Accion_Engine::draw(Jugadores * o, int id)
{
	if (a!=NULL)
		a->draw(o,id);
}

int Accion_Engine::gestion_acc( )
{
	a->gestion_acc();
	return 0;
}

void Accion_Engine::switch_puntero(IAccion *c)
{
	if (a != NULL)
	{
		delete a;
		a = c;
	}
	else
		a = c;
}
