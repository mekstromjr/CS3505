/**
 * Michael Ekstrom
 * u1170312
 * A4: A Trie and Rule-of-Three 
 */
#include "Trie.h"
#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::endl;
using std::string;

int main(int argc, char **argv) {
    if(argc < 3) {
        cout << "Insufficent arguments. Quitting" << endl;
        return 0;
    }

    std::ifstream dictionaryFile, queryFile;
    dictionaryFile.open(argv[1]);
    if(!dictionaryFile.is_open()) {
        cout << "Dictionary file failed to open. Quitting" << endl;
        return 0;
    }
    
    queryFile.open(argv[2]);
    if(!queryFile.is_open()) {
        cout << "Query file Failed to open. Quitting" << endl;
        return 0;
    }

    string text { };
    Trie dictionaryTrie { };
    while(getline(dictionaryFile, text)) 
        dictionaryTrie.addWord(text);
    
    while(getline(queryFile, text)) {
        cout << "Checking " << text << ":" << endl;
        if(dictionaryTrie.isWord(text))
            cout << "Word found" << endl;
        else
            cout << "Word not found" << endl;
        
        for(string s: dictionaryTrie.allWordsStartingWithPrefix(text))
            cout << s << " ";
        
        cout << endl;
    }
    
    dictionaryFile.close();
    queryFile.close();

    //----------------- Rule-of-3 testing ----------------------
    // /*
    string words[8] {"a", "an", "ant", "aunt", "ban", "can", "yell", "zebra"};
    Trie og { };
    for(string s : words)
        og.addWord(s);

    //Copy Constructor
    cout << "Copy constructor independence test: ";
    Trie duplicate {og};
    //Show they are independent by adding an extra 'word' to the duplicate
    string notInOg("notinog");
    duplicate.addWord(notInOg);
    if(og.isWord(notInOg) != duplicate.isWord(notInOg))
        cout << "PASS" << endl;
    else
        cout << "FAIL" << endl;
    //*/

    // /*
    //Assignment Operator
    cout << "Assignment Operator test: ";
    og = duplicate;
    if(og.isWord(notInOg) == duplicate.isWord(notInOg))
        cout << "PASS" << endl;
    else
        cout << "FAIL" << endl;
    
    //*/
    
    return 0;
}