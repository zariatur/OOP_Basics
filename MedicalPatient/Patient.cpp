#include "patient.hpp"
#include <iostream>
#include <stdexcept>

Patient::Patient(const std::string& name, int age, float bodyTemp, int heartRate, int respRate, int bloodPressure) 
    : name(name), age(age), bodyTemp(bodyTemp), heartRate(heartRate), respRate(respRate), bloodPressure(bloodPressure) {
    validateVitals();
}

Patient::~Patient() {
    encryptData();
    std::cout << "Patient data encrypted upon destruction.\n";
}

void Patient::validateVitals() {
    if (bodyTemp < 36.0 || bodyTemp > 37.5)
        throw std::invalid_argument("Invalid body temperature.");
    if (heartRate < 60 || heartRate > 100)
        throw std::invalid_argument("Invalid heart rate.");
    if (respRate < 16 || respRate > 20)
        throw std::invalid_argument("Invalid respiratory rate.");
    if (bloodPressure < 80 || bloodPressure > 120)
        throw std::invalid_argument("Invalid blood pressure.");
}

void Patient::displayPatientInfo() const {
    std::cout << "Patient: " << name << "\n";
    std::cout << "Age: " << age << "\n";
    std::cout << "Body Temperature: " << bodyTemp << " °C\n";
    std::cout << "Heart Rate: " << heartRate << " bpm\n";
    std::cout << "Respiratory Rate: " << respRate << " breaths/min\n";
    std::cout << "Blood Pressure: " << bloodPressure << " mmHg\n";
}

void Patient::encryptData() {
    for (auto& c : name) {
        c ^= 0xAA;
    }
}

void Patient::decryptData() {
    for (auto& c : name) {
        c ^= 0xAA;
    }
}

std::string Patient::getName() const { return name; }
int Patient::getAge() const { return age; }
float Patient::getBodyTemp() const { return bodyTemp; }
int Patient::getHeartRate() const { return heartRate; }
int Patient::getRespRate() const { return respRate; }
int Patient::getBloodPressure() const { return bloodPressure; }
