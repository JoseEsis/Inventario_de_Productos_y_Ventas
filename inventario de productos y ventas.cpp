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
void listarProductos(Producto inventario[], int &cantidadProductos)
{
	for(int i=0; i<cantidadProductos; i++)
	{
		cout<<i+1<<"| Nombre: "<<inventario[i].nombre<<endl;
		cout<<"   Precio: "<<inventario[i].precio<<endl;		
		
	}
}
void buscarProducto(Producto inventario[], int &cantidadProductos)
{

	string nombreProducto;
	cout<<"Ingrese el nombre del producto: ";
    cin.ignore();
	getline(cin, nombreProducto );
	for(int i=0; i<cantidadProductos; i++)
	{
		if(inventario[i].nombre==nombreProducto)
		{
			cout<<"\nProducto encontrado"<<endl;
			cout<<"Nombre: "<<inventario[i].nombre<<endl;
			cout<<"Precio: "<<inventario[i].precio<<endl;
			break;
		}
	}
		
}
void actualizarProducto(Producto inventario[], int &cantidadProductos)
{
	string nombreActualizar;
    cout<<"Ingrese el nombre del producto a actualizar: ";
    cin.ignore();
    getline(cin, nombreActualizar);
    
    for (int i = 0; i < cantidadProductos; ++i) 
	{
        if (inventario[i].nombre == nombreActualizar) 
		{
            cout << "Ingrese el nuevo nombre del producto: ";
            getline(cin, inventario[i].nombre);
            cout << "Ingrese el nuevo precio del producto: ";
            cin >> inventario[i].precio;
            cout << "Producto actualizado correctamente.\n";
            break;  
        }
    }
}
void eliminaProducto(Producto inventario[], int &cantidadProductos, string &nombreEliminar)
{
	for (int i=0; i <cantidadProductos; i++)
	{
        if (inventario[i].nombre == nombreEliminar) 
		{
            for (int j=i; j<cantidadProductos-1; j++)
			{
                inventario[j] = inventario[j + 1];
            }
            cantidadProductos--;
            cout << "Producto eliminado." << endl;
            break;
        }
    }
}
void registrarVenta(Venta registroVentas[], int &cantidadVentas, Producto inventario[], int cantidadProductos) 
{
    cout<<"Ingrese el idVenta: ";
    cin>>registroVentas[cantidadVentas].idVenta;
    cin.ignore();
    cout <<"Ingrese el nombre del producto: ";
    getline(cin, registroVentas[cantidadVentas].producto);

    for (int i=0; i<cantidadProductos; i++)
	{
        if (inventario[i].nombre == registroVentas[cantidadVentas].producto) 
		{
            cout<<"Ingrese la cantidad: ";
            cin>>registroVentas[cantidadVentas].cantidad;
            registroVentas[cantidadVentas].precioTotal=registroVentas[cantidadVentas].cantidad*inventario[i].precio;
			cout<<"El precio total es: "<< registroVentas[cantidadVentas].precioTotal<< endl;
			cout<<"Venta registrada.\n";
			cantidadVentas++;
            break;
        }
    } 
}
void listarVenta(Venta registroVentas[], int &cantidadVentas)
{
	for(int i=0; i <cantidadVentas; i++)
    {
        cout<<i+1<< " | idVenta: " << registroVentas[i].idVenta<<endl;
        cout<<"Producto: "<<registroVentas[i].producto<<endl;
        cout<<"Cantidad: "<<registroVentas[i].cantidad<<endl;
        cout<<"precio total: "<<registroVentas[i].precioTotal<<endl;
    }
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
            case 'B': 
			{
				cout<<"\nLISTA DE LOS PRODUCTOS REGISTRADOS: "<<endl;
               	listarProductos(inventario, cantidadProductos);
                break;
            }
            case 'C': 
			{
				cout<<"\nBUSCAR PRODUCTO: "<<endl;
				buscarProducto(inventario, cantidadProductos);               
                break;
            }
            case 'D': 
			{
				cout<<"\nACTUALIZAR PRODUCTO: "<<endl;
				actualizarProducto( inventario, cantidadProductos);
                break;
            }
            case 'E': 
			{
				cout << "\nELIMINAR UN PRODUCTO: " << endl;
                string nombreEliminar;
                cout << "Ingrese el nombre del producto: ";
				cin.ignore();
                getline(cin, nombreEliminar);
                eliminaProducto(inventario, cantidadProductos, nombreEliminar);
				break;    			
            }
            case'F':
            {
            	cout<<"\nREGISTRAR UNA VENTA: "<<endl;
				registrarVenta(registroVentas, cantidadVentas,  inventario, cantidadProductos); 
            	
            	break;
			}
			case 'G':
			{
				cout<<"\nLISTAR REGISTRO DE VENTAS: "<<endl;
				if(cantidadVentas==0){
					cout<<"\nNo hay una venta registrada."<<endl;
				}
				else
				{
					listarVenta( registroVentas,cantidadVentas);
				}
				
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
