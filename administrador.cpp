#include <iostream>
using namespace std;

#include "administrador.h"

int VerificaNumero(){

        // Verificar si la entrada es un número entero
        int opcion;
        while(true){
        std::cout<<">>";
        while (!(std::cin>>opcion) || std::cin.peek() != '\n') {
            std::cin.clear();  // Limpiar el estado de error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Descartar la entrada no válida
            std::cout << "Entrada no valida. Por favor, ingrese un numero entero.\n";

            std::cout << ">>";
        }

        // Verificar si la entrada está en el rango deseado
        if (opcion < 0 || opcion > 12) {
            std::cout << "Opcion no valida. Debe estar entre 0 y 12.\n";

            continue;  // Volver al inicio del bucle

        }
        return opcion;
      }
}

void Admin::MenuAdmin(){

while(true){
    cout<<"Bienvenido admin"<<endl;
    cout<<endl;
    cout<<"Indique la accion a realizar: "<<endl;
    cout<<endl;
    cout<<"***************************"<<endl;
    cout<<"Bienvenido al menu de gestion"<<endl;
    cout<<"***************************"<<endl;
    cout<<"1-DAR DE ALTA UN PRODUCTO"<<endl;
    cout<<"2-DAR DE ALTA UN VENDEDOR"<<endl;
    cout<<"3-DAR DE BAJA UN PRODUCTO"<<endl;
    cout<<"4-DAR DE BAJA UN VENDEDOR"<<endl;
    cout<<"5-VER IMPORTE TOTAL RECAUDADO"<<endl;
    cout<<"6-VER IMPORTE RECAUDADO POR VENDEDOR"<<endl;
    cout<<"7-MODIFICAR UN PRODUCTO"<<endl;
    cout<<"8-MODIFICAR UN VENDEDOR"<<endl;
    cout<<"9-LISTAR PRODUCTOS"<<endl;
    cout<<"10-LISTAR VENDEDORES"<<endl;
    cout<<"11-BUSCAR VENDEDOR"<<endl;
    cout<<"12-BUSCAR PRODUCTO"<<endl;
    cout<<"***************************"<<endl;
    cout<<"0-VOLVER"<<endl;

    int op = VerificaNumero();

    system("cls");
    switch(op){

case 1:
    _manager.Cargar();
    system("pause");
    system("cls");
    break;

case 2:
    {
    _managerVendedor.CargarVendedor();
    system("cls");
    }
    break;

case 3:
    _manager.EliminarArticulo();
    system("pause");
    system("cls");
    break;


case 4:
    _managerVendedor.EliminarVendedor();
    system("pause");
    system("cls");
    break;

case 5:
    ///PARA SOLUCIONAR
    _managerVendedor.TotalRecaudado();
    system("pause");
    system("cls");


    break;

case 6:
    _managerVendedor.TotalRecaudadoXVendedor();
    system("pause");
    system("cls");
    break;


case 7:

    _manager.ModificarProducto();
    system("pause");
    system("cls");
    break;

case 8:

    _managerVendedor.ModificarVendedor();
    system("pause");
    system("cls");
    break;


case 9:
    _manager.ListarProductos();
    system("pause");
    system("cls");
    break;

case 10:
    _managerVendedor.ListarVendedores();
    system("pause");
    system("cls");
    break;

case 11:
    _managerVendedor.BuscarVendedor();
    system("pause");
    system("cls");
    break;

case 12:
    _manager.BuscarXID();
    system("pause");
    system("cls");
    break;

default:
    return;
    break;
        }
    }
}
