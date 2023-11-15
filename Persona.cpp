#include "Persona.h"

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

void Persona::cargar(int f)
{
    _estado=true;


    while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Valor invalido, ingrese solo numeros"<<endl;
            cout<<"Ingrese nuevamente el valor"<<endl;
            _legajo=f;

        }
    cout<<"Ingrese nombre: "<<endl;
    cin.ignore();
    cin.getline(_nombre, 30);
    cout<<"Ingrese apellido: "<<endl;
    cin.getline(_apellido, 30);
    cout<<"Ingrese fecha de Alta de forma ordenada"<<endl;
    _fechaDeAlta.cargar();
    while(_fechaDeAlta.getAnio()==0){
            cout<<"La fecha ingresada no existe en el calendario, ingrese una fecha valida"<<endl;
            _fechaDeAlta.cargar();
        }


}

void Persona::mostrar()
{

    cout<<"Legajo: "<<_legajo<<endl;
    cout<<"Nombre y apellido "<<_nombre<<" "<<_apellido<<endl;
    cout<<"Fecha de alta"<<_fechaDeAlta.toString()<<endl;

}
