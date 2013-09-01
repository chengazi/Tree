#include "binarySearchTree.h"

int main()
{
  BSearchTree mTree;
  int in;
  while(cin>>in)
  {
    if(-1 != in)
      mTree.addNode(in);
    else
      break;
  }
  mTree.print();
  
  return 0;
}
