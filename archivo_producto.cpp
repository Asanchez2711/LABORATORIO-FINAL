#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "archivo_producto.h"


 int archivo_producto:: archivoProductoContar(){

    FILE *p=fopen("producto.dat", "rb");
    if(p==nullptr){
        return 0;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Producto);

 }

 Producto archivo_producto::leerProducto(int pos,Producto reg){



        reg.set_id(-1);
        FILE *p;
        p=fopen(_nombre.c_str(), "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof(Producto)*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
 }


 bool archivo_producto:: BorrarProducto(Producto reg, int pos){

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

 bool archivo_producto:: ModificarProducto(Producto reg,int pos){

FILE *p;
    p=fopen(_nombre.c_str(), "rb+");
    if(p==NULL){
        return false;
    }
    fseek(p,sizeof (Producto)*pos,0);
    bool escribio=fwrite(&reg,sizeof reg,1,p);
    fclose(p);
    return escribio;

 }

 bool archivo_producto:: GuardarProducto(Producto reg){

       FILE *p;
    p=fopen(_nombre.c_str(),"ab");
    if(p==NULL){
        return false;
    }
    bool escribio=fwrite(&reg,sizeof (Producto),1,p);
	fclose(p);
    return escribio;

 }


 bool archivo_producto:: ListarProductos(){

Producto reg;
    FILE *pAlu;
    pAlu=fopen(_nombre.c_str(), "rb");
    if(pAlu==NULL){
        return false;
    }
    while(fread(&reg,sizeof reg,1,pAlu)==1){
            if(reg.getEstado()!=false){
        reg.mostrar();
        cout<<endl;}
    }
    fclose(pAlu);
    return true;

 }


 int archivo_producto::BuscarIdProducto(int id){
Producto reg;

    FILE *p;
    p=fopen(_nombre.c_str(), "rb");
    int pos=0;
    if(p==NULL){
        return -2;
    }
    while(fread(&reg,sizeof reg,1,p)==1){
        if(id==reg.getId()){
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -1;
}


void archivo_producto::borrarProductoVoid(int posicion){

    int i;
    Producto reg;
    FILE *p;
    FILE *q;

    vector<Producto> vectorProducto;


    p=fopen(_nombre.c_str(), "rb+");
    fseek(p,1,SEEK_END);
    q=fopen("temp.dat", "ab+");

    for(i=0;i<sizeof(p)/sizeof (Producto);i++){
        if(i!=posicion){
            fread(&reg,sizeof (Producto),1,p);
            fwrite(&reg,sizeof (Producto),1,q);
        }



        }

    cout<<sizeof(p);
    cout<<sizeof(q);
 /*
    //remove(_nombre.c_str());
    //rename("temp.dat","producto.dat");
*/
}

Producto archivo_producto::LeerProductoBuscado(int nro){
    Producto reg;
    FILE *p=fopen("producto.dat", "rb");
    if(p==nullptr){
        return reg;
    }
    fseek(p, nro * sizeof(Producto), SEEK_SET);
    fread(&reg, sizeof(Producto), 1, p);
    fclose(p);
    return reg;
}
