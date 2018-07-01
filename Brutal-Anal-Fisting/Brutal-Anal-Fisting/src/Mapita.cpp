#include <string>
#include "Mapita.h"



Mapita::Mapita()
{
	src = 0;
	destino = 0;
	for (int i = 0; i < 10; i++)// Inicializar todas las distancias como infintas y stpSet[] a false 
	{
		dist[i] = INT_MAX, sptSet[i] = false;// nodos[i] = 0;//posibilidad de utilizar memoria dinamica para nodos
	}
}

int Mapita::minDistance(int dist[], bool sptSet[])
{
	int minimo = INT_MAX;
	int min_index;
	for (int i = 0; i < 10; i++)
		if (sptSet[i] == false && dist[i] <= minimo)//si no se ha añadido todavía el nodo a SPT y su distancia es menor que INT_MAX
			minimo = dist[i], min_index = i;

	return min_index;
}

void Mapita::printSolution(int dist[], int destino)
{
	cout << "Vertex" << "       " << "Distance from Source" << endl;
	cout << destino + 1 << "         " << dist[destino] << endl;
	/*for (int i = 0; i < n-1; i++)
		cout << nodos[i] << "->";
	cout << nodos[n-1] << endl;*/
}

void Mapita::dijkstra()
{
	int n = 0, i = 0;//numero de nodos para llegar al destino desde el origen
	for (int i = 0; i < 10; i++)
		dist[i] = INT_MAX, sptSet[i] = false;//, nodos[i] = 0; Inicializar todas las distancias como infintas y stpSet[] a false 

														   
	dist[src] = 0;// La distancia del nodo fuente al mismo es siempre 0
	//nodos[0] = src;

	// Encontrar el camino más corto para todos los vértices
	for (int count = 0; count < 10 - 1; count++)
	{

		int u = minDistance(dist, sptSet);//Coger el vértice con menor distancia de los vértices sin procesar, u siempre es igual a src en la primera iteración
		sptSet[u] = true; // Marcar el vértice elegido como procesado.
		

						  //Actualizar el valor de dist en función de los vértices adyacentes del src
		for (int v = 0; v < 10; v++)

			// Actualizar dist[v] solo si es false en sptSet, hay un camino desde u a v, y la distancia total del camino desde la fuente a v pasando por u es 
			// más pequeña que el valor actual de dist[v]
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
			{
				dist[v] = dist[u] + graph[u][v];
				//nodos[count] = u;
				//n++;
			}
	}

	printSolution(dist, destino);
}

/*
Mapita::~Mapita()
{
}*/
/*
void extract_(string line, int &fil, int &col);

bool ** Mapita::read_Dimacs(string nombre)
{
	ifstream f(nombre, ifstream::in);
	string line;
	string aux;
	string aux1;
	char token;
	stringstream sstr;
	int fil = 0, col = 0;

	//falta meter el if en caso de que no se abra bien
	if (!f)
	{
		cout << "No se puede abrir el archivo" << endl;
		return NULL;
	}
	else
	{
		while (!f.eof())
		{
			getline(f, line);
			cout << line << endl;
			token = line[0];

			switch (token)
			{
			case 'c':
			{
				//cout << line << endl;
				break;
			}
			case 'p':
			{
				sstr.str(line);
				sstr >> aux >> aux >> nodes >> edges;
				if (edges == -1 || nodes == -1)
				{
					cout << "ERROR DE PROTOCOLO" << endl;
					return NULL;
				}
				else
				{
					cout << "CREATING MATRIX" << endl;
					create();
				}
				//cout << "AUX: " << aux << " NODES: " << nodes << " EDGES: " << edges << endl;
				break;
			}
			case 'e':
			{
				extract_(line, fil, col);
				//cout << " FIL: " << fil << " COL: " << col << endl;
				vecinos[fil - 1][col - 1] = 1;
				vecinos[col - 1][fil - 1] = 1;
				break;
			}

			default:
			{
				cout << "¡¡¡ERROR DE PROTOCOLO!!!\n" << endl;
				if (vecinos != NULL)
				{
					cout << "BORRANDO LOS DATOS...";
					erase();
				}

				return vecinos;
				break;
			}
			}
		}
	}

	f.close();
	return vecinos;
}

void extract_(string line, int &fil, int &col)
{
	stringstream sstr(line);
	string aux;
	sstr >> aux >> fil >> col;
}

void Mapita::erase()
{
	if (vecinos != NULL)
	{
		for (int i = 0; i < nodes; i++)
			delete[] vecinos[i];
		delete[] vecinos;
	}
	vecinos = NULL;
}

void Mapita::create()
{
	vecinos = new bool*[nodes];

	for (int i = 0; i < nodes; i++)
		vecinos[i] = new bool;

	for (int i = 0; i < nodes; i++)
	{
		for (int j = 0; j < nodes; j++)
			vecinos[i][j] = 0;
	}
}

int * Mapita::find_neighbors(int id)//las id deben de ir de 0 a 9
{
	int l = 0;
	int* aux = new int[nodes];

	for (int i = 0; i < nodes; i++)
		if (vecinos[id - 1][i])
		{
			aux[l++] = i + 1;
			cout << "[" << aux[l - 1] << "]";
		}
	cout << endl;
	neighbors = new int[l];
	for (int i = 0; i < l; i++)
		neighbors[i] = aux[i];
	delete[] aux;
	return neighbors;
}

void Mapita::erase_neighbors()
{
	delete[] neighbors;
}

ostream & Mapita::print(ostream & o)
{
	// TODO: insertar una instrucción return aquí
	for (int i = 0; i < nodes; i++)
	{
		for (int j = 0; j < nodes; j++)
			o << "[" << vecinos[i][j] << "]";
		o << "\n";
	}
	return o;
}

*/

