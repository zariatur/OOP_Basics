#include "calendar.hpp"
#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>

std::chrono::system_clock::time_point get_time_from_user(const std::string& prompt) {
    std::cout << prompt << " (YYYY-MM-DD HH:MM:SS): ";
    std::string input;
    std::getline(std::cin, input);

    std::tm tm = {};
    std::istringstream ss(input);
    ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");

    if (ss.fail()) {
        std::cerr << "Invalid format. Please enter the date in YYYY-MM-DD HH:MM:SS format.\n";
        return get_time_from_user(prompt);
    }

    return std::chrono::system_clock::from_time_t(std::mktime(&tm));
}

int main() {
    Calendar my_calendar;
    int choice;

    while (true) {
        std::cout << "\nCalendar Menu:\n";
        std::cout << "1. Add Event\n";
        std::cout << "2. Show Events\n";
        std::cout << "3. Refresh Calendar\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) {
            std::string name;
            std::cout << "Enter event name: ";
            std::getline(std::cin, name);

            auto start = get_time_from_user("Enter start time");
            auto end = get_time_from_user("Enter end time");

            my_calendar.add_event(name, start, end);
        } else if (choice == 2) {
            my_calendar.display_events();
        } else if (choice == 3) {
            my_calendar.refresh();
            std::cout << "Expired events removed.\n";
        } else if (choice == 4) {
            std::cout << "Exiting...\n";
            break;
        } else {
            std::cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
