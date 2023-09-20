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
        static const int alphabetSize_ {26};

        /// @brief Stores if the current node and its parent nodes form a word.
        bool isWord_;
        /// @brief Array storing pointers to other nodes of the Trie. Each letter a-z is represented by the index 0-25 respectively
        Trie** alphabet_;

        /// @brief Recursive method for adding letters to the trie
        /// @param word 
        void addWordRecursive(std::string word);

        /// @brief Recursive method for determining if a word is in the trie
        /// @param word 
        bool isWordRecursive(std::string word);

        /// @brief Checks the word to ensure all characters are from a-z lower case. 
        /// @param word 
        /// @return true if all characters are a-z lower case, false if any other character appears.
        bool isValidWord(std::string word);

        /// @brief Returns a vector with all words that contain the given prefix
        /// @param prefix Contains the remaining characters of the prefix
        /// @param word Contains characters from trie above this node in the tree
        /// @param words Contains words from the trie with prefix this point
        /// @return 
        std::vector<std::string>& allWordsStartingWithPrefixRecursive(std::string prefix, std::string word, std::vector<std::string>& words);

    public:
        /// @brief default constructor
        Trie();

        /// @brief copy constructor
        /// @param other 
        Trie(const Trie& other);

        /// @brief A destructor
        ~Trie();

        /// @brief assignment= operator
        /// @param other 
        /// @return 
        Trie& operator=(Trie other);

        /// @brief The word passed into the method should be added to the Trie object. 
        ///     Duplicate adds should not change the Trie. 
        ///     You may assume that the word is only made up of lower-case characters from a-z.
        /// @param word 
        void addWord(std::string word);

        /// @brief Any character in the string not made up of characters 'a'-'z' causes an immediate return of false. 
        ///     If the word is found in the Trie, the method should return true, otherwise return false.  
        ///     A Trie should report that an empty string is not in the Trie.
        /// @param word 
        /// @return 
        bool isWord(std::string word);

        /// @brief Characters in the prefix string should be tested to make sure they are only 'a'-'z'.
        ///     If the prefix is a word, that should be included.
        ///     An empty prefix should return all words in the Trie.
        /// @param word 
        /// @return a vector<std::string> that contains all the words in the Trie that begin with the passed in argument prefix string. 
        std::vector<std::string> allWordsStartingWithPrefix(std::string word);
};

#endif