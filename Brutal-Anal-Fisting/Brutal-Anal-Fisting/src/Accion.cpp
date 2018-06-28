#include "Accion.h"

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

int Gestion_tropas::gestion_acc( )
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


int Comercio::gestion_acc( )
{
	right = Comercio::check(id);
	if (idr == 2)
	{
		cout << "Seleccione la opcion de comercio: 1. Comida a cambio de oro 2. Oro a cambio de comida 3. Diplomacia a cambio de oro 4. Oro a cambio de diplomacia"<< endl;
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
			break;
		}
	}
}

int Diplomacia :: gestion_acc( )
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
		}
		else
		{
			return -10;//el jugador se va haciendo menos diplomático
			amistad = 2;//enemistad
			cout << "Operacion realizada con exito" << endl;//aqui habria que cambiar la relacion con esa region en el grafo de relaciones
		}
	}
}

int Mejorar::gestion_acc( )
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



void onMenu(int opcion) {
	switch (opcion) {
	case Accion::opc_menu::gest_tropas:
	{
		idr = 1;
		//llamada a la gestión de tropas

		break;
	}
	
	case Accion::opc_menu::comercio:
	{
		idr = 2;
		//lamada a la gestión de comercio
		break;
	}
	case Accion::opc_menu::diplomacia:
	{
		idr = 3;
		//llamada a la diplomacia
		break;
	}
	case Accion::opc_menu::mejorar:
	{
		idr = 4;
		//lamada a la mejora
		break;
	}
	case Gestion_tropas::opcion_gest::Atacar:
	{
		idr = 5;
		//llamada a la opciónd de Atacar
		break;
	}
	case Gestion_tropas::opcion_gest::Defender:
	{
		idr = 6;
		//llamada a la opción de Defender
		break;
	}
	case Gestion_tropas::opcion_gest::Generar_tropas:
	{
		idr = 7;
		//llamada a la opción de Defender
		break;
	}
	case Diplomacia::opcion_dip::Alianza:
	{
		idr = 8;
		//llamada a la Alianza
		break;
	}
	case Diplomacia::opcion_dip::Guerra:
	{
		idr = 9;
		//llamada la Guerra
		break;
	}
	case Mejorar::opcion_mej::Ataque:
	{
		idr = 10;
		//lamada al Ataque
		break;
	}
	case Mejorar::opcion_mej::Defensa:
	{
		idr = 11;
		//llamada a la Defensa
		break;
	}
	case Mejorar::opcion_mej::Agricultura:
	{
		idr = 12;
		//lamada a la Agricultura
		break;
	}
	default:
		idr = 0;
	}
	glutPostRedisplay();
}

int Accion::draw( ) {
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
	return 0;
}

int Accion::gestion_acc( )
{
	//en principio esta no hace nada
	return 0;
}

int Gestion_tropas::draw( )//opcion tiene que guardar el numero de la region en funcion de las coordenadas del raton en el click de x region--> crear funcion de region (idea)
{
	if (idr == 5)//Atacar
	{
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("Seleccione la region que desea atacar", -4.5, 4.5);
		//aqui guardar la region que se desea atacar en un atributo de las clase y llamar a check_option para determinar si es válida la elección.
		//condicion de haber declarado la guerra previamente-->diplomacia
		if (right == false)
		{
			ETSIDI::setTextColor(1, 1, 0);
			ETSIDI::setFont("fuentes/Bitwise.ttf", 16);//poner fuente de GOT
			ETSIDI::printxy("Opcion no válida", -4.5, 4.5);
			ETSIDI::printxy("Seleccione la region que desea atacar", -4.5, 3.5);
			return -1;
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
			cin >> tropas;
			return tropas;
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
		return tropas;
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
		return tropas;
	}
	return -1;
}

int Comercio::draw( )
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
		ETSIDI::printxy("1. Comida a cambio de oro 2. Oro a cambio de comida 3. Diplomacia a cambio de oro 4. Oro a cambio de diplomacia" , -4.5, 2.5);
		cin >> opcion;
		switch (opcion)
		{
		case 1:
		{
			ETSIDI::printxy("2 de agricultura por cada moneda de oro", -4.5, 4.5);
			cin >> cantidad;
			return cantidad;
		}
			break;
		case 2:
		{
			ETSIDI::printxy("2 de agricultura por cada moneda de oro", -4.5, 4.5);
			cin >> cantidad;
			return cantidad;
		}
			break;
		case 3:
		{
			ETSIDI::printxy("1 de diplomacia por cada moneda de oro", -4.5, 4.5);
			cin >> cantidad;
			return cantidad;
		}
			break;
		case 4:
		{
			ETSIDI::printxy("1 de diplomacia por cada moneda de oro", -4.5, 4.5);
			cin >> cantidad;
			return cantidad;
		}
			break;
		default:
			ETSIDI::printxy("Opcion incorrecta", -4.5, 2.5);
			break;
		}
		
	}
	return -1;
}

int Diplomacia::draw( )
{
	if (idr == 8)//Diplomacia
	{
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("Seleccione la region con la que quiere aliarse", -4.5, 4.5);
		//aqui guardar la region que se desea atacar en un atributo de las clase y llamar a check_option para determinar si es válida la elección.
		if (right == false)
		{
			ETSIDI::setTextColor(1, 1, 0);
			ETSIDI::setFont("fuentes/Bitwise.ttf", 16);//poner fuente de GOT
			ETSIDI::printxy("Opcion no válida", -4.5, 4.5);
			ETSIDI::printxy("Seleccione la region con la que desee aliarse", -4.5, 3.5);
		}
		else
		{
			return +10;
		}
	}
		if (idr == 9)
		{
			ETSIDI::setTextColor(1, 1, 0);
			ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
			ETSIDI::printxy("Seleccione la region a la que quiere declarar la guerra", -4.5, 4.5);
			//aqui guardar la region que se desea atacar en un atributo de las clase y llamar a check_option para determinar si es válida la elección.
			if (right == false)
			{
				ETSIDI::setTextColor(1, 1, 0);
				ETSIDI::setFont("fuentes/Bitwise.ttf", 16);//poner fuente de GOT
				ETSIDI::printxy("Opcion no válida", -4.5, 4.5);
				ETSIDI::printxy("Seleccione la region a la que quiere declarar la guerra", -4.5, 3.5);
			}
			else
			{
			
				amistad = 2;//enemistad
				ETSIDI::printxy("Operacion realizada con exito", -4.5, 2.5);//aqui habria que cambiar la relacion con esa region en el grafo de relaciones
				return -10;//el jugador se va haciendo menos diplomático
			}
		}
}

int Mejorar::draw( )
{
	if (idr == 10)//Mejorar ataque, gestionar cantidad de ataque que se aumenta por turno
	{
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("Seleccione la cantidad de ataque que quiere mejorar", -4.5, 4.5);
		cin >> cantidad;
		return cantidad;
	}
	if (idr == 11)//Mejorar defensa, gestionar cantidad de defensa que se aumenta por turno
	{
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("Seleccione la cantidad de defensa que quiere mejorar", -4.5, 4.5);
		cin >> cantidad;
		return cantidad;
	}
	if (idr == 12)//mejorar agricultura
	{
		//gestionar cantidad de comida que se consigue por turno.
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("Seleccione la cantidad de agricultura que quiere mejorar", -4.5, 4.5);
		cin >> cantidad;
		return cantidad;
	}
}

int Accion_Engine::draw( )
{
	if (a!=NULL)
		a->draw();
	return 0;
}

int Accion_Engine::gestion_acc( )
{
	a->gestion_acc();
	return 0;
}
