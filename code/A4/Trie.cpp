/**
 * Michael Ekstrom
 * u1170312
 * A4: A Trie and Rule-of-Three 
 */
#include "Trie.h"

Trie::Trie() : isWord_ {false} {
    alphabet_ = new Trie*[alphabetSize_];
    
    for(int i = 0; i < alphabetSize_; i++)
        alphabet_[i] = nullptr;

    alphabet_ = alphabet_;
}

Trie::Trie(const Trie& other) {
    isWord_ = other.isWord_;
    alphabet_ = new Trie*[alphabetSize_] { };
    for(int i = 0; i < alphabetSize_; i++)
        alphabet_[i] = other.alphabet_[i];
}

Trie::~Trie() {
    for(int i = 0; i < alphabetSize_; i++)
        if(alphabet_[i])
            delete alphabet_[i];

    // delete [] alphabet_;
}

Trie& Trie::operator=(Trie other) {
    std::swap(alphabet_, other.alphabet_);
    std::swap(isWord_, other.isWord_);

    return *this;
}

void Trie::addWord(std::string word) {
    if(!isValidWord(word))
        return;

    addWordRecursive(word);
}

void Trie::addWordRecursive(std::string word) {
    if(word.size() == 0) {
        isWord_ = true;
        return;
    }

    if(!alphabet_[word[0] - 'a']) 
        alphabet_[word[0] - 'a'] = new Trie(); 

    (*alphabet_[word[0] - 'a']).addWordRecursive(word.substr(1)); 
}

bool Trie::isWord(std::string word) {
    //Check to make sure all characters are 'a' - 'z'
    if(!isValidWord(word))
        return false;
    
    return isWordRecursive(word);
}

bool Trie::isWordRecursive(std::string word) {
    if(word.size() == 0)
        return isWord_;    
    
    if(alphabet_[word[0] - 'a'])
        return (*alphabet_[word[0] - 'a']).isWordRecursive(word.substr(1)); 

    //Word is not in the trie
    return false;
}

std::vector<std::string> Trie::allWordsStartingWithPrefix(std::string word) {
    std::vector<std::string> words { };
    //Check to ensure word contains valid characters
    if(word.size() != 0 && !isValidWord(word))
        return words;

    allWordsStartingWithPrefixRecursive(word, "", words);

    return words;
}

std::vector<std::string>& Trie::allWordsStartingWithPrefixRecursive(std::string prefix, std::string word, std::vector<std::string>& words) {
    //Navigate to prefix node
    if(prefix.size() > 0) {
        if(alphabet_[prefix[0] - 'a'])
            return (*alphabet_[prefix[0] - 'a']).allWordsStartingWithPrefixRecursive(prefix.substr(1), word + prefix[0], words);
        else
            return words;
    }
        
    //If the current node, which is at or longer than the prefix, is a word, add it
    if(isWord_)
        words.push_back(word);

    //Check the branches of this node for words and add them
    for(unsigned int i = 0; i < alphabetSize_; i++) {
        if(alphabet_[i])
            (*alphabet_[i]).allWordsStartingWithPrefixRecursive(prefix, word + (char)(i + 'a'), words);
        
    }
    
    return words;
}


bool Trie::isValidWord(std::string word) {
    if(word.size() == 0)
        return false;
    
    for(unsigned int i = 0; i < word.size(); i++)
        if(word[i] - 'a' > 25 || word[i] - 'a' < 0)
            return false;

    return true;
}