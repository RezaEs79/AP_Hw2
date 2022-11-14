#include <vector>
#include<string>

#ifndef TRIE_H
#define TRIE_H

class Trie
{
  public:
    Trie();
    ~Trie();
    void insert(std::string str);
    bool search(std::string query);
    // void bfs(std::function<void(Node*& node)> func);
    
    class Node
    {
      public:
        Node(char data, bool is_finished);
        Node();
        std::vector<Node*> children;
        char data;
        bool is_finished;
    };

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