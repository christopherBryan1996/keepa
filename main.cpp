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
 //creacion de objetos 
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
 			
 			
 			return "Id: "+idStr+" Nombre: "+name+" Precio: "+priceStr+" Tipo: "+ body+ " Ano: "+yearStr+" Modelo:"+model;
		}
		
		void SetPrice(float newPrece){
			price=newPrece;
		}
		float GetPrice(){
			return price;
		}
		int GetId(){
			return id;
		}
		string GetName(){
			return name;
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
        float GetPriceFloat(){
			return price;
		}
		

        int GetId(){
            return id;
        }

        string ToyName(){
            return name;
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
        int GetId(){
			return id;
		}
		string GetName(){
			return name;
		}
		int GetPriceInt(){
        	return cost;
		}
};
 //fincion para cambiar de precio solo un 10% a su alsa o asu baja
float changePrice(float price){
	int percentage=price*.10;
	int max=price+percentage;
	int min=price-percentage;
	return min+rand() % (max-min);
	
}

int main(int argc, char** argv) {
	string fname;
	int op;
	cout <<"Bienvenido a Keepa en c++ \n";
	
	Art_toy *articles = new Art_toy[50];
	Car* car= new Car[49];
	Medicine* medicine = new  Medicine[50];
	
	int addId[3];
	int addSum=0;
	//inicio para dar la opcion a seleccionar que base de datos le interesa 
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
	//llenado de los objetos de la base de datos seleccionada 
	if(fname=="toy"){
		int it=0;
		ifstream file (TOY);
	    string line;
	    char lim = ',';
	    getline(file, line);
	    cout<<"Cargando";
	    while (getline(file,line))
	    {
	    	
	    	int idStr;
            float priceStr;
	    	stringstream stream(line); // Convertir la cadena a un stream
	        string name, id, manufacturer, price;
	        // Extraer todos los valores de esa fila
	        getline(stream, name, lim);
	        
	        getline(stream, manufacturer, lim);
	        getline(stream, price, lim);
	        std::istringstream(id)>>idStr;
            std::istringstream(price)>>priceStr;
	        
	        // Imprimir
	        
	        articles[it]=Art_toy(name,it,manufacturer,priceStr);
            it++;
            Sleep(50);
	        cout << ".";
	        
	    }
	}
	else if(fname=="medicine"){
		ifstream file (MEDICINE);
	    string line;
	    char lim = ',';
	    int count=0;
	    getline(file, line);
	    cout<<"Cargando";
	    while (getline(file,line))
	    {
	    	stringstream stream(line); // Convertir la cadena a un stream
	        string Nombre,Id,Sustancia,costo;
	        int idt;
	        float cos;
	        // Extraer todos los valores de esa fila
	        getline(stream, Nombre, lim);
	        getline(stream, Sustancia, lim);
	        getline(stream, costo, lim);
	        std::istringstream(costo) >> cos;
		    medicine [count] = Medicine(Nombre, count, Sustancia, cos);
      		
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
	//seleccionar los articulos a moritoriar solo se podran escojer 3 
	cout<<"\n";
	int statusGlobal=true;
	while (statusGlobal){
		int op2;
        cout<<"\nConoce nuestros productos o desea ver una lista?"<<endl;
        cout<<"[1] Conozco los productos"<<endl;
        cout<<"[2] Deseo ver las listas"<<endl;
        cout<<"Selección: ";
        cin>>op2;
            if(cin.fail()){
			cout <<"Solo numeros enteros, reinicie el programa \n";
			break;
		    }
		bool status=true;
        switch (op2)
        {
        case 1:
            while(status){
            	int op3;
            	bool statusTwo=true;
	            cout<<"Como desea realizar su busqueda?"<<endl;
	            cout<<"[1] Búsqueda por ID"<<endl;
	            cout<<"[2] Búsqueda por nombre"<<endl;
	            cout<<"Selección: ";
	            cin>>op3;
				
	            if(cin.fail()){
					cout <<"Solo numeros enteros, reinicie el programa \n";
					statusGlobal=false;
					break;
				}
				switch(op3){
					case 1:
						while(addSum<3 and statusTwo){
							int idCout;
							cout << "Ingrese su id por favor: ";
							cin >> idCout;
							if(cin.fail()){
								cout <<"Solo numeros enteros, reinicie el programa \n";
								status=false;
								statusGlobal=false;
								break;
							}
							if(fname=="toy"){
								for (int i = 0; i < 50; i++){
                                    
									if(articles[i].GetId()==idCout){
                                        char opSoN;
										
				            			cout <<"Tu producto es: \n";
				            			cout << articles[i].GetProduct()<<endl;
				            			cout <<"Si es correcto coloque 's' y se agregara para su seguimiento, de lo contrario 'n' y ponga un nuevo id"<<endl;
				            			cout << "Si desea salir precione 'c' y si no tiene ninguno agregado se acabara el programa" << endl;
				            		    cin >> opSoN;

				            			if(opSoN=='s' or opSoN=='S'){
				            				addId[addSum]=i;
				            				cout << "Se agrego con exito \n";
				            				addSum++;
										}
										if(opSoN=='c' or opSoN=='C'){
											status=false;
											statusGlobal=false;
											statusTwo=false;
											break;
										}
                                    }
                                }
				            }
				            else if(fname=="medicine"){
				            	for(int i=0;i<50;i++){
				            		if(medicine[i].GetId()==idCout){
				            			char opSoN;
				            			
				            			cout <<"Tu producto es: \n";
				            			cout << medicine[i].GetMedicine()<<endl;
				            			cout <<"Si es correcto coloque 's' y se agregara para su seguimiento, de lo contrario 'n' y ponga un nuevo id"<<endl;
				            			cout << "Si desea salir precione 'c' y si no tiene ninguno agregado se acabara el programa" << endl;
				            			cin >> opSoN;
				            			if(opSoN=='s' or opSoN=='S'){
				            				addId[addSum]=idCout;
				            				cout << "Se agrego con exito \n";
				            				addSum++;
										}
										if(opSoN=='c' or opSoN=='C'){
											status=false;
											statusGlobal=false;
											statusTwo=false;
											break;
										}
									}
								}
				            }
				            else if(fname=="car"){
				            	for(int i=0;i<50;i++){
				            		if(car[i].GetId()==idCout){
				            			char opSoN;
				            			cout <<"Tu producto es: \n";
				            			cout << car[i].GetProduct()<<endl;
				            			cout <<"Si es correcto coloque 's' y se agregara para su seguimiento, de lo contrario 'n' y ponga un nuevo id"<<endl;
				            			cout << "Si desea salir precione 'c' y si no tiene ninguno agregado se acabara el programa" << endl;
				            			cin >> opSoN;
				            			if(opSoN=='s' or opSoN=='S'){
				            				addId[addSum]=idCout;
				            				cout << "Se agrego con exito \n";
				            				addSum++;
										}
										if(opSoN=='c' or opSoN=='C'){
											status=false;
											statusGlobal=false;
											statusTwo=false;
											break;
										}
									}
								}
							}
						}
						
						status=false;
						statusGlobal=false;
					break;
					case 2:
						while(addSum<3 and statusTwo){
							string idCout;
							cout << "Ingrese el nombre por favor: ";
							cin >> idCout;
							
							if(fname=="toy"){
								for(int i=0;i<50;i++){
				            		if(articles[i].ToyName()==idCout){
				            			char opSoN;
				            			cout <<"Tu producto es: \n";
				            			cout << articles[i].GetProduct()<<endl;
				            			cout <<"Si es correcto coloque 's' y se agregara para su seguimiento, de lo contrario 'n' y ponga un nuevo id"<<endl;
				            			cout << "Si desea salir precione 'c' y si no tiene ninguno agregado se acabara el programa" << endl;
				            			cin >> opSoN;
				            			if(opSoN=='s' or opSoN=='S'){
				            				addId[addSum]=i;
				            				cout << "Se agrego con exito \n";
				            				addSum++;
										}
										if(opSoN=='c' or opSoN=='C'){
											status=false;
											statusGlobal=false;
											statusTwo=false;
											break;
										}
										if(addSum==3){
				            				break;
										}
									}
								}
				            }
				            else if(fname=="medicine"){
				            	for(int i=0;i<50;i++){
				            		if(medicine[i].GetName()==idCout){
				            			char opSoN;
				            			cout <<"Tu producto es: \n";
				            			cout << medicine[i].GetMedicine()<<endl;
				            			cout <<"Si es correcto coloque 's' y se agregara para su seguimiento, de lo contrario 'n' y ponga un nuevo id"<<endl;
				            			cout << "Si desea salir precione 'c' y si no tiene ninguno agregado se acabara el programa" << endl;
				            			cin >> opSoN;
				            			if(opSoN=='s' or opSoN=='S'){
				            				addId[addSum]=i;
				            				cout << "Se agrego con exito \n";
				            				addSum++;
										}
										if(opSoN=='c' or opSoN=='C'){
											status=false;
											statusGlobal=false;
											statusTwo=false;
											break;
										}
									}
								}
				            }
				            else if(fname=="car"){
				            	for(int i=0;i<50;i++){
				            		if(car[i].GetName()==idCout){
				            			char opSoN;
				            			cout <<"Tu producto es: \n";
				            			cout << car[i].GetProduct()<<endl;
				            			cout <<"Si es correcto coloque 's' y se agregara para su seguimiento, de lo contrario 'n' y ponga un nuevo id"<<endl;
				            			cout << "Si desea salir precione 'c' y si no tiene ninguno agregado se acabara el programa" << endl;
				            			cin >> opSoN;
				            			
				            			if(opSoN=='s' or opSoN=='S'){
				            				addId[addSum]=i;
				            				cout << "Se agrego con exito \n";
				            				addSum++;
										}
										if(opSoN=='c' or opSoN=='C'){
											status=false;
											statusGlobal=false;
											statusTwo=false;
											break;
										}
										if(addSum==3){
				            				break;
										}
									}
								}
							}
						}
						status=false;
						statusGlobal=false;
					break;
					default:
						cout<<"Digite solo del 1 al 2 por favor\n";	
					break;
				}
			}
            
            
            break;
        case 2:
            int op4;
            if(fname=="toy"){
            for (int i = 0; i < 50; i++)
            {
                cout<<"["<<i+1<<"]\n"<<articles[i].GetProduct()<<endl;
                cout<<"Para el siguiente articulo"<<endl;
                op4 = cin.get();
               
            }
            
            }
            else if(fname=="medicine"){

            }
            else if(fname=="car"){

            }
            else{

            }
            break;
        default:
        	cout<<"Digite solo del 1 al 2 por favor\n";
            break;
        }
	}
	//mostar los datos señalados 
	if(addSum>0){
		int iMori=0;
		float priceInit[3];
		cout << "Tus productos a moritoriar son: \n";
		if(fname=="toy"){
			for(int i=0;i<addSum;i++){
        		priceInit[i]=articles[addId[i]].GetPriceFloat();
				cout << articles[addId[i]].GetProduct()<<endl; 
			}
			while(iMori<3){
				int iTime=0;
				cout << "\nAnalizando sus productos ";
				while(iTime<5){
					Sleep(1000);
		        	cout << ".";
		        	iTime++;
				}
				for(int i=0;i<addSum;i++){
	        		cout << "\nEl producto: ";
	        		cout << articles[addId[i]].GetPriceFloat() << endl;
	        		cout << "El precio inicial es: " << priceInit[i] << endl;
	        		int desgracia=priceInit[i];
	        		int porcentaje=desgracia*.10;
	        		if(porcentaje==0){
	        		 	porcentaje=1;
					}
				 	int max=desgracia+porcentaje;
					int min=desgracia-porcentaje;
					int desgraciados = min+rand() % (max-min);
					articles[addId[i]].SetPrice(desgraciados);
					if(priceInit[i]>desgraciados){
						cout << "El precio a bajado, ahora es de: "<<desgraciados<<endl;
						cout <<"El precio inicial es: "<< priceInit[i]<<endl;
						Sleep(2000);
					}else{
						cout << "El precio a subido, ahora es de: "<<desgraciados<<endl;
						cout <<"El precio inicial es: "<< priceInit[i]<<endl;
						Sleep(2000);
					}
					Sleep(1000);
				}
				 iMori++;
			}
		
        }
        else if(fname=="medicine"){
        	for(int i=0;i<addSum;i++){
        		priceInit[i]=medicine[addId[i]].GetPriceInt();
				cout << medicine[addId[i]].GetMedicine()<<endl;
			}
			while(iMori<3){
				int iTime=0;
				cout << "\nAnalizando sus productos ";
				while(iTime<5){
					Sleep(1000);
		        	cout << ".";
		        	iTime++;
				}
				for(int i=0;i<addSum;i++){
	        		cout << "\nEl producto: ";
					cout << medicine[addId[i]].GetName()<<endl;
					cout << "El precio inicial es: "<<priceInit[i]<<endl;
					float newPrice=changePrice(medicine[addId[i]].GetPriceInt());
					medicine[addId[i]].Setcost(newPrice);
					if(priceInit[i]>newPrice){
						cout << "El precio a bajado, ahora es de: "<<newPrice<<endl;
						cout <<"El precio inicial es: "<< priceInit[i]<<endl;
						Sleep(1000);
					}else{
						cout << "El precio a subido, ahora es de: "<<newPrice<<endl;
						cout <<"El precio inicial es: "<< priceInit[i]<<endl;
						Sleep(1000);
					}
					Sleep(1000);
				}
				
		        iMori++;
			}
        }
        else if(fname=="car"){
			for(int i=0;i<addSum;i++){
        		priceInit[i]=car[addId[i]].GetPrice();
				cout << car[addId[i]].GetProduct()<<endl;
			}
			while(iMori<3){
				int iTime=0;
				cout << "\nAnalizando sus productos ";
				while(iTime<5){
					Sleep(1000);
		        	cout << ".";
		        	iTime++;
				}
				for(int i=0;i<addSum;i++){
	        		cout << "\nEl producto: ";
					cout << car[addId[i]].GetProduct()<<endl;
					cout << "El precio inicial es: "<<priceInit[i]<<endl;
					float newPrice=changePrice(car[addId[i]].GetPrice());
					car[addId[i]].SetPrice(newPrice);
					if(priceInit[i]>newPrice){
						cout << "El precio a bajado, ahora es de: "<<newPrice<<endl;
						cout <<"El precio inicial es: "<< priceInit[i]<<endl;
						Sleep(2000);
					}else{
						cout << "El precio a subido, ahora es de: "<<newPrice<<endl;
						cout <<"El precio inicial es: "<< priceInit[i]<<endl;
						Sleep(2000);
					}
					Sleep(1000);
				}
				
		        iMori++;
			}
		}	
	}else{
		cout << "Reinicie el programa y seleccione uno o mas productos para su moritoreo \n";
	}
}


