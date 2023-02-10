#include <string>

class Node {
    private:
        Node* branches[26];
        bool isWord;
    public:
        Node();
        Node(bool isAWord);
        bool hasBranch(char branchName);
        void addBranch(char branchName);
        void addBranch(char branchName, bool isAWord);
        bool isAWord();
        Node& getBranch(char branchName);
        Node& operator=(const Node& other);
        // void print(string spacing);
};