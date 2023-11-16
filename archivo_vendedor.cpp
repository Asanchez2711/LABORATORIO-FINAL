#include "archivo_vendedor.h"
#include "empleado.h"

int archivo_empleado:: archivoEmpleadoContar(){

        FILE *p;
        p=fopen(_nombre.c_str(), "rb");
        if(p==NULL) return -1;
        fseek(p, 0,SEEK_END);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Empleado);

 }

 Empleado archivo_empleado::leerEmpleado(int pos, Empleado reg){


        reg.setLegajo(-1);
        FILE *p;
        p=fopen(_nombre.c_str(), "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof(Empleado)*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
 }


 bool archivo_empleado:: BorrarEmpleado(Empleado reg, int pos){

    FILE *p;
    p=fopen(_nombre.c_str(), "rb+");///+ agrega al modo lo que le falta
    if(p==NULL){
        return false;
    }
    fseek(p, pos * sizeof (reg),0);
    bool escribio=fwrite(&reg,sizeof reg,1,p);
    fclose(p);
    return escribio;

 }

 bool archivo_empleado:: ModificarEmpleado(Empleado reg,int pos){

    FILE *p;
    p=fopen(_nombre.c_str(), "rb+");
    if(p==NULL){
        return false;
    }
    fseek(p,sizeof (Empleado)*pos,0);
    bool escribio=fwrite(&reg,sizeof reg,1,p);
    fclose(p);
    return escribio;

 }

  bool archivo_empleado:: GuardarEmpleado(Empleado reg){

    FILE *p;
    p=fopen(_nombre.c_str(),"ab");
    if(p==NULL){
        return false;
    }
    bool escribio=fwrite(&reg,sizeof (Empleado),1,p);
	fclose(p);
    return escribio;

 }

 bool archivo_empleado:: ListarEmpleados(){

Empleado reg;

    FILE *pAlu;
    pAlu=fopen(_nombre.c_str(), "rb");
    if(pAlu==NULL){
        return false;
    }
    while(fread(&reg,sizeof reg,1,pAlu)==1){
if(reg.getEstado()==true){
        reg.mostrar();
        cout<<"************************************"<<endl;
        cout<<endl;
    }}
    fclose(pAlu);
    return true;

 }

int archivo_empleado::BuscarLegajoEmpleado(int legajo, Empleado reg){


    FILE *p;
    p=fopen(_nombre.c_str(), "rb");
    int pos=0;
    if(p==NULL){
        return -2;
    }
    while(fread(&reg,sizeof reg,1,p)==1){
        if(legajo==reg.getLegajo()){
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -1;
}

int archivo_empleado::BuscarEmpleadoenArchivo(int codigo){
    Empleado reg;
    int i=0;
    FILE *p=fopen(_nombre.c_str(), "rb");
    if(p==nullptr){
        return -1;
    }
    while(fread(&reg, sizeof(Empleado), 1, p)==1)
    {
        if(reg.getLegajo()==codigo){
            fclose(p);
            return i;
        }
        i++;
    }

    return -1;
}

Empleado archivo_empleado::Leer(int nroRegistro){
    Empleado reg;
    FILE *p=fopen(_nombre.c_str(), "rb");
    if(p==nullptr){
        return reg;
    }
    fseek(p, nroRegistro * sizeof(Empleado), SEEK_SET);
    fread(&reg, sizeof(Empleado), 1, p);
    fclose(p);
    return reg;

}

