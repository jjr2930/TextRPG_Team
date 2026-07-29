#ifndef SHOP_H
#define SHOP_H

#include <string>
#include <vector>

using namespace std;

enum class SelectedMenuType
{
    Sell = 1,
    Buy = 2,
    Exit = 3,
};


class Shop
{
public:
    Shop();
public:
    void PrintMainMenu();
    void PrintSellMenu();
    void PrintBuyMenu();
private:
    vector<string> itemsForSale;
};

#endif