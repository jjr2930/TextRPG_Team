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
    static constexpr int MIN_ITEM_NUMBER_FOR_SALE = 1;
    static constexpr int MAX_ITEM_NUMBER_FOR_SALE = 9;
    static constexpr int MIN_ITEM_NUMBER_FOR_BUY = 1;
    static constexpr int MAX_ITEM_NUMBER_FOR_BUY = 9;

    Shop();
public:
    void PrintMainMenu();
    void PrintSellMenu();
    void PrintBuyMenu();
private:
    vector<string> itemsForSale;
};

#endif