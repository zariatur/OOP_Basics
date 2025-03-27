#ifndef EVENT_HPP
#define EVENT_HPP

#include <iostream>
#include <string>
#include <chrono>

class Event {
private:
    std::string name;
    std::chrono::system_clock::time_point start_time;
    std::chrono::system_clock::time_point end_time;

public:
    Event(const std::string& name, std::chrono::system_clock::time_point start, std::chrono::system_clock::time_point end);
    ~Event();

    std::string get_name() const;
    std::chrono::system_clock::time_point get_start_time() const;
    std::chrono::system_clock::time_point get_end_time() const;
};

#endif
