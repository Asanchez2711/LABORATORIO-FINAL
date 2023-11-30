#include "Persona.h"
#include <cctype>


bool Persona::esSoloLetras(const char *cadena)
{
    for (int i = 0; cadena[i] != '\0'; ++i)
    {
        if (!isalpha(cadena[i]) && cadena[i] != ' ')
        {
            return false; // Se encontró un carácter que no es una letra ni un espacio
        }
    }
    return true; // Todos los caracteres son letras o espacios
}

void Persona::setLegajo(int legajo)
{
    _legajo=legajo;
}
void Persona::setNombre(string nombre)
{
    strcpy(_nombre, nombre.c_str());
}

void Persona::setApellido(string apellido)
{
    strcpy(_apellido, apellido.c_str());
}

void Persona::setFechaDeAlta(Fecha fechaDeAlta)
{
    _fechaDeAlta.cargar();
}

void Persona::setEstado(bool estado)
{
    _estado=estado;
}

int Persona::getLegajo() const
{
    return _legajo;
}

string Persona::getNombre() const
{
    return _nombre;
}

string Persona::getApellido() const
{
    return _apellido;
}

Fecha Persona::getFechaDeAlta() const
{
    return Fecha(_fechaDeAlta);
}

bool Persona::getEstado() const
{
    return _estado;
}


void Persona::cargar(int f) {
    _estado = true;

    _legajo = f;

    cout << "Ingrese nombre: " << endl;
    cin.ignore();
    cin.getline(_nombre, 30);

    while (!esSoloLetras(_nombre)) {
        cout << "Nombre invalido, ingrese solo letras (o 'T' para terminar)" << endl;
        cout << "Ingrese nuevamente el nombre: ";
        cin.getline(_nombre, 30);

        if (toupper(_nombre[0]) == 'T') {
            cout << "Carga de datos terminada por el usuario." << endl;
            return;
        }
    }

    cout << "Ingrese apellido: " << endl;
    cin.getline(_apellido, 30);

    while (!esSoloLetras(_apellido)) {
        cout << "Apellido invalido, ingrese solo letras (o 'T' para terminar)" << endl;
        cout << "Ingrese nuevamente el apellido: ";
        cin.getline(_apellido, 30);

        if (toupper(_apellido[0]) == 'T') {
            cout << "Carga de datos terminada por el usuario." << endl;
            return;
        }
    }

    cout << "Ingrese fecha de Alta de forma ordenada" << endl;
    _fechaDeAlta.cargar();

    while (_fechaDeAlta.getAnio() == 0) {
        cout << "La fecha ingresada no existe en el calendario, ingrese una fecha valida" << endl;
        _fechaDeAlta.cargar();
    }
}

void Persona::mostrar()
{

    cout<<"Legajo: "<<_legajo<<endl;
    cout<<"Nombre y apellido "<<_nombre<<" "<<_apellido<<endl;
    cout<<"Fecha de alta"<<_fechaDeAlta.toString()<<endl;

}

bool Persona::esNumero(string numero)
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

