#include<iostream>
#pragma once

using namespace std;


struct node
{
   struct node *prev;
   int n;
   struct node *next;
}  *head,*temp,*temp1,*temp2,*temp4;

class ADT_class
{
   public:
   
   // Constructors
   int count;
   void pushFront();
   void pushBack();
   void insert();
   void popFront();
   void print();
   int size();
   void reverseList(int head2);
   int mtoLastElement(int head2);
   void create();
};

