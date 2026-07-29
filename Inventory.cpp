#include "Inventory.h"
void Inventory::addItem(int itemID, int addQTY)
{

    for (int i = 0; i < backpack.size(); i++)
    {
        if (backpack[i].itemID == itemID)
        {
            backpack[i].QTY += addQTY;
            return;
        }
    }

    if (backpack.size() < 10)
    {
        Inventory newSlot;

        newSlot.itemID = itemID;
        newSlot.QTY = addQTY;

        backpack.push_back(newSlot);
    }
    else
    {
        cout << "Inventory Full!\n";
    }
}