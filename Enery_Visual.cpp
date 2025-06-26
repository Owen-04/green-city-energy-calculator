#include <emscripten/bind.h>
#include <string>

using namespace emscripten;

// Calculate annual energy saved
double calculate_annual_energy_saved(double wattage, double hoursPerDay, double reductionPercent) {
    double originalUsage = wattage * hoursPerDay;
    double reducedUsage = originalUsage * (reductionPercent / 100.0);
    double dailySavedEnergy = reducedUsage / 1000.0;
    double annualSavedEnergy = dailySavedEnergy * 365;
    return annualSavedEnergy;
}

EMSCRIPTEN_BINDINGS(energy_module) {
    function("calculate_annual_energy_saved", &calculate_annual_energy_saved);
}
