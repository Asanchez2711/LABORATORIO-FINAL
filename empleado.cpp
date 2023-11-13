#include "Empleado.h"

//#COMENTO ESTA PARTE PORQUE FIGURA QUE NO ENCUENTRA "Empleado.h" en el directorio
//#PRUEBA
//#include "Empleado.h"
#include "Fecha.h"

using namespace std;

void Empleado::setTotalVendido(float totalVendido)
{
    _totalVendido=totalVendido;
}

float Empleado::getTotalVendido() const
{
    return _totalVendido;
}

void Empleado::mostrar() const
{
        cout<<"El Estado es: ";
        if(getEstado()==true){
            cout<<"Activo"<<endl;
        } else {
            cout<<"Inactivo"<<endl;
        }
        if(getEstado()==true){
        cout<<"El Legajo es: "<<getLegajo()<<endl;
        cout<<"El nombre es: "<<getNombre()<<endl;
        cout<<"El apellido es: "<<getApellido()<<endl;
        cout<<"La Fecha de Alta es: "<<getFechaDeAlta().toString()<<endl;
        cout<<"El total vendido hasta la fecha es: "<<_totalVendido<<endl;
       } else {
        cout<<"Producto ya no se encuentra"<<endl;
        }
}

void Empleado::SetEliminado(bool eliminado){
    _eliminado=eliminado;
}

bool Empleado::GetEliminado()const{
    return _eliminado;
}

Empleado::Empleado(){
_eliminado=false;
}
