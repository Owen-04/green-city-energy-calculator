// Wait for the WebAssembly module to be ready
Module.onRuntimeInitialized = function() {
    document.getElementById('calculateBtn').onclick = function() {
        const wattage = parseFloat(document.getElementById('wattage').value);
        const hoursPerDay = parseFloat(document.getElementById('hoursPerDay').value);
        const reductionPercent = parseFloat(document.getElementById('reductionPercent').value);

        const result = Module.calculate_annual_energy_saved(wattage, hoursPerDay, reductionPercent);
        document.getElementById('result').textContent =
            `Estimated Annual Energy Saved: ${result.toFixed(2)} kWh`;
    };
};
