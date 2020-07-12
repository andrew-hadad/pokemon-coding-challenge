#include <iostream>
#include "Pokemon.h"

using namespace std;

int main()
{
    trainer1 t1;
    trainer2 t2;
    int fDamage, wDamage, gDamage;
    string userChoice;

    cout << "Welcome to Pallet Town, Professor Oak!" << endl;

    while (userChoice != "no")
    {
    cout << "What type of Pokemon would you like to give trainer 1 (water, fire, or grass)?" << endl;
    cin >> t1.type;

    // Check if user entered a valid pokemon type
    while (t1.type != "water" && t1.type != "fire" && t1.type != "grass")
    {
        cerr << "Error. Invalid input." << endl;
        cout << "Please enter 'water', 'fire', or 'grass': ";
        cin >> t1.type;
    }

    cout << "How much health should trainer 1's Pokemon be?" << endl;
    cin >> t1.health;

    while (t1.health <= 0) // Pokemon health must be positive
    {
        cerr << "Error. Invalid input." << endl;
        cout << "Please enter a positive value: ";
        cin >> t1.health;
    }

    cout << "Excellent! Now what about trainer 2's type?" << endl;
    cin >> t2.type;

    while (t2.type != "water" && t2.type != "fire" && t2.type != "grass")
    {
        cerr << "Error. Invalid input." << endl;
        cout << "Please enter 'water', 'fire', or 'grass': ";
        cin >> t2.type;
    }

    cout << "How much health should trainer 2's Pokemon be?" << endl;
    cin >> t2.health;

    while (t2.health <= 0)
    {
        cerr << "Error. Invalid input." << endl;
        cout << "Please enter a positive value: ";
        cin >> t2.health;
    }

    while ((t1.health > 0) && (t2.health > 0))
    {
        cout << "Enter " << t1.type << " attack: ";
        cin >> t1.attack;

        // Pokemon attack must be positive
        while (t1.attack <= 0)
        {
            cerr << "Error. Invalid input." << endl;
            cout << "Please enter a positive value: ";
            cin >> t1.attack;
        }

        // Trainer 1 attacks while fire and grass verse each other in battle
        if ((t1.type == "fire" && t2.type == "grass") || (t1.type == "grass" && t2.type == "fire"))
        {
            fDamage = 2 * t1.attack;
            gDamage = t1.attack / 2;

            if (t1.type == "fire" && t2.type == "grass")
            {
                t2.health = t2.health - fDamage;
                cout << t2.type << " health: " << t2.health << endl;
            }

            if (t1.type == "grass" && t2.type == "fire")
            {
                t2.health = t2.health - gDamage;
                cout << t2.type << " health: " << t2.health << endl;
            }
        }

        // Trainer 1 attacks while grass and water verse each other in battle
        if ((t1.type == "grass" && t2.type == "water") || (t1.type == "water" && t2.type == "grass"))
        {
            gDamage = 2 * t1.attack;
            wDamage = t1.attack / 2;

            if (t1.type == "grass" && t2.type == "water")
            {
                t2.health = t2.health - gDamage;
                cout << t2.type << " health: " << t2.health << endl;
            }

            if (t1.type == "water" && t2.type == "grass")
            {
                t2.health = t2.health - wDamage;
                cout << t2.type << " health: " << t2.health << endl;
            }
        }

        // Trainer 1 attacks while water and fire verse each other in battle
        if ((t1.type == "water" && t2.type == "fire") || (t1.type == "fire" && t2.type == "water"))
        {
            wDamage = 2 * t1.attack;
            fDamage = t1.attack / 2;

            if (t1.type == "water" && t2.type == "fire")
            {
                t2.health = t2.health - wDamage;
                cout << t2.type << "health: " << t2.health << endl;
            }

            if (t1.type == "fire" && t2.type == "water")
            {
                t2.health = t2.health - fDamage;
                cout << t2.type << " health: " << t2.health << endl;
            }
        }
        
        // Program stops looping after trainer 2's Pokemon is all out of health
        if (t2.health <= 0)
        {
            break;
        }

        cout << "Enter " << t2.type << " attack: ";
        cin >> t2.attack;

        while (t2.attack <= 0)
        {
            cerr << "Error. Invalid input." << endl;
            cout << "Please enter a positive value: ";
            cin >> t2.attack;
        }

        // Trainer 2 attacks (fire vs grass)
        if ((t1.type == "fire" && t2.type == "grass") || (t1.type == "grass" && t2.type == "fire"))
        {
            fDamage = 2 * t2.attack;
            gDamage = t2.attack / 2;

            if (t1.type == "fire" && t2.type == "grass")
            {
                t1.health = t1.health - gDamage;
                cout << t1.type << " health: " << t1.health << endl;
            }

            if (t1.type == "grass" && t2.type == "fire")
            {
                t1.health = t1.health - fDamage;
                cout << t1.type << " health: " << t1.health << endl; 
            }
        }

        // Trainer 2 attacks (grass vs water)
        if ((t1.type == "grass" && t2.type == "water") || (t1.type == "water" && t2.type == "grass"))
        {
            gDamage = 2 * t2.attack;
            wDamage = t2.attack / 2;

            if (t1.type == "grass" && t2.type == "water")
            {
                t1.health = t1.health - wDamage;
                cout << t1.type << " health: " << t1.health << endl;
            }

            if (t1.type == "water" && t2.type == "grass")
            {
                t1.health = t1.health - gDamage;
                cout << t1.type << " health: " << t1.health << endl;
            }
        }

        // Trainer 2 attacks (water vs fire)
        if ((t1.type == "water" && t2.type == "fire") || (t1.type == "fire" && t2.type == "water"))
        {
            wDamage = 2 * t2.attack;
            fDamage = t2.attack / 2;

            if (t1.type == "water" && t2.type == "fire")
            {
                t1.health = t1.health - fDamage;
                cout << t1.type << " health: " << t1.health << endl;
            }

            if (t1.type == "fire" && t2.type == "water")
            {
                t1.health = t1.health - wDamage;
                cout << t1.type << " health: " << t1.health << endl;
            }
        }
    }

    // Winner is determined by which Pokemon's health did not hit 0 or below
    if (t1.health > t2.health)
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