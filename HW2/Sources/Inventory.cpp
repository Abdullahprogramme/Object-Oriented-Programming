#include "../Headers/Inventory.hpp"
#include "../Headers/Potion.hpp"
#include "../Headers/HealthPotion.hpp"
#include "../Headers/StaminaPotion.hpp"
#include "../Headers/Player.hpp"
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include "../raylib.h" 

using namespace std;

Inventory::Inventory() : size(4), potionCount(0) {
    potions = new Potion*[size]; // Allocate memory for the array of potions
}

Inventory::~Inventory() {
    for (int i = 0; i < potionCount; i++) {
        delete potions[i]; // Delete each potion in the inventory
    }
    delete[] potions; // Delete the array of pointers to potions
}

void Inventory::increaseSize() {
    size += 1;
    Potion** newPotions = new Potion*[size]; // Allocate new memory for the larger array
    for (int i = 0; i < potionCount; i++) {
        newPotions[i] = potions[i]; // Copy existing potions to the new array
    }
    delete[] potions; // Delete the old array
    potions = newPotions; // Point to the new array
}

void Inventory::addPotion(Potion* potion) {
    if (potionCount >= size) {
        increaseSize(); // Increase the size of the inventory if full
    }
    potions[potionCount++] = potion; // Add the potion to the inventory and increment the count
}

void Inventory::removePotion(Potion* potion) {
    for (int i = 0; i < potionCount; i++) {
        if (potions[i] == potion) { // Check if the potion is in the inventory
            delete potions[i]; // Delete the potion
            for (int j = i; j < potionCount - 1; j++) {
                potions[j] = potions[j + 1]; // Shift remaining potions to fill the gap
            }
            potionCount--; // Decrease the count of potions
            break;
        }
    }
}

void Inventory::usePotion(const string& potionName, Player* player) {
    int effect = 0; 
    for (int i = 0; i < potionCount; i++) {
        if (potions[i]->getName() == potionName) { // Check if the potion is in the inventory
            Potion* potion = potions[i];
            if (dynamic_cast<HealthPotion*>(potion)) {
                HealthPotion* healthPotion = dynamic_cast<HealthPotion*>(potion);

                effect = healthPotion->getHealthRestored(); // Get the effect of the potion
                player->setHealth(player->getHealth() + effect); // Restore health to the player

                if (player->getHealth() > 100) { // Check if health exceeds max limit
                    player->setHealth(100);
                }
                cout << "You used a Health Potion! Effect: " << effect << endl;
            } else if (dynamic_cast<StaminaPotion*>(potion)) {
                StaminaPotion* staminaPotion = dynamic_cast<StaminaPotion*>(potion);

                effect = staminaPotion->getStaminaRestored(); // Get the effect of the potion
                player->setStamina(player->getStamina() + effect); // Restore stamina to the player

                if (player->getStamina() > 100) { // Check if stamina exceeds max limit
                    player->setStamina(100);
                }
            }

            removePotion(potion); // Remove the potion from the inventory
            return;
        }
    }
}

void Inventory::displayPotions(Player* player) {
    // Create a map to store potion counts
    unordered_map<string, int> potionCounts;
    for (int i = 0; i < potionCount; i++) {
        string potionNameLower = potions[i]->getName();
        transform(potionNameLower.begin(), potionNameLower.end(), potionNameLower.begin(), ::tolower);
        potionCounts[potionNameLower]++;
    }

    string potionName = ""; // Input buffer for potion name
    bool isDisplaying = true; // Flag to control the display loop

    while (isDisplaying && !WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Display potion counts
        int yOffset = 20;
        DrawText("Potions in Inventory:", 20, yOffset, 20, BLACK);
        yOffset += 30;

        for (const auto& [name, count] : potionCounts) {
            DrawText((name + " x" + to_string(count)).c_str(), 20, yOffset, 20, BLACK);
            yOffset += 30;
        }

        // Draw input box for potion name
        DrawRectangle(20, 300, 360, 40, LIGHTGRAY);
        DrawRectangleLines(20, 300, 360, 40, BLACK);
        DrawText("Enter potion name to use:", 20, 260, 20, BLACK);
        DrawText(potionName.c_str(), 25, 310, 20, BLACK);

        // Capture user input
        if (IsKeyPressed(KEY_BACKSPACE) && !potionName.empty()) {
            potionName.pop_back(); // Remove the last character
        } else {
            for (int key = KEY_A; key <= KEY_Z; key++) {
                if (IsKeyPressed(key)) {
                    potionName += static_cast<char>(key + 32); // Convert to lowercase
                }
            }
            if (IsKeyPressed(KEY_SPACE)) {
                potionName += ' '; // Add a space
            }
        }

        // When the user presses Enter, use the potion
        if (IsKeyPressed(KEY_ENTER)) {
            if (potionCounts.find(potionName) != potionCounts.end()) {
                
                // Capitalizing first letter of both words in potionName
                potionName[0] = toupper(potionName[0]); // Capitalize first letter
                for (size_t i = 1; i < potionName.length(); i++) {
                    if (potionName[i - 1] == ' ') {
                        potionName[i] = toupper(potionName[i]); // Capitalize letter after space
                    }
                }
                usePotion(potionName, player); // Use the potion
                potionCounts[potionName]--; // Decrease the count in the map
                if (potionCounts[potionName] <= 0) {
                    potionCounts.erase(potionName); // Remove from map if count is 0
                }
                potionName.clear(); // Clear the input buffer
                isDisplaying = false; // Exit the display loop
            } else {
                cout << "Potion not found in inventory!" << endl;
                potionName.clear(); // Clear the input buffer
                isDisplaying = false; // Exit the display loop
            }
        }

        // Allow the user to close the inventory with ESC
        if (IsKeyPressed(KEY_ESCAPE)) {
            isDisplaying = false; // Exit the display loop
        }

        EndDrawing();
    }
}