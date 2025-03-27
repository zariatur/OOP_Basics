#include "hospital.hpp"
#include "patient.hpp"
#include <iostream>

int main() {
    try {
        Patient patient1("John Doe", 30, 36.5, 75, 18, 110);
        Patient patient2("Jane Smith", 25, 37.0, 85, 19, 115);

        Hospital hospital;
        hospital.addPatient(patient1);
        hospital.addPatient(patient2);

        std::cout << "Listing all patients in the hospital:\n";
        hospital.listPatients();
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
