#include <iostream>
#include "Trie.h"


Trie::Trie(){
    root = new Node();
}

Trie::Trie(Trie& toCopy){
    this->root = toCopy.getRoot(); 
}

Trie::~Trie(){

}

Trie& Trie::operator=(const Trie& other) {

}

Node& Trie::getRoot() {
    return root;
}

//Assume word is lowercase letters from a-z, no need to deal with malformed words
void Trie::addAWord(std::string word)  {
    char wordCharArr[word.length()];

    for(int i = 0; i < word.length(); i++) 
        wordCharArr[i] = word[i];

    
}

//Any character that is not [a-z] should return false, empty string returns false
bool Trie::isAWord(std::string word) {

}

//ie. Root node becomes the last character in the prefix after traversing to that node, then traverse the tree...
//if prefix is a word, include it. If prefix contains characters not included in [a-z], return an empty vector
//Empty prefix should return all words in the trie
std::vector<std::string> Trie::allWordsBeginningWithPrefix(std::string prefix) {

}
