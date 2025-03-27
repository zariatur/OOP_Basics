#include "gps.hpp"
#include <iostream>
#include <limits>

double getValidatedInput(const std::string& prompt, double min, double max) {
    double value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        
        if (std::cin.fail() || value < min || value > max) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a value between " << min << " and " << max << ".\n";
        } else {
            return value;
        }
    }
}

int main() {
    double lat = getValidatedInput("Enter Latitude (-90 to 90): ", -90.0, 90.0);
    double lon = getValidatedInput("Enter Longitude (-180 to 180): ", -180.0, 180.0);

    try {
        GPSLocation gps(lat, lon);
        gps.display();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
