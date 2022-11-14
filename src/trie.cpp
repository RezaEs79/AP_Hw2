#include<string>
#include "trie.h"

Trie::Node::Node() {is_finished = false;}
Trie::Node::Node(char data, bool is_finished){
    data=data; is_finished=is_finished;}

Trie::Trie(){
    root = new Node();
}

Trie::~Trie(){}


void Trie::insert(std::string str){
    // std::vector<Node*> children;
    Node* curr = root;
    for (int i = 0; i < str.length(); i++) {
        int index = str[i] - 'A';
        if (!curr->children[index])
            curr->children[index] = new Node();
            curr = curr->children[index];
    }
   curr->is_finished= true; //last node as leaf
}

bool Trie::search(std::string query){ //check if key is present in trie. If present returns true
   Node* curr = root;
   for (int i = 0; i < query.length(); i++) {
      int index = query[i] - 'A';
      if (!root->children[index])
        return false;
      curr = root->children[index];
   }
   return (curr != NULL && curr->is_finished);
}

// void Trie::bfs(std::function<void(Node*& node)> func){}

// Trie::~Trie()
// {
//     if(root == nullptr) return;
//     std::vector<Node*> nodes;
//     this->bfs([&nodes](Trie::Node*& node){nodes.push_back(node);});
//     for(const auto& node : nodes)
//         delete node;
// }