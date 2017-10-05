/* @Author
 * Student Name: Ugurcan Polat
 * Student ID : 150140117
 * Date: 11.10.2017
 */

#ifndef CardManager_h
#define CardManager_h

#include <string>
#include "Card.h"

class CardManager {
  private:
    Card* cards;
    int size;
  public:
    CardManager();
    ~CardManager();
    void fullSort();
    void filterSort();
    void insertCard(const Card& new_card);
};

#endif /* CardManager_h */
