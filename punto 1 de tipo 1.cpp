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
		float hora[];
	public:
		void parquear(string, float);
		void sacar(float);
		void contarceldas(string);
		Parqueadero();
		bool parqueaderovacio();
		bool parqueaderolleno();
		/*void setArr(string*, int);
		void setHora(int*, int);
		string getArr(int);
		int getHora(int);*/
	
};

/*void Parqueadero::setArr(string carrosen[], int i)
{
	arr[i] = carrosen[i];
}

void Parqueadero::setHora(int horasen[], int i)
{
	hora[i] = horasen[i];
}

string Parqueadero::getArr(int i)
{
	return arr[i];
}

int Parqueadero::getHora(int i)
{
	return hora[i];
}
*/


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

void Parqueadero::parquear(string vehiculo, float horas)
{
	if(parqueaderolleno()==false)
	{
		tope++;
		arr[tope] = vehiculo;
		hora[tope] = horas;
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

void Parqueadero::sacar(float horasal)
{
	int horafin, var=tope;
	string p;
	float horas;
	
	if(parqueaderovacio()==false)
	{
		p = arr[var];
		horas = hora[var];
		
		while(var>=0)
		{
			arr[var] = arr[var-1];
			hora[var] = hora[var-1];
			var--;
		}
		tope--;
		horafin = horasal - horas;
		horafin = horafin*1500;
		cout << "Su liquidacion es de: " << horafin;
			
	}
	else
	{
		cout << "\a";
		cout << "No hay vehiculos, espere clientela"; 
	}
}

void Parqueadero::contarceldas(string arr)
{
	int i, dispo = 0, ocup = 0;
	
	//sencillamente en este ciclo, se van contando los espacios, si es NULL, se va contanto en ocup (ocupados) y si no en dispo (disponibles
	for(i=0; i<limit; i++)
	{
		if(arr[i] != '\0')
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

//Parqueadero carro = Parqueadero ();  pa hacer un carrito
//carro.parquear(); para hacer en el main


