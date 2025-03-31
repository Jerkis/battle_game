#include <iostream>
#include <string>
using namespace std;

// Base class
class Character {
protected:
    string name;
    int health;

public:
    Character(string n, int h) : name(n), health(h) {}

    virtual void attack(Character& target) = 0;

    void displayStats() {
        cout << name << "'s Health: " << health << endl;
    }

    bool isAlive() {
        return health > 0;
    }

    string getName() const {
        return name;
    }

    void takeDamage(int damage) {
        health -= damage;
        if (health < 0) health = 0;
    }
};

// Derived class: Hero
class Hero : public Character {
public:
    Hero(string n) : Character(n, 100) {}

    void attack(Character& target) override {
        cout << name << " swings a mighty sword at " << target.getName() << "!" << endl;
        target.takeDamage(20);
    }
};

// Derived class: Monster
class Monster : public Character {
public:
    Monster(string n) : Character(n, 80) {}

    void attack(Character& target) override {
        cout << name << " bites " << target.getName() << "!" << endl;
        target.takeDamage(15);
    }
};

int main() {
    Hero player("Knight");
    Monster enemy("Goblin");

    cout << "\n BATTLE BEGINS \n";
    player.displayStats();
    enemy.displayStats();

    // Turn-based battle until one is defeated
    while (player.isAlive() && enemy.isAlive()) {
        player.attack(enemy);
        if (enemy.isAlive()) {
            enemy.attack(player);
        }
        player.displayStats();
        enemy.displayStats();
    }

    if (!player.isAlive()) {
        cout << "\nThe Knight has fallen. Goblin wins!" << endl;
    } else {
        cout << "\nThe Goblin has been defeated!" << endl;
    }

    cout << "\n Battle Over " << endl;
    return 0;
}