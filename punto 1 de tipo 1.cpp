//Desarrollo del punto 1 tipo 1

//Librerias
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

using namespace std;

class Parqueadero
{
	private: 
		int tope;
		int limit;
		string arr[];
		int hora[];
	public:
		void parquear(string, float);
		//float liquidar(float); no es necesaria, pues en la funcion parquear ya se añadio el cobro
		void sacar(string, float);
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
	if(parqueaderolleno()==false)
	{
		tope++;
		cout << "Ingrese marca de vehiculo y modelo (sin espacios)"; cin >> vehiculo;
		arr[tope] = vehiculo;
		cout << "Ingrese la hora de entrada (hora militar)"; cin >> hora;
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

void Parqueadero::sacar(string vehiculo, float hora)
{
	int i, horasal, horafin, cobro, a;
	if(parqueaderovacio()==false)
	{
		for(i=tope; i>=0; i--)
		{
			if(arr[i] == vehiculo)
			{
				arr[i] = NULL; //aca se asigna un vacio en donde estaba el carro, para que quede vacio
				cout << "Ingrese la hora de salida de " << vehiculo; cin >> horasal;
				horafin = hora[i] - horasal;
				cobro = 0; 
				a = i; //la a se iguala a i, para que a tenga el valor de i, osea la hora, y se pueda manejar la i abajo
				//ciclo para calcular el precio del parqueo
				for(i=hora[a]; i<=horafin; i = i + 1000)
				{
					cobro = cobro + 1000;
				}
				hora[a] = NULL; 
				cout << "Lo que debe pagar es " << cobro << " vuelva pronto!";
			}
			else
			{
				cout << "\a";
				cout << "Ese vehiculo no ha entrado";
			}
		}
	}
	else
	{
		cout << "\a";
		cout << "No hay vehiculos, espere clientela"; 
	}
}

int Parqueadero::contarceldas(string arr[])
{
	int i, dispo = 0, ocup = 0;
	
	//sencillamente en este ciclo, se van contando los espacios, si es NULL, se va contanto en ocup (ocupados) y si no en dispo (disponibles
	for(i=0; i<19; i++)
	{
		if(arr[i] == NULL)
		{
			ocup++;
		}
		else
		{
			dispo++;
		}
	}
	cout << "\a";
	cout << "Hay " << ocup << "celdas ocupadas";
	cout << "Hay " << dispo << "celdas disponibles";
}


