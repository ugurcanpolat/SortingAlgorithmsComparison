/* @Author
 * Student Name: Ugurcan Polat
 * Student ID : 150140117
 * Date: 11.10.2017
 */

#ifndef CardManager_h
#define CardManager_h

#include "Card.cpp"

#ifndef type_enum
#define type_enum
typedef enum SortingType {
    NONE=0, FULLSORTED, FILTEREDSORT, INSERTION, MERGE,
    INSERTIONFULL, INSERTIONFILTER, MERGEFULL, MERGEFILTER
} SORTINGTYPE;
#endif /* type_enum */

#ifndef compare_enum
#define compare_enum
typedef enum CompareType {
    CLASS=0, COST, NAME, TYPE
} COMPARETYPE;
#endif /* compare_enum */


class CardManager {
  private:
    Card* cards;
    int size;
    void insertionSort();
    void mergeSort();
  public:
    CardManager();
    ~CardManager();
    float fullSort(SORTINGTYPE sorting_algorithm);
    float filterSort(SORTINGTYPE sorting_algorithm);
    void insertCard(const Card& new_card);
    void writeOutputFile(const string file_name) const;
};

#endif /* CardManager_h */
