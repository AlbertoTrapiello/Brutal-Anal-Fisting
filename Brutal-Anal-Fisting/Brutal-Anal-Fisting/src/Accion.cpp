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

void Gestion_tropas::gestion_acc(Jugadores j)
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
			while ((tropas > j.ataque && j.ataque!=0) || tropas<0)
			{
				cout << "No hay suficientes tropas, introduzca un numero valido" << endl;
				cin >> tropas;
			}
			if (tropas < j.ataque)
			{
				//mandar tropas al ataque
				cout << "Operacion realizada con exito" << endl;
				//que las tropas lleguen a la region en x turnos y calcular el numero de tropas necesarias para conquistar
			}
		}
	}
	break;
	case 6://poner condicion de que esten en guerra con la region, sino es ilogico 
	{
		cout << "Introduzca el numero de tropas con las que desea defender su region" << endl;
		cin >> tropas;
		while ((tropas > j.ataque && j.ataque!=0) || tropas<0)
		{
			cout << "No hay suficientes tropas" << endl;
			cout << "Introduzca el numero de tropas con las que desea defender su region" << endl;
			cin >> tropas;
		}
		if (tropas < j.ataque)
		{
			//movimiento de tropas instantaneo a la region
			j.defensa += tropas;//se incrementa la defensa con el numero de tropas que defienden
			cout << "Operacion realizada con exito" << endl;
		}

	}
	break;
	case 7://Generar
	{
		cout << "Introduzca el numero de tropas que quiere generar" << endl;
		cin >> tropas;
		while ((tropas < j.oro && j.oro!=0) || tropas<0)
		{
			cout << "No hay oro suficiente para generar las tropas" << endl;
			cout << "Introduzca el numero de tropas que quiere generar" << endl;
			cin >> tropas;
		}
		if(tropas>j.oro)
		{
			j.oro -= tropas;//se gasta x oro
			j.ataque += tropas;//el jugador tiene x tropas mas
			cout << "Operacion realizada con exito" << endl;
		}
	}
	break;
	default:
		break;
	}
}

void Comercio::gestion_acc(Jugadores j)
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
			if (j.oro < 0.5*cantidad || cantidad<0)
			{
				cout << "No hay oro suficiente o la cantidad es menor que 0" << endl;
			}
			else
			{
				j.comida += cantidad;
				j.oro -= 0.5*cantidad;
				cout << "Operacion realizada con exito" << endl;
			}
			break;
		case 2:
			cout << "2 de agricultura por cada moneda de oro" << endl;
			cin >> cantidad;
			if (j.comida < 2 * cantidad || cantidad<0)
			{
				cout << "No hay comida suficiente o la cantidad es menor que 0" << endl;
			}
			else
			{
				j.oro += cantidad;
				j.comida -= 2 * cantidad;
				cout << "Operacion realizada con exito" << endl;
			}
			break;
		case 3:
			cout << "1 de diplomacia por cada moneda de oro" << endl;
			cin >> cantidad;
			if (j.oro < cantidad || cantidad<0)
			{
				cout << "No hay oro suficiente" << endl;
			}
			else
			{
				j.oro -= cantidad;
				j.diplomacia += cantidad;
				cout << "Operacion realizada con exito" << endl;
			}
			break;
		case 4:
			cout << "1 de diplomacia por cada moneda de oro" << endl;
			cin >> cantidad;
			if (j.diplomacia < cantidad)
			{
				cout << "No hay oro suficiente o la cantidad es menor que 0" << endl;
			}
			else
			{
				j.diplomacia -= cantidad;
				j.oro += cantidad;
				cout << "Operacion realizada con exito" << endl;
			}
			break;
		default:
			cout << "Opcion incorrecta" << endl;
			break;
		}
	}
}

void Diplomacia :: gestion_acc(Jugadores j)
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
			if (j.diplomacia < 50)
			{
				cout << "No hay diplomacia suficiente" << endl;
			}
			else
			{
				j.diplomacia += 10;//el jugador se va haciendo más diplomático
				amistad = 1;//aliados
				cout << "Operacion realizada con exito" << endl;//aqui habria que cambiar la relacion con esa region en el grafo de relaciones
			}
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
			j.diplomacia -= 10;//el jugador se va haciendo menos diplomático
			amistad = 2;//enemistad
			cout << "Operacion realizada con exito" << endl;//aqui habria que cambiar la relacion con esa region en el grafo de relaciones
		}
	}
}

void Mejorar::gestion_acc(Jugadores j)
{
	right = Mejorar::check(id);
	if (idr == 10)//Mejorar ataque, gestionar cantidad de ataque que se aumenta por turno
	{
		cout << "Seleccione la cantidad de ataque que quiere mejorar" << endl;
		cin >> cantidad;
		if (j.oro<cantidad || cantidad<0)
		{
			cout << "Opcion no válida" << endl;
		}
		else
		{
			j.ataque += cantidad;
			j.oro -= cantidad;
			cout << "Operacion realizada con exito" << endl;
		}
	}
	if (idr == 11)//Mejorar defensa, gestionar cantidad de defensa que se aumenta por turno
	{
		cout << "Seleccione la cantidad de defensa que quiere mejorar" << endl;
		cin >> cantidad;
		if (j.oro<cantidad || cantidad<0)
		{
			cout << "Opcion no válida" << endl;
		}
		else
		{
			j.defensa += cantidad;
			j.oro -= cantidad;
			cout << "Operacion realizada con exito" << endl;
		}
	}
	if (idr == 12)//mejorar agricultura
	{
		//gestionar cantidad de comida que se consigue por turno.
	}
}

/*void Accion::gestion_acc(Jugadores j)
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

void Gestion_tropas::draw(Jugadores j)//opcion tiene que guardar el numero de la region en funcion de las coordenadas del raton en el click de x region--> crear funcion de region (idea)
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
			j.defensa += tropas;//las tropas se añaden a la defensa de la region
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

void Comercio::draw(Jugadores j)
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
			if (j.oro < 0.5*cantidad || cantidad < 0)
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
		}
			break;
		case 2:
		{
			ETSIDI::printxy("2 de agricultura por cada moneda de oro", -4.5, 4.5);
			cin >> cantidad;
			if (j.comida < 2 * cantidad || cantidad < 0)
			{
				ETSIDI::printxy("No hay comida suficiente", -4.5, 2.5);
			}
			else
			{
				j.oro += cantidad;
				j.comida -= 2 * cantidad;
				ETSIDI::printxy("Operacion realizada con exito", -4.5, 2.5);
				//eliminar poligono--> como?
			}
		}
			break;
		case 3:
		{
			ETSIDI::printxy("1 de diplomacia por cada moneda de oro", -4.5, 4.5);
			cin >> cantidad;
			if (j.oro < cantidad || cantidad < 0)
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
		}
			break;
		case 4:
		{
			ETSIDI::printxy("1 de diplomacia por cada moneda de oro", -4.5, 4.5);
			cin >> cantidad;
			if (j.diplomacia < cantidad || cantidad < 0)
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
		}
			break;
		default:
			ETSIDI::printxy("Opcion incorrecta", -4.5, 2.5);
			break;
		}
		
	}

}

void Diplomacia::draw(Jugadores j)
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
			if (j.diplomacia < 50)
			{
				ETSIDI::printxy("No hay diplomacia suficiente", -4.5, 2.5);
			}
			else
			{
				j.diplomacia += 10;//el jugador se va haciendo más diplomático
				amistad = 1;//aliados
				ETSIDI::printxy("Operacion realizada con exito", -4.5, 2.5);//aqui habria que cambiar la relacion con esa region en el grafo de relaciones
			}
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
				j.diplomacia -= 10;//el jugador se va haciendo menos diplomático
				amistad = 2;//enemistad
				ETSIDI::printxy("Operacion realizada con exito", -4.5, 2.5);//aqui habria que cambiar la relacion con esa region en el grafo de relaciones
			}
		}
}

void Mejorar::draw(Jugadores j)
{
	if (idr == 10)//Mejorar ataque, gestionar cantidad de ataque que se aumenta por turno
	{
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("Seleccione la cantidad de ataque que quiere mejorar", -4.5, 4.5);
		cin >> cantidad;
		if (j.oro<cantidad || cantidad<0)
		{
			ETSIDI::setTextColor(1, 1, 0);
			ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
			ETSIDI::printxy("Opcion no válida", -4.5, 4.5);
		}
		else
		{
			j.ataque += cantidad;
			j.oro -= cantidad;
			ETSIDI::printxy("Operacion realizada con exito", -4.5, 2.5);
		}
	}
	if (idr == 11)//Mejorar defensa, gestionar cantidad de defensa que se aumenta por turno
	{
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("Seleccione la cantidad de defensa que quiere mejorar", -4.5, 4.5);
		cin >> cantidad;
		if (j.oro<cantidad || cantidad<0)
		{
			ETSIDI::setTextColor(1, 1, 0);
			ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
			ETSIDI::printxy("Opcion no válida", -4.5, 4.5);
		}
		else
		{
			j.defensa += cantidad;
			j.oro -= cantidad;
			ETSIDI::printxy("Operacion realizada con exito", -4.5, 2.5);
		}
	}
	if (idr == 12)//mejorar agricultura
	{
		//gestionar cantidad de comida que se consigue por turno.
	}
}