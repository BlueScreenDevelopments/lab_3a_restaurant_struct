#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

/*
Brandon Julao
COMSC-210-5470
09.07.25
Restaurant Struct

*/

struct Restaurant{
string name;
string address;
string cuisine;
double rating;
int priceLevel;
bool hasDelivery;
};

Restaurant makeRestaurantFromConsole();
void printRestaurant(const Restaurant& r);


/*Receive Input */
Restaurant makeRestaurantFromConsole(){
    Restaurant r;

    cout << "Name: ";
    getline (cin, r.name);

    cout << "Address: ";
    getline (cin, r.address);

    cout << "Cuisine: ";
    getline(cin, r.cuisine);

    cout << "Rating (0-5): ";
    while (!(cin >> r.rating) || r.rating < 0.0 || r.rating > 5.0){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter a number 0-5: ";
    }

 cin.ignore(numeric_limits<streamsize>::max(), '\n'); //running into errors, flush newline

    cout << "Price level (1-4): ";
    while (!(cin >> r.priceLevel) || r.priceLevel < 1 || r.priceLevel > 4){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter a number 1-4: ";
    }

     cin.ignore(numeric_limits<streamsize>::max(), '\n'); //running into errors, flush newline

    cout << "Has Delivery? (1 = yes, 2 = no): ";
    int deliveryInt;
    while (!(cin >> deliveryInt) || (deliveryInt != 0 && deliveryInt !=1)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter 1 or 0: ";
    }

    r.hasDelivery = (deliveryInt ==1);

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //eating the trailing newline just in case
    return r;
}

/*Output Console*/
void printRestaurant (const Restaurant& r){
cout << "---------------\n";
cout << r.name << " " << r.cuisine << "\n";
cout << r.address << "\n";
cout << "Rating: " << fixed << setprecision(1) << r.rating << " / 5.0 \n";
cout << "Price: " << string(r.priceLevel, '$') << "\n";
cout << "Delivery: " << (r.hasDelivery ? "Yes" : "No") << "\n";
};


/*Testing Grounds */
int main() {
    cout << "Enter a restaurant:\n";
    Restaurant r = makeRestaurantFromConsole();
    cout << "\nYou entered:\n";
    printRestaurant(r);
}
