/* @Author
 * Student Name: Ugurcan Polat
 * Student ID : 150140117
 * Date: 11.10.2017
 */

#include "Card.h"

Card::Card(const string inputName, const string inputCardClass, const string inputRarity,
           const string inputSet, const string inputType, const int inputCost) {
    name = inputName;
    cardClass = inputCardClass;
    rarity = inputRarity;
    set = inputSet;
    type = inputType;
    cost = inputCost;
}

string Card::getName() const {
    return name;
}

string Card::getClass() const {
    return cardClass;
}

string Card::getType() const {
    return type;
}

int Card::getCost() const {
    return cost;
}
