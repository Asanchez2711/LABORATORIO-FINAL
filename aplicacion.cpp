#include <iostream>
#include <limits>
using namespace std;


#include "aplicacion.h"

void Aplicacion::MenuApp() {
    while (true) {
        std::cout << "*****************" << std::endl;
        std::cout << "*******APP*******" << std::endl;
        std::cout << "*****************" << std::endl;
        std::cout << "-1 ADMINISTRADOR" << std::endl;
        std::cout << "-2 VENDEDOR " << std::endl;
        std::cout << "*****************" << std::endl;
        std::cout << "-0 SALIR DEL PROGRAMA" << std::endl;
        int opcion;

        std::cout << ">>";
        // Verificar si la entrada es un número entero
        while (!(std::cin >> opcion) || std::cin.peek() != '\n') {
            std::cin.clear();  // Limpiar el estado de error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Descartar la entrada no válida
            std::cout << "Entrada no valida. Por favor, ingrese un numero entero.\n";
            std::cout << ">>";
        }

        // Verificar si la entrada está en el rango deseado
        if (opcion < 0 || opcion > 2) {
            std::cout << "Opcion no valida. Debe estar entre 0 y 2.\n";
            continue;  // Volver al inicio del bucle
        }

        switch (opcion) {
            case 0:
                return;
            case 1:
                system("cls");
                _admin.MenuAdmin();
                break;
            case 2:
                system("cls");
                _vendedor.MenuVendedor();
                break;
        }
    }
}




