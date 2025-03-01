#include "Dungeon.hpp"
#include "Room.hpp"
#include "Player.hpp"
#include "DLL.hpp"
#include "Enemy.hpp"
#include "Treasure.hpp"
#include "Room_Stack.hpp"
#include "Enemy_Queue.hpp"

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <unordered_map>

using namespace std;

void make_enemies(Room* room) {
    // random seeder
    srand(time(0));

    static unordered_map<string, int> enemyHealths = {{"Shadow Stalker", 10}, {"Hollow Sentinel", 15}, {"Dark Knight", 20}, {"Soul Eater", 25}, {"Death Bringer", 30}, {"Bloodfang Berserker", 35}};
    static unordered_map<string, int> enemyAttacks = {{"Shadow Stalker", 7}, {"Hollow Sentinel", 8}, {"Dark Knight", 9}, {"Soul Eater", 10}, {"Death Bringer", 11}, {"Bloodfang Berserker", 12}};

    static string enemyNames[6] = {"Shadow Stalker", "Hollow Sentinel", "Dark Knight", "Soul Eater", "Death Bringer", "Bloodfang Berserker"};
    
    // making enemies
    Enemy* enemy1 = new Enemy();
    enemy1->setName(enemyNames[rand() % 6]);
    enemy1->setHealth(enemyHealths[enemy1->getName()]);
    enemy1->setAttack(enemyAttacks[enemy1->getName()]);

    Enemy* enemy2 = new Enemy();
    enemy2->setName(enemyNames[rand() % 6]);
    enemy2->setHealth(enemyHealths[enemy2->getName()]);
    enemy2->setAttack(enemyAttacks[enemy2->getName()]);

    Enemy* enemy3 = new Enemy();
    enemy3->setName(enemyNames[rand() % 6]);
    enemy3->setHealth(enemyHealths[enemy3->getName()]);
    enemy3->setAttack(enemyAttacks[enemy3->getName()]);

    // making a dynamic array of enemies   
    Enemy** enemies = new Enemy*[3];
    enemies[0] = enemy1;
    enemies[1] = enemy2;
    enemies[2] = enemy3;


    room->setEnemies(*enemies);
    room->setNumEnemies(3);

    Enemy_Queue* enemy_queue = new Enemy_Queue(3);
    for (unsigned int i = 0; i < room->getNumEnemies(); i++) {
        enemy_queue->enqueue(enemies[i]);
    }

    room->setEnemyQueue(enemy_queue);
}

void make_treasures(Room* room) {
    // random seeder
    srand(time(0));

    // list of treasures to randomly choose from
    static string WeaponsNames[2] = {"Doomfang Blade", "Phantom Piercer"};
    static string treasureNames[4] = {"Eilxir of Vitalis", "Vigor Draught", "Eclipse Plate", "Aegis of the Lost"};

    // making treasures
    Treasure* treasure1 = new Treasure();
    treasure1->setName(WeaponsNames[rand() % 2]);
    if (treasure1->getName() == "Doomfang Blade") {
        treasure1->setDescription("A cursed sword that drains the soul of its victims");
    } else if (treasure1->getName() == "Phantom Piercer") {
        treasure1->setDescription("Arrows that phase through armor and hit vital spots");
    }

    if (treasure1->getName() == "Doomfang Blade") {
        treasure1->setAttack(20);
        treasure1->setDefense(0);
    } else if (treasure1->getName() == "Phantom Piercer") {
        treasure1->setAttack(15);
        treasure1->setDefense(0);
    }

    Treasure* treasure2 = new Treasure();
    treasure2->setName(treasureNames[rand() % 4]);

    if (treasure2->getName() == "Elixir of Vitalis") {
        treasure2->setDescription("A rare elixir said to be made from celestial herbs");
    } else if (treasure2->getName() == "Vigor Draught") {
        treasure2->setDescription("A refreshing potion that restores energy instantly");
    } else if (treasure2->getName() == "Eclipse Plate") {
        treasure2->setDescription("A dark enchanted armor that absorbs some damage");
    } else if (treasure2->getName() == "Aegis of the Lost") {
        treasure2->setDescription("A legendary shield said to repel even the strongest magic");
    }

    if (treasure2->getName() == "Elixir of Vitalis") {
        treasure2->setAttack(0);
        treasure2->setDefense(0);
    } else if (treasure2->getName() == "Vigor Draught") {
        treasure2->setAttack(0);
        treasure2->setDefense(0);
    } else if (treasure2->getName() == "Eclipse Plate") {
        treasure2->setAttack(0);
        treasure2->setDefense(5);
    } else if (treasure2->getName() == "Aegis of the Lost") {
        treasure2->setAttack(0);
        treasure2->setDefense(0);
    }

    static unordered_map<string, string> artifactsDescriptions = {{"Heart of the Abyss", "A pulsating gemstone that whispers forbidden knowledge"},
        {"Oblivion Core", "A dark orb that consumes light and distorts reality"},
        {"Soul of the Void", "A swirling mass of shadows that hungers for life"}
    };
    string artifactsNames[3] = {"Heart of the Abyss", "Oblivion Core", "Soul of the Void"};

    Treasure* treasure3 = new Treasure();
    treasure3->setName(artifactsNames[rand() % 3]);
    treasure3->setDescription(artifactsDescriptions[treasure3->getName()]);
    treasure3->setAttack(0);
    treasure3->setDefense(0);

    // making a dynamic array of treasures
    Treasure* treasures = new Treasure[3];
    treasures[0] = *treasure1;
    treasures[1] = *treasure2;
    treasures[2] = *treasure3;

    room->setTreasures(treasures);
    room->setNumTreasures(3);
}

void make_dungeon() {
    Dungeon* dungeon = new Dungeon();

    Room* room1 = new Room();
    room1->setName("The Forsaken Chamber");
    room1->setDescription("A room filled with the echoes of past prisoners, their whispers guiding or deceiving.");
    make_enemies(room1);
    make_treasures(room1);
    dungeon->add_room(room1);

    Room* room2 = new Room();
    room2->setName("Bloodfang Arena");
    room2->setDescription("An ancient battle pit where the dead rise to challenge intruders.");
    make_enemies(room2);
    make_treasures(room2);
    dungeon->add_room(room2);
    cout << "Room 2: added" << endl;

    Room* room3 = new Room();
    room3->setName("The Void Nexus");
    room3->setDescription("A rift in reality distorts time, space, and sanity itself.");
    make_enemies(room3);
    make_treasures(room3);
    dungeon->add_room(room3);
    cout << "Room 3: added" << endl;

    dungeon->start();
}

int main() {
    make_dungeon();
    return 0;
}
