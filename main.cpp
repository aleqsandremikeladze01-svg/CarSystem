#include <iostream>
#include "car_type.h"
using namespace std;
enum choice{
    Add = 1,
    Sell,
    Save,
    Print,
    Exit
};
int main(){
    Car_Salon salon;
    int input;
    choice user_choice;
    do{
        cout << "1. Add a car" << endl;
        cout << "2. Sell a car" << endl;        
        cout << "3. Save the car salon data to a file" << endl;
        cout << "4. Print the car salon data" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> input;
        if(cin.fail()){
            cout << "Error: Plese enter a number: " << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        user_choice = (choice)input;
        switch(user_choice){
            case Add:{
                string model;
                string ID;
                string color;
                int year;

                cout << "Enter model: ";
                cin.ignore(1000, '\n');
                getline(cin, model);
                cout << "Enter ID: ";
                cin >> ID;
                cout << "Enter color: ";
                cin >> color;
                cout << "Enter year: ";
                cin >> year;
                
                if(cin.fail()){
                    cout << "Error: Plese enter a number: " << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    continue;
                }
                
                salon.add(Car(model, ID, color, year));
                break;
            }
            case Sell:{
                string ID;
                cout << "Enter ID: ";
                cin >> ID;
                salon.sell(Car("", ID, "", 0));
                break;

            }
            case Save:{
                salon.save_to_file();
                cout << "Save of succssesfully" << endl;
                break;
            }
            case Print:{
                salon.print();
                break;

            }
            case Exit:{
                cout << "Exit";
                break;
            }
            default:
                cout << "Error!" << endl;
        }
        

    }while(user_choice != Exit);
    

    return 0;
}