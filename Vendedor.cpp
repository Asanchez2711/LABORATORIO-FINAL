#include "Vendedor.h"

using namespace std;
void Vendedor_menu::MenuVendedor(){

while(true){
cout<<"BIENVENIDO AL MENU EMPLEADO"<<endl;
cout<<endl;
cout<<"Indique la accion a realizar: "<<endl;
cout<<endl;
cout<<"***************************"<<endl;
cout<<"1-GUARDAR CLIENTE"<<endl;
cout<<"2-BORRAR CLIENTE"<<endl;
cout<<"3-LISTAR CLIENTES"<<endl;
cout<<"4-BUSCAR CLIENTE"<<endl;
cout<<"5-CARGAR COMPRA"<<endl;
cout<<"6-VER IMPORTE COMISIONADO HASTA EL MOMENTO"<<endl;
cout<<"***************************"<<endl;
cout<<"0-SALIR"<<endl;
int opcion;
cout<<">>";
cin>>opcion;
system("cls");
switch(opcion){

case 1:{

        cout<<"ESTA POR GUARDAR UN CLIENTE"<<endl;
        Cliente cliente;
        cliente.cargar();
        archivo_cliente arch("cliente.dat");
        arch.GuardarCliente(cliente);
        system("pause");
        system("cls");
        break;
}

case 2:{
    cout<<"ESTA POR BORRAR UN CLIENTE"<<endl;
        Cliente cliente;
        int legajo,i;
        archivo_cliente arch("cliente.dat");
        int cantidad=arch.archivoClienteContar();
        cout<<"Ingrese Legajo de cliente"<<endl;
        cin>>legajo;

        for(i=0;i<cantidad;i++){
                cliente=arch.leerCliente(i,cliente);
                cliente.setEstado(false);
                if(legajo==cliente.getLegajo()){
                    arch.BorrarCliente(cliente,i);
                }
        }
        system("pause");
        system("cls");
        break;
}

case 3:{
    archivo_cliente arch("cliente.dat");
    arch.ListarClientes();
    system("pause");
    system("cls");
    break;
}

case 4:{
    int legajo,posicion;
    archivo_cliente arch("cliente.dat");
    Cliente cliente;
    cout<<"Ingrese el legajo del cliente a buscar"<<endl;
    cin>>legajo;
    posicion=arch.BuscarLegajoCliente(legajo,cliente);
    cliente=arch.leerCliente(posicion,cliente);
    if(cliente.getLegajo()==legajo){
        cliente.mostrar();
    } else {
        cout<<"No hay ningun cliente con el legajo "<<legajo<<endl;
    }
    system("pause");
    system("cls");
    break;
}

case 5:
    {

        manager_vendedor management;

        management.CargarVenta();


        break;
    }

case 6:
    {
        archivo_venta archven;
        archven.ListarVentas();

        break;
    }


default:
    return;
    break;
            }
        }
    }

