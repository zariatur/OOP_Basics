#include <iostream>
#include "game.hpp"
#include "character.hpp"

void add_character_from_input(Game& game) {
    std::string name;
    int health, power, num_skills;
    
    std::cout << "Enter character name: ";
    std::cin >> name;
    
    std::cout << "Enter character health: ";
    std::cin >> health;
    
    std::cout << "Enter character power: ";
    std::cin >> power;

    Character newCharacter(name, health, power);

    std::cout << "Enter the number of skills: ";
    std::cin >> num_skills;

    for (int i = 0; i < num_skills; ++i) {
        std::string skill_name;
        int skill_level;
        std::cout << "Enter skill " << i + 1 << " name: ";
        std::cin >> skill_name;
        
        std::cout << "Enter skill " << i + 1 << " level: ";
        std::cin >> skill_level;
        
        newCharacter.add_skill(skill_name, skill_level);
    }

    game.add_character(newCharacter);
}

void attack_character_from_input(Game& game) {
    std::string attacker_name, target_name;
    std::cout << "Enter attacker character name: ";
    std::cin >> attacker_name;
    
    std::cout << "Enter target character name: ";
    std::cin >> target_name;
    
    game.character_attack(attacker_name, target_name);
}

void level_up_skill_from_input(Game& game) {
    std::string character_name, skill_name;
    int level_increase;
    
    std::cout << "Enter character name: ";
    std::cin >> character_name;

    std::cout << "Enter skill name: ";
    std::cin >> skill_name;

    std::cout << "Enter level increase: ";
    std::cin >> level_increase;

    game.level_up_character_skill(character_name, skill_name, level_increase);
}

int main() {
    Game game;

    int choice;
    while (true) {
        std::cout << "Game Menu:\n";
        std::cout << "1. Add Character\n";
        std::cout << "2. Display Characters\n";
        std::cout << "3. Attack Character\n";
        std::cout << "4. Level Up Skill\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                add_character_from_input(game);
                break;
            case 2:
                game.display_characters();
                break;
            case 3:
                attack_character_from_input(game);
                break;
            case 4:
                level_up_skill_from_input(game);
                break;
            case 5:
                std::cout << "Exiting the game.\n";
                return 0;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    }
}
