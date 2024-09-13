#include <iostream>

using namespace std;

int main()
{
	float sugar = 0.03125, butter = 0.021, flour = 0.0573;
	int cookieCount;

	cout << "How many cookies would you like to bake:";

	cin >> cookieCount;

	cout << "\n\nYou will need...\n" << (sugar * cookieCount) << "Cups of sugar,";

	cout << "\n" << (butter * cookieCount) << " cups of butter,";

	cout << "\nand " << (flour * cookieCount) << " cups of flour.";
}
