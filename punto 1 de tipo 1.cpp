//Desarrollo del punto 1 tipo 1

//Librerias
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class Parqueadero
{
	private: 
		int tope;
		int limit;
		string arr[];
		float hora[];
	public:
		void parquear(string, float);
		float liquidar(float);
		void sacar();
		int contarceldas(string);
		Parqueadero();
		bool parqueaderovacio();
		bool parqueaderolleno();
};

Parqueadero::Parqueadero()
{
	limit = 19;
	tope = -1;
	arr[limit];
	hora[limit];
}

bool Parqueadero::parqueaderovacio()
{
	if(tope==-1)
	{
		return true;	
	}
	else
	{
		return false;	
	}	
}

bool Parqueadero::parqueaderolleno()
{
	if(tope==limit)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Parqueadero::parquear(string vehiculo, float hora)
{
	if(parqueaderolleno==false)
	{
		tope++;
		arr[tope] = vehiculo;
		hora[tope] = hora;
		cout << "\a";
		cout << "¡Vehiculo parqueado correctamente!";
		system("pause");
	}
	else
	{
		cout << "\a";
		cout << "No se puede parquear, no hay celdas :(";
		system("pause");
	}
}

void Parqueadero::sacar(string vehiculo)
{
	int i;
	if(colavacia==false)
	{
		for(i=tope; i>=0; i--)
		{
			if(arr[i] == vehiculo)
			{
				
			}
		}
	}
}


