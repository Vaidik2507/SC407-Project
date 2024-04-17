// Function to calculate fuel consumption (in liters per kilometer)
float calculateFuelConsumption(int rpm, int speed, int throttle, float coolantTemp, float afr, int engineLoad) {
  // Calculate fuel consumption based on RPM, speed, throttle, coolant temperature, engine load, and air-fuel ratio
  // Example calculation logic using empirical formula, adjust according to your needs
  // Constants for fuel consumption calculation
  const float FUEL_DENSITY_GASOLINE = 0.74; // Density of gasoline in kg/liter
  const float FUEL_CONS_MULT = 0.00000003735; // Fuel consumption constant
  const float FUEL_CONS_AIR_DENSITY = 1.225; // Air density at sea level in kg/m^3
  const float ENGINE_DISPLACEMENT = 1.6; // Engine displacement in liters

  // Adjust throttle position for better accuracy (optional)
  throttle = map(throttle, 0, 100, 0, 70); // Map throttle range from 0-100 to 0-70

  // Calculate fuel consumption using empirical formula
  float fuelConsumption = FUEL_CONS_MULT * rpm * throttle * (1 + 0.0016 * speed) * FUEL_DENSITY_GASOLINE;

  // Adjust fuel consumption based on coolant temperature (assuming higher temperature decreases consumption)
  fuelConsumption *= (1 - 0.02 * (coolantTemp - 90)); // Adjust for temperature deviation from 90 Celsius

  // Adjust fuel consumption based on engine load (higher load increases consumption)
  fuelConsumption *= (1 + 0.01 * engineLoad); // Adjust for engine load

  // Adjust fuel consumption based on air-fuel ratio (lower AFR results in higher consumption)
  fuelConsumption *= (14.7 / afr); // Adjust for deviation from stoichiometric AFR

  return fuelConsumption;
}