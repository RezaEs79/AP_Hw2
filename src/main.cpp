
#include <iostream>
#include <gtest/gtest.h>
#include "trie.h"

int main(int argc, char **argv)
{
    // if (true) // make false to run unit-tests
    if (false) 
    {
        // debug section
        // class Trie *root = Trie();
   
        // Trie();
        // root.insert("THE");
        // Trie::root.insert("THERE");

    }
    else
    {
        
        ::testing::InitGoogleTest(&argc, argv);
        std::cout << "RUNNING TESTS ..." << std::endl;
        int ret{RUN_ALL_TESTS()};
        if (!ret)
            std::cout << "<<<SUCCESS>>>" << std::endl;
        else
            std::cout << "FAILED" << std::endl;
    }
    return 0;
}