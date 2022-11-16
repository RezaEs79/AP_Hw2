#include "trie.h"
// #include <functional>
// #include <iostream>
// #include <queue>
// #include <string>
// #include <list>

Trie::Node::Node(char data, bool is_finished)
{
    this->data = data;
    this->is_finished = is_finished;
}

Trie::Trie()
{
    root = new Node('\0', false);
}

void Trie::insert(std::string str)
{
    Node* curr = root;
    for (size_t i = 0; i < str.length(); i++) {

        if (!(root->children.size())) { // Just for empty Trie that has only root (No Children!)
            Node* child { new Node { str[i], false } };
            curr->children.push_back(child);
            curr = curr->children[i];
        }
        else{
            bool found { false };
            
            for (size_t j = 0; j < curr->children.size(); j++) { // Check if Common node is present, Continue from there
                if ((curr->children[j]->data) == str[i]) {
                    curr = curr->children[j];
                    found = true;
                    break;
                }
            }
            
            if (!found) { // If there was No Common Node make one and Point to it
                Node* child { new Node { str[i], false } };
                curr->children.push_back(child);
                curr = curr->children.back();
            }
        }
    }
    curr->is_finished = true; // last node as leaf

}

bool Trie::search(std::string query)
{ // check if query is present in trie. If present returns true
    Node* curr = root;
    unsigned int Sizeofstr{static_cast<unsigned>(query.length())};
    unsigned int len{0};
    for (size_t i = 0; i < Sizeofstr; i++) {
        for (size_t j = 0; j < curr->children.size(); j++) { 
                if ((curr->children[j]->data) == query[i]) { // Check if Common node is present, Continue from there
                    curr = curr->children[j];
                    len++;
                }
            }
    }
    return (Sizeofstr == len && curr->is_finished);
}

void Trie::bfs(std::function<void(Trie::Node*& node)> func)
{
    Node* curr=root;
    std::queue<Node*> Q;
    Q.push(root);
    while (!Q.empty()) { 
        curr = Q.front();
        if (curr->children.size())
        {
            for (size_t j = 0; j < curr->children.size(); j++)
                Q.push(curr->children[j]);
        }
        func(curr);
        Q.pop();
    }
}


Trie::~Trie()
{
    if(root == nullptr) return;
    std::vector<Node*> nodes;
    this->bfs([&nodes](Trie::Node*& node){nodes.push_back(node);});
    for(const auto& node : nodes)
        delete node;
}


void add_children(Trie::Node* new_node, Trie::Node* old_node)
{
    for(Trie::Node* old_node_child : old_node->children){
        Trie::Node* new_node_child = new Trie::Node(old_node_child->data, old_node_child->is_finished);
        new_node->children.push_back(new_node_child);
        add_children(new_node_child, old_node_child);
    }
}

Trie::Trie(const Trie& trie)
{
    root = new Node(trie.root->data, trie.root->is_finished);
    add_children(root, trie.root);
}

void Trie::operator=(const Trie& trie){
    root = new Node(trie.root->data, trie.root->is_finished);
    add_children(root, trie.root);

}

Trie::Trie(std::initializer_list<std::string> challenge):Trie()
{
    for(auto str :challenge){
        insert(str);
    }
}