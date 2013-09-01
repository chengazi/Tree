#include "binarySearchTree.h"
// private
TreeNode::TreeNode():value(0),leftChild(0),rightChild(0)
{
}
TreeNode::TreeNode(int v):value(v),leftChild(0),rightChild(0)
{
}


void TreeNode::setValue(int v)
{
  this->value = v;
}

int TreeNode::getValue()const 
{
  return this->value;
}

BSearchTree::BSearchTree():root(0){}

BSearchTree::BSearchTree(int v)
{
  root = new  TreeNode(v);
}
/*
 * This is a non recurtive version of adding a node to the 
 * Binary Search Tree. In fact We can use recursion to write 
 * a much more clean and clear version of addNode function
int BSearchTree::addNode(int v)
{
  if(0==root) // first element of the bs tree
  {
    root = new TreeNode(v);
    return 0;
  }
  TreeNode* curP;
  curP = root;

  while(curP != 0)
  {
    if(curP->getValue() > v )
    {
      if(0 == curP->leftChild)
      {
        curP->leftChild = new TreeNode(v);
        break;
      }
      else
      {
        curP = curP->leftChild;
        continue;
      }
    }
    else 
    {
      if(0 == curP->rightChild)
      {
        curP->rightChild = new TreeNode(v);
        break;
      }
      else
      {
        curP = curP->rightChild;
        continue;
      }
    }
  }
  return 0;
}
*/
/**
 * recursion Version of addNode
 * Consider the three condition below
 * 1. the root node is empty.
 *    create a root node and assign the value
 * 2. the value of v is greater than the one of current node
 *    call addNode function of the rightchild
 * 3. the value is less than or equal to the one of the current node
 *    call addNode function of the lefChild
 */
int BSearchTree::addNodeToCurNode(TreeNode* cur, int v)
{
  if(!cur)
    return -1;
  else if(v > cur->getValue())
  {
    if(cur->rightChild)
      addNodeToCurNode(cur->rightChild,v);
    else
      cur->rightChild = new TreeNode(v);
  }
  else
  {
    if(cur->leftChild)
      addNodeToCurNode(cur->leftChild,v);
    else
      cur->leftChild = new TreeNode(v);
  }
}
int BSearchTree::addNode(int v)
{
  if(!this->root)
  {
    this->root = new TreeNode(v);
    return 0;
  }
  return addNodeToCurNode(this->root, v);
}
/**
 * Delete Node can be more clear too. let's do it tomorrow.
int BSearchTree::deleteNode( int v)
{
  TreeNode* curP = root; 
  bool founded = false;
  if(0 == root )
    return -1;
  while(curP != 0)
  {
    if(curP->getValue() == v)
    {
      founded = true;
      break;
    }
    else if(curP->getValue() > v)
      curP = curP->leftChild;
    else 
      curP = curP->rightChild;
  }
  if(!founded)
    return -1;
  else
  {
    if(0 == curP->leftChild && 0 == curP->rightChild)
    {
      delete curP;
      return 0;
    }
    if(curP->leftChild)
    {
      TreeNode* maxChild = getMax(curP);
      if(0!=maxChild)
      {
        TreeNode* temp = maxChild->rightChild;
        curP->setValue(maxChild->rightChild->getValue());
        maxChild->rightChild = temp->leftChild;
        delete temp;
      }
    }
    else 
    {
      TreeNode* minChild = getMin(curP);
      if(0!= minChild)
      {
        TreeNode* temp = minChild->leftChild;
        curP->setValue(temp->getValue());
        minChild->leftChild = temp->rightChild;
        delete temp;
      }
    }
  }
  return 0;
}
*/
TreeNode* BSearchTree::getMax(TreeNode* node)
{
  if(!node || !node->leftChild)
    return 0;
  if(0 == node->leftChild->rightChild)
    return node;
  else
  {
    TreeNode* curN = node->leftChild;
    while(curN->rightChild->rightChild)
      curN = curN->rightChild;
    return curN;
  }
}

TreeNode* BSearchTree::getMin(TreeNode* node)
{
  if(!node || !node->rightChild)
    return 0;
  if(0 == node->rightChild->leftChild)
    return node;
  else
  {
    TreeNode* curN = node->rightChild;
    while(curN->leftChild->leftChild)
      curN = curN->leftChild;
    return curN;
  }
}
void BSearchTree::print()
{
  firstOrder(this->root);
}
void BSearchTree::firstOrder(TreeNode* rt)
{
  if(rt)
  {
  if(rt->leftChild)
    firstOrder(rt->leftChild);
  cout<<rt->getValue()<<" " <<endl;
  if(rt->rightChild)
    firstOrder(rt->rightChild);
  }
}

void BSearchTree::deleteAll(TreeNode* node)
{
  if(node)
  {
    if(node->leftChild)
    {
      if(node->leftChild->leftChild)
        deleteAll(node->leftChild);
      if(node->leftChild->rightChild)
        deleteAll(node->rightChild);
      if(node->leftChild->leftChild == 0 && node->leftChild->rightChild==0)
      {
        TreeNode* temp = node->leftChild;
        node->leftChild = 0;
        delete temp;
      }
    }
    if(node->rightChild)
    {
      if(node->rightChild->leftChild)
        deleteAll(node->rightChild);
      if(node->rightChild->rightChild)
        deleteAll(node->rightChild);
      if(node->rightChild->leftChild == 0 && node->rightChild->rightChild== 0)
      {
        TreeNode* temp = node->rightChild;
        node->rightChild = 0;
        delete temp;
      }
    }

  }
}
BSearchTree::~BSearchTree()
{
  deleteAll(this->root);
  if(this->root)
    delete this->root;
}
