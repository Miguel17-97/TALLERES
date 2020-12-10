/*
	Name: Desarrollo del punto 10 de tipo 2
	Copyright: 
	Author: Miguel Angel Bañol Cifuentes, David Duque, Pablo Emilio Hernandez
	Date: 09/12/20 22:59
	Description: Se tiene una bicola generada de numeros aleatorios entre (100,500) se desea implementar una cola
				o una pila con sus operaciones básicas, el usuario deses que opcion tomar.
*/

#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

using namespace std;


class Cola
{
	private:
		int tam;
		int limite;
		int tope;
		int vect[];
		
	public:
		Cola(int); // constructor de la clase
		~Cola () {cout << "Destruyendo programa.";}
		void encolar (int);
		int desencolar ();
		bool colallena ();
		bool colavacia ();
		void mostrarcola ();
		int numeroAleatorio ();
};

Cola :: Cola (int n)
{
	tam = n;
	limite = n-1;
	tope = -1;
	vect [n];
}

bool Cola :: colallena ()
{
	if (tope == limite)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Cola :: colavacia ()
{
	if (tope == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Cola :: encolar (int info)
{
	if (colallena () == false)
	{
		tope ++;
		vect [tope] = info;
		cout << "\tDato insertado\t" << endl;
	}
	else
	{
		cout << "\t Cola llena, no se puede insertar.\t";
	}
}

int Cola :: desencolar ()
{
	int p, i = 0;
	
	if (colavacia () == false)
	{
		p = vect [i];
		
		while (i <= tope)
		{
			vect [i] = vect [i+1];
			i ++;
		}
		
		tope--;
	}
	
	return p;
}

void Cola :: mostrarcola ()
{
	int desencolando = 0;
	Cola nueva = Cola (tam);
	
	if (colavacia() == true)
	{
		cout << "La cola está vacia, no hay elementos para mostrar.";
	}
	else
	{
		while (colavacia() == false && nueva.colallena() == false)
		{
			desencolando = desencolar();
			cout << "|" << desencolando << "|" << " -> ";
			nueva.encolar(desencolando);
		}
		
		// Regresamos los datos a la cola original
		
		while (colallena() == false && nueva.colavacia() == false)
		{
			desencolando = nueva.desencolar();
			encolar(desencolando);
		}
	}
}

int Cola :: numeroAleatorio ()
{
	return 100 + rand() % 400;
}

// Cambiar la funcion numero aleatorio para el main y no en la clase Cola....

main ()
{
	int tam = 0, j, rand;
	short opcion = 0;
	
	cout << "Digite la dimension de la cola aleatoria (esta tendra el mismo tamaño que la normal): ";
	cin >> tam;
	Cola aleatoria = Cola (tam);
	Cola normal = Cola (tam);
	srand((unsigned)time(0));
	
	for (j = 0; j < tam; j++)
	{
		aleatoria.encolar(aleatoria.numeroAleatorio());
		rand = aleatoria.numeroAleatorio();
		cout << rand << endl;
	}
	
	do
	{
		cout << "\t********** MENU **********\t\n";
		cout << "\t(1). Encolar desde la cola aleatoria\t\n";
		cout << "\t(2). Desencolar el dato aleatorio\t\n";
		cout << "\t(3). Mostrar cola normal\t\n";
		cout << "\t(4). Salir\t\n";
		cin >> opcion;
		switch (opcion)
		{
			case 1: cout << "\n Trayendo datos... " << endl;
					normal.encolar(aleatoria.desencolar());
			break;
			
			case 2: cout << "\n Desencolando... " << endl;
					normal.desencolar();
			break;
		
			case 3: cout << "\n Mostrando cola..." << endl;
					normal.mostrarcola();
			break;
			
			default: cout << "\t---------- opcion no valida ----------\t";
			break;
						
	    }
	}while (opcion < 4);
		
	
	return 0;
}






