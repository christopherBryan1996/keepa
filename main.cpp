#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <sstream>
#include <string>
#include <string.h>
#include <fstream>
#define TOY "DB/BDjuguetes.csv"
#define MEDICINE "DB/MEDICAMENTOS.csv"
#define CAR "DB/car_ad.csv"

 using namespace std;
 class Car{
 	private:
 		int id;
 		string name;
 		float price;
 		string body;
 		int year;
 		string model;
 	public:
 		Car(int _id, string _name, float _price, string  _body, int _year, string _model){
 			id=_id;
 			name= _name;
 			price=_price;
 			body=_body;
 			year=_year;
 			model=_model;
		 }
		 Car(){
		 }
 		string GetProduct(){
 			stringstream stream;
 			stringstream stream2;
 			stringstream stream3;
 			
 			stream << id;
 			string idStr;
 			stream >> idStr;
 			
 			stream2 <<  price;
 			string priceStr;
 			stream2 >> priceStr;
 			
 			stream3 << year;
 			string yearStr;
 			stream3 >> yearStr;
 			
 			
 			return "Id: "+idStr+" Nombre: "+name+" Precio: "+priceStr+" Tipo: "+ body+ " A�o: "+yearStr+" Modelo:"+model;
		}
		
		void SetPrice(float newPrece){
			price=newPrece;
		}
		int GetPrice(){
			return price;
		}
 };
 
 class Art_toy{
    public:
        int id;
        float price;
        string name;
        string manufacturer;

    public:
        Art_toy(){}
        Art_toy(string _name, int _id, string _manufacturer, float _price){
            id=_id;
            price = _price;
            name = _name;
            manufacturer = _manufacturer;
            }  
        void SetPrice(float _price){
                  price = _price;
            }
              
        string GetProduct(){
        	stringstream stream;
 			
 			stream << id;
 			string idStr;
 			stream >> idStr;
 			
            string InfoProduct =
            "Name: "+name+"\n"+"id: "+idStr+"\n"+
            "Manufacturer: "+manufacturer;
            return InfoProduct;
            }
            
        string GetPrice(){
        	stringstream stream;
 			
 			stream << price;
 			string priceStr;
 			stream >> priceStr;
        	
            string PriceProduct = 
            "Price: $"+priceStr+"\n";
            return PriceProduct;
            } 
};
 

int main(int argc, char** argv) {
	string fname;
	int op;
	cout <<"Bienvenido a Keepa en c++ \n";
	Car* car= new Car[49];
	
	while(true){
		cout <<"Tenemos un listado:\n 1 Jugetes\n 2 Medicamento\n 3 Carros\n";
		cout <<"Digite el numero de su listado favorito: \n";
		cin >> op;
		if(cin.fail()){
			cout <<"Solo numeros enteros reinicie el programa \n";
			break;
		}
		switch (op){
			case 1:
				fname="toy";
			break;
			case 2:
				fname="medicine";
			break;
			case 3:
				fname="car";
			break;
			default:
				cout<<"Digite solo del 1 al 3 por favor\n";	
			break;	
		}
		if(fname.length()>0){
			break;
		}
	}
	
	if(fname=="toy"){
		cout << "I'm toy";
		ifstream file (TOY);
	    string line;
	    char lim = ',';
	    getline(file, line);
	    while (getline(file,line))
	    {
	    	stringstream stream(line); // Convertir la cadena a un stream
	        string name, id, manufacturer, price;
	        // Extraer todos los valores de esa fila
	        getline(stream, name, lim);
	        getline(stream, id, lim);
	        getline(stream, manufacturer, lim);
	        getline(stream, price, lim);
	        
	        // Imprimir
	        cout << "==================" << endl;
	        cout << "Name: " << name << endl;
	        cout << "id: " << id << endl;
	        cout << "Manufacturer: " << manufacturer << endl;
	        cout << "Price: " << price << endl;
	    }
	}
	else if(fname=="medicine"){
		cout << "I'm medicine";
		ifstream file (MEDICINE);
	    string line;
	    char lim = ',';
	    getline(file, line);
	    while (getline(file,line))
	    {
	    	stringstream stream(line); // Convertir la cadena a un stream
	        string name, id, manufacturer, price;
	        // Extraer todos los valores de esa fila
	        getline(stream, name, lim);
	        getline(stream, id, lim);
	        getline(stream, manufacturer, lim);
	        getline(stream, price, lim);
	        
	        // Imprimir
	        cout << "==================" << endl;
	        cout << "Name: " << name << endl;
	        cout << "id: " << id << endl;
	        cout << "Manufacturer: " << manufacturer << endl;
	        cout << "Price: " << price << endl;
	    }
	}else if(fname=="car"){
		
		cout << "I'm car";
		ifstream file (CAR);
	    string line;
	    char lim = ',';
	    getline(file, line);
	    int count=0;
	    cout<<"Cargando";
	    while (getline(file,line))
	    {
	    	stringstream stream(line); // Convertir la cadena a un stream
	        string name, price, body, year,model;
	        // Extraer todos los valores de esa fila
	        getline(stream, name, lim);
	        getline(stream, price, lim);
	        getline(stream, body, lim);
	        getline(stream, year, lim);
	        getline(stream, model, lim);
	        car[count]=Car(count,name, 50, body, 1995, model);
	        
	        // Imprimir
	        cout << "=";
	        count++;
	    }
	    cout<<count;
	}
	for(int i=0;i<=49;i++){
		cout<<car[i].GetProduct()<<endl;
	}
	cout<< fname;
	 
	
	
	std::cout << "Hello world!\n";

}
