#pragma once
#include <vector>
#include <string>



class Inventory
{
public:

    std::vector<Inventory>backpack;

    void addItem(int itemID, int addQuantity);

};