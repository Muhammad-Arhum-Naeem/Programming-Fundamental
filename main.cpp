#include<iostream>
#include<cstring>
#include<stdlib.h>

using namespace std;
//function to clear console
void clear(){
    system("cls");
}


// Function to perform login
bool Login(string userName[],string pass[],string inputName, string inputPass, int size, int& place) {
    place = -1; // Default value for place, indicating username not found
    bool nameFlag = false;

    // Checking if username is present and finding its index
    for (int i = 0; i < size; ++i) {
        if (inputName == userName[i]) {
            nameFlag = true;
            place = i;
            break;
        }
    }

    // Validating username and password
    if (place != -1 && inputPass == pass[place]) {
        cout << "Welcome: "<<userName[place]<<endl;
        return true;
    } else {
        cout << "Invalid UserName or Password..."<<endl;
        return false;
    }
}
//Function To create new account
    bool Create_Account(string Costumer[], string CostumerPass[], int balance[], int RegId[], int& InitialSize) {
        InitialSize++;
        string Name, Pass;
        int bal;
        cout<<"Enter Name: ";
        cin>>Name;
        cout<<"Create a Password: ";
        cin>>Pass;
        cout<<"Enter Your Initial Balance: ";
        cin>>bal;
        Costumer[InitialSize] = Name;
        CostumerPass[InitialSize] = Pass;
        balance[InitialSize] = bal;
        RegId[InitialSize] = InitialSize + 1000; 
        return true;
    }

    //function to add item by client
    void addItem(string Items[], double price[], int quantity[], int& available, int max) {
    int addItem = 0;
    cout << "How many Items you want to add: ";
    cin >> addItem;

    for (int i = 0; i < addItem; i++) {
        cout << "Item Name: ";
        cin >> Items[available];
        cout << "Price of Item: ";
        cin >> price[available];
        cout << "Quantity of Item: ";
        cin >> quantity[available];
        available++;
    }

    cout << "Updated List: " << endl;
    cout<<"Sr # \t Item \t Price \t Quantity"<<endl;
    for (int i = 0; i < available; i++) {
        cout << i + 1 << ": " << Items[i] << '\t' << price[i] << '\t' << quantity[i] << endl;
    }
}
//function to remove item
void removeItem(string Items[],double price[],int quantity[],int& available,int max) {
    int removeItem = -1;

    while (removeItem != 0) {
        cout << "PRESS ZERO FOR BACK" << endl;
        cout << "What Item You Want To Remove: " << endl;

        for (int i = 0; i < available; i++) {
            cout << i + 1 << ": " << Items[i] << endl;
        }

        cin >> removeItem;

        if (removeItem == 0) {
            break;
        }

        for (int i = removeItem - 1; i < available; i++) {
            Items[i] = Items[i + 1];
            price[i] = price[i + 1];
            quantity[i] = quantity[i + 1];
        }

        available--;

        cout << "Updated List: " << endl;

        for (int i = 0; i < available; i++) {
            cout << i + 1 << ": " << Items[i] << '\t' << price[i] << '\t' << quantity[i] << endl;
        }
    }
}

//function to update price

void updatePrice(string Items[], double price[], int quantity[], int available) {
    int priceUpdate = -1;

    do {
        cout << "PRESS ZERO FOR BACK" << endl;
        cout << "What Item's Price You Want to Update: " << endl;

        for (int i = 0; i < available; i++) {
            cout << i + 1 << ": " << Items[i] << '\t' << price[i] << '\t' << quantity[i] << endl;
        }

        int newPrice = 0;
        cin >> priceUpdate;

        if (priceUpdate == 0) {
            break;
        }

        cout << "Enter New Price: ";
        cin >> newPrice;
        price[priceUpdate - 1] = newPrice;

        cout << "Updated List: " << endl;

        for (int i = 0; i < available; i++) {
            cout << i + 1 << ": " << Items[i] << '\t' << price[i] << '\t' << quantity[i] << endl;
        }
    } while (priceUpdate != 0);
}
//function to update quantity

void updateQuantity(string Items[],double price[],int quantity[],int available) {
    int quantityUpdate = -1;

    do {
        cout << "What Item's Quantity You want to update: " << endl;

        for (int i = 0; i < available; i++) {
            cout << i + 1 << ": " << Items[i] << '\t' << price[i] << '\t' << quantity[i] << endl;
        }

        int newQuantity = 0;
        cin >> quantityUpdate;

        if (quantityUpdate == 0) {
            break;
        }

        cout << "Enter New Quantity: ";
        cin >> newQuantity;
        quantity[quantityUpdate - 1] = newQuantity;

        cout << "Updated List: " << endl;

        for (int i = 0; i < available; i++) {
            cout << i + 1 << ": " << Items[i] << '\t' << price[i] << '\t' << quantity[i] << endl;
        }
    } while (quantityUpdate != 0);
}


//function to view inventory
void viewInvetory(string Items[], double price[], int quantity[], int available){
    cout<<"Sr # \t Item \t Price \t Quantity"<<endl;
    for(int i=0; i<available; i++){
        cout << i + 1 << ": " << Items[i] << '\t' << price[i] << '\t' << quantity[i] << endl;
    }
}
//---------------------------------------------------------------------------------------------//
//function for purchasing 
void selectItems(string cart[],string Items[],int quantity[],double price[], int& cartIndex, double& totalPrice, int& available) {
    int choice = -1;
    int itemsSelected = 0;

    do {
        // Display available items
        for (int i = 0; i < available; i++) {
            cout << i + 1 << ". " << Items[i] << " - Rs" << price[i] << " (Quantity: " << quantity[i] << ")" << endl;
        }

        cout << endl << "Enter your choice (0 to exit selection): ";
        cin >> choice;

        if (choice >= 1 && choice <= available) {
            int index = choice - 1; // To indicate items
            if (quantity[index] > 0) {
                cout << "You selected: " << Items[index] << endl;
                cart[cartIndex++] = Items[index]; // Add selected item to the cart
                totalPrice += price[index]; // Update total price
                quantity[index]--; // Decrease the item's quantity
                itemsSelected++; // Increment items selected
                cout << "Price added to total: Rs." << price[index] << endl;
                cout << "Updated Total: Rs." << totalPrice << endl;
                cout << "Updated Quantity of " << Items[index] << ": " << quantity[index] << endl;
            } else {
                cout << "Sorry, " << Items[index] << " is out of stock!" << endl;
            }
        } else if (choice != 0) {
            cout << "Invalid choice!" << endl;
        }
    
    } while (choice != 0);
        cout << "Items placed in the cart:" << endl;
        for (int i = 0; i < cartIndex; i++) {
            cout << endl << cart[i] << endl; // Display items in the cart
        }
        cout << endl;
        if (itemsSelected > 1) {
            cout << "Total Price for " << itemsSelected << " items: Rs." << totalPrice << endl;
        } else {
            cout << "Total Price to pay: Rs." << totalPrice << endl;
        }
}





int main(){
    int place;
    //arrays for admin id and pass
    const int size = 5;
    string userName[size] = {"admin", "root", "user", "arhum", "ahad"};
    string pass[size] = {"admin", "root", "user", "@rhum", "@h@d"};
    //-----------------------------------------------------//
    //arrays for users//
    const int maxSize = 20;
    int InitialSize = 3;
    string Costumer[maxSize] = {"costumer1", "costumer2", "costumer3"};
    string CostumerPass[maxSize] = {"Pass1", "Pass2", "Pass3"};
    int balance[maxSize] = {500, 1000, 300};
    int RegId[maxSize] = {1001, 1002, 1003};
    string cart[maxSize] = {};
    double totalPrice = 0.0;
    int cartIndex = -1;
    //----------------------------------------------------//
    //ARRAY FOR INVENTORY
    const int max = 20;
    int available = 5; //initially available itmes
    string Items[max] = {"Item1", "Item2", "Item3", "Item4", "Item5"};
    double price[max] = {100, 50, 50, 45, 200};
    int quantity[max] = {5, 8, 10, 15, 50};
    int update = -1; //depends upon what staff want to do
    

    //----------------------------------------------------//
    int loginOption;
    //string to be entered by user as input
    string inputName, inputPass;
    //----------------------------------------------------//
    cout<<" ________________________________"<<endl
         <<"|                                |"<<endl
         <<"|           WELCOME              |"<<endl
         <<"|  [1]Staff         [2]Costumer  |"<<endl
         <<"|       [3]Create Account        |"<<endl
         <<"|________________________________|"<<endl;
    cin>>loginOption;
    clear();
    //------------------------------------------------------//

    if(loginOption == 1){
        do{
            cout<<"User Name: ";
            cin>>inputName;
            cout<<"Password: ";
            cin>>inputPass;
            
        }while(Login(userName, pass,inputName, inputPass, size, place) == false);
        if(Login(userName, pass,inputName, inputPass, size, place) == true){
            cout << "Sr.\tItems\tPrices\tQuantity" << endl;
            for(int i = 0; i < available; i++){
                cout << i + 1 << ": " << Items[i] << '\t' << price[i] << '\t' << quantity[i] << endl;
            }
            do{
                cout<<"What do you want to do: "<<endl
                <<"[1] Add Item"<<endl
                <<"[2] Remove Item"<<endl
                <<"[3] Update Price"<<endl
                <<"[4] Update Quantity"<<endl
                <<"[5] View Inventory"<<endl
                <<"[0] For Returning To End Program"<<endl;
                cin>>update;   
                if(update == 1){
                    addItem(Items,price,quantity,available,max);
                }
                else if(update == 2){
                    removeItem(Items,price,quantity,available,max);
                }
                else if(update == 3){
                    updatePrice(Items,price,quantity,available);
                }
                else if(update == 4){
                    updateQuantity(Items,price,quantity,available);
                }
                else if(update == 5){
                    viewInvetory(Items, price, quantity, available);
                }
            } while(update != 0);

        }
    }
    //---------------------------------------------------------------------------------//
    else if(loginOption == 2){
        do{
            cout<<"User Name: ";
            cin>>inputName;
            cout<<"Password: ";
            cin>>inputPass;
            
        }while(Login(Costumer, CostumerPass,inputName, inputPass, maxSize, place) == false);
        cout<<"Name: "<<Costumer[place]<<endl;
        cout<<"Balance: "<<balance[place]<<endl;
        selectItems(cart,Items,quantity,price,cartIndex,totalPrice,available);

    }
    //---------------------------------------------------------------------------------------//
    else if(loginOption == 3){
        if(Create_Account(Costumer, CostumerPass, balance,RegId,InitialSize) == true){
            cout<<"||   Account Created Successfully     ||"<<endl;
        }
        do{
            cout<<"||------------------------------------||"<<endl;
            cout<<"User Name: ";
            cin>>inputName;
            cout<<"Password: ";
            cin>>inputPass;
            
        }while(Login(Costumer, CostumerPass,inputName, inputPass, maxSize, place) == false);
        cout<<"Name: "<<Costumer[place]<<endl;
        cout<<"Balance: "<<balance[place]<<endl;
        cout<<"Costumer ID: "<<RegId[place]<<endl;

    }
}
