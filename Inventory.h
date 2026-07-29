#pragma once
#include <vector>
#include <string>



class Inventory
{
public:

    std::vector<Inventory>backpack;
    std::vector<Inventory>potionPouch;

    std::string name;
    int itemID;
    int QTY;
    int maxQTY = 64;
    
    void addItem(int itemID, int addQTY);

};