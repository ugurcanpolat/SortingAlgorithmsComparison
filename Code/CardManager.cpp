/* @Author
 * Student Name: Ugurcan Polat
 * Student ID : 150140117
 * Date: 11.10.2017
 */

#include "CardManager.h"

#include <fstream>
#include <chrono>

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

float CardManager::fullSort(SORTINGTYPE sorting_algorithm) {
    using namespace chrono;
    
    auto sortingStart = high_resolution_clock::now();

    if (sorting_algorithm == INSERTION) {
        
    } else if (sorting_algorithm == MERGE) {
        
    } else {
        cout << "Wrong input for sorting algorithm selection.";
        return -1;
    }
    
    auto sortingEnd = high_resolution_clock::now();
    float elapsed_time = duration_cast<microseconds>(sortingEnd - sortingStart).count();
    
    return elapsed_time;
}

float CardManager::filterSort(SORTINGTYPE sorting_algorithm) {
    using namespace chrono;
    auto sortingStart = high_resolution_clock::now();
    
    if (sorting_algorithm == INSERTION) {
        Card key;
        int i, j;
        for (j=1; j < size; j++) {
            key = *(cards+j);
            i = j - 1;
            
            while ((i >= 0) && (key.compare(*(cards+i), TYPE)) > 0) {
                *(cards+(i+1)) = *(cards+i);
                i--;
            }
            *(cards+(i+1)) = key;
        }
    } else if (sorting_algorithm == MERGE) {
        
    } else {
        cout << "Wrong input for sorting algorithm selection.";
        return -1;
    }
    
    auto sortingEnd = high_resolution_clock::now();
    float elapsed_time = duration_cast<microseconds>(sortingEnd - sortingStart).count();
    
    return elapsed_time;
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

void CardManager::writeOutputFile(const string file_name) const {
    ofstream output(file_name, ofstream::out);
    
    if (!output.is_open()) {
        cout << endl << "Error opening output file." << endl << endl;
        return;
    }
    
    for (int counter = 0; counter < size; counter++) {
        output << (*(cards+counter)).getName() << '\t';
        output << (*(cards+counter)).getClass() << '\t';
        output << (*(cards+counter)).getRarity() << '\t';
        output << (*(cards+counter)).getSet() << '\t';
        output << (*(cards+counter)).getType() << '\t';
        output << (*(cards+counter)).getCost() << endl;
    }
    
    output.close();
}

