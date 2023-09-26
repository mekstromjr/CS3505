/**
 * Michael Ekstrom
 * u1170312
 * A4: A Trie and Rule-of-Three 
 */
#include "Trie.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::endl;
using std::string;
using std::vector;

const string testWords_[8] {"a", "an", "ant", "aunt", "ban", "can", "yell", "zebra"};
const string independenceTestWord_ {"test"}; 

/// @brief Small test for the inclusion of the copy constructor
bool copyConstructorIncludesAllContentsTest();

/// @brief Small test for the independence of the copy constructor
bool copyConstructorIndependenceTest();

/// @brief Small test for the inclusion of the assignment operator
bool assignmentOperatorIncludesAllContentsTest();

/// @brief Small test for the independence of the assignment operator
bool assignmentOperatorIndependenceTest();

/// @brief Uses testWords_ to build a small trie for testing
Trie setUpSmallTrie();

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
    
    while(getline(dictionaryFile, inputText)) {
        dictionaryTrie.addWord(inputText);
    }
    
    while(getline(queryFile, inputText)) {
        cout << "Checking " << inputText << ":" << endl;
        if(dictionaryTrie.isWord(inputText)) {
            cout << "Word found" << endl;
        } else {
            cout << "Word not found" << endl;
        }
        
        for(string s: dictionaryTrie.allWordsStartingWithPrefix(inputText)) {
            cout << s << " ";
        }
        cout << endl;
    }
    
    dictionaryFile.close();
    queryFile.close();

    //----------------- Rule-of-3 testing ----------------------//
    cout << endl << "---- Rule-of-3 testing ----" << endl;
    //-- Copy Constructor Tests --//
    // Show all contents were copied by checking that they all contain the same number of words
    cout << "Copy constructor includes all contents test: ";    
    if(copyConstructorIncludesAllContentsTest()) {
        cout << "PASS" << endl;
    } else {
        cout << "FAIL" << endl;
    }

    // Show they are independent by adding an extra 'word' to the duplicate
    cout << "Copy constructor independence test: ";
    // Show that duplicate has the extra word, but the original does not.
    if(copyConstructorIndependenceTest()) {
        cout << "PASS" << endl;
    } else {
        cout << "FAIL" << endl;
    }

    //-- Assignment Operator Tests --//
    // Show they now have the same contents by checking that they both contain a word that og did not have before the assignment.
    cout << "Assignment Operator includes all contents test: ";
    if(assignmentOperatorIncludesAllContentsTest()) {
        cout << "PASS" << endl;
    } else {
        cout << "FAIL" << endl;
    }
    
    cout << "Assignment Operator indendence test: ";
    // Show that duplicate has an extra word, but the original does not.
    if(assignmentOperatorIndependenceTest()) {
        cout << "PASS" << endl;
    } else {
        cout << "FAIL" << endl;
    }
    
    return 0;
}

bool copyConstructorIncludesAllContentsTest() {
    Trie original = setUpSmallTrie();
    Trie copy {original};

    vector<string> originalWords = original.allWordsStartingWithPrefix("");
    vector<string> copyWords = copy.allWordsStartingWithPrefix("");
    //Check both tries contain the same number of words
    if(originalWords.size() != copyWords.size()) {
        return false;
    }

    //Check both tries contain the same words
    for(string s: originalWords) {
        if(!copy.isWord(s)) {
            return false;
        }
    }

    return true;
}

bool copyConstructorIndependenceTest() {
    Trie original = setUpSmallTrie();
    Trie copy {original};

    copy.addWord(independenceTestWord_);

    vector<string> originalWords = original.allWordsStartingWithPrefix("");
    vector<string> copyWords = copy.allWordsStartingWithPrefix("");
    //Check both tries do not contain the same number of words, 
    if(originalWords.size() == copyWords.size()) {
        return false;
    }

    //Check extra word is not in the original trie.
    if(original.isWord(independenceTestWord_)) {
        return false;
    }

    return true;
}

bool assignmentOperatorIncludesAllContentsTest() {
    Trie original = setUpSmallTrie();
    Trie copy = original;

    vector<string> originalWords = original.allWordsStartingWithPrefix("");
    vector<string> copyWords = copy.allWordsStartingWithPrefix("");
    //Check both tries contain the same number of words
    if(originalWords.size() != copyWords.size()) {
        return false;
    }

    //Check both tries contain the same words
    for(string s: originalWords) {
        if(!copy.isWord(s)) {
            return false;
        }
    }

    return true;
}

bool assignmentOperatorIndependenceTest() {
    Trie original = setUpSmallTrie();
    Trie copy = original;

    copy.addWord(independenceTestWord_);

    vector<string> originalWords = original.allWordsStartingWithPrefix("");
    vector<string> copyWords = copy.allWordsStartingWithPrefix("");
    //Check both tries do not contain the same number of words, 
    if(originalWords.size() == copyWords.size()) {
        return false;
    }

    //Check extra word is not in the original trie.
    if(original.isWord(independenceTestWord_)) {
        return false;
    }

    return true;
   
}


Trie setUpSmallTrie() {
    Trie trie { };

    for(string s: testWords_) {
        trie.addWord(s);
    }

    return trie;
}