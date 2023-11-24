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
int legajo;

    std::cout << "ESTA POR GUARDAR UN CLIENTE" << std::endl;
    Cliente cliente; // Asegúrate de tener la clase Cliente definida

    do {
        std::cout << "Ingrese el numero de legajo del cliente: ";
        std::cin >> legajo;

        if (std::cin.fail() || legajo <= 0) {
            std::cin.clear(); // Limpiar el indicador de error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descartar la entrada incorrecta
            std::cout << "Por favor, ingrese un numero de legajo mayor a cero." << std::endl;
        } else {
            break; // Salir del bucle si la entrada es válida
        }
    } while (true);
        cliente.cargar(legajo);
        archivo_cliente arch("cliente.dat");
        arch.GuardarCliente(cliente);
        system("pause");
        system("cls");
        break;
}

case 2:{
    cout<<"ESTA POR BORRAR UN CLIENTE"<<endl;
        Cliente cliente;
        int contador =0;

        int legajo,i,posicion;
        archivo_cliente arch("cliente.dat");
        int cantidad=arch.archivoClienteContar();
        cout<<"Ingrese Legajo de cliente"<<endl;
        cin>>legajo;
        while(cin.fail()){
            if (std::cin.fail()) {
            std::cin.clear();  // Limpiar el estado de error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Descartar la entrada no válida
            std::cout << "Entrada no valida. Por favor, ingrese un numero entero.\n";
            cin>>legajo;


        }
        }
    posicion=arch.BuscarLegajoCliente(legajo,cliente);
    cliente=arch.leerCliente(posicion,cliente);

    if(cliente.getLegajo()==legajo&&(cliente.getEstado()==true)){
        cliente.mostrar();
        contador++;



    } else {
           if(contador==0){cout<<"No hay ningun cliente con el legajo "<<legajo<<endl;}
    }
       /*
       for(i=0;i<cantidad;i++){
            cliente=arch.leerCliente(i,cliente);
        if (cliente.getLegajo()==legajo){
            cout<<"Legajo ya existente";
            break;
        } else if (cliente.getLegajo()!=legajo && cantidad==i-1 ){
            cout<<"Legajo no existente";
            break;
        }

       }
    */
        for(i=0;i<cantidad;i++){
                cliente=arch.leerCliente(i,cliente);
                cliente.setEstado(false);
                if(legajo==cliente.getLegajo()){
                    arch.BorrarCliente(cliente,i);
                }
        }
        cout<<endl;
        cout<<"CLIENTE BORRADO"<<endl;
        cout<<endl;
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

    manager_vendedor v;
    v.buscarCliente();
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

