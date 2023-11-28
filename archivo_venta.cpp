#include "archivo_venta.h"
#include "archivo_vendedor.h"
#include <iostream>
#include <string>

archivo_venta::archivo_venta()
{
  _nombre = "Ventas.dat";

}

int archivo_venta:: archivoVentaContar(){

        FILE *p;
        p=fopen(_nombre.c_str(), "rb");
        if(p==NULL) return -1;
        fseek(p, 0,SEEK_END);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Venta);

 }

 Venta archivo_venta::leerVenta(int pos, Venta reg){


        reg.setidVenta(-1);
        FILE *p;
        p=fopen(_nombre.c_str(), "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof(Venta)*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
 }



 bool archivo_venta::BorrarVenta(Venta reg, int pos){

    FILE *p;
    p=fopen(_nombre.c_str(), "rb+");///+ agrega al modo lo que le falta
    if(p==NULL){
        return false;
    }
    fseek(p,sizeof (reg)*pos,0);
    bool escribio=fwrite(&reg,sizeof reg,1,p);
    fclose(p);
    return escribio;

 }

 bool archivo_venta::ModificarVenta (Venta reg,int pos){

    FILE *p;
    p=fopen(_nombre.c_str(), "rb+");
    if(p==NULL){
        return false;
    }
    fseek(p,sizeof (Venta)*pos,0);
    bool escribio=fwrite(&reg,sizeof reg,1,p);
    fclose(p);
    return escribio;

 }

  bool archivo_venta:: GuardarVenta(Venta reg){

       FILE *p;
    p=fopen(_nombre.c_str(),"ab");
    if(p==NULL){
        return false;
    }
    bool escribio=fwrite(&reg,sizeof (Venta),1,p);
	fclose(p);
    return escribio;

 }

 bool archivo_venta::ListarVentas(){

Venta reg;

    FILE *pAlu;
    pAlu=fopen(_nombre.c_str(), "rb");
    if(pAlu==NULL){
        return false;
    }
    while(fread(&reg,sizeof reg,1,pAlu)==1){

        reg.mostrarVenta();
        cout<<endl;
    }
    fclose(pAlu);
    return true;

 }

int archivo_venta::BuscarIdVenta(int id, Venta reg){


    FILE *p;
    p=fopen(_nombre.c_str(), "rb");
    int pos=0;
    if(p==NULL){
        return -2;
    }
    while(fread(&reg,sizeof reg,1,p)==1){
        if(id==reg.getidVenta()){
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -1;
}
