#include <iostream>
#include <limits>
using namespace std;


#include "aplicacion.h"

void Aplicacion::MenuApp(){
while(true){
cout<<"*****************"<<endl;
cout<<"*******APP*******"<<endl;
cout<<"*****************"<<endl;
cout<<"-1 ADMINISTRADOR"<<endl;
cout<<"-2 VENDEDOR "<<endl;
cout<<"*****************"<<endl;
cout<<"-0 SALIR DEL PROGRAMA"<<endl;
int opcion;
cout<<">>";
cin>>opcion;
    do {
        // Verificar si la entrada es un número entero
        if (std::cin.fail()) {
            std::cin.clear();  // Limpiar el estado de error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Descartar la entrada no válida
            std::cout << "Entrada no valida. Por favor, ingrese un numero entero.\n";
            system("pause");
            system("cls");
            continue;  // Volver al inicio del bucle
        }

        // Verificar si la entrada está en el rango deseado
        if (opcion < 0 || opcion > 2) {
            std::cout << "Opcion no valida. Debe estar entre 0 y 2.\n";
            system("pause");
            system("cls");
        }


switch(opcion){

case 0:
    return;
    break;
case 1:
    {
    system("cls");
    _admin.MenuAdmin();
    }
    break;
case 2:
    system("cls");
    _vendedor.MenuVendedor();
    break;
      }
   } while (opcion < 0 || opcion > 2);
  }

}




