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
		void contarceldas();
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
	cout << "Parqueando";
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
		cout << "No se puede parquear, no hay celdas ";
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

void Parqueadero::contarceldas()
{
	int i, dispo = 0, ocup = 0;
	
	cout << "entrando a contar celdas";
	
	//sencillamente en este ciclo, se van contando los espacios, si es NULL, se va contanto en ocup (ocupados) y si no en dispo (disponibles
	for(i=0; i<limit; i++)
	{
		if(arr[i] != "\0")
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

int main()
{
	short opc;
	bool ctrl = true;
	string vehiculo;
	float hora, horasal;
	Parqueadero carro = Parqueadero();
	do
	{
		cout << "\a";
		cout << "***********MENU************" << endl;
		cout << "|(1) Para parquear         |" << endl;
		cout << "|(2) Para sacar un vehiculo|" << endl;
		cout << "|(3) Para contar celdas    |" << endl;
		cout << "|(4) Acabar jornada        |" << endl;
		cout << "****************************" << endl;
		cout << "Elija una opcion: "; cin >> opc;
		while((opc < 1) || (opc > 4))
		{
			cout << "\a";
			cout << "Opcion no valida, intente otra vez: "; cin >> opc;
		}
		
		switch(opc)
		{
			case 1: 
					cout << "Ingrese el vehiculo a parquear: "; cin >> vehiculo; fflush(stdin);
					cout << "\n";
					cout << "Ingrese la hora a la que entro: "; cin >> hora; fflush(stdin);
					carro.parquear(vehiculo, hora);
					
					break;	
			case 2: 
					cout << "Ingrese la hora de salida: "; cin >> horasal; fflush(stdin);
					carro.sacar(horasal);
					system("pause");
					system("cls");
					break;
			case 3: 
					carro.contarceldas();		
					system("pause");
					system("cls");
					break;
			case 4: 
					ctrl = false;
					EXIT_SUCCESS;
		}
	}while(ctrl==true);
	
	return 0;
	
}


