#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <iostream>

using namespace std;

class TreeNode
{
  private:
    int value;
  public:
    TreeNode();
    TreeNode(int v);
    void setValue(int v);
    int getValue()const;
  public:
    TreeNode* leftChild;
    TreeNode* rightChild;
};

class BSearchTree
{
  public:
    BSearchTree();//Create a empty Binary Search Tree
    BSearchTree(int v);//Create a Binary Search Tree with a value 
    ~BSearchTree();
    int addNode(int v);//add a node to the tree. return 0 for add successfully
    int deleteNode( int v); //delete the node which containing the value. return 0 for delete successfully, 1 for failed
    //void print(Prrinter p); //print the element A functor. implement it later
    void print();
    void deleteAll(TreeNode* node);
  private:
    TreeNode* root; // the root element of the BSearchTree
    void firstOrder(TreeNode* root);
    TreeNode* getMax(TreeNode* node);
    TreeNode* getMin(TreeNode* node);
    int deleteNode(TreeNode* node,int v);
    int addNodeToCurNode(TreeNode* cur, int v);
};

#endif
