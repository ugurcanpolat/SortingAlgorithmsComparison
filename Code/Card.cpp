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
    
    int otherCost = cmp.getCost();
    
    // Get values for comparison type
    switch(compareBy) {
        case CLASS:
            self = cardClass;
            other = cmp.getClass();
            break;
        case COST:
            if (cost < otherCost) {
                return -1;
            } else if (cost == otherCost) {
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
        case FULL:
            return fullCompare(*this, cmp);
        default:
            return -1;
            break;
    }
    
    // Return string compare
    return self.compare(other);
}

int Card::fullCompare(const Card& self, const Card& cmp) const {
    /* This function compares |this| card with the |cmp| by
     full sort procedure */
    
    // Get the comparison results for Class, Cost and Name
    int classCompare = self.compare(cmp, CLASS);
    int costCompare = self.compare(cmp, COST);
    int nameCompare = self.compare(cmp, NAME);
    
    if (classCompare == 0) {
        if (costCompare == 0) { // Same Class, Cost and Name
            return nameCompare;
        } else { // Same Class, different Cost
            return costCompare;
        }
    } else { // Different Class
        return classCompare;
    }
}
