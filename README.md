# **OOP Game Project**

This is a simple object-oriented programming (OOP) game project implemented in C++ using Raylib. The game involves navigating through rooms, fighting enemies, collecting potions, and progressing through levels.

---

## **Features**
- **Player Movement**: Navigate through rooms and interact with objects.
- **Enemy AI**: Enemies move independently and engage in combat with the player.
- **Inventory System**: Collect and use potions to restore health or stamina.
- **Weapon System**: Equip weapons to fight enemies.
- **Room Progression**: Clear rooms by defeating all enemies to progress to the next level.

---

## **Setup Instructions**

### **Prerequisites**
1. Install a C++ compiler (e.g., GCC or MinGW for Windows).
2. Install [Raylib](https://www.raylib.com/) (a simple and easy-to-use library for game development).
3. Ensure you have a terminal or command prompt to run commands.

---

### **Compilation**
To compile the project, use the following command:

```bash
g++ -o maze.exe Sources/*.cpp  Main/main.cpp -I C:\raylib1\include -L C:\raylib1\lib -lraylib -lopengl32 -lgdi32 -lwinmm
```

### **Running the game**
```bash
./maze.exe
```

---


### File Structure
```
├── Headers/                # Header files for classes
│   ├── Enemy.hpp           # Enemy class
│   ├── Player.hpp          # Player class
│   ├── Room.hpp            # Room class
│   ├── Inventory.hpp       # Inventory class
│   └── ...                 # Other headers
├── Sources/                # Source files for implementation
│   ├── Enemy.cpp           # Enemy implementation
│   ├── Player.cpp          # Player implementation
│   ├── Room.cpp            # Room implementation
│   ├── Inventory.cpp       # Inventory implementation
│   └── ...                 # Other sources
├── Main/                   # Main entry point
│   └── main.cpp            # Main game loop
├── README.md               # Project documentation
└── raylib.h                # raylibs file
```

### Steps to run the game:
1. 
```bash
git clone https://github.com/your-username/your-repo-name.git
cd your-repo-name
```

2.
```bash
g++ -o maze.exe Sources/*.cpp  Main/main.cpp -I C:\raylib1\include -L C:\raylib1\lib -lraylib -lopengl32 -lgdi32 -lwinmm
```

3.
```bash
./maze.exe
```

---

### **Dependencies**
1. Raylib: A simple and easy-to-use library for game development.
2. Installation instructions: Raylib Installation Guide
3. C++17: Ensure your compiler supports C++17 or higher.
