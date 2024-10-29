#include <iostream>
#include <string>

using namespace std;

/*How this program is desined is a little different from what I would expect, as normally one of the objects would carry some data about the other or
their would be some designated container class for paired up objects like the cars and meters in this assinment (I personally would just make each meter
hold a variable for a parked car and if this value is null (Are classed nullable by default in C++?) skip this parking meterbecause it is currently unused)
so I am just going to place them in paralell arrays and hope that that is what you wanted us to do. */

// Define a class for parked cars
class ParkedCar {
private:
    string make;
    string model;
    string color;
    string licenseNumber;
    int minutesParked;

public:

    // Constructor with default parameters
    ParkedCar(string mk = "MAKE", string ml = "MODEL", string co = "COLOR", string ln = "", int mn = 0)
        : make(mk), model(ml), color(co), licenseNumber(ln), minutesParked(mn) {}

    // Getters
    string getMake() { return make; }
    string getModel() { return model; }
    string getColor() { return color; }
    string getLicenseNumber() { return licenseNumber; }
    int getMinutesParked() { return minutesParked; }
};

// Define a class for parking meters
class ParkingMeter {
public:
    int timePaid;

    // Constructor with default parameter
    ParkingMeter(int tm = 0) : timePaid(tm) {}
};

// Define a class for officers
class PoliceOfficer {
public:
    string name;
    int badgeNum;

    // Constructor with default parameters
    PoliceOfficer(string nm = "NAME", int bn = 0) : name(nm), badgeNum(bn) {}

    bool checkForViolation(int time, ParkedCar car, ParkingMeter meter) {
        int minutesOverpaid = car.getMinutesParked() - meter.timePaid;
        return (minutesOverpaid > 0);
    }
};

// Define class for parking tickets
class ParkingTicket {
private:
    PoliceOfficer officer;
    ParkingMeter meter;
    ParkedCar car;

public:
    // Constructor that takes ParkedCar, ParkingMeter, and PoliceOfficer objects as parameters
    ParkingTicket(ParkedCar c, ParkingMeter m, PoliceOfficer o) : car(c), meter(m), officer(o) {}

    // Getters for parking ticket information
    string getVehicleLicenseNumber() { return car.getLicenseNumber(); }
    string getMakeAndModel() { return car.getModel() + " " + car.getMake(); }
    string getColor() { return car.getColor(); }
    int getMeterMinutesPaid() { return meter.timePaid; }
    int getMinutesParked() { return car.getMinutesParked(); }
    double getParkingFee() {
        int minutesOverpaid = car.getMinutesParked() - meter.timePaid;
        if (minutesOverpaid <= 0) return 0.0; // No fine
        else return (25 + (10 * ceil(minutesOverpaid / 60))); // Fine amount in dollars
    }

    void printTicket() {
        cout << "*** Parking Ticket ***\n";
        cout << "Officer " << officer.name << " Badge Number: B" << officer.badgeNum << "\n\n";
        cout << "Vehicle License Number: " << car.getLicenseNumber() << "\n";
        cout << "Make: " << getMakeAndModel() << "\n";
        cout << "Meter Minutes Paid: " << meter.timePaid << " minutes\n";
        cout << "Minutes Parked: " << car.getMinutesParked() << " minutes\n";
        cout << "Parking Fee: $" << getParkingFee() << "\n";
    }
};

int main() {
    // Test array of ParkedCars
    ParkedCar cars[] = {
        ParkedCar("Toyota", "Camry", "Red", "ABC123", 120),
        ParkedCar("Honda", "Civic", "Blue", "XYZ456", 90),
        ParkedCar("Ford", "Fiesta", "Green", "LMN789", 30)
    };

    // Sest array of ParkingMeters
    ParkingMeter meters[] = {
        ParkingMeter(60),
        ParkingMeter(75),
        ParkingMeter(45)
    };

    PoliceOfficer officer("Officer Smith", 1234);

    // Iterate through each car / meter pair and test for parking violations 
    for (int i = 0; i < sizeof(cars) / sizeof(cars[0]); i++) {
        if (officer.checkForViolation(meters[i].timePaid, cars[i], meters[i])) {
            ParkingTicket ticket(cars[i], meters[i], officer);
            ticket.printTicket();
            cout << endl;
        }
    }

    return 0;
}
