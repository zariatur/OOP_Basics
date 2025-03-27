#ifndef HOSPITAL_HPP
#define HOSPITAL_HPP

#include "patient.hpp"
#include <vector>

class Hospital {
private:
    std::vector<Patient> patients;

public:
    void addPatient(const Patient& patient);
    void listPatients() const;
};

#endif
