#ifndef PATIENT_HPP
#define PATIENT_HPP

#include <string>
#include <iostream>

class Patient {
private:
    std::string name;
    int age;
    float bodyTemp;
    int heartRate;
    int respRate;
    int bloodPressure;
    
    void validateVitals();

public:
    Patient(const std::string& name, int age, float bodyTemp, int heartRate, int respRate, int bloodPressure);
    ~Patient();
    
    void displayPatientInfo() const;
    void encryptData();
    void decryptData();

    std::string getName() const;
    int getAge() const;
    float getBodyTemp() const;
    int getHeartRate() const;
    int getRespRate() const;
    int getBloodPressure() const;
};

#endif
