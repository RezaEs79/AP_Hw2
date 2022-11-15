#include "trie.h"
#include <functional>
#include <iostream>
#include <queue>
#include <string>

Trie::Node::Node(char data, bool is_finished)
{
    this->data = data;
    this->is_finished = is_finished;
}

Trie::Trie()
{
    root = new Node('\0', false);
}

Trie::~Trie() { }

void Trie::insert(std::string str)
{
    Node* curr = root;
    for (size_t i = 0; i < str.length(); i++) {
        std::cout << curr->children.size() << std::endl;
        if (!(root->children.size())) {
            Node* child { new Node { str[i], false } };
            curr->children.push_back(child);
            curr = curr->children[i];
        }
        else{
            bool found { false };
            for (size_t j = 0; j < curr->children.size(); j++) {
                if ((curr->children[j]->data) == str[i]) {
                    curr = curr->children[j];
                    found = true;
                    break;
                }
            }
            if (!found) {
                Node* child { new Node { str[i], false } };
                curr->children.push_back(child);
                curr = curr->children.back();
            }
        }

        // std::cout << root->children[i]->data <<std::endl;
    }
    curr->is_finished = true; // last node as leaf
    std::cout << "hi" << std::endl;
    // std::cout << this->root->children[0]->is_finished;
    // std::cout << curr->is_finished;

    //     int index = str[i] - 'a';
    //     if (!curr->children[index])
    //         curr->children[index] = new Node();
    //     curr = curr->children[index];
    // }
    // curr->is_finished = true; // last node as leaf
}

bool Trie::search(std::string query)
{ // check if key is present in trie. If present returns true
    Node* curr = root;
    for (int i = 0; i < query.length(); i++) {
        int index = query[i] - 'A';
        if (!root->children[index])
            return false;
        curr = root->children[index];
    }
    return (curr != NULL && curr->is_finished);
}

// void Trie::bfs(std::function<void(Node*& node)> func)
// {

//             void BFS (int source) {

//             queue<Node*> node;

//             visited[source] = true;
//             Q.push(source);

//             while (!Q.empty()) {

//                 int node = Q.front();
//                 Q.pop();
//                 cout << node << " ";

//                 for (auto& adj_node : adjlist[node]) {
//                     if (!visited[adj_node]) {
//                         visited[adj_node] = true;
//                         Q.push(adj_node);
//                     }
//                 }
//             }
// }
// Trie::~Trie()
// {
//     if(root == nullptr) return;
//     std::vector<Node*> nodes;
//     this->bfs([&nodes](Trie::Node*& node){nodes.push_back(node);});
//     for(const auto& node : nodes)
//         delete node;
// }