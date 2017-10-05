/* @Author
 * Student Name: Ugurcan Polat
 * Student ID : 150140117
 * Date: 11.10.2017
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "CardManager.cpp"

#define FULLSORTED   0
#define FILTEREDSORT 1
#define INSERTION    2
#define MERGE        3

#define INSERTIONFULL   4
#define INSERTIONFILTER 5
#define MERGEFULL       6
#define MERGEFILTER     7

using namespace std;

int main(int argc, const char * argv[]) {
    if (argc < 5) {
        cout << endl << "Missing arguments to proceed." << endl << endl;
        return 0;
    }
    
    int sorting_procedure, sorting_algorithm, sorting_type;
    
    if (strcmp(argv[1], "-full") == 0) {
        sorting_procedure = FULLSORTED;
    } else if (strcmp(argv[1], "-filter") == 0) {
        sorting_procedure = FILTEREDSORT;
    } else {
        cout << argv[1] << endl;
        cout << endl << "Invalid argument for sorting procedure selection." << endl << endl;
        return 0;
    }
    
    if (strcmp(argv[2], "-i") == 0) {
        sorting_algorithm = INSERTION;
    } else if (strcmp(argv[2], "-m") == 0) {
        sorting_algorithm = MERGE;
    } else {
        cout << endl << "Invalid argument for sorting algorithm selection." << endl << endl;
        return 0;
    }
    
    switch(sorting_algorithm) {
        case INSERTION:
            sorting_type = (sorting_procedure == FULLSORTED) ? INSERTIONFULL : INSERTIONFILTER;
            break;
        case MERGE:
            sorting_type = (sorting_procedure == FULLSORTED) ? MERGEFULL : MERGEFILTER;
            break;
    }
    
    string input_filename(argv[3]);
    string output_filename(argv[4]);
    
    ifstream input(input_filename, ifstream::in); // Read
    ofstream output(output_filename, ofstream::out); // Write
    
    if (!input.is_open() || !output.is_open()) {
        cout << endl << "Error openning file(s)." << endl << endl;
        return 0;
    }
    
    string line;
    
    while(!input.eof()) {
        getline(input, line); // Read the line.
        
        // If line is empty, no need to take action.
        if(line.empty()) break;
        
        stringstream linestream(line);
        
        string hero_name, hero_class, hero_rarity, hero_set, hero_type;
        int hero_cost;
        
        getline(linestream, hero_name, '\t');
        linestream >> hero_class >> hero_rarity >> hero_set >> hero_type >> hero_cost;
    }
    
    // Close all files.
    input.close();
    output.close();
    return 0;
}
