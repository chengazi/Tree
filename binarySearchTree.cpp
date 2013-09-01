#include "binarySearchTree.h"

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
