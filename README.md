Welcome to the green city energy calculator
This is a simple C++ console program created as part of the LDCW6123 group project titled **"Green City, Smart Living: A Vision for Sustainable Urban Futures."**  
The tool helps users estimate how much energy they can save annually by reducing the usage of household electronic devices.

Features

- Calculates **daily and annual energy saved** based on user input
- Allows users to enter **multiple devices**
- Accepts:
  - Device name
  - Device power (in watts)
  - Daily usage (in hours)
  - Planned reduction percentage
- Displays a **summary of all devices and their individual savings**
- Shows **total estimated energy saved annually**

-  How It Works

1. User enters device information
2. The program calculates daily and annual energy saved:
    daily_saved = (power × hours × reduction%) / 1000
    annual_saved = daily_saved × 365
3. User can repeat for multiple devices
4. Summary report is shown at the end
Enter the name of your device (e.g., Air Conditioner): Laptop

Enter the device power consumption in watts (W): 100

Enter the number of hours you use it per day: 5

Enter the reduction percentage (e.g., 20 for 20%): 30

Energy Saving Summary for: Laptop
Daily energy saved: 0.15 kWh
Estimated yearly energy saved: 54.75 kWh

Add another device? (Y/N): n

