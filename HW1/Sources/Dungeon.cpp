#include "../Headers/Dungeon.hpp"
#include "../Headers/Room.hpp"
#include "../Headers/Player.hpp"
#include "../Headers/DLL.hpp"
#include "../Headers/Enemy_Queue.hpp"

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

Dungeon::Dungeon() {
    dungeon = new DLL();
    To_Check = new DLL();
    current_room = nullptr;
    to_check = nullptr;
    player = nullptr;
    room_stack = new Stack(3);
}

Dungeon::~Dungeon() {
    delete dungeon;
    delete To_Check;
    delete player;
    delete room_stack;
    cout << "Deleted dungeon" << endl;
}

void Dungeon::add_room(Room* room) {
    dungeon->add_room(room);
    To_Check->add_room(room);
}

void Dungeon::next_room() {
    dungeon->next_room();
    current_room = dungeon->get_current();
    if (current_room != nullptr) {
        room_stack->push(current_room);
    }
}

void Dungeon::previous_room() {
    dungeon->previous_room();
    current_room = dungeon->get_current();
    if (current_room != nullptr) {
        room_stack->pop();
    }
}

void Dungeon::next_to_check() {
    To_Check->next_room();
    to_check = To_Check->get_current();
}

void Dungeon::previous_to_check() {
    To_Check->previous_room();
    to_check = To_Check->get_current();
}

void Dungeon::show_choices() {
    cout << "--------------------------------" << endl;
    cout << left << setw(20) << "Room Name" << setw(20) << "Room Description" << endl;
    cout << setw(20) << current_room->getName() << setw(20) << current_room->getDescription() << endl << endl;
    cout << "What would you like to do? Enter the number of the choice" << endl;
    cout << "1. Attack enemies" << endl;
    cout << "2. Move to previous room" << endl;
    cout << "3. Move to next room" << endl;
    cout << "4. Show inventory" << endl;
    cout << "5. Use item" << endl;
    cout << "6. Show player stats" << endl;
    cout << "7. Show enemies in the room" << endl;
    cout << "--------------------------------" << endl;
    cout << "Enter your choice: ";
    int choice;
    
    do {
        cin >> choice;
        switch (choice) {
            case 1:
                current_room->attackEnemies(player);
                break;
            case 2:
                cout << "Moving to previous room" << endl;
                previous_room();
                show_choice_treasures();
                player->setStamina(player->getStamina() - 10);
                player->setMoves(player->getMoves() - 1);
                break;
            case 3:
                cout << "Moving to next room" << endl;
                next_room();
                show_choice_treasures();
                player->setStamina(player->getStamina() - 10);
                player->setMoves(player->getMoves() - 1);
                break;
            case 4:
                player->getInventory()->Print();
                break;
            case 5:
                useItem();
                break;
            case 6:
                cout << left << setw(10) << "Health" << setw(10) << "Stamina" << setw(10) << "Moves" << setw(10) << "Defense" << setw(10) << "Armor" << endl;
                cout << left << setw(10) << player->getHealth() << setw(10) << player->getStamina() << setw(10) << player->getMoves() << setw(10) << player->getDefense() << setw(10) << player->getArmor() << endl;break;
            case 7:
                current_room->printEnemies();
                break;
            default:
                cout << "Invalid choice" << endl;   
        }
    } while (choice < 1 || choice > 7);
}

void Dungeon::start() {
    cout << "--------------------------------" << endl;
    cout << "Welcome to the dungeon!" << endl;
    cout << "You have to navigate through the dungeon and defeat the enemies to reach the end" << endl;
    cout << "If you are not able to defeat the enemies or run out of moves, you lose" << endl;
    cout << "You can use items to increase your health, stamina, defense, and armor" << endl;
    cout << "You can also pick up weapons and armor to increase your attack and defense" << endl;
    cout << "You can also pick up artifacts that will be added to your inventory" << endl;
    cout << "--------------------------------" << endl;


    player = new Player();

    current_room = dungeon->get_current();
    to_check = To_Check->get_current();
    show_choice_treasures();
    while (player->getHealth() > 0 && player->getMoves() > 0) {
        show_choices();

        if (isGameOver()) {
            cout << "You have defeated all the enemies" << endl;
            cout << "You have won the game" << endl;
            break;
        }

    }

    cout << "Game over" << endl;
    if (player->getHealth() <= 0) {
        cout << "You have been defeated" << endl;
    } else {
        cout << "You have run out of moves" << endl;
    }

    cout << "Thank you for playing" << endl;

    // Freeing the memory by calling the destructor
    delete this;
}

void Dungeon::useItem() {
    cout << "Enter the name of the item you would like to use, this will be only used one for attack: ";
    string item_name;
    cin.ignore();
    getline(cin, item_name);
    Treasure item;
    item.setName(item_name);

    // Use the item
    // if it is a health potion, increase health
    // if it is a stamina potion, increase stamina
    // if it is a weapon, equip the weapon by setting the current weapon of the player
    // if it is armor, increase the defense of the player
    // if it is a shield, increase the armor of the player
    // if it is an artifact, just add it to the inventory

    while ( item_name != "Doomfang Blade" && item_name != "Phantom Piercer" && item_name != "Elixir of Vitalis" && item_name != "Vigor Draught" && item_name != "Eclipse Plate" && item_name != "Aegis of the Lost" && item_name != "Heart of the Abyss" && item_name != "Oblivion Core" && item_name != "Soul of the Void") {
        cout << "Invalid item. Please enter a valid item: ";
        cin.ignore();
        getline(cin, item_name);
        item.setName(item_name);
    }

    if (item_name == "Elixir of Vitalis") {
        player->setHealth(player->getHealth() + 10);
    } else if (item_name == "Vigor Draught") {
        player->setStamina(player->getStamina() + 10);
    } else if (item_name == "Doomfang Blade") {
        Treasure* sword = new Treasure();
        sword->setName("Doomfang Blade");
        sword->setAttack(20);
        sword->setDefense(0);
        player->setCurrentWeapon(sword);
    } else if (item_name == "Phantom Piercer") {
        Treasure* arrow = new Treasure();
        arrow->setName("Phantom Piercer");
        arrow->setAttack(15);
        arrow->setDefense(0);
        player->setCurrentWeapon(arrow);
    } else if (item_name == "Eclipse Plate") {
        player->setDefense(player->getDefense() + 5);
    } else if (item_name == "Aegis of the Lost") {
        player->setArmor(player->getArmor() + 5);
    } else if (item_name == "Heart of the Abyss" || item_name == "Oblivion Core" || item_name == "Soul of the Void") {
        player->getInventory()->Add(item);
    } else {
        cout << "Invalid item" << endl;
    }

    player->getInventory()->Remove(item);

    cout << item_name << " used" << endl;
}

void Dungeon::show_choice_treasures() {
    cout << "You are presented with the following treasures which can be either weapons, armor, or artifacts" << endl;
    if (current_room->getTreasure() == nullptr) {
        cout << "No treasures in the room" << endl;
    } else {
        cout << "If its a weapon, the attack is the attack power of the weapon otherwise it is 0" << endl;
        cout << "If its armor, the defense is the defense power of the armor otherwise it is 0" << endl << endl;

        cout << left << setw(20) << "Name" << setw(60) << "Description" << setw(20) << "Attack" << setw(20) << "Defense" << endl;
        for (unsigned int i = 0; i < current_room->getNumTreasures() - 1; i++) {
            cout << left << setw(20) << current_room->getTreasure()[i].getName() << setw(60) << current_room->getTreasure()[i].getDescription() << setw(20) << current_room->getTreasure()[i].getAttack() << setw(20) << current_room->getTreasure()[i].getDefense() << endl;
        }

        cout << "Would you like to pick up the " << current_room->getTreasure()[current_room->getNumTreasures() - 1].getName() << " which is an artifact? (yes/no): ";
        string choice;
        cin >> choice;
        if (choice == "yes") {
            player->getInventory()->Add(current_room->getTreasure()[current_room->getNumTreasures() - 1]);
            cout << current_room->getTreasure()[current_room->getNumTreasures() - 1].getName() << " picked up" << endl;
            // current_room->setNumTreasures(current_room->getNumTreasures() - 1);
        } else {
            cout << "You chose not to pick up the " << current_room->getTreasure()[current_room->getNumTreasures() - 1].getName() << endl;
        }

        cout << "Pick one of the weapons or defense given above: ";
        string weapon_choice;
        cin.ignore();
        getline(cin, weapon_choice);
        do {
            for (unsigned int i = 0; i < current_room->getNumTreasures(); i++) {
                if (current_room->getTreasure()[i].getName() == weapon_choice) {
                    player->getInventory()->Add(current_room->getTreasure()[i]);
                    // current_room->setNumTreasures(current_room->getNumTreasures() - 1);
                    cout << "Weapon picked up" << endl;
                    break;
                }
            }

            if (weapon_choice != "Doomfang Blade" && weapon_choice != "Phantom Piercer" && weapon_choice != "Eclipse Plate" && weapon_choice != "Aegis of the Lost" && weapon_choice != "Vigor Draught" && weapon_choice != "Elixir of Vitalis") {
                cout << "Invalid weapon. Please enter a valid weapon: ";
                getline(cin, weapon_choice);
            }
        } while (weapon_choice != "Doomfang Blade" && weapon_choice != "Phantom Piercer" && weapon_choice != "Eclipse Plate" && weapon_choice != "Aegis of the Lost" && weapon_choice != "Vigor Draught" && weapon_choice != "Elixir of Vitalis");

        cout << weapon_choice << " picked up" << endl;
    }
}

bool Dungeon::isGameOver() {
    // Save the current state of to_check
    DLL* originalToCheck = To_Check;
    Room* originalRoom = to_check;
    bool allEnemiesDefeated = false;

    // Iterate through all rooms
    do {
    
        if (to_check->EnemiesDefeated) {
            allEnemiesDefeated = true;

            // Restore the original state of to_check
            To_Check = originalToCheck;
            to_check = originalRoom;
            
            return allEnemiesDefeated;
        } else {
            allEnemiesDefeated = false;                
        }

        next_to_check();
    } while (To_Check->peek_next() != nullptr);

    // Restore the original state of to_check
    To_Check = originalToCheck;
    to_check = originalRoom;

    return allEnemiesDefeated;
}
