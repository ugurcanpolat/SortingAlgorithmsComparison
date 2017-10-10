/* @Author
 * Student Name: Ugurcan Polat
 * Student ID : 150140117
 * Date: 11.10.2017
 * * * * * * * * * * * * * * * * * *
 
 Compile command: g++ -std=c++11 150140117.cpp -o project1
 
  * * * * * * * * * * * * * * * * * */

#include <iostream> // cout
#include <iomanip> // setprecision, fixed
#include <fstream> // ifstream
#include <sstream> // stringstream
#include <string> // string
#include <cstring> // strcmp

#include "CardManager.cpp"

#ifndef type_enum
#define type_enum
typedef enum SortingType {
    NONE=0, FULLSORTED, FILTEREDSORT, INSERTION, MERGE,
    INSERTIONFULL, INSERTIONFILTER, MERGEFULL, MERGEFILTER
} SORTINGTYPE;
#endif /* type_enum */

using namespace std;

int main(int argc, const char * argv[]) {
    // All arguments must be passed with run command
    if (argc < 5) {
        cout << endl << "Missing arguments to proceed." << endl << endl;
        return 0;
    }
    
    SORTINGTYPE sorting_procedure, sorting_algorithm, sorting_type = NONE;
    
    // Determine sorting procedure
    if (strcmp(argv[1], "-full") == 0) {
        sorting_procedure = FULLSORTED;
    } else if (strcmp(argv[1], "-filter") == 0) {
        sorting_procedure = FILTEREDSORT;
    } else {
        cout << argv[1] << endl;
        cout << endl << "Invalid argument for sorting procedure selection." << endl << endl;
        return 0;
    }
    
    // Determine sorting algorithm
    if (strcmp(argv[2], "-i") == 0) {
        sorting_algorithm = INSERTION;
    } else if (strcmp(argv[2], "-m") == 0) {
        sorting_algorithm = MERGE;
    } else {
        cout << endl << "Invalid argument for sorting algorithm selection." << endl << endl;
        return 0;
    }
    
    // Create a single variable for sorting type
    switch(sorting_algorithm) {
        case INSERTION:
            sorting_type = (sorting_procedure == FULLSORTED) ? INSERTIONFULL : INSERTIONFILTER;
            break;
        case MERGE:
            sorting_type = (sorting_procedure == FULLSORTED) ? MERGEFULL : MERGEFILTER;
            break;
        default:
            sorting_type = NONE;
            break;
    }
    
    // Get input and output filenames
    string input_filename(argv[3]);
    string output_filename(argv[4]);
    
    ifstream input(input_filename, ifstream::in); // Read
    
    if (!input.is_open()) {
        cout << endl << "Error opening input file." << endl << endl;
        return 0;
    }
    
    string line;
    CardManager cardManager;
    
    while(!input.eof()) {
        getline(input, line); // Read the line
        
        // If line is empty, no need to take action
        if(line.empty()) break;
        
        // Create stringstream to parse with '\t'
        stringstream linestream(line);
        
        string hero_name, hero_class, hero_rarity, hero_set, hero_type;
        int hero_cost;
        
        // Parse the line
        getline(linestream, hero_name, '\t');
        getline(linestream, hero_class, '\t');
        getline(linestream, hero_rarity, '\t');
        getline(linestream, hero_set, '\t');
        getline(linestream, hero_type, '\t');
        linestream >> hero_cost;
        // Create a new card and insert it to |cardManager|
        Card new_card(hero_name, hero_class, hero_rarity, hero_set, hero_type, hero_cost);
        cardManager.insertCard(new_card);
    }
    
    // Close the input file since it is no longer needed
    input.close();
    
    float sort_time = 0;
    
    // Sort cards depending on the sorting type
    switch (sorting_type) {
        case INSERTIONFULL:
            sort_time = cardManager.fullSort(INSERTION);
            break;
        case INSERTIONFILTER:
            sort_time = cardManager.filterSort(INSERTION);
            break;
        case MERGEFULL:
            sort_time = cardManager.fullSort(MERGE);
            break;
        case MERGEFILTER:
            sort_time = cardManager.filterSort(MERGE);
            break;
        default:
            break;
    }
    
    // Write sorted cards into the output file
    cardManager.writeOutputFile(output_filename);

    cout << endl << "Time elapsed: " << fixed << setprecision(0) << sort_time;
    cout << " microseconds" << endl << endl;
    
    return 0;
}
