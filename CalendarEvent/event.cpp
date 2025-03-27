#include "event.hpp"

Event::Event(const std::string& name, std::chrono::system_clock::time_point start, std::chrono::system_clock::time_point end)
    : name(name), start_time(start), end_time(end) {}

Event::~Event() {
    std::cout << "Event \"" << name << "\" has been deleted.\n";
}

std::string Event::get_name() const {
    return name;
}

std::chrono::system_clock::time_point Event::get_start_time() const {
    return start_time;
}

std::chrono::system_clock::time_point Event::get_end_time() const {
    return end_time;
}
