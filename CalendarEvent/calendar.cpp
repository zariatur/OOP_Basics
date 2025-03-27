#include "calendar.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <algorithm>


bool Calendar::is_conflicting(const Event& new_event, const Event& existing_event) const {
    return !(new_event.get_end_time() <= existing_event.get_start_time() || new_event.get_start_time() >= existing_event.get_end_time());
}

std::string Calendar::time_point_to_string(std::chrono::system_clock::time_point tp) const {
    std::time_t time = std::chrono::system_clock::to_time_t(tp);
    std::tm* tm = std::localtime(&time);
    std::stringstream ss;
    ss << std::put_time(tm, "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

void Calendar::add_event(const std::string& name, std::chrono::system_clock::time_point start, std::chrono::system_clock::time_point end) {
    Event new_event(name, start, end);

    for (const auto& existing_event : events) {
        if (is_conflicting(new_event, *existing_event)) {
            std::cout << "Conflict detected: \"" << name << "\" overlaps with \"" << existing_event->get_name() << "\".\n";
            return;
        }
    }

    events.push_back(std::make_shared<Event>(name, start, end));
    std::cout << "Event \"" << name << "\" added successfully.\n";
}

void Calendar::refresh() {
    auto now = std::chrono::system_clock::now();
    events.erase(std::remove_if(events.begin(), events.end(),
                                [now](const std::shared_ptr<Event>& event) {
                                    return event->get_end_time() < now;
                                }),
                 events.end());
}

void Calendar::display_events() const {
    if (events.empty()) {
        std::cout << "No upcoming events.\n";
        return;
    }

    for (const auto& event : events) {
        std::cout << "Event: " << event->get_name()
                  << " | Start: " << time_point_to_string(event->get_start_time())
                  << " | End: " << time_point_to_string(event->get_end_time()) << "\n";
    }
}
