#include <functional>
#include <initializer_list> // for std::initializer_list
#include <iostream>
#include <list>
#include <queue>
#include <string>
#include <vector>

#ifndef TRIE_H
#define TRIE_H

class Trie {
public:
    Trie();
    ~Trie();
    Trie(std::initializer_list<std::string>);
    void insert(std::string str);
    bool search(std::string query);

    Trie(const Trie& trie);

    Trie(Trie&& trie);

    void operator=(const Trie& trie);

    void operator=(Trie&& trie);

    class Node {
    public:
        Node(char data, bool is_finished);
        Node();
        std::vector<Node*> children;
        char data;
        bool is_finished;
    };

    void bfs(std::function<void(Node*& node)> func);

    Node* root;

private:
};

#endif // TRIE_H