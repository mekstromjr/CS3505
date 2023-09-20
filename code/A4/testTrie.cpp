#include "Trie.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;

int main() {
    string input { };
    vector<string> dictionaryWords { };
    Trie trie { };
    cin >> input;
    string word { };
    for(int i = 0; i < input.size(); i++) {
        if(input[i] == ',') {
            dictionaryWords.push_back(word);
            trie.addWord(word);
            word = "";
            continue;
        }
        word += input[i];
    }

    string prefix = "";

    vector<string> trieWords = trie.allWordsStartingWithPrefix(prefix);

    cout << "prefix: " << prefix << endl;
    for(string s : trieWords) {
        cout << s << endl;
    }

    return 0;
}