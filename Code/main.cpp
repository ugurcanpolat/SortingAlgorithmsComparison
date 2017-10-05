/* @Author
 * Student Name: Ugurcan Polat
 * Student ID : 150140117
 * Date: 11.10.2017
 */

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, const char * argv[]) {
//    if (argc < 5) {
//        cout << "Missing arguments." << endl << "Exiting..." << endl;
//        return 0;
//    }
    
    if (strcmp(argv[1], "-full") == 0) {
        
    } else if (strcmp(argv[1], "-filter") == 0) {
        
    } else {
        cout << "Invalid argument for sorting procedure selection." << endl;
        return 0;
    }
    
    if (strcmp(argv[2], "-i") == 0) {
        
    } else if (strcmp(argv[2], "-m") == 0) {
        
    } else {
        cout << "Invalid argument for sorting algorithm selection." << endl;
        return 0;
    }
    
    ifstream input("hs-set-10k.txt", ifstream::in); // Read
    ofstream output("out.txt", ofstream::out); // Write
    
    if (!input.is_open()) {
        cout << "Error openning file." << endl;
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
