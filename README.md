# Tournament Management System

## Overview
The **Tournament Management System** is a C++ application designed to organize and manage tournaments efficiently. It allows users to register players, schedule matches, record results, and determine winners based on predefined tournament rules.

## Features
- Player registration and management
- Tournament scheduling (single-elimination, round-robin, etc.)
- Match result recording
- Automatic winner determination
- Simple and intuitive command-line interface (CLI)
- File-based data storage

## Installation
1. Clone the repository:
   ```sh
   git clone https://github.com/thelazygenius404/Cpp_Project.git
   cd Cpp_project
   ```
2. Compile the program using a C++ compiler:
   ```sh
   g++ -o tournament main.cpp  -std=c++11
   ```
3. Run the executable:
   ```sh
   ./tournament
   ```

## Usage
1. Start the application.
2. Choose an option from the menu (e.g., register players, schedule matches, enter results).
3. Follow the on-screen instructions to manage the tournament.
4. View results and declare the winner.

## File Structure
```
/tournament-management
│── main.cpp         # Entry point of the program
│── arbitre.h        # Implementation of referee management
│── equipe.h         # Implementation of club management
│── match.h          # Implementation of match management
│── terrain.h        # Implementation of stadium management
│── arbitre.h        # Implementation of inscription management
│── README.md        # Documentation file
```

## Requirements
- C++11 or later
- A C++ compiler (e.g., GCC, Clang, MSVC)

## Future Enhancements
- Graphical User Interface (GUI)
- Support for additional tournament formats
- Online multiplayer support

