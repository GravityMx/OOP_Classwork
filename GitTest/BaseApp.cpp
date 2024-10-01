#include <iostream>
#include <string>

using namespace std;

void inputAllPrices(float& priceY2, float& priceY1, float& priceY0);

void calculateAllRates(float priceY2, float priceY1, float priceY0, float& rate2_1, float& rate1_0);

void outputAllRates(float rate2_1, float rate1_0);

void calculateRate(float oldPrice, float newPrice, float& rate);

float inputWithPrompt(string str);

void outputWithPrompt(string str, float out);

int main()
{
    cout << "Hello World!\n";
}

void inputAllPrices(float& priceY2, float& priceY1, float& priceY0)
{
    priceY0 = inputWithPrompt("Please input the price of the item from today: ");

    priceY1 = inputWithPrompt("Please input the price of the item from one year ago: ");

    priceY2 = inputWithPrompt("Please input the price of the item from two years ago: ");
}

void calculateAllRates(float priceY2, float priceY1, float priceY0, float& rate2_1, float& rate1_0)
{
    calculateRate(priceY2, priceY1, rate2_1);

    calculateRate(priceY1, priceY0, rate1_0);
}

void outputAllRates(float rate2_1, float rate1_0)
{
    outputWithPrompt("The inflation rate from year 2 to year 1 is ", rate2_1);

    outputWithPrompt("The inflation rate from year 1 to year 0 is ", rate1_0);
}

void calculateRate(float oldPrice, float newPrice, float& rate)
{
    rate = (newPrice - oldPrice) / oldPrice;
}

float inputWithPrompt(string str)
{
    float input;

    cout << str;

    cin >> input;

    return input;
}

void outputWithPrompt(string str)
