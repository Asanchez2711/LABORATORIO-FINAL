#include "Vendedor.h"
#include"manager_vendedor.h"
#include "Venta.h"
#include "archivo_venta.h"

#include <iostream>
#include <limits>
#include <iomanip>




using namespace std;
void Vendedor_menu::MenuVendedor() {
    while (true) {
        cout << "BIENVENIDO AL MENU EMPLEADO" << endl;
        cout << endl;
        cout << "Indique la accion a realizar: " << endl;
        cout << endl;
        cout << "***************************" << endl;
        cout << "1-GUARDAR CLIENTE" << endl;
        cout << "2-BORRAR CLIENTE" << endl;
        cout << "3-LISTAR CLIENTES" << endl;
        cout << "4-BUSCAR CLIENTE" << endl;
        cout << "5-CARGAR COMPRA" << endl;
        cout << "6-VER IMPORTE COMISIONADO HASTA EL MOMENTO" << endl;
          cout << "7-LISTAR VENTAS" << endl;
        cout<<"8-EMPLEADO CON MAYOR RECAUDACION "<<endl;
        cout << "***************************" << endl;
        cout << "0-SALIR" << endl;

        int opcion;
        cout << ">>";
        cin >> opcion;
        system("cls");

        if (cin.fail() || opcion < 0 || opcion > 8) {
            cin.clear();  // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input

            cout << "Error: Opcion invalida. Ingrese un numero del 0 al 8." << endl;
            cout<<endl;
              system("pause");
        system("cls");
            continue;  // Restart the loop
        }
switch(opcion){

case 1:{
int legajo;
string legajos;
        cout<<"ESTA POR GUARDAR UN CLIENTE"<<endl;
        Cliente cliente;
        cout<<endl;
        cout<<"Ingrese el numero de legajo del cliente: "<<endl;
        cin>>legajos;
        while (esNumero(legajos))
        {
            cout<<"HA INGRESADO UN VALOR INVALIDO"<<endl;
            cout<<"INGRESE UN VALOR NUMERICO MAYOR A 0"<<endl;
            cin>>legajos;
        }
        legajo = stoi(legajos);

       archivo_cliente arch("cliente.dat");
      int cont= arch.BuscarIdCliente(legajo);

       if(cont<0){
        cliente.cargar(legajo);

        arch.GuardarCliente(cliente);}
        else{cout<<endl;cout<<"EL NUMERO DE CLIENTE CON ESE LEGAJO YA EXISTE"<<endl;
        cout<<endl;


        }
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
        cliente.setEstado(false);
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
archivo_empleado archEmpleado("empleado.dat");

Empleado objEmpleado;

int idEmpl,contar,pos,i;

contar = archEmpleado.archivoEmpleadoContar();


for(i=0;i<contar;i++){
    objEmpleado=archEmpleado.Leer(i);
    if(objEmpleado.getEstado()==true){
        objEmpleado.mostrar();
        cout<<endl<<"Y su comision es de: "<<objEmpleado.getTotalVendido()*0.10<<endl<<endl<<endl;
    }
}

/*

cout<<"La comision de que empleado quiere ver ? Ingrese ID Vendedor"<<endl;
cin>>idEmpl;

pos=archEmpleado.BuscarLegajoEmpleado(idEmpl,objEmpleado);

if(pos>=0){
  objEmpleado =archEmpleado.Leer(pos);
  papa=objEmpleado.getTotalVendido()*0.10;

}



        cout<<endl;
        cout<<"ESTE ES EL IMPORTE COMISIONADO HASTA EL MOMENTO POR CADA VENDEDOR: "<<papa<<endl;
        cout<<endl;

*/

    break;
   }


case 7:
{
    archivo_venta archvent;
    archvent.ListarVentas();

    break;
}



case 8:{

cout<<endl;

archivo_empleado archivito("empleado.dat");

int contar=archivito.archivoEmpleadoContar();
Empleado obj;
int c;

cout<<endl;
int maximo;
string name;

for(c=0;c<contar;c++){


    obj=archivito.Leer(c);
if(obj.getTotalVendido()>maximo){
maximo=obj.getTotalVendido();
name=obj.getNombre();

       }
}

cout<<"El vendedor que mas vendio historicamente fue : "<<name<<" un importe de : "<<maximo<<endl;
cout<<endl;


        system("pause");
        system("cls");


break;
}








default:
    return;
    break;
            }
        }
    }
bool Vendedor_menu::esNumero(string numero)
 {
     for (char cad : numero )
     {
         if(!isdigit(cad))
         {
             return true;
         }
     }

     return false;

 }

