#ifndef SHOP_H
#define SHOP_H

enum class ShopMenuType
{
    Sell,
    Buy,
    Exit,
};

class Shop
{
public:
    ShopMenuType ProcessMenu();
};

#endif

