#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string deviceName;
    double wattage;
    double hoursPerDay;
    double reductionPercent;
    double dailySavedEnergy;
    double annualSavedEnergy;
    double totalAnnualEnergySaved = 0.0;
    char choice;

    vector<string> deviceList;
    vector<double> energyList;

    cout << "🌱 Welcome to the Green City Smart Living - Energy Saving Calculator!\n";
    cout << "---------------------------------------------------------------------\n";

    do {
        // Input section
        cout << "\nEnter the name of your device (e.g., Air Conditioner): ";
        cin.ignore();
        getline(cin, deviceName);

        cout << "Enter the device power consumption in watts (W): ";
        cin >> wattage;

        cout << "Enter the number of hours you use it per day: ";
        cin >> hoursPerDay;

        cout << "Enter the percentage of usage reduction you'd like to simulate (e.g., 20 for 20%): ";
        cin >> reductionPercent;

        // Calculation
        double originalUsage = wattage * hoursPerDay;
        double reducedUsage = originalUsage * (reductionPercent / 100.0);
        dailySavedEnergy = reducedUsage / 1000.0; // kWh
        annualSavedEnergy = dailySavedEnergy * 365;

        totalAnnualEnergySaved += annualSavedEnergy;
        deviceList.push_back(deviceName);
        energyList.push_back(annualSavedEnergy);

        // Result for this item
        cout << "\n📊 Energy Saving Summary for: " << deviceName << endl;
        cout << "---------------------------------------------------------------\n";
        cout << "Daily energy saved: " << dailySavedEnergy << " kWh\n";
        cout << "Estimated yearly energy saved: " << annualSavedEnergy << " kWh\n";

        if (annualSavedEnergy > 100) {
            cout << "🌍 Great job! You're making a big impact on the environment.\n";
        } else {
            cout << "🌱 Every small step counts! Keep up the effort.\n";
        }

        // Ask if user wants to continue
        cout << "\nDo you want to enter another device? (Y/N): ";
        cin >> choice;

    } while (choice == 'Y' || choice == 'y');

    // Final summary
    cout << "\n🧾 Summary of All Devices and Energy Saved:\n";
    cout << "---------------------------------------------------------------\n";
    for (size_t i = 0; i < deviceList.size(); ++i) {
        cout << "- " << deviceList[i] << ": " << energyList[i] << " kWh/year\n";
    }
    cout << "---------------------------------------------------------------\n";
    cout << "Total estimated energy saved annually: " << totalAnnualEnergySaved << " kWh\n";
    cout << "Thank you for contributing to a greener future! 🌿\n";

    return 0;
}
