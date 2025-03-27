#include "hospital.hpp"
#include <iostream>

void Hospital::addPatient(const Patient& patient) {
    patients.push_back(patient);
}

void Hospital::listPatients() const {
    if (patients.empty()) {
        std::cout << "No patients in the hospital.\n";
        return;
    }
    for (const auto& patient : patients) {
        patient.displayPatientInfo();
        std::cout << "--------------------------------\n";
    }
}
