#include<iostream>
#pragma once
 
using namespace std;

struct node
{
   double data;
   node *next;
}  *head,*temp;

class ADT_class
{
   public:
   
   // Constructor
    ~ADT_class();
    ADT_class();
    void pushFront(int x);
    void pushBack(int item);
    void popFront();
    void popBack();
    void insert(int value,int position);
    int mtoLastElement(int m);
    int size();
    void print();
    void reverseList();
};

