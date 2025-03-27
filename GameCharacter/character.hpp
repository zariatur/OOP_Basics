#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include <vector>
#include <iostream>

class Character {
public:
    std::string name;
    int health;
    int power;
    struct Skill {
        std::string name;
        int level;
    };
    std::vector<Skill> skills;

    Character(const std::string& characterName, int characterHealth, int characterPower);

    void add_skill(const std::string& skillName, int skillLevel);
    void display() const;
    void attack(Character& target) const;
    void level_up_skill(const std::string& skillName, int levelIncrease);
};

#endif 
