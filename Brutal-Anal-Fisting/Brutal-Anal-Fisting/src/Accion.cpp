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
void Gestion_tropas::set_num(int num)
{
	tropas = num;
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
void Comercio::set_num(int num)
{
	cantidad = num;
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

void Mejorar::set_num(int num)
{
	cantidad = num;
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

void Diplomacia::set_num(int num)
{
	amistad = num;
}

IAccion::IAccion()
{
	id = 0;
	right = false;
}

/*ostream & Accion::print_options(ostream &o)//modo por teclado
{
	o << "Gestionar Tropas" << endl;
	o << "Comercio" << endl;
	o << "Diplomacia" << endl;
	o << "Mejorar" << endl;
	return o;
}*/

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

int IAccion::get_option(istream&i)//modo por teclado
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
	idr = IAccion::get_option(i);
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
	idr = IAccion::get_option(i);
	id = idr;
	return id;
}

int Diplomacia::get_option(istream &i)
{
	idr = IAccion::get_option(i);
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
	idr = IAccion::get_option(i);
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
/*
bool Accion::check(int id)
{
	id = Accion::get_option(cin);
	if (id == 0)
		right = false;
	else
		right = true;
	return right;
}*/

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
	if (id == 0)
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

//si la region del jugador 1 es distinta que la del 2 o la misma se gestiona externamente Mundo::check_action()

bool Gestion_tropas::gestion_acc(Jugadores & j1, Jugadores & j2)
{
	if (idr == 5)//Atacar--> Para atacar hay que antes declarar la guerra, cuando llamemos atacar tenemos que asegurarnos de que el vector de diplomacia tiene a 1 (enemistad) en la componente
	{//de la region correspondiente. Todo esto externamente.
		if ((tropas > j1.ataque && j1.ataque != 0) || tropas < 0)
		{
			error_click = true;
			return false;
		}
		else
		{
			j1.ataque -= tropas;
			//hacer que las tropas lleguen en x turnos en funcion de su distancia minima
			if (tropas < j2.defensa)
			{
				tropas = 0;
				j2.defensa -= 0.5*tropas;//posicion de defensor, el defensor si gana pierde menos defensa que el atacante ataque
			}
			else
			{
				tropas -= j2.defensa;
				j1.ataque += tropas;
				j2.defensa = 0;
				//la region del jugador 2 ha sido conquistada por el jugador 1
				j1.oro += j2.oro;
				j1.comida += j2.comida;
				j1.ataque += j2.ataque;
			}
			error_click = false;
			return true;
		}
	}
	if (idr == 6)
	{
		if ((tropas > j1.ataque && j1.ataque != 0) || tropas < 0)
		{
			error_click = true;
			return false;
		}
		else
		{
			j1.ataque -= tropas;
			//si las tropas estan fuera, que tarden x turnos en llegar a la propia region
			j1.defensa += tropas;
			error_click = false;
			return true;
		}
	}
	if (idr == 7)
	{
		if (tropas > j1.comida * 4 && j1.comida!=0 || tropas<0)
		{
			error_click = true;
			return false;
		}
		else
		{
			j1.comida -= 0.25*tropas;
			j1.ataque += tropas;
			error_click = false;
			return true;
		}
	}
	return 0;
}


bool Comercio::gestion_acc(Jugadores & j1, Jugadores &j2)
{
	//cout << "He hecho la opción ";
	switch (opcion)
	{
	case 1:
	{
		if (j1.comida >= 50)
		{
			j1.comida -= 50;
			j1.oro += 25;
			error_click = false;
			//cout << "comida se ha reducido en 50" << endl;
			//ponemos Printxy?
			return true;
		}
		else
		{
			error_click = true;
			return false;
		}
		cout << 1 << "error:" << error_click << endl;
		break;
	}
	case 2:
	{
		if(j1.oro >= 50)
		{
			j1.oro -= 50;
			j1.comida += 100;
			error_click = false;
			//cout << "oro se ha reducido en 100" << endl;
			return true;
		}
		else
		{
			error_click = true;
			return false;
		}
		cout << 2 << "error:" << error_click << endl;
		break;
	}
	case 3:
	{
		if (j1.diplomacia >= 10)
		{
			j1.diplomacia -= 10;
			j1.oro += 50;
			//cout << "diplomacia se ha reducido en 10" << endl;
			error_click = false;
			return true;
		}
		else
		{
			error_click = true;
			return false;
		}
		cout << 3 << "error:" << error_click << endl;
		break;
	}
	case 4:
	{
		if (j1.oro >= 150)
		{
			j1.oro -= 150;
			j1.diplomacia += 50;
			//cout << "oro se ha reducido en 150" << endl;
			error_click = false;
			return true;
		}
		else
		{
			error_click = true;
			return false;
		}
		cout << 4 << "error:" << error_click << endl;
		break;
	}
	}

	return 0;
}

bool Diplomacia :: gestion_acc(Jugadores & j1, Jugadores & j2)
{
	//right = Diplomacia::check(id);
	if (idr == 8)//Diplomacia
	{
		//cout << "Seleccione la region con la que quiere aliarse" << endl;
		//cin >> opcion;
		if (j1.diplomacia>=50)//gestionar segun el numero de la region si es posible--> region del 1 al 9...
		{
			//cout << "Opcion no válida" << endl;
			//cout << "Seleccione la region con la que desee aliarse" << endl;
			//cin >> opcion;
			j1.diplomacia += 10;
			j2.diplomacia += 10;
			//cambiar vector de relaciones 
			//se hacen amigos
			j1.relaciones[j2.casa] = 0;
			j2.relaciones[j1.casa] = 0;
			error_click = false;
			return true;
		}
		else
		{
			error_click = true;
			return false;
		}
	}
	if (idr == 9)
	{
		//cout << "Seleccione la region a la que quiere declarar la guerra" << endl;
		//cin >> opcion;
		//aqui guardar la region que se desea atacar en un atributo de las clase y llamar a check_option para determinar si es válida la elección.
			//cout << "Opcion no válida" << endl;
			//cout << "Seleccione la region a la que quiere declarar la guerra" << endl;
			//cin >> opcion;
			//return opcion;
			j1.diplomacia -= 15;//te haces menos amistoso
			//cambiar vector de relaciones 
			//se hacen enemigos
			j1.relaciones[j2.casa] = 1;
			j2.relaciones[j1.casa] = 1;
			error_click = false;
			return true;
	}
	return 0;
}

bool Mejorar::gestion_acc(Jugadores & j1, Jugadores & j2)
{

	//right = Mejorar::check(id);
	if (idr == 10)//Mejorar oro, gestionar cantidad de oro que se aumenta
	{
		//cout << "Seleccione la cantidad de ataque que quiere mejorar" << endl;
		j1.oro += 50;
		error_click = false;
		return true;
	}
	if (idr == 11)//Mejorar defensa, gestionar cantidad de defensa que se aumenta por turno
	{
		//cout << "Seleccione la cantidad de defensa que quiere mejorar" << endl;
		j1.defensa += 100;
		error_click = false;
		return true;
	}
	if (idr == 12)//mejorar agricultura
	{
		//gestionar cantidad de comida que se consigue por turno.
		//cout << "Seleccione la cantidad de aricultura que quiere mejorar" << endl;
		j1.comida += 75;
		error_click = false;
		return true;
	}
	return 0;
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



/*void Accion::draw(int id) {

}

bool Accion::gestion_acc(Jugadores & j1, Jugadores & j2)
{
	//en principio esta no hace nada
	return false;
}

void Accion::set_num(int num)
{
	
}*/

void Gestion_tropas::draw(int id)//opcion tiene que guardar el numero de la region en funcion de las coordenadas del raton en el click de x region--> crear funcion de region (idea)
{//meter en id el valor de idr
	menu_pop();
	if (id == 5)//Atacar
	{

		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Game of thrones.ttf", 8);
		ETSIDI::printxy("Seleccione  la  region", 4.0, 8.0);
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
		ETSIDI::setFont("fuentes/Game of thrones.ttf", 8.0);
		ETSIDI::printxy("Numero de tropas", 4.0, 8.0);
		ETSIDI::printxy("para defender", 4.0, 7.0); 

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
		ETSIDI::setFont("fuentes/Game of thrones.ttf", 7);
		ETSIDI::printxy("numero de tropas", 4.0, 8.0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 8);
		ETSIDI::printxy("(10 tropas cuestan 10 de oro)", 4.0, 7.0);
	}
}

void Comercio::draw(int id)
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
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Game of thrones.ttf", 7);
		ETSIDI::printxy("Seleccione la opcion", 4.0, 9.0);
		ETSIDI::setFont("fuentes/Game of thrones.ttf", 6.0);
		ETSIDI::printxy("1.Comida a cambio de oro " , 4.0, 8.0);
		ETSIDI::printxy("2.Oro a cambio de comida ", 4.0, 7.0);
		ETSIDI::printxy("3.Diplomacia a cambio de oro ", 4.0, 6.0);
		ETSIDI::printxy("4.Oro a cambio de diplomacia ", 4.0, 5.0);
		/*
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
		*/
	}

}

void Diplomacia::draw(int id)
{
	menu_pop();
	if (id == 8)//Diplomacia
	{
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Game of thrones.ttf", 7);
		ETSIDI::printxy("Seleccione la region ", 4, 7);
		ETSIDI::printxy("con la que aliarse", 4, 6);
		//aqui guardar la region que se desea atacar en un atributo de las clase y llamar a check_option para determinar si es válida la elección.
		/*if (right == false)
		{
			ETSIDI::setTextColor(1, 1, 0);
			ETSIDI::setFont("fuentes/Game of thrones.ttf", 12);//poner fuente de GOT
			ETSIDI::printxy("Opcion no válida", -4.5, 4.5);
			ETSIDI::printxy("Seleccione la region con la que desee aliarse", -4.5, 3.5);
		}
		else
		{
		}*/
	}
		if (id == 9)
		{
			ETSIDI::setTextColor(1, 1, 0);
			ETSIDI::setFont("fuentes/Game of thrones.ttf", 7);
			ETSIDI::printxy("Seleccione la region", 4, 7);
			ETSIDI::printxy("a la que declarar", 4, 6);
			ETSIDI::printxy("la guerra", 4, 5);
			//aqui guardar la region que se desea atacar en un atributo de las clase y llamar a check_option para determinar si es válida la elección.
			/*if (right == false)
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
			}*/
		}
}

void Mejorar::draw(int id)
{
	menu_pop();
	if (id == 10)//Mejorar ataque, gestionar cantidad de ataque que se aumenta por turno
	{
		ETSIDI::setTextColor(1, 0, 1);
		ETSIDI::setFont("fuentes/Game of thrones.ttf", 7);
		ETSIDI::printxy("Seleccione la cantidad ", 4, 6);
		ETSIDI::printxy("de ataque a mejorar", 4, 5);
	}
	if (id == 11)//Mejorar defensa, gestionar cantidad de defensa que se aumenta por turno
	{
		ETSIDI::setTextColor(1, 0, 1);
		ETSIDI::setFont("fuentes/Game of thrones.ttf", 7);
		ETSIDI::printxy("Seleccione la cantidad ", 4, 6);
		ETSIDI::printxy("de defensa a mejorar", 4, 5);
	}
	if (id == 12)//mejorar agricultura
	{
		//gestionar cantidad de comida que se consigue por turno.
		ETSIDI::setTextColor(1, 0, 1);
		ETSIDI::setFont("fuentes/Game of thrones.ttf", 7);
		ETSIDI::printxy("Seleccione la cantidad", 4, 6);
		ETSIDI::printxy(" de agricultura a mejorar", 4, 5);
	}
}

void Accion_Engine::draw( int id)
{
	if (a!=NULL)
		a->draw(id);
}

bool Accion_Engine::gestion_acc(Jugadores & j1, Jugadores &j2)
{
	if(a!=NULL)
		return a->gestion_acc(j1, j2);
	
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

void Accion_Engine::set_num(int num)
{
	a->set_num(num);
}
