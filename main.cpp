#include <iostream>
#include "Pokemon.h"

using namespace std;

int main()
{
    Pokemon p1;
    Pokemon p2;
    int fDamage, wDamage, gDamage;
    string userChoice;

    cout << "Welcome to Pallet Town!" << endl;

    while (userChoice != "no")
    {
    cout << "What type of Pokemon would you like to give trainer 1 (water, fire, or grass)?" << endl;
    cin >> p1.type;

    // Check if user entered a valid pokemon type
    while (p1.type != "water" && p1.type != "fire" && p1.type != "grass")
    {
        cerr << "Error. Invalid input." << endl;
        cout << "Please enter 'water', 'fire', or 'grass': ";
        cin >> p1.type;
    }

    cout << "How much health should trainer 1's Pokemon be?" << endl;
    cin >> p1.health;

    while (p1.health <= 0) // Pokemon health must be positive
    {
        cerr << "Error. Invalid input." << endl;
        cout << "Please enter a positive value: ";
        cin >> p1.health;
    }

    cout << "How much attack should trainer 1's Pokemon perform?" << endl;
    cin >> p1.attack;

    while (p1.attack <= 0)
    {
        cerr << "Error. Invalid input." << endl;
        cout << "Please enter a positive value: ";
        cin >> p1.attack;
    }

    cout << "Excellent! Now what about trainer 2's type?" << endl;
    cin >> p2.type;

    while (p2.type != "water" && p2.type != "fire" && p2.type != "grass")
    {
        cerr << "Error. Invalid input." << endl;
        cout << "Please enter 'water', 'fire', or 'grass': ";
        cin >> p2.type;
    }

    cout << "How much health should trainer 2's Pokemon be?" << endl;
    cin >> p2.health;

    while (p2.health <= 0)
    {
        cerr << "Error. Invalid input." << endl;
        cout << "Please enter a positive value: ";
        cin >> p2.health;
    }

    cout << "How much attack should trainer 2's Pokemon perform?" << endl;
    cin >> p2.attack;

    while (p2.attack <= 0)
    {
        cerr << "Error. Invalid input." << endl;
        cout << "Please enter a positive value: ";
        cin >> p2.attack;
    }

    while ((p1.health > 0) && (p2.health > 0))
    {
        // Trainer 1 attacks while fire and grass verse each other in battle
        if ((p1.type == "fire" && p2.type == "grass") || (p1.type == "grass" && p2.type == "fire"))
        {
            fDamage = 2 * p1.attack;
            gDamage = p1.attack / 2;

            if (p1.type == "fire" && p2.type == "grass")
            {
                p2.health = p2.health - fDamage;
                cout << p2.type << " health: " << p2.health << endl;
            }

            if (p1.type == "grass" && p2.type == "fire")
            {
                p2.health = p2.health - gDamage;
                cout << p2.type << " health: " << p2.health << endl;
            }
        }

        // Trainer 1 attacks while grass and water verse each other in battle
        if ((p1.type == "grass" && p2.type == "water") || (p1.type == "water" && p2.type == "grass"))
        {
            gDamage = 2 * p1.attack;
            wDamage = p1.attack / 2;

            if (p1.type == "grass" && p2.type == "water")
            {
                p2.health = p2.health - gDamage;
                cout << p2.type << " health: " << p2.health << endl;
            }

            if (p1.type == "water" && p2.type == "grass")
            {
                p2.health = p2.health - wDamage;
                cout << p2.type << " health: " << p2.health << endl;
            }
        }

        // Trainer 1 attacks while water and fire verse each other in battle
        if ((p1.type == "water" && p2.type == "fire") || (p1.type == "fire" && p2.type == "water"))
        {
            wDamage = 2 * p1.attack;
            fDamage = p1.attack / 2;

            if (p1.type == "water" && p2.type == "fire")
            {
                p2.health = p2.health - wDamage;
                cout << p2.type << "health: " << p2.health << endl;
            }

            if (p1.type == "fire" && p2.type == "water")
            {
                p2.health = p2.health - fDamage;
                cout << p2.type << " health: " << p2.health << endl;
            }
        }
        
        // Program stops looping after trainer 2's Pokemon is all out of health
        if (p2.health <= 0)
        {
            break;
        }

        // Trainer 2 attacks (fire vs grass)
        if ((p1.type == "fire" && p2.type == "grass") || (p1.type == "grass" && p2.type == "fire"))
        {
            fDamage = 2 * p2.attack;
            gDamage = p2.attack / 2;

            if (p1.type == "fire" && p2.type == "grass")
            {
                p1.health = p1.health - gDamage;
                cout << p1.type << " health: " << p1.health << endl;
            }

            if (p1.type == "grass" && p2.type == "fire")
            {
                p1.health = p1.health - fDamage;
                cout << p1.type << " health: " << p1.health << endl; 
            }
        }

        // Trainer 2 attacks (grass vs water)
        if ((p1.type == "grass" && p2.type == "water") || (p1.type == "water" && p2.type == "grass"))
        {
            gDamage = 2 * p2.attack;
            wDamage = p2.attack / 2;

            if (p1.type == "grass" && p2.type == "water")
            {
                p1.health = p1.health - wDamage;
                cout << p1.type << " health: " << p1.health << endl;
            }

            if (p1.type == "water" && p2.type == "grass")
            {
                p1.health = p1.health - gDamage;
                cout << p1.type << " health: " << p1.health << endl;
            }
        }

        // Trainer 2 attacks (water vs fire)
        if ((p1.type == "water" && p2.type == "fire") || (p1.type == "fire" && p2.type == "water"))
        {
            wDamage = 2 * p2.attack;
            fDamage = p2.attack / 2;

            if (p1.type == "water" && p2.type == "fire")
            {
                p1.health = p1.health - fDamage;
                cout << p1.type << " health: " << p1.health << endl;
            }

            if (p1.type == "fire" && p2.type == "water")
            {
                p1.health = p1.health - wDamage;
                cout << p1.type << " health: " << p1.health << endl;
            }
        }
    }

    // Winner is determined by which Pokemon's health did not hit 0 or below
    if (p1.health > p2.health)
    {
        cout << "Trainer 1 Wins!" << endl;
    }
    else
    {
        cout << "Trainer 2 Wins!" << endl;
    }

    cout << "If you would like to play again, enter anything you want. If not, enter 'no'." << endl;
    cin >> userChoice;
    }

    cout << "Thank you for playing!" << endl;

    return 0;
}