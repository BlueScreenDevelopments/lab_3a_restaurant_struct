#include <iostream>
#include <iomanip>
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

    cout << "Cusine: ";
    getline(cin, r.cuisine);

}

/*Output Console*/
void printRestaurant (const Restaurant& r){
cout << "---------------\n";
cout << r.name << " " << r.cuisine << "\n";
cout << r.address << "\n";
cout << "Rating: " << fixed << setprecision(1) << r.rating << "5.0 \n";
cout << "Price: " << string(r.priceLevel, '$') << "\n";
cout << "Delivery: " << (r.hasDelivery ? "Yes" : "No") << "\n";
};


/*Testing Grounds */
int main(){
     Restaurant demo{"Cafe Atlas", "123 Main St", "Mediterranean", 4.6, 2, true};
    printRestaurant(demo);

};