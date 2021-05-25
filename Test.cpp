#include "doctest.h"
#include "BinaryTree.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace ariel;
using namespace std;

TEST_CASE("create tree and add elements"){

    BinaryTree<string> bt;
    CHECK_NOTHROW(bt.add_root("4"));
    CHECK_NOTHROW(bt.add_left("4","3"));
    CHECK_NOTHROW(bt.add_right("4","5"));
    CHECK_NOTHROW(bt.add_right("5","7"));
    CHECK_NOTHROW(bt.add_left("7","10"));
    string root = "4";
    auto it = bt.begin_preorder();
    CHECK(*it == root);
    it++;
    CHECK(*it == "3");
    it++;
    CHECK(*it == "5");
    it++;
    CHECK(*it == "7");
    it++;
    CHECK(*it == "10");

    CHECK_NOTHROW(bt.add_root("2"));

}
TEST_CASE("post order traversal"){

    BinaryTree<string> bt;
    bt.add_root("4");
    bt.add_left("4","3");
    bt.add_right("4","5");
    bt.add_right("5","7");
    bt.add_left("7","10");

    vector<string> v = {"3" , "10" , "7" , "5" , "4"};
    auto it = bt.begin_preorder();
    for(auto s : v){
        CHECK(s == *it);
        it++;
    }

}



TEST_CASE("pre order traversal"){

    BinaryTree<string> bt;
    bt.add_root("4");
    bt.add_left("4","3");
    bt.add_right("4","5");
    bt.add_right("5","7");
    bt.add_left("7","10");

    vector<string> v = {"4" , "3" , "5" , "7" , "10"};
    auto it = bt.begin_preorder();
    for(auto s : v){
        CHECK(s == *it);
        it++;
    }

}

TEST_CASE("in order traversal"){

    BinaryTree<string> bt;
    bt.add_root("4");
    bt.add_left("4","3");
    bt.add_right("4","5");
    bt.add_right("5","7");
    bt.add_left("7","10");

    vector<string> v = {"3" , "4" , "5" , "7" , "10"};
    auto it = bt.begin_inorder();
    for(auto s : v){
        CHECK(s == *it);
        it++;
    }

}

TEST_CASE("adding elements to existing and non existing nodes"){

    BinaryTree<string> bt;
    bt.add_root("4");
    bt.add_left("4","3");
    bt.add_right("4","5");
    bt.add_right("5","7");
    bt.add_left("7","10");

    CHECK_NOTHROW(bt.add_left("10","15"));
    CHECK_NOTHROW(bt.add_right("7","8"));
    CHECK_THROWS(bt.add_left("11","12"));
    CHECK_THROWS(bt.add_left("12","6"));
    CHECK_THROWS(bt.add_left("12","6"));
}
