#include "Shop.h"
#include <iostream>

using namespace std;

Shop::Shop()
    : itemsForSale({ "Health Potion", "Power Up Potion" })
{
}

void Shop::PrintMainMenu()
{
    cout << "Welcome to my shop:\n";
    cout << "1. Sell" << endl;
    cout << "2. Buy" << endl;
    cout << "3. Exit" << endl;

    SelectedMenuType choice;
    int input;
    cin >> input;
    choice = static_cast<SelectedMenuType>(input);
    switch (choice)
    {
        case SelectedMenuType::Sell:
            PrintSellMenu();
            break;
        case SelectedMenuType::Buy:
            PrintBuyMenu();
            break;
        case SelectedMenuType::Exit:
            break;
        default:
            break;
    }
}

void Shop::PrintSellMenu()
{
    bool loop = true;
    while (true)
    {
        cout << "select to sell items." << endl;
        cout << "1 ~ 9: item to sell" << endl;
        cout << "0: exit" << endl;

        //for llop display player inventory
        int input;
        cin >> input;

        if (1 <= input && input <= 9)
        {
            //checking out of range;
            //1. remove item from player inventory
            //2. add gold to player inventory
        }
        else if (input == 0)
        {
            loop = false;
        }
        else
        {
            cout << "Invalid input, please try again." << endl;
        }
    }
}

void Shop::PrintBuyMenu()
{
    while (true)
    {
        cout << "select to buy items." << endl;
        cout << "1 ~ 9: item to buy" << endl;
        cout << "0: exit" << endl;

        //for loop display shop inventory
        int input;
        cin >> input;

        if (1 <= input && input <= 9)
        {
            //checking out of range;
            //1. remove gold from player inventory
            //2. add item to player inventory
        }
        else if (input == 0)
        {
            return;
        }
        else
        {
            cout << "Invalid input, please try again." << endl;
        }
    }
}
