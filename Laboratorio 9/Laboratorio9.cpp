#include <iostream>
#include <vector>

using namespace std;

/*
Laboratorio #9
Jeremy Cáceres y Adalí Garrán
*/

class LinkedList {

    public:
    
    LinkedList(){
    }
    
    int getValue() {
		return value;
	}
	LinkedList* getList() {
		return rest;
	}
    
    
    //El siguiente método se utilizará únicamente para hacer pruebas
    LinkedList l1 (int i, int j){
        value = i;
		rest = (LinkedList*)malloc(sizeof(LinkedList));
		rest->value = j;
		rest->rest = nullptr;
    }
    
    
    int longitud() {//cuenta la cantidad de elementos en una lista
        LinkedList* lista = (LinkedList*)malloc(sizeof(LinkedList));
        lista->value = value;
        lista->rest = rest;
	    int contador = 1;
	    if (lista->value == 0 && lista->rest == nullptr) {
		    return 0;
	    }
    	else {
		    while (lista->rest != nullptr) {
			    contador++;
			    lista = lista->rest;
		    }
		    return contador;
	    }
    }
    
   
    //Problema #1: El metodo push agrega un elemento al final de la lista encadenada.
    void push(int valor){
        LinkedList *newRest = new LinkedList;//Se reserva espacio para añadir el valor como una nueva linkedlist
        newRest->value = valor;//El value de la nueva lista será el valor deseado
        newRest->rest = nullptr;//El resto será nullptr, porque será el final de la lista
        
        LinkedList* lista = this;
        
        while(lista->rest != nullptr){//Se repite el ciclo hasta que se llegue al final de la lista actual
            lista = lista->rest;
        }
        
        lista->rest = newRest;//Se agrega el valor al final de la lista
    }
    
   
    //Problema #2 : El metodo "toVector" retorna un vector con los valores de la lista
    vector<int> toVector(){
        vector<int> vector;//Se define un vector temporal donde se guardarán los valores
        int valor = value;
        LinkedList* resto = rest;

		while (resto != nullptr) {//Se repite el ciclo mientras no se llegue al final de la lista
			vector.push_back(valor);//Se agrega el valor al vector
			valor = resto->value;//El nuevo valor será el siguiente en la lista
			resto = resto->rest;
		}
		//Cuando se llega a que el resto es nullptr aún queda el value de esa última LinkedList
		vector.push_back(valor);//Agrega el último valor al vector

		return vector;
    }

    //Problema #3: Operador []
    int& operator[](const int indice){
        
        LinkedList* lista = this;//Se define una lista temporal con los valores de la actual
        
        for(int i = 0; i<indice; i++){//Se recorre la lista hasta llegar al índice deseado
            lista = lista->rest;
        }
        
        return lista->value;//Se retorna el value que se encuentra en el índice
    }

    
    //Problema #4: Destructor
    ~LinkedList(){
        value = 0;//Borra el value
        delete rest; //Borra la memoria del puntero de LinkedLists
    }

    
    //Problema #5: Operador =
    LinkedList& operator=(LinkedList& otra){
        
        value = 0;
        delete rest;
        rest = nullptr;
        
        int contador = otra.longitud();
    
        value = otra.value;//El value, será el valor de la otra lista
        
        for(int i = 1; i<contador; i++){
            push(otra[i]);
        }
        
        return *this;
    }

    private:
    int value;
    LinkedList* rest;
};



int main()
{
    //Listas a utilizar para las pruebas
    LinkedList l;
    l.l1(1,2);
    
    LinkedList l2;
    l2.l1(4,5);
    
    //Prueba problema #1
    l.push(3);
    cout<<l.getValue()<<endl;// 1
    cout<<l.getList()->getValue()<<endl;// 2
    cout<<l.getList()->getList()->getValue()<<endl;// 3
    cout<<l.longitud()<<endl;// longitud: 3
    
    //Prueba problema #2
    vector<int> lista = l.toVector();
    cout<<lista[0]<<endl;//1
    cout<<lista[1]<<endl;//2
    cout<<lista[2]<<endl;//3
    
    //Prueba problema #3
    cout<<l[0]<<endl;//1
    cout<<l[1]<<endl;//2
    cout<<l[2]<<endl;//3
       
    //Prueba problema #5
    l2.push(6);
    l = l2;
    cout<<l[0]<<endl;//4
    cout<<l[1]<<endl;//5
    cout<<l[2]<<endl;//6
    


    return 0;
}






