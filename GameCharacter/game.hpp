#ifndef GAME_HPP
#define GAME_HPP

#include "character.hpp"
#include <vector>

class Game {
private:
    std::vector<Character> characters;

public:
    void add_character(const Character& character);
    void display_characters() const;
    void character_attack(const std::string& attackerName, const std::string& targetName);
    void level_up_character_skill(const std::string& characterName, const std::string& skillName, int levelIncrease);
};

#endif 
