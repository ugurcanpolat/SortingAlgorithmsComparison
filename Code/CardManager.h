/* @Author
 * Student Name: Ugurcan Polat
 * Student ID : 150140117
 * Date: 11.10.2017
 */

#ifndef CardManager_h
#define CardManager_h

#include "Card.cpp"

#include <vector> // vector

#ifndef type_enum
#define type_enum
typedef enum SortingType {
    NONE=0, FULLSORTED, FILTEREDSORT, INSERTION, MERGE,
    INSERTIONFULL, INSERTIONFILTER, MERGEFULL, MERGEFILTER
} SORTINGTYPE;
#endif /* type_enum */

class CardManager {
  private:
    vector<Card> cards;
    int size;
    void insertionSort(COMPARETYPE compareBy);
    void mergeSort(int p, int r, COMPARETYPE compareBy);
    void merge(int p, int q, int r, COMPARETYPE compareBy);
  public:
    CardManager();
    float fullSort(SORTINGTYPE sorting_algorithm);
    float filterSort(SORTINGTYPE sorting_algorithm);
    void insertCard(const Card& new_card);
    void writeOutputFile(const string file_name) const;
};

#endif /* CardManager_h */
