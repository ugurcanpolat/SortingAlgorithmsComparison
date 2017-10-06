/* @Author
 * Student Name: Ugurcan Polat
 * Student ID : 150140117
 * Date: 11.10.2017
 */

#include "Card.h"

Card::Card(const string inputName, const string inputCardClass,
           const string inputRarity, const string inputSet,
           const string inputType, const int inputCost) {
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

string Card::getRarity() const {
    return rarity;
}

string Card::getSet()const {
    return set;
}

string Card::getType() const {
    return type;
}

int Card::getCost() const {
    return cost;
}

int Card::compare(const Card& cmp, COMPARETYPE compareBy) const {
    string self, other;
    
    switch(compareBy) {
        case CLASS:
            self = cardClass;
            other = cmp.getClass();
            break;
        case COST:
            if (cost < cmp.getCost()) {
                return -1;
            } else if (cost == cmp.getCost()) {
                return 0;
            } else {
                return 1;
            } break;
        case NAME:
            self = name;
            other = cmp.getName();
            break;
        case TYPE:
            self = type;
            other = cmp.getType();
            break;
        default:
            return -1;
            break;
    }
    
    if (self.compare(other) > 0) {
        return -1;
    } else if (self.compare(other) == 0) {
        return 0;
    } else {
        return 1;
    }
}
