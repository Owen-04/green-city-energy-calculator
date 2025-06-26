#include <limits>
#include <iostream>
#include <string>
using namespace std;

// Structure to store device info
struct Device {
    string name;
    double annualEnergySaved;
};

// Input validation
double getValidatedInput(string prompt) {
    double value;

    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail() || value <= 0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a positive number.\n";
        } else {
            cin.ignore(1000, '\n');
            return value;
        }
    }
}

int main() {
    Device devices[100];  // Fixed-size array
    int count = 0;
    double wattage, hoursPerDay, reductionPercent;
    double dailySavedEnergy, annualSavedEnergy, totalAnnualEnergySaved = 0.0;
    char choice;

    cout << "Welcome to the Green City Smart Living - Energy Saving Calculator!\n";
    cout << "---------------------------------------------------------------------\n";

    do {
        Device device;

        cout << "\nEnter the name of your device (e.g., Air Conditioner): ";
        getline(cin, device.name);

        wattage = getValidatedInput("Enter the device power consumption in watts (W): ");
        hoursPerDay = getValidatedInput("Enter the number of hours you use it per day: ");
        reductionPercent = getValidatedInput("Enter the reduction percentage (e.g., 20 for 20%): ");

        // Calculate savings
        double originalUsage = wattage * hoursPerDay;
        double reducedUsage = originalUsage * (reductionPercent / 100.0);
        dailySavedEnergy = reducedUsage / 1000.0;
        annualSavedEnergy = dailySavedEnergy * 365;

        device.annualEnergySaved = annualSavedEnergy;
        devices[count++] = device;
        totalAnnualEnergySaved += annualSavedEnergy;

        cout << "\nEnergy Saving Summary for: " << device.name << endl;
        cout << "Daily energy saved: " << dailySavedEnergy << " kWh\n";
        cout << "Estimated yearly energy saved: " << annualSavedEnergy << " kWh\n";

        if (device.annualEnergySaved > 100)
            cout << "Great job! You're making a big impact on the environment.\n";
        else
            cout << "Every small step counts! Keep up the effort.\n";

        cout << "\nDo you want to enter another device? (Y/N): ";
        cin >> choice;
        cin.ignore();
    } while ((choice == 'Y' || choice == 'y') && count < 100);

    // Summary
    cout << "\nSummary of All Devices:\n";
    cout << "---------------------------------------------------------------\n";
    for (int i = 0; i < count; ++i) {
        cout << "- " << devices[i].name << ": " << devices[i].annualEnergySaved << " kWh/year\n";
    }
    cout << "---------------------------------------------------------------\n";
    cout << "Total estimated energy saved annually: " << totalAnnualEnergySaved << " kWh\n";
    cout << "Thank you for contributing to a greener future! \n";

    return 0;
}
