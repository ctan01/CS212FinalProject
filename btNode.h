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
  private:
    Item data;
    btNode *left;
    btNode *right;
    btNode *parent;
};

#include "btNode.cpp"
#endif
