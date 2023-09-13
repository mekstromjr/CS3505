#include "Node.h"
#include <string>
#include <vector>

class Trie {
    private:
        Node root;
        Node& getRoot();

    public:
        Trie();
        Trie(Trie& toCopy);
        ~Trie();
        Trie& operator=(const Trie& other);
        Trie& operator+=(const Trie& other);
        //Assume word is lowercase letters from a-z, no need to deal with malformed words
        void addAWord(std::string word);

        //Any character that is not [a-z] should return false, empty string returns false
        bool isAWord(std::string word);

        //ie. Root node becomes the last character in the prefix after traversing to that node, then traverse the tree...
        //if prefix is a word, include it. If prefix contains characters not included in [a-z], return an empty vector
        //Empty prefix should return all words in the trie
        std::vector<std::string> allWordsBeginningWithPrefix(std::string prefix);
        void print();

};