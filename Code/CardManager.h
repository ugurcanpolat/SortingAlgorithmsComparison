/* @Author
 * Student Name: Ugurcan Polat
 * Student ID : 150140117
 * Date: 11.10.2017
 */

#ifndef CardManager_h
#define CardManager_h

#include "Card.cpp"

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
    int getSize() const;
};

#endif /* CardManager_h */
