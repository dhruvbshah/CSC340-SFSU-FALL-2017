#include "tree.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Tree::Tree()
{
   start = NULL;
}

Tree::Tree(const Tree&other)
{  
   copyOther(other);
}

Tree::~Tree()
{
   clear();
}

Tree& Tree::operator=(const Tree& other)
{  
   start = new TreeNode;
   copyOther(other);
   return *this;
}

void Tree::push(int value)
{
   TreeNode *node = new TreeNode();
   node->value = value;
   if(start == NULL)
      start = node;
   else
      pushFrom(start, node);
}

TreeNode* Tree::find(int value) const
{
   return findFrom(start, value);
}

void Tree::print() const
{
   printFrom(start, 2);
   cout<<endl;
}

void Tree::deleteNode(int value)
{
   deleteFrom(start, value);
}

void Tree::copyOther(const Tree&other)
{  
  start = new TreeNode;
  copyFrom(other.start);
}

void Tree::clear()
{
   clearFrom(start);
}

void Tree::pushFrom(TreeNode* startingPoint, TreeNode* nodeToPush)
{
   if(nodeToPush->value<startingPoint->value)
   {
       if(startingPoint->left != NULL)
           pushFrom(startingPoint->left, nodeToPush);
       else
       {
           startingPoint->left = nodeToPush;
       }
   }
   else if(nodeToPush->value>startingPoint->value)
   {
       if(startingPoint->right != NULL)
           pushFrom(startingPoint->right, nodeToPush);
       else
       {
           startingPoint->right = nodeToPush;
       }
   }
}

TreeNode* Tree::findFrom(TreeNode* startingPoint, int value) const
{
   if(startingPoint == NULL)
       return NULL;
   if(startingPoint->value == value)
       return startingPoint;
   else if(startingPoint->value<value)
       return findFrom(startingPoint->right, value);
   else
       return findFrom(startingPoint->left, value);
}

void Tree::printFrom(TreeNode* startintPoint, int numSpaces) const
{
   if(startintPoint == NULL)
      return;
   
   cout << " " << startintPoint->value << endl;
   for(int i=0; i<numSpaces; i++)
       cout<<" ";
   printFrom(startintPoint->left, numSpaces + 3);
   printFrom(startintPoint->right, numSpaces + 3);
  
}

void Tree::copyFrom(TreeNode* startintPoint)
{
   if(startintPoint == NULL) 
      return;
   
   TreeNode *n = new TreeNode();
   n->value = startintPoint->value;
   pushFrom(start, n);
   copyFrom(startintPoint->left);
   copyFrom(startintPoint->right);
}

void Tree::deleteFrom(TreeNode* startintPoint, int value)
{
   if(startintPoint == NULL) 
      return;
   
   TreeNode* n = startintPoint;
   TreeNode* parent = NULL;
   
   //locate the value to be deleted
   while(n != NULL)
   {
      if(n->value == value)
         break;
      else
      {  
         parent = n;
         if(value < n->value)
         n = n->left;
      else
         n = n->right;
      }
   }
  
   if(n == NULL) //did not find the node
      return;
  
   if(n->left == NULL && n->right == NULL)
   {
      if(parent == NULL) //deleting root
      {
         start = NULL;
      }
      else
      {
         if(parent->left == n)
            parent->left = NULL;
         else
            parent->right = NULL;
      }
      delete n;
   }
   else if(n->left != NULL && n->right == NULL)
   {
      if(parent == NULL) //deleting root
      {
         start = n->left;
      }
      else
      {
         if(parent->left == n)
            parent->left = n->left;
         else
            parent->right = n->left;
      }
      delete n;
   }
   else if(n->left == NULL && n->right != NULL)
   {
      if(parent == NULL) //deleting root
      {
         start = n->right;
      }
      else
      {
         if(parent->left == n)
            parent->left = n->right;
         else
            parent->right = n->right;
      }
      delete n;
   }
   else //node to be deleted has both children
   {
      TreeNode* succParent = n;
      TreeNode* successor = n->right;
      
      while(successor->left != NULL)
      {
         succParent = successor;
         successor = successor->left;
      }
   int copyVal = successor->value;
   deleteFrom(start, copyVal);
   n->value = copyVal; //copy the value of sucessor into the node
   }
}

void Tree::clearFrom(TreeNode* startingPoint)
{
   if(startingPoint == NULL)
       return;
   clearFrom(startingPoint->left);
   clearFrom(startingPoint->right);
      delete startingPoint;
}