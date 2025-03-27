#include "gps.hpp"

GPSLocation::GPSLocation() : latitude(0.0), longitude(0.0) {}

GPSLocation::GPSLocation(double lat, double lon) {
    setLatitude(lat);
    setLongitude(lon);
}

GPSLocation::~GPSLocation() {
    std::ofstream logFile("gps_log.txt", std::ios::app);
    if (logFile.is_open()) {
        logFile << "Last recorded position: Latitude = " << latitude 
                << ", Longitude = " << longitude << std::endl;
        logFile.close();
    }
    
    std::cout << "GPSLocation object destroyed. Last recorded position: "
              << "Latitude = " << latitude << ", Longitude = " << longitude << std::endl;
}

double GPSLocation::getLatitude() const {
    return latitude;
}

double GPSLocation::getLongitude() const {
    return longitude;
}

void GPSLocation::setLatitude(double lat) {
    if (lat < -90 || lat > 90) {
        throw std::invalid_argument("Error: Latitude must be between -90 and 90.");
    }
    latitude = lat;
}

void GPSLocation::setLongitude(double lon) {
    if (lon < -180 || lon > 180) {
        throw std::invalid_argument("Error: Longitude must be between -180 and 180.");
    }
    longitude = lon;
}

void GPSLocation::display() const {
    std::cout << "Current GPS Position: ";
    std::cout << std::fixed << std::setprecision(6) << "Latitude = " << latitude 
              << (latitude >= 0 ? "° N, " : "° S, ")
              << "Longitude = " << longitude 
              << (longitude >= 0 ? "° E" : "° W") << std::endl;
}
