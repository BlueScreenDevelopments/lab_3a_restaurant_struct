#include <iostream>
#include <iomanip>
#include <limits>
#include <vector>
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

    cout << "Has Delivery? (1 = yes, 0 = no): ";
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
cout << "\n----------------------------------------------\n";
cout << r.name << " -- " << r.cuisine << " Cuisine \n";
cout << r.address << "\n";
cout << "Rating: " << fixed << setprecision(1) << r.rating << " / 5.0 \n";
cout << "Price: " << string(r.priceLevel, '$') << "\n";
cout << "Delivery: " << (r.hasDelivery ? "Yes" : "No") << "\n";
};


/*Testing Grounds */
int main() {
    vector<Restaurant> places;


    //Two Restaurants Inputs from Consoles ----
    cout << "Enter restaurant 1:\n";
    places.push_back(makeRestaurantFromConsole());

    cout << "Enter restaurant 2:\n";
    places.push_back(makeRestaurantFromConsole());


    // Two more hard-coded objects.
    places.push_back(Restaurant{"Noodle Hub", "77 Oak Ave", "Thai", 4.2, 1, true});
    places.push_back(Restaurant{"Prime Cut", "9 Market Sq", "Steakhouse", 4.8, 4, false});

    cout << "\n=== All Restaurants ===\n";
    for (const auto& r : places) {
        printRestaurant(r);
    }

}
