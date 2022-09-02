#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <sstream>
#include <string>
#include <string.h>
#include <ctime>
#include <Windows.h>
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
 			
 			
 			return "Id: "+idStr+" Nombre: "+name+" Precio: "+priceStr+" Tipo: "+ body+ " Año: "+yearStr+" Modelo:"+model;
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
class Medicine{
    private:
        string name;
        string substance;
        float cost;
        int id;

    public:
        Medicine(string _name, int _id, string _substance, float _cost){
            id = _id;
            cost = _cost;
            name = _name;
            substance = _substance;
            }  
            Medicine(){}
        void Setcost(float _cost){
                  cost = _cost;
            }
              
        string GetMedicine(){
        	stringstream stream;
 			
 			stream << id;
 			string idStr;
 			stream >> idStr;
 			
            string InfoMedicine =
            "Name: "+name+"\n"+"id: "+idStr+"\n"+
            "Sustancia: "+substance;
            return InfoMedicine;
            }
            
        string Getcost(){
        	stringstream stream;
        	stream << cost;
 			string costStr;
 			stream >> costStr;
            string CostMedicine = 
            "Costo: $"+costStr+"\n";
            return CostMedicine;
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
	    int count=0;
	    Medicine* medicine = new  Medicine[50];
	    getline(file, line);
	    while (getline(file,line))
	    {
	    	stringstream stream(line); // Convertir la cadena a un stream
	        string Nombre,Id,Sustancia,costo;
	        int idt;
	        float cos;
	        // Extraer todos los valores de esa fila
	        getline(stream, Nombre, lim);
	        getline(stream, Id, lim);
	        getline(stream, Sustancia, lim);
	        getline(stream, costo, lim);
	        std::istringstream(Id) >> idt; 
	        std::istringstream(costo) >> cos;
		    medicine [count] = Medicine(Nombre, idt, Sustancia, cos);
      		count++;    
      		
	        // Imprimir
	        Sleep(50);
	        cout << ".";
	        count++;
	    }
	}else if(fname=="car"){
		ifstream file (CAR);
	    string line;
	    char lim = ',';
	    getline(file, line);
	    int count=0;
	    cout<<"Cargando";
	    while (getline(file,line))
	    {
	    	int yearInt;
	    	float priceFloat;
	    	stringstream stream(line); // Convertir la cadena a un stream
	        string name, price, body, year,model;
	        // Extraer todos los valores de esa fila
	        getline(stream, name, lim);
	        getline(stream, price, lim);
	        getline(stream, body, lim);
	        getline(stream, year, lim);
	        getline(stream, model, lim);
	        std::istringstream(year) >> yearInt;
	        std::istringstream(price) >> priceFloat;
	        car[count]=Car(count,name, priceFloat, body, yearInt, model);
	        
	        // Imprimir
	        Sleep(50);
	        cout << ".";
	        count++;
	    }
	}
	
}
