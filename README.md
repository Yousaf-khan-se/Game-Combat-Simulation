# Fantasy Creature Combat Simulator

A robust C++ console application that simulates tactical combat between mythical creatures (Dragons and Ichneumons). This project serves as a demonstration of core Object-Oriented Programming (OOP) principles and logic-driven game mechanics.

## 🕹️ Game Overview
This application simulates a turn-based environment where creatures have specific attributes like health, force, and position. The game logic calculates attack damage based on levels and distances, and handles "evolution" (leveling up) when a creature defeats an opponent.

## 💎 Core OOP Concepts
- **Inheritance**: Uses a base `Creature` class with specialized derived classes (`Dragon` and `Ichneumon`).
- **Encapsulation**: Protects creature stats and ensures state changes (like health reduction) happen through controlled methods.
- **Polymorphism**: Implements virtual-like behavior where different species have unique attack calculations (e.g., Ichneumons use poison, while Dragons are affected by distance).
- **Access Specifiers**: Proper use of `protected` members to allow child classes access to base attributes while hiding them from the global scope.

## ✨ Key Features
- **Dynamic Combat Logic**: Damage is not static; it is calculated using: `Damage = Level * Force`.
- **Species-Specific Perks**: 
  - **Ichneumon**: Adds a poison bonus to every attack.
  - **Dragon**: Can fly to specific positions but loses extra life points during attacks based on the distance from the target.
- **Leveling System**: Creatures gain levels upon winning a fight, increasing their combat effectiveness.
- **Position Tracking**: A 1D coordinate system that influences the "range" and "cost" of attacks.

## 🚀 How to Run
1. Ensure you have a C++ compiler installed (GCC/G++ recommended).
2. Compile the file:
   ```bash
   g++ creaturemain.cpp -o CombatSim
