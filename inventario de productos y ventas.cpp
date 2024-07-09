#include <iostream>
#include <string>
using namespace std;

struct Producto 
{
	string nombre;
	float precio;   
};

struct Venta
{
	int idVenta;
	string producto;
	int cantidad;
	float precioTotal;
};

void agregarProducto(Producto inventario[], int &cantidadProductos)
{
    cout<<"Ingrese el nombre del producto: ";
    cin.ignore();
    getline(cin,inventario[cantidadProductos].nombre);
    cout<<"Ingrese precio del producto: ";
    cin>>inventario[cantidadProductos].precio;
    cantidadProductos++;

}

int main() 
{
    char opcion;
    const int productoTam= 100;
    const int ventaTam=100;
    int cantidadProductos = 2;
    int cantidadVentas = 0;
    Producto inventario[productoTam]={
    {"Papel",1.00}, {"Libros",10.00}	
	};
    Venta registroVentas[ventaTam];

    do {
        cout<<"\nINVENTARIO DE PRODUCTOS Y VENTAS\n"<<endl;
        cout<<"A. Agregar un nuevo producto\n";
        cout<<"B. Listar los productos registrados\n";
        cout<<"C. Buscar un producto por nombre\n";
        cout<<"D. Actualizar los datos de un producto\n";
        cout<<"E. Eliminar un producto\n";
        cout<<"F. Registrar una venta\n";
        cout<<"G. Listar las ventas realizadas\n";
        cout<<"H. Calcular el total de ventas realizadas\n";
        cout<<"S. Salir del programa\n";
        cout<<endl;
        cout<<"Elija una opcion: ";
		cin>>opcion;
		cout<<endl;
        switch(opcion)
		{
            case 'A': 
			{
				cout<<"\nAGREGAR PRODUCTO: "<<endl;
				agregarProducto(inventario, cantidadProductos);
                break;
            }
            default: 
			{
                cout << "\nOpcion invalida " << endl;
                break;
            }
        }       
	
    } while (opcion != 'S');

    return 0;
}
