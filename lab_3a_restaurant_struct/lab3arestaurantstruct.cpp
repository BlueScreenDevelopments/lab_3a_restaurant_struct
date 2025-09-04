#include <iostream>
#include <iomanip>
using namespace std;

/*
Brandon Julao
COMSC-210-5470
09.03.25
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

void printRestaurant (const Restaurant& r){
cout << "-----\n";
cout << r.name << " " << r.cuisine << "\n";
};



int main(){
    cout << "\nIT'S HAPPENING...\n";
};

