#include <iostream>

using namespace std;

class counterType {
private:
    int counter;

public:
    counterType(int cont) {
        counter = cont;
    }

    //set the counter value
    void setCounter(int value) {
        if (value >= 0)
            counter = value;
        else
            cout << "Counter value must be nonnegative." << endl;
    }

    // retrieve the counter value
    int getCounter() const {
        return counter;
    }

    // increment the counter
    void incrementCounter() {
        counter++;
    }

    // decrement the counter
    void decrementCounter() {
        if (counter > 0)
            counter--;
        else
            cout << "Counter cannot be negative." << endl;
    }

    //reset the counter
    void resetCounter() {
        counter = 0;
    }
};

int main() {
    counterType myCounter(0);

    // Test the class functionality
    myCounter.setCounter(10);
    cout << "Counter value: " << myCounter.getCounter() << endl; 

    myCounter.incrementCounter();
    cout << "Counter after increment: " << myCounter.getCounter() << endl; 

    myCounter.decrementCounter();
    cout << "Counter after decrement: " << myCounter.getCounter() << endl;

    myCounter.decrementCounter();
    myCounter.decrementCounter();
    cout << "Counter after 2 more decrements: " << myCounter.getCounter() << endl;

    myCounter.resetCounter();
    cout << "Counter after reset: " << myCounter.getCounter() << endl; // Output: 0

    return 0;
}
