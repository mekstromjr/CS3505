/**
 * Michael Ekstrom
 * u1170312
 * A4: A Trie and Rule-of-Three 
 */
#include "Trie.h"

Trie::Trie() : isWord_ {false} {
    for(unsigned int i = 0; i < branchesCount_; i++) {
        branches_[i] = nullptr;
    }
}

Trie::Trie(const Trie& other) {
    isWord_ = other.isWord_;
    
    for(unsigned int i = 0; i < branchesCount_; i++) {
        if(other.branches_[i]) {
            branches_[i] = new Trie(*other.branches_[i]);
        } else {
            branches_[i] = nullptr;
        }
    }
}

Trie::~Trie() {
    for(unsigned int i = 0; i < branchesCount_; i++) {
        delete branches_[i];
    }
}

Trie& Trie::operator=(Trie other) {
    std::swap(branches_, other.branches_);
    std::swap(isWord_, other.isWord_);

    return *this;
}

void Trie::addWord(std::string word) {
    if(containsOnlyValidCharacters(word)) {
        addWordRecursive(word);
    }
}

void Trie::addWordRecursive(std::string word) {
    // Base case: Reached end of string, no more charcters to add.
    if(0 == word.size()) {
        isWord_ = true;
        return;
    }

    if(!branches_[word[0] - charOffset_]) {
        branches_[word[0] - charOffset_] = new Trie(); 
    }

    (*branches_[word[0] - charOffset_]).addWordRecursive(word.substr(1)); 
}

bool Trie::isWord(std::string word) {
    if(containsOnlyValidCharacters(word)) {
        return isWordRecursive(word);
    }

    return false;
}
    

bool Trie::isWordRecursive(std::string word) {
    // Base case: Reached end of input string
    if(0 == word.size()) {
        return isWord_;    
    }
    
    if(branches_[word[0] - charOffset_]) {
        return (*branches_[word[0] - charOffset_]).isWordRecursive(word.substr(1)); 
    }

    // Base case: Reached end of the trie
    return false;
}

std::vector<std::string> Trie::allWordsStartingWithPrefix(std::string prefix) {
    std::vector<std::string> wordsWithPrefix { };

    if(0 == prefix.size()) {
        allWordsBelowCurrentNode("", wordsWithPrefix);
    }

    if(containsOnlyValidCharacters(prefix)) {
        allWordsStartingWithPrefixRecursive(prefix, "", wordsWithPrefix);
    }

    return wordsWithPrefix;
}

std::vector<std::string>& Trie::allWordsStartingWithPrefixRecursive(std::string prefix, std::string word, std::vector<std::string>& words) {
    // Base case: No more characters in the prefix
    if(0 == prefix.size()) {
       return allWordsBelowCurrentNode(word, words);
    }
    
    //Navigate to the node of the last character of prefix if it exists
    if(branches_[prefix[0] - charOffset_]) {
        return (*branches_[prefix[0] - charOffset_]).allWordsStartingWithPrefixRecursive(prefix.substr(1), word + prefix[0], words);
    }
    
    // Base case: Reached end of the trie
    return words;
}

std::vector<std::string>& Trie::allWordsBelowCurrentNode(std::string word, std::vector<std::string>& words) {
    if(isWord_) {
        words.push_back(word);
    }

    // Check all branches of this node for words
    for(unsigned int i = 0; i < branchesCount_; i++) {
        if(branches_[i]) {
            (*branches_[i]).allWordsBelowCurrentNode(word + (char)(i + charOffset_), words);
        }
    }

    // Base case: Reached end of the trie
    return words;
}

bool Trie::containsOnlyValidCharacters(std::string word) {
    if(0 == word.size()) {
        return false;
    }
    
    // Checks to ensure every character will have an index within the bounds of the trie.
    for(unsigned int i = 0; i < word.size(); i++) {
        if(word[i] - charOffset_ >= branchesCount_ || word[i] - charOffset_ < 0) {
            return false;
        }
    }

    return true;
}