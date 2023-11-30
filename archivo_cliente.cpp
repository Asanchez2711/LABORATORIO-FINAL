#include "archivo_cliente.h"

#include <iostream>
#include <string>




 int archivo_cliente:: archivoClienteContar(){

        FILE *p;
        p=fopen(_nombre.c_str(), "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Cliente);

 }

 Cliente archivo_cliente::leerCliente(int pos, Cliente reg){


        reg.setLegajo(-1);
        FILE *p;
        p=fopen(_nombre.c_str(), "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof(Cliente)*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
 }


 bool archivo_cliente:: BorrarCliente(Cliente reg, int pos){

    FILE *p;
    p=fopen(_nombre.c_str(), "rb+");///+ agrega al modo lo que le falta
    if(p==NULL){
        return false;
    }
    fseek(p,sizeof (reg)*pos,0);
    bool escribio=fwrite(&reg,sizeof (Cliente),1,p);
    fclose(p);
    return escribio;

 }

 bool archivo_cliente:: ModificarCliente(Cliente reg,int pos){

FILE *p;
    p=fopen(_nombre.c_str(), "rb+");
    if(p==NULL){
        return false;
    }
    fseek(p,sizeof (Cliente)*pos,0);
    bool escribio=fwrite(&reg,sizeof reg,1,p);
    fclose(p);
    return escribio;

 }

 bool archivo_cliente:: GuardarCliente(Cliente reg){

       FILE *p;
    p=fopen(_nombre.c_str(),"ab");
    if(p==NULL){
        return false;
    }
    bool escribio=fwrite(&reg,sizeof (Cliente),1,p);
	fclose(p);
    return escribio;

 }


 bool archivo_cliente:: ListarClientes(){

Cliente reg;
    FILE *pAlu;
    pAlu=fopen(_nombre.c_str(), "rb");
    if(pAlu==NULL){
        return false;
    }
    while(fread(&reg,sizeof (Cliente),1,pAlu)==1){
        if(reg.getEstado()==true){
        reg.Mostrar();

        cout<<endl;
        }
    }
    fclose(pAlu);
    return true;

 }


 int archivo_cliente::BuscarIdCliente(int id){
Cliente reg;

    FILE *p;
    p=fopen(_nombre.c_str(), "rb");
    int pos=0;
    if(p==NULL){
        return -2;
    }
    while(fread(&reg,sizeof reg,1,p)==1){
        if(id==reg.getLegajo() && reg.getEstado()==true){
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -1;
}


 int archivo_cliente::BuscarLegajoCliente(int legajo, Cliente reg){


    FILE *p;
    p=fopen(_nombre.c_str(), "rb");
    int pos=0;
    if(p==NULL){
        return -2;
    }
    while(fread(&reg,sizeof (Cliente),1,p)==1){
        if(legajo==reg.getLegajo() && reg.getEstado()==true){
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -1;
}

Cliente archivo_cliente::Leer(int pos)
{
    Cliente reg;
    FILE *p=fopen(_nombre.c_str(), "rb");
    if(p==nullptr){
        return reg;
    }
    fseek(p, pos * sizeof(Cliente), SEEK_SET);
    fread(&reg, sizeof(Cliente), 1, p);
    fclose(p);
    return reg;
}
