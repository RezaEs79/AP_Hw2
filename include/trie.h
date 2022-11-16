#include <string>
#include <vector>
#include <functional>
#include <initializer_list> // for std::initializer_list
#include <iostream>
#include <queue>
#include <list>

#ifndef TRIE_H
#define TRIE_H

class Trie {
public:
    Trie();
    ~Trie();
    Trie(std::initializer_list<std::string> );
    void insert(std::string str);
    bool search(std::string query);

    Trie(const Trie& trie);

    Trie(Trie&& trie){root=trie.root;trie.root=nullptr;}

    void operator=(const Trie& trie);
    void operator=(Trie&& trie){root=trie.root;trie.root=nullptr;}

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

// class Cube
// {
// public:
//   Cube(double side); // Constructor
//   double volume(); // Calculate volume of a cube
//   bool hasLargerVolumeThan(Cube cube); // Compare volume of a cube with another
// private:
//   double m_side;
// };

/*
Cube::Cube(double side) : m_side{side}
{
std::cout << "Cube constructor called." << std::endl;
}*/

#endif // TRIE_H