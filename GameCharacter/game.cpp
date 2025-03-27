#include "game.hpp"
#include <iostream>
#include <algorithm>

void Game::add_character(const Character& character) {
    characters.push_back(character);
}

void Game::display_characters() const {
    if (characters.empty()) {
        std::cout << "No characters in the game.\n";
        return;
    }

    for (const auto& character : characters) {
        character.display();
    }
}

void Game::character_attack(const std::string& attackerName, const std::string& targetName) {
    auto attacker = std::find_if(characters.begin(), characters.end(),
        [&attackerName](const Character& c) { return c.name == attackerName; });

    auto target = std::find_if(characters.begin(), characters.end(),
        [&targetName](const Character& c) { return c.name == targetName; });

    if (attacker != characters.end() && target != characters.end()) {
        attacker->attack(*target);
    } else {
        std::cout << "Character not found!\n";
    }
}

void Game::level_up_character_skill(const std::string& characterName, const std::string& skillName, int levelIncrease) {
    auto character = std::find_if(characters.begin(), characters.end(),
        [&characterName](const Character& c) { return c.name == characterName; });

    if (character != characters.end()) {
        character->level_up_skill(skillName, levelIncrease);
    } else {
        std::cout << "Character not found!\n";
    }
}
