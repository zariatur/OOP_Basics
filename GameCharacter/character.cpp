#include "character.hpp"

Character::Character(const std::string& characterName, int characterHealth, int characterPower) 
    : name(characterName), health(characterHealth), power(characterPower) {}

void Character::add_skill(const std::string& skillName, int skillLevel) {
    Skill skill = {skillName, skillLevel};
    skills.push_back(skill);
}

void Character::display() const {
    std::cout << "Character: " << name << "\n";
    std::cout << "Health: " << health << "\n";
    std::cout << "Power: " << power << "\n";
    std::cout << "Skills:\n";
    for (const auto& skill : skills) {
        std::cout << " - " << skill.name << ": Level " << skill.level << "\n";
    }
}

void Character::attack(Character& target) const {
    std::cout << name << " attacks " << target.name << " with power " << power << "!\n";
    target.health -= power;
    if (target.health < 0) target.health = 0; 
    std::cout << target.name << " has " << target.health << " health left.\n";
}

void Character::level_up_skill(const std::string& skillName, int levelIncrease) {
    for (auto& skill : skills) {
        if (skill.name == skillName) {
            skill.level += levelIncrease;
            std::cout << name << "'s " << skillName << " leveled up to level " << skill.level << "!\n";
            return;
        }
    }
    std::cout << name << " doesn't have the skill " << skillName << ".\n";
}
