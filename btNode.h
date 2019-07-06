#ifndef __BTNODE_H__
#define __BTNODE_H__
#include <iostream>
#include <cstdlib>
using namespace std;

template <class Item>
class btNode{
  public:
    btNode(){
      const Item& data = Item( ),
      left = NULL;
      right = NULL;
      parent = NULL;
    }
   Item& data() { return data;}
   btNode* left(){ return left;}
   btNode* right(){ return right;}
   void set_data(const Item& entry){ data = entry;}
   void set_left(btNode* newLeft){ left = newLeft;}
   void set_right(btNode* newRight){ right = newRight;}
   bool isLeaf() const{ return (left==NULL) && (right==NULL);}
    
  private:
    Item data;
    btNode *left;
    btNode *right;
    btNode *parent;
};

#include "btNode.cpp"
#endif
