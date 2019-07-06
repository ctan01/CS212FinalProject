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
   Item getData() { return data;}
   btNode* getLeft(){ return left;}
   btNode* getRight(){ return right;}
   void setData(const Item& entry){ data = entry;}
   void setLeft(btNode* inLeft){ left = inLeft;}
   void setRight(btNode* inRight){ right = inRight;}
   bool isLeaf() const{ return (getLeft()==NULL) && (getRight()==NULL);}
    
  private:
    Item data;
    btNode *left;
    btNode *right;
    btNode *parent;
};

#include "btNode.cpp"
#endif
