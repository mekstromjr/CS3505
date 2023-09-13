#include "Node.h"


Node::Node() {
    isWord = false;
}

Node::Node(bool isAWord) {
    Node::isWord = isAWord;
}


bool Node::hasBranch(char branchName) {
    return nullptr == branches['a' - branchName];
}

void Node::addBranch(char branchName) {
    Node::addBranch(branchName, false);
}

void Node::addBranch(char branchName, bool isWord) {
    if(!hasBranch(branchName)) 
        branches['a'-branchName] = new Node();
}

bool Node::isAWord() {
    return isWord;
}

Node& Node::getBranch(char branchName) {
    return *branches['a' - branchName];
}