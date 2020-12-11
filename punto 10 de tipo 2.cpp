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
		~Cola () {cout << "\n\n\nDestruyendo programa.\n\n\n";}
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
		cout << "\n\t Dato insertado\t" << endl;
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
		p = vect [i]; // 
		
		while (i <= tope)
		{
			vect [i] = vect [i+1];
			i ++;
		}
		
		tope--;
	}
	else
	{
		cout << "No hay datos para sacar.";
	}
	
	return p;
}

void Cola :: mostrarcola ()
{
	int desencolando_uno = 0, desencolando_dos = 0;
	Cola nueva = Cola (tam);
	
	if (colavacia() == true)
	{
		cout << "\tLa cola está vacia, no hay elementos para mostrar.\t\n";
	}
	else
	{
		while (colavacia() == false)
		{
			desencolando_uno = desencolar();
			cout << "\t     |"<< desencolando_uno <<"|\t";
			nueva.encolar(desencolando_uno);
		}
		
		cout << "\tRegresando datos a la pila normal.\n";// Regresamos los datos a la cola original
		
		while (colallena() == false)
		{
			desencolando_dos = nueva.desencolar();
			encolar(desencolando_dos);
		}
	}
}

int Cola :: numeroAleatorio ()
{
	
}

// Cambiar la funcion numero aleatorio para el main y no en la clase Cola....

int numeroAleatorio(int a, int b)
{
	return a + (rand() % b);
} // PARAMETRIZACIÓN

int numeroAleatorio(int, int);

main ()
{
	int tam = 0, j, rand;
	short opcion = 0;
	
	cout << "Digite la dimension de la cola aleatoria (esta tendra el mismo tamaño que la normal): ";
	cin >> tam;
	Cola aleatoria = Cola (tam);
	Cola normal = Cola (tam);
	srand((unsigned)time(0)); // Serie especifica de numeros aleatorios
	
	while (aleatoria.colallena() == false)
	{
		rand = numeroAleatorio (100,500);
		aleatoria.encolar(rand);
		cout << "\t     |"<< rand <<"|\t";
	}
	
	cout << "\n\n";
	
	do
	{
		cout << "\n";
		cout << "\t********** MENU **********\t\n";
		cout << "\t(1). Encolar desde la cola aleatoria\t\n";
		cout << "\t(2). Desencolar el dato aleatorio\t\n";
		cout << "\t(3). Mostrar cola normal\t\n";
		cout << "\t(4). Salir\t\n";
		cout << "\t opcion: ";
		cin >> opcion; cout << "\n";
		
		while ((opcion < 1) or (opcion>4))
		{
			cout << "\t Opcion incorrecta, inserte de nuevo una opcion valida: ";
			cin >> opcion;
		}
		
		switch (opcion)
		{
			case 1: cout << "\tTrayendo datos... " << endl;
					normal.encolar(aleatoria.desencolar());
					system ("pause");
					system ("cls");
			break;
			
			case 2: cout << "\tDesencolando... " << endl;
					normal.desencolar();
					system ("pause");
					system ("cls");
			break;
		
			case 3: cout << "\tMostrando cola..." << endl;
					normal.mostrarcola();
					system ("pause");
					system ("cls");
			break;						
	    }
	}while (opcion < 4);
		
	
	return 0;
}






