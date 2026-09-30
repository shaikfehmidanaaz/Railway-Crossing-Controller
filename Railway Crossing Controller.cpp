#include <iostream>
#include <string>
using namespace std;

class RailwayCrossingController {
private:
    bool trainDetected;
    bool gateClosed;

public:
    RailwayCrossingController() {
        trainDetected = false;
        gateClosed = false;
    }

    void detectTrain(bool detected) {
        trainDetected = detected;
    }

    void controlGate() {
        if (trainDetected) {
            gateClosed = true;

            cout << "\nTrain Detected!" << endl;
            cout << "Warning Light: ON" << endl;
            cout << "Buzzer: ON" << endl;
            cout << "Railway Gate: CLOSED" << endl;
            cout << "Vehicles: STOP" << endl;
        }
        else {
            gateClosed = false;

            cout << "\nNo Train Detected." << endl;
            cout << "Warning Light: OFF" << endl;
            cout << "Buzzer: OFF" << endl;
            cout << "Railway Gate: OPEN" << endl;
            cout << "Vehicles: GO" << endl;
        }
    }

    void displayStatus() {
        cout << "\n--------- SYSTEM STATUS ---------" << endl;

        if (trainDetected)
            cout << "Train Status : APPROACHING" << endl;
        else
            cout << "Train Status : NOT DETECTED" << endl;

        if (gateClosed)
            cout << "Gate Status  : CLOSED" << endl;
        else
            cout << "Gate Status  : OPEN" << endl;

        cout << "---------------------------------" << endl;
    }
};

int main() {

    RailwayCrossingController system;

    int choice;

    cout << "====================================" << endl;
    cout << "   RAILWAY CROSSING CONTROLLER" << endl;
    cout << "====================================" << endl;

    cout << "\nEnter Train Status:" << endl;
    cout << "1. Train Approaching" << endl;
    cout << "2. No Train" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1) {
        system.detectTrain(true);
    }
    else if (choice == 2) {
        system.detectTrain(false);
    }
    else {
        cout << "Invalid choice!" << endl;
        return 0;
    }

    system.controlGate();
    system.displayStatus();

    return 0;
}
