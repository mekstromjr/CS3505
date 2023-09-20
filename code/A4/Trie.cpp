/**
 * Michael Ekstrom
 * u1170312
 * A4: A Trie and Rule-of-Three 
 */
#include "Trie.h"

Trie::Trie() : isWord_ {false} {
    for(unsigned int i = 0; i < branchesCount_; i++)
        branches_[i] = nullptr;
}

Trie::Trie(const Trie& other) {
    isWord_ = other.isWord_;
    
    for(unsigned int i = 0; i < branchesCount_; i++)
        if(other.branches_[i])
            branches_[i] = new Trie(*other.branches_[i]);
        else
            branches_[i] = nullptr;
}

Trie::~Trie() {
    for(unsigned int i = 0; i < branchesCount_; i++)
        delete branches_[i];
}

Trie& Trie::operator=(Trie other) {
    std::swap(branches_, other.branches_);
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

    if(!branches_[word[0] - charOffset_]) 
        branches_[word[0] - charOffset_] = new Trie(); 

    (*branches_[word[0] - charOffset_]).addWordRecursive(word.substr(1)); 
}

bool Trie::isWord(std::string word) {
    //Check to make sure all characters are a-z
    if(!isValidWord(word))
        return false;
    
    return isWordRecursive(word);
}

bool Trie::isWordRecursive(std::string word) {
    if(word.size() == 0)
        return isWord_;    
    
    if(branches_[word[0] - charOffset_])
        return (*branches_[word[0] - charOffset_]).isWordRecursive(word.substr(1)); 

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
        if(branches_[prefix[0] - charOffset_])
            return (*branches_[prefix[0] - charOffset_]).allWordsStartingWithPrefixRecursive(prefix.substr(1), word + prefix[0], words);
        else
            return words;
    }
        
    //If the current node, which is at or longer than the prefix, is a word, add it
    if(isWord_)
        words.push_back(word);

    //Check the branches of this node for words and add them
    for(unsigned int i = 0; i < branchesCount_; i++) {
        if(branches_[i])
            (*branches_[i]).allWordsStartingWithPrefixRecursive(prefix, word + (char)(i + charOffset_), words);
        
    }
    
    return words;
}


bool Trie::isValidWord(std::string word) {
    if(word.size() == 0)
        return false;
    
    for(unsigned int i = 0; i < word.size(); i++)
        if(word[i] - charOffset_ > branchesCount_ - 1 || word[i] - charOffset_ < 0)
            return false;

    return true;
}