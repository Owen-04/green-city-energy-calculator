#include <iostream>
#include <string>
using namespace std;

int main() {
    string deviceName;
    double wattage;
    double hoursPerDay;
    double reductionPercent;
    double dailySavedEnergy;
    double annualSavedEnergy;

    cout << "Welcome to the Green City Smart Living - Energy Saving Calculator!" << endl;
    cout << "---------------------------------------------------------------" << endl;

    cout << "Enter the name of your device (e.g., Air Conditioner): ";
    getline(cin, deviceName);

    cout << "Enter the device power consumption in watts (W): ";
    cin >> wattage;

    cout << "Enter the number of hours you use it per day: ";
    cin >> hoursPerDay;

    cout << "Enter the percentage of usage reduction you'd like to simulate (e.g., 20 for 20%): ";
    cin >> reductionPercent;

    // Calculate energy saved in kWh
    double originalUsage = wattage * hoursPerDay;
    double reducedUsage = originalUsage * (reductionPercent / 100.0);
    dailySavedEnergy = reducedUsage / 1000.0; // convert to kWh
    annualSavedEnergy = dailySavedEnergy * 365;

    cout << "\n📊 Energy Saving Summary for: " << deviceName << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << "Daily energy saved: " << dailySavedEnergy << " kWh" << endl;
    cout << "Estimated yearly energy saved: " << annualSavedEnergy << " kWh" << endl;

    // Environmental message
    if (annualSavedEnergy > 100) {
        cout << "Great job! You're making a big impact on the environment \n";
    } else {
        cout << "Every small step counts! Keep up the effort \n";
    }

    return 0;
}
