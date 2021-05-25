
#pragma once
#include <stdexcept>
using namespace std;

namespace ariel{
    template<typename T> class BinaryTree{

        private:
        struct node{
            T val;
            node* right;
            node* left;
            node(const T& val):val(val),right(nullptr),left(nullptr){}
        };
        node* root;

        
        class iterator {
   
        private:
        node* ptr= nullptr;

        public:
        //initialize iterator
        iterator(node* ptr){
            this->ptr = ptr;
        }
        //operator* returns the value of type T inside the node
        T& operator*(){
            T& value = ptr->val;
             return value;
        }
        //operator-> return a pointer of type T to the value of a node
        T* operator->(){
         T* ans = &(ptr->val);
         return ans;
        }
        //it++
        iterator& operator++(){
           return *this;
        }
        //++it
        iterator operator++(int){
            return *this;
        }
        //checks whether the iterator reached the end of the pointer of the last node of the tree
        bool operator!=(const iterator& it) {
            if(ptr != it.ptr){
                return true;
            }
           return false;
        }


    };
        
        public:
        //Initialize an empty tree
        BinaryTree<T>(){}

        BinaryTree<T>& add_root(const T& val){
            node* r = new node(val);
            root = r;
            return *this;
        }
        //check whether the node we want to add on the left or the right side has a parent node
        bool exist(const T& elem){
            return true;
        }
        BinaryTree<T>& add_left(const T& current,const T& left_child){
            if(!exist(current)){
                throw std::invalid_argument("the specified node does not exist");
            }
            return *this;
        }
        BinaryTree<T>& add_right(const T& current,const T& right_child){
            if(!exist(current)){
                throw std::invalid_argument("the specified node does not exist");
            }
            return *this;
        }
        iterator begin_preorder(){
            iterator it(root);
            return it;
        }
        iterator end_preorder(){
            iterator it(root);
            return it;
        }

        iterator begin_inorder(){
            iterator it(root);
            return it;
        }

        iterator end_inorder(){
            iterator it(root);
            return it;
        }
        iterator begin_postorder(){
            iterator it(root);
            return it;
        }

        iterator end_postorder(){
            iterator it(root);
            return it;
        } 

        iterator begin(){
            iterator it(root);
            return it;
        }                         
        iterator end(){
            iterator it(root);
            return it;
        } 

    };
    //template operator <<
    template<class T> inline ostream& operator<<(ostream& out, const BinaryTree<T>& val){
        return out;
    }

}