#ifndef CALENDAR_HPP
#define CALENDAR_HPP

#include "event.hpp"
#include <vector>
#include <memory>

class Calendar {
private:
    std::vector<std::shared_ptr<Event>> events;

    bool is_conflicting(const Event& new_event, const Event& existing_event) const;
    std::string time_point_to_string(std::chrono::system_clock::time_point tp) const;

public:
    void add_event(const std::string& name, std::chrono::system_clock::time_point start, std::chrono::system_clock::time_point end);
    void refresh();
    void display_events() const;
};

#endif
