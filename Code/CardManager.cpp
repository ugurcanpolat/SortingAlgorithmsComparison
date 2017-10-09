/* @Author
 * Student Name: Ugurcan Polat
 * Student ID : 150140117
 * Date: 11.10.2017
 */

#include "CardManager.h"

#include <fstream>
#include <chrono>

CardManager::CardManager() {
    size = 0;
}

void CardManager::insertionSort(COMPARETYPE compareBy) {
    Card key;
    int i, j;
    for (j=1; j < size; j++) {
        key = cards[j];
        i = j - 1;
        
        while ((i >= 0) && (key.compare(cards[i], compareBy)) < 0) {
            cards[i+1] = cards[i];
            i--;
        }
        cards[i+1] = key;
    }
}

void CardManager::mergeSort(int p, int r, COMPARETYPE compareBy) {
    if (p < r) {
        int q = (p + r) / 2;
        mergeSort(p, q, compareBy);
        mergeSort(q+1, r, compareBy);
        merge(p, q, r, compareBy);
    }
}

void CardManager::merge(int p, int q, int r, COMPARETYPE compareBy) {
    int n1 = (q - p) + 1;
    int n2 = (r - q);
    
    int i, j;
    
    vector<Card> left;
    vector<Card> right;
    
    left.resize(n1);
    right.resize(n2);
    
    for(i = 0; i < n1; i++) {
        left[i] = cards[p+i];
    }
    
    for(j = 0; j < n2; j++) {
        right[j] = cards[q+j+1];
    }

    i = j = 0;
    int k;
    for(k=p; k < r; k++) {
        if ((i >= n1) || (j >= n2))
            break;
        
        if ((left[i]).compare(right[j], compareBy) <= 0) {
            cards[k] = left[i];
            i++;
        } else {
            cards[k] = right[j];
            j++;
        }
    }
    
    while(i < n1) {
        cards[k] = left[i];
        i++;
        k++;
    }
    
    while(j < n2) {
        cards[k] = right[j];
        j++;
        k++;
    }
}

float CardManager::fullSort(SORTINGTYPE sorting_algorithm) {
    using namespace chrono;
    auto sortingStart = high_resolution_clock::now();
    
    if (sorting_algorithm == INSERTION) {
        insertionSort(FULL);
    } else if (sorting_algorithm == MERGE) {
        mergeSort(0, size-1, FULL);
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
        insertionSort(TYPE);
    } else if (sorting_algorithm == MERGE) {
        mergeSort(0, size-1, TYPE);
    } else {
        cout << "Wrong input for sorting algorithm selection.";
        return -1;
    }
    
    auto sortingEnd = high_resolution_clock::now();
    float elapsed_time = duration_cast<microseconds>(sortingEnd - sortingStart).count();
    
    return elapsed_time;
}

void CardManager::insertCard(const Card& new_card) {
    cards.push_back(new_card);
    size++;
}

void CardManager::writeOutputFile(const string file_name) const {
    ofstream output(file_name, ofstream::out);
    
    if (!output.is_open()) {
        cout << endl << "Error opening output file." << endl << endl;
        return;
    }
    
    for (int counter = 0; counter < size; counter++) {
        output << (cards[counter]).getName() << '\t';
        output << (cards[counter]).getClass() << '\t';
        output << (cards[counter]).getRarity() << '\t';
        output << (cards[counter]).getSet() << '\t';
        output << (cards[counter]).getType() << '\t';
        output << (cards[counter]).getCost() << endl;
    }
    
    output.close();
}

