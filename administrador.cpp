#include <iostream>
using namespace std;

#include "administrador.h"

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
    int opcion;
    cout<<">>";
    cin>>opcion;
    system("cls");
    switch(opcion){

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
    ///FIX
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
    break;

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
