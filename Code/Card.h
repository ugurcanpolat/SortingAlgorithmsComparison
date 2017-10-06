/* @Author
 * Student Name: Ugurcan Polat
 * Student ID : 150140117
 * Date: 11.10.2017
 */

#ifndef Card_h
#define Card_h

#include <string>

using namespace std;

#ifndef compare_enum
#define compare_enum
typedef enum CompareType {
    CLASS=0, COST, NAME, TYPE
} COMPARETYPE;
#endif /* compare_enum */

class Card {
  private:
    string name;
    string cardClass;
    string rarity;
    string set;
    string type;
    int cost;
  public:
    Card() {};
    Card(const string name, const string cardClass,
         const string rarity, const string set,
         const string type, const int cost);
    string getName() const;
    string getClass() const;
    string getRarity() const;
    string getSet() const;
    string getType() const;
    int getCost() const;
    int compare(const Card& cmp, COMPARETYPE compareBy) const;
};

#endif /* Card_h */
