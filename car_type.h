#ifndef Car_Type_H
#define Car_Type_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

enum Status{
    Added,
    Sold,
    Error,
    Not_Found
};

class Car{
    private:
        string model;
        string ID;
        string color;
        int year;
    public:
        Car(){
            this->model ="Unknown";
            this->ID = "Unknown";
            this->color = "Unknown";
            this->year = 0000;
        }
        Car(const string& model,const string& ID, const string& color, int year){
            this->model = model;
            this->ID = ID;
            this->color = color;
            this->year = year;
        }
        inline string get_model() const{
            return this->model;
        }
        inline string get_ID() const{
            return this->ID;
        }
        inline string get_color()const{
            return this->color;
        }
        inline int get_year() const{
            return this->year;
        }
        void print() const{
            cout << "---------------------------" << endl;
            cout << "Model: " << this->model << endl;
            cout << "ID: " << this->ID << endl;
            cout << "Color: " << this->color << endl;
            cout << "Year: " << this->year << endl;
            cout << "-----------------------------" << endl;
        }
};

class Car_Salon{
    private:
        Car Car_type[10];
        int Max_Number;
        int Number_type;
    public:
        Car_Salon(){
            this->Max_Number = 10;
            this->Number_type = 0;
        }
        bool is_unique(const Car& new_car){
            for(int i = 0; i < Number_type; i++){
                if(new_car.get_ID() == Car_type[i].get_ID()){
                    return false;

                }
                
            }
            return true;
        }
        Status add(Car&& new_car){
            if(Number_type >= Max_Number){
                    cout << "Car salon is full. Cannot add more cars." << endl;
                    return Status::Error;
                }   
            if(is_unique(new_car)){
                Car_type[Number_type] = new_car;
                Number_type++;
                return Status::Added;      
            }
            cout << "Error: ID already exists!"<< endl;
            return Status::Error;
        }
        Status sell(Car&& remove_car){
            if(Number_type == 0) return Status::Not_Found;

            for(int i = 0; i < Number_type; i++){
                if(remove_car.get_ID() == Car_type[i].get_ID()){
                    for(int j = i; j < Number_type - 1; j++){
                        Car_type[j] = Car_type[j + 1];
                    }
                    Number_type--;
                    return Status::Sold;
                }
            }
            cout << "Car not found " << endl;
            return Status::Not_Found;
        }
        
        void print(){
            if(Number_type == 0){
                cout << "Don't print: " << endl;
            }
            cout << "---------------------------------" << endl;
            cout << "Car Salon:" << endl;
            for(int i = 0; i < Number_type; i++){
                Car_type[i].print();
        
            }
            cout << "---------------------------------" << endl;
            cout << "Maximum number: " << Max_Number << endl;
            cout << "Number of seats remaining: "  << Max_Number - Number_type << endl;
            cout << "Number: " << Number_type << endl;
        }
        void save_to_file(){
            ofstream file("Save.txt");

            if(!file.is_open()){
                return;
            }
            if(Number_type == 0){
                cout << "Unable to import file" << endl;
            }
            for(int i = 0; i < Number_type; i++){
                file <<Car_type[i].get_model() << " " << Car_type[i].get_ID() << " "
                    << Car_type[i].get_color() << " "   << Car_type[i].get_year() << endl;
            }
            file.close();
        }


};

#endif