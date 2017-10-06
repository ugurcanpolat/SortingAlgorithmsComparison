/* @Author
 * Student Name: Ugurcan Polat
 * Student ID : 150140117
 * Date: 11.10.2017
 */

#include "CardManager.h"

CardManager::CardManager() {
    cards = nullptr;
    size = 0;
}

CardManager::~CardManager() {
    if (size == 1)
        delete cards;
    else if (size > 1)
        delete [] cards;
}

void CardManager::fullSort() {
    
}

void CardManager::filterSort() {
    
}

void CardManager::insertCard(const Card& new_card) {
    // If there is no card yet, create the new one. Then, return.
    if (size == 0) {
        cards = new Card;
        *cards = new_card;
        size++;
        return;
    }
    
    // Create temporary memory to keep data before deleting |cards|.
    Card *temp = new Card[size];
    
    // Copy all cards.
    for(int i=0; i < size; i++)
        temp[i] = *(cards+i);
    
    // Release the memory of |cards| to allocate new space.
    if (size == 1)
        delete cards;
    else if (size > 1)
        delete [] cards;
    
    // Allocate memory for new size.
    cards = new Card[size+1];
    
    // Get the info stored before re-allocating |cards|.
    for(int i=0; i < size; i++)
        *(cards+i) = temp[i];
    
    // Release the memory used by temp.
    delete [] temp;
    
    // Get new card.
    *(cards+size) = new_card;
    size++;
}

int CardManager::getSize() const {
    return size;
}
