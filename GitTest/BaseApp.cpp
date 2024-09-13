#include <iostream>

using namespace std;

int main()
{
    float basePrice, discount, finalPrice;

    cout << "Welcome to the discount calculation app! \n";

    cout << "Please enter the base price of the item: ";

    cin >> basePrice;

    cout << "\nPlease enter the discount (as a decimal): ";

    cin >> discount;

    finalPrice = basePrice - (basePrice * discount);

    cout << "\nYour total comes to : " << finalPrice;

}