/**
 * Michael Ekstrom
 * u1170312
 * A4: A Trie and Rule-of-Three 
 */
#ifndef TRIE_H
#define TRIE_H

#include <vector>
#include <string>

class Trie {
    private:
        /// @brief Defines the number of branches each trie node has. Prevents magic numbers
        static const int branchesCount_ {26};

        /// @brief Defines which character will be located at branches_[0]. Prevents magic numbers
        static const char charOffset_ {'a'};

        /// @brief Stores if the current node, together with its parent nodes, forms a word.
        bool isWord_;

        /// @brief Array storing other nodes of the Trie. Each letter a-z is represented by the index 0-25 respectively
        Trie* branches_[branchesCount_];

        /// @brief Recursive method for adding characters to the trie
        /// @param word 
        void addWordRecursive(std::string word);

        /// @brief Recursive method for determining if a word is in the trie
        /// @param word 
        bool isWordRecursive(std::string word);

        /// @brief Recursivly gets all words from the trie that contain the given prefix
        /// @param prefix Contains the remaining characters of the prefix
        /// @param word Contains characters from trie above this node in the trie. ie. The word up to this point.
        /// @param words Contains words from the trie with the prefix up to this point
        /// @return vector containing all words in the trie below this node with the given prefix.
        std::vector<std::string>& allWordsStartingWithPrefixRecursive(std::string prefix, std::string word, std::vector<std::string>& wordsWithPrefix);

        /// @brief Adds all words from this node in the trie and below to the words list.
        /// @param word - characters from trie up to and including this node
        /// @param words - words from above this node in the trie which will be appended onto.
        /// @return vector containing all words in the trie below this node. 
        std::vector<std::string>& allWordsBelowCurrentNode(std::string word, std::vector<std::string>& words);

        /// @brief Checks the word to ensure all characters are from a-z lower case. 
        /// @param word 
        /// @return True if all characters are a-z lower case, False for any other characters or an empty string
        bool containsOnlyValidCharacters(std::string word);

       
    public:
        /// @brief Default Constructor
        Trie();

        /// @brief Copy Constructor
        /// @param other 
        Trie(const Trie& other);

        /// @brief Destructor
        ~Trie();

        /// @brief Assignment Operator
        /// @param other 
        /// @return 
        Trie& operator=(Trie other);

        /// @brief Attempts to add word to the trie. 
        ///     Duplicate adds do not change the Trie. 
        ///     Word is assumed to only be made up of lower-case characters from a-z.
        /// @param word - Word which will be added to the trie
        void addWord(std::string word);

        /// @brief Checks if the given word is in the trie. Any character in the string not 
        ///     made up of characters a-z or an empty string causes an immediate return of false. 
        ///     If the word is found in the Trie, the method returns true, otherwise returns false.  
        /// @param word - Word which is searched for in the trie.
        /// @return - True if word was found in the trie, false otherwise.
        bool isWord(std::string word);

        /// @brief Gets a list of words from the trie that start with the given prefix.
        ///     An empty prefix returns all words in the Trie.
        ///     A prefix containing invalid characters (not a-z) will return an empty vector.
        /// @param prefix - prefix all words in the output vector will begin with. 
        /// @return a vector that contains all the words in the Trie that begin with the prefix string. 
        std::vector<std::string> allWordsStartingWithPrefix(std::string prefix);
};

#endif