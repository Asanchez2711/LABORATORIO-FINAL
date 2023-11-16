#include <limits>

#include "Fecha.h"

using namespace std;


void Fecha::AgregarDia()
{

    if(_dia+1>31){
        _dia=1;
        _mes=_mes+1;
    } else if(_dia+1>28 && _mes==2 && _anio%4!=0){
        _dia=1;
        _mes=3;
    } else if(_dia+1>29 && _mes==2){
        _dia=1;
        _mes=3;
    } else if((_dia+1>30 && _mes==4)||(_dia+1>30 && _mes==6)||(_dia+1>30 && _mes==9)||(_dia+1>30 && _mes==11)){
        _dia=1;
        _mes=_mes+1;
    } else if (_dia==31 && _mes==12){
        _dia=1;
        _mes=1;
        _anio=_anio+1;
    } else {
    _dia=_dia+1;
    }


}

void Fecha::RestarDia()
{
    if(_dia-1==0 && _mes-1==0){
        _dia=31;
        _mes=12;
        _anio=_anio-1;
    } else if((_dia-1==0 && _mes==5)||(_dia-1==0 && _mes==7)||(_dia-1==0 && _mes==10)||(_dia-1==0 && _mes==12)){
        _dia=30;
        _mes=_mes-1;
    } else if((_dia-1==0 && _mes==2)||(_dia-1==0 && _mes==4)||(_dia-1==0 && _mes==6)||(_dia-1==0 && _mes==8)||(_dia-1==0 && _mes==9)||(_dia-1==0 && _mes==11)){
        _dia=31;
        _mes=_mes-1;
    } else if(_dia-1==0 && _mes==3 && _anio%4==0){
        _dia=29;
        _mes=2;
    } else if(_dia-1==0 && _mes==3 && _anio%4!=0){
        _dia=28;
        _mes=2;
    } else {
      _dia=_dia-1;
    }

}

Fecha::Fecha()
{

}

Fecha::Fecha(int dia, int mes, int anio)
{   //if(dia%1==0 || mes%1==0 || anio%1==0){
       // _dia=1;
       // _mes=1;
       // _anio=2023;
   // } else
    if(dia<1 || dia>31){
        _dia=-1;
        _mes=1;
        _anio=2023;
    } else if(dia>28 && mes==2 && anio%4!=0) {
        _dia=-1;
        _mes=1;
        _anio=2023;
    } else if(dia>29 && mes==2){
        _dia=-1;
        _mes=1;
        _anio=2023;
    } else if((dia>30 && mes==4)||(dia>30 && mes==6)||(dia>30 && mes==9)||(dia>30 && mes==11)){
        _dia=-1;
        _mes=1;
        _anio=2023;
    } else if(mes<0 || mes>12){
        _dia=-1;
        _mes=1;
        _anio=2023;
    } else {
        _dia=dia;
        _mes=mes;
        _anio=anio;
    }

}

void Fecha::AgregarDias(int dias)
{
    int i,sumoresto=2;
    if(dias>0){
        sumoresto=1;
    } else if(dias<0){
        sumoresto=3;
    }
    if(sumoresto==1){
        for(i=0;i<dias;i++){
            this->AgregarDia();
        }
    }
    if(sumoresto==3){
        for(i=dias;i<0;i++){
            this->RestarDia();
        }
    }
}

string Fecha::toString() const
{
   string dia= to_string(_dia);
   string mes= to_string(_mes);
   string anio= to_string(_anio);
   string fechaString;

    if(_dia<10 ){
        dia="0"+dia;
    }
    if(_mes<10){
        mes="0"+mes;
    }
    fechaString=dia+"/"+mes+"/"+anio;

    return fechaString;
}

void Fecha::setDia(int dia)
{
    if(dia>0 || dia<32){
       _dia = dia;
    }

}
void Fecha::setMes(int mes)
{
    if(mes>0 || mes<13){
       _mes = mes;
    }
}

void Fecha::setAnio(int anio)
{
    _anio=anio;
}

int Fecha::getDia() const
{
    return _dia;
}

int Fecha::getMes() const
{
    return _mes;
}

int Fecha::getAnio() const
{
    return _anio;
}

void Fecha::cargar()
{
    int dia,mes,anio;

    cout<<"Ingrese dia: "<<endl;
    cin>>dia;
    while (cin.fail())
        {

            /*
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Valor invalido, ingrese solo numeros"<<endl;
            cout<<"Ingrese nuevamente el valor"<<endl;
            */

            //validarNumeros();
            cin>>dia;

        }
    cout<<"Ingrese mes: "<<endl;
    cin>>mes;
    while (cin.fail())
        {
            /*
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Valor invalido, ingrese solo numeros"<<endl;
            cout<<"Ingrese nuevamente el valor"<<endl;*/

            //validarNumeros();
            cin>>mes;

        }
    cout<<"Ingrese anio: "<<endl;
    cin>>anio;
    while (cin.fail())
        {
            /*
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Valor invalido, ingrese solo numeros"<<endl;
            cout<<"Ingrese nuevamente el valor"<<endl;*/

            //validarNumeros();
            cin>>anio;

        }

    if(dia<1 || dia>31){
        _dia=1;
        _mes=1;
        _anio=0;
    } else if(dia>28 && mes==2 && anio%4!=0) {
        _dia=1;
        _mes=1;
        _anio=0;
    } else if(dia>29 && mes==2){
        _dia=1;
        _mes=1;
        _anio=0;
    } else if((dia>30 && mes==4)||(dia>30 && mes==6)||(dia>30 && mes==9)||(dia>30 && mes==11)){
        _dia=1;
        _mes=1;
        _anio=0;
    } else if(mes<0 || mes>12){
        _dia=1;
        _mes=1;
        _anio=0;
    } else {
        _dia=dia;
        _mes=mes;
        _anio=anio;
    }

}

void Fecha::mostrar() const
{
    cout<<"El dia es: "<<_dia<<endl;
    cout<<"El mes es: "<<_mes<<endl;
    cout<<"El anio es: "<<_anio<<endl;
}

