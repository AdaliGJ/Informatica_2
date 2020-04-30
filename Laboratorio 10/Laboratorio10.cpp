#include <iostream>
#include <vector> 

using namespace std;

/*
Laboratorio #10
Jeremy Cáceres y Adalí Garrán
*/

//Struct auxiliar para representar la eficiencia del avión dentro de cada rango de altura
struct RangEfi{
  int AltMin;
  int AltMax;
  float efi;
};


//Tarea #1
class Avion{
    
    public:
    
    //Se inicia el avión con velocidad y altura 0
    Avion(){
        velocidad = 0;
        altura = 0;
    }
    
    
    //Método para aumentar la velocidad si esta no supera la velocidad máxima del avión
    bool acelerar(int a){
        int nuevaVelocidad = velocidad + a;
        if(nuevaVelocidad > vMax){
            return false;
        }
        else{
            velocidad = nuevaVelocidad;
            return true;
        }
    }
    
    
    //Método para cambiar de altura por la ingresada si esta no es mayor a la altura máxima del avión
    bool ascender (int altitud){
        if(altitud>aMax){
            return false;
        }
        else{
            altura = altitud;
            
            for(int i = 0; i<rangos.size(); i++){
                if(altura>=rangos[i].AltMin && altura<=rangos[i].AltMax){
                    eficiencia = rangos[i].efi;
                    break;
                }
            }
            
            return true;
        }
    }
    

    //Método para obtener el consumo del avión que es igual a la eficiencia por la velocidad
    float getConsumoActual(){
        float consumo = eficiencia*velocidad;
        return consumo;
    }
    
    //getters (para pruebas)
    float getEfi(){
        return eficiencia;
    }
    
    vector<RangEfi> getRangos(){
        return rangos;
    }
    
    int getAltura(){
        return altura;
    }
    
    int getVelocidad(){
        return velocidad;
    }
    
    
    protected:
    vector<RangEfi> rangos;//Vector con los rangos de altura y las eficiencias que le corresponden
    float eficiencia;
    int vMax;
    int aMax;
    
    private:
    int velocidad;
    int altura;
};


//Tarea #2
class Concorde: public Avion{
    
    public:
    Concorde(): Avion(){
        //Se establecen los parámetros específicos del concorde
        vMax = 2350;
        aMax = 60000;
        eficiencia = 4;
        
        RangEfi r1; r1.AltMin=0; r1.AltMax=29999; r1.efi=4;
        RangEfi r2; r2.AltMin=30000; r2.AltMax=39999; r2.efi=2;
        RangEfi r3; r3.AltMin=40000; r3.AltMax=49999; r3.efi=1.5;
        RangEfi r4; r4.AltMin=50000; r4.AltMax=60000; r4.efi=1.0;
        
        rangos.push_back(r1);
        rangos.push_back(r2);
        rangos.push_back(r3);
        rangos.push_back(r4);
    }
};


class A320: public Avion{
    
    public:
    A320(): Avion(){
        //Se establecen los parámetros específicos del A320
        vMax = 950;
        aMax = 40000;
        eficiencia =2;
        
        RangEfi r1; r1.AltMin=0; r1.AltMax=19999; r1.efi=2;
        RangEfi r2; r2.AltMin=20000; r2.AltMax=29999; r2.efi=1.3;
        RangEfi r3; r3.AltMin=30000; r3.AltMax=40000; r3.efi=1;
        
        rangos.push_back(r1);
        rangos.push_back(r2);
        rangos.push_back(r3);
        
    }
};


class EMB130: public Avion{
    
    public:
    EMB130(): Avion(){
        //Se establecen los parámetros específicos del EMB130
        vMax = 500;
        aMax = 30000;
        eficiencia = 1.7;
        
        RangEfi r1; r1.AltMin=0; r1.AltMax=4999; r1.efi=1.7;
        RangEfi r2; r2.AltMin=5000; r2.AltMax=14999; r2.efi=1.2;
        RangEfi r3; r3.AltMin=15000; r3.AltMax=30000; r3.efi=1;
        
        rangos.push_back(r1);
        rangos.push_back(r2);
        rangos.push_back(r3);
        
    }
    
};

int main(){
    
    //Realización de pruebas
    Concorde c;
    c.ascender(39999);
    c.acelerar(20);
    cout<<"La velocidad actual del concorde es de "<<c.getVelocidad()<<" km/h"<<endl;
    cout<<"El consumo actual del concorde es: "<<c.getConsumoActual()<<endl;
    printf("La eficiencia del concorde a %i pies de altura es de %f\n", c.getAltura(),c.getEfi());
    
    A320 a;
    a.ascender(31000);
    a.acelerar(78);
    cout<<"La velocidad actual del A320 es de "<<a.getVelocidad()<<" km/h"<<endl;
    cout<<"El consumo actual del A320 es: "<<a.getConsumoActual()<<endl;
    printf("La eficiencia del A320 a %i pies de altura es de %f\n", a.getAltura(),a.getEfi());
    
    EMB130 e;
    e.ascender(12000);
    e.acelerar(7800000);
    cout<<"La velocidad actual del EMB130 es de "<<e.getVelocidad()<<" km/h"<<endl;//no aumenta porque se excede de la máxima
    e.acelerar(500);
    cout<<"La velocidad actual del EMB130 es de "<<e.getVelocidad()<<" km/h"<<endl;
    cout<<"El consumo actual del EMB130 es: "<<e.getConsumoActual()<<endl;
    printf("La eficiencia del EMB130 a %i pies de altura es de %f\n", e.getAltura(),e.getEfi());
    
    return 0;
}