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

    Trie dictionaryTrie { };
    string inputText { };
    
    while(getline(dictionaryFile, inputText)) 
        dictionaryTrie.addWord(inputText);
    
    while(getline(queryFile, inputText)) {
        cout << "Checking " << inputText << ":" << endl;
        if(dictionaryTrie.isWord(inputText))
            cout << "Word found" << endl;
        else
            cout << "Word not found" << endl;
        
        for(string s: dictionaryTrie.allWordsStartingWithPrefix(inputText))
            cout << s << " ";
        
        cout << endl;
    }
    
    dictionaryFile.close();
    queryFile.close();

    //----------------- Rule-of-3 testing ----------------------//
    string words[8] {"a", "an", "ant", "aunt", "ban", "can", "yell", "zebra"};
    Trie og { };
    for(string s : words)
        og.addWord(s);

    //Copy Constructor Tests
    Trie duplicate {og};
    // Show all contents were copied by checking that they all contain the same number of words
    cout << "Copy constructor includes all contents test: ";    
    if(og.allWordsStartingWithPrefix("").size() == duplicate.allWordsStartingWithPrefix("").size())
        cout << "PASS" << endl;
    else
        cout << "FAIL" << endl;

    // Show they are independent by adding an extra 'word' to the duplicate
    cout << "Copy constructor independence test: ";
    string notInOg("notinog");
    duplicate.addWord(notInOg);
    // Show that duplicate has the extra word, but the original does not.
    if(og.isWord(notInOg) != duplicate.isWord(notInOg))
        cout << "PASS" << endl;
    else
        cout << "FAIL" << endl;

    //Assignment Operator Test
    og = duplicate;
    // Show they now have the same contents by checking that they both contain a word that og did not have before the assignment.
    cout << "Assignment Operator includes all contents test: ";
    if(og.isWord(notInOg) == duplicate.isWord(notInOg))
        cout << "PASS" << endl;
    else
        cout << "FAIL" << endl;
    
    cout << "Assignment Operator indendence test: ";
    // Show that duplicate has an extra word, but the original does not.
    notInOg = "notinogtwo";
    duplicate.addWord(notInOg);
    if(og.isWord(notInOg) != duplicate.isWord(notInOg))
        cout << "PASS" << endl;
    else
        cout << "FAIL" << endl;
    
    return 0;
}