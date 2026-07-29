#include "Item.h"
#include <iostream>
#include <vector>
#include <string>

void Item::useitem(int itemID, int useQTY) {
	if (itemID >= 0 && itemID <= 7)
	{
		std::cout << "Wielded " << useQTY << " " << name << std::endl;
	}
    else if (itemID > 7 && itemID <12 && QTY > 0)
    {
        QTY -= useQTY;
        std::cout << "Used " << useQTY << " " << name << ". Remaining quantity: " << QTY << std::endl;
    }
}
	
