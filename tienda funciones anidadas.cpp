#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

const int num=5;
struct infoProducto{
	string caducidad;
	char tamano[20];
	int cantidad;
};

struct producto{
	int clave;
	char nombre[15];
	struct infoProducto datosProducto;
	double precio;
}productos[num];

void menu();
void agregarProducto();
void bodega();
int buscarLugarVacio();

int main()
{
	int opcion;
	
	do{
		menu();
		cin>>opcion;
		
		switch(opcion)
		{
			case 1:
				agregarProducto();
				break;
			case 2:
				bodega();
				break;
			case 3:
				cout<<"Gracias por utulizar el programa."<<endl;
				break;
			default:
				cout<<"Opcion no valida";
				break;
		}
			
	}while(opcion != 3);
	
	getch();
	return 0;
}

void menu(){
	cout<<"Bienvenido "<<endl;
	cout<<"1.Agregar productos"<<endl;
	cout<<"2.Ver productos disponibles"<<endl;
	cout<<"3. Salir"<<endl;
	cout<<"Ingresar la operacion que desea realizar: ";
}

void bodega()
{
	cout << endl;
    cout << setw(6) << "CLAVE"
            << setw(35) << "NOMBRE"
            << setw(25) << "TAMANO"
            << setw(15) << "CADUCIDAD"
            << setw(25) << "CANTIDAD"
            << setw(7) << "PRECIO" << endl;
    for (int i = 0; i < num; i++) {
        if (productos[i].clave != 0) {
            cout << setw(6) << productos[i].clave
                    << setw(35) << productos[i].nombre
                    << setw(25) << productos[i].datosProducto.tamano
                    << setw(15) << productos[i].datosProducto.caducidad
                    << setw(25) << productos[i].datosProducto.cantidad
                    << setw(7) << productos[i].precio<<endl;
        }
    }
}

void agregarProducto(){
	int lugarVacio;
	lugarVacio=buscarLugarVacio();
	if(lugarVacio==-1){
		cout<<"\nYa no hay lugar disponible. "<<endl;
		return;
	}
	fflush(stdin);
	cout<<"\nIngresar clave del producto: "; cin>>productos[lugarVacio].clave;
	fflush(stdin);
	cout<<"\nIngresar nombre del producto: "; cin.getline(productos[lugarVacio].nombre,15,'\n');
	cout<<"Ingresar precio del producto: "; cin>>productos[lugarVacio].precio;
	fflush(stdin);
	cout<<"\nIngresar cantidad del producto: "; cin>>productos[lugarVacio].datosProducto.cantidad;
	fflush(stdin);
	cout<<"\nIngresar tamano del producto: "; cin.getline(productos[lugarVacio].datosProducto.tamano,20,'\n');
	cout<<"\nIngresar caducidad del producto: "; getline(cin,productos[lugarVacio].datosProducto.caducidad);
	cout<<"\n";
	
}

int buscarLugarVacio(){
	
	for(int i=0; i<num; i++)
	{
		if(productos[i].clave == 0)
		{
			return i;
		}
	}
	return -1;
	
}
