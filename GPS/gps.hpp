#ifndef GPS_HPP
#define GPS_HPP

#include <iostream>
#include <fstream>
#include <iomanip>

class GPSLocation {
private:
    double latitude;
    double longitude;

public:
    GPSLocation();
    GPSLocation(double lat, double lon); 

    ~GPSLocation();

    double getLatitude() const;
    double getLongitude() const;

    void setLatitude(double lat);
    void setLongitude(double lon);

    void display() const;
};

#endif 
