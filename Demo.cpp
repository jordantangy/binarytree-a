/**
 * Demo file for the exercise on binary tree
 *
 * @author Erel Segal-Halevi
 * @since 2021-04
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "BinaryTree.hpp"
using namespace ariel;

int main() {
  BinaryTree<int> tree_of_ints;
  tree_of_ints.add_root(1)
  .add_left(1, 9)      // Now 9 is the left child of 1
  .add_left(9, 4)      // Now 4 is the left child of 9
  .add_right(9, 5)     // Now 5 is the right child of 9
  .add_right(1, 3)     // Now 3 is the right child of 1
  .add_left(1, 2);     // Now 2 is the left child of 1, instead of 9 (the children of 9 remain in place)

  cout << tree_of_ints << endl;  /* Prints the tree in a reasonable format. For example:
        1
        |--------|
        2        3
        |---|
        4   5
  */

  for (auto it=tree_of_ints.begin_preorder(); it!=tree_of_ints.end_preorder(); ++it) {
    cout << (*it) << " " ;
  }  // prints: 1 2 4 5 3
  for (auto it=tree_of_ints.begin_inorder(); it!=tree_of_ints.end_inorder(); ++it) {
    cout << (*it) << " " ;
  }  // prints: 4 2 5 1 3 
  for (auto it=tree_of_ints.begin_postorder(); it!=tree_of_ints.end_postorder(); ++it) {
    cout << (*it) << " " ;
  }  // prints: 4 5 2 3 1

  for (int element: tree_of_ints) {  // this should work like inorder
    cout << element << " " ;
  }  // prints: 4 2 5 1 3 


  // The same should work with other types, e.g. with strings:
  
  BinaryTree<string> tree_of_strings;
  tree_of_strings.add_root("1")     
  .add_left("1", "9")      // Now 9 is the left child of 1
  .add_left("9", "4")      // Now 4 is the left child of 9
  .add_right("9", "5")     // Now 5 is the right child of 9
  .add_right("1", "3")     // Now 3 is the right child of 1
  .add_left("1", "2");     // Now 2 is the left child of 1, instead of 9 (the children of 9 remain in place)
  cout << tree_of_strings << endl; 

  for (auto it=tree_of_strings.begin_preorder(); it!=tree_of_strings.end_preorder(); ++it) {
    cout << (*it) << " " ;
  }  // prints: 1 2 4 5 3
  for (auto it=tree_of_strings.begin_inorder(); it!=tree_of_strings.end_inorder(); ++it) {
    cout << (*it) << " " ;
  }  // prints: 4 2 5 1 3 
  for (auto it=tree_of_strings.begin_postorder(); it!=tree_of_strings.end_postorder(); ++it) {
    cout << (*it) << " " ;
  }  // prints: 4 5 2 3 1

  // demonstrate the arrow operator:
  for (auto it=tree_of_strings.begin_postorder(); it!=tree_of_strings.end_postorder(); ++it) {
    cout << it->size() << " " ;
  }  // prints: 1 1 1 1 1 


  for (const string& element: tree_of_strings) {  // this should work like inorder
    cout << element << " " ;
  }   // prints: 4 2 5 1 3 

}
