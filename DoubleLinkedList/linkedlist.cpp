#include "Linkedlist.h"

// Methods

ADT_class::~ADT_class()
{
   if(head==NULL)
   return;
   while(head!=NULL)
   {
      temp=head->next;
      delete head;
      head=temp;
   }
}

ADT_class::ADT_class()
{
   head=NULL;
}

void ADT_class::pushFront(int x)
{
   temp=head;
   head=new node;
   head->data=x;
   head->next=temp;
   cout<<"New Node Inserted successfully at the begining"<<endl;
   cout<<"New List:"<<endl;
   print();
}

void ADT_class::pushBack(int item)
{
   node *temp2;
   if(head==NULL)
   {
      head=new node;
      head->data=item;
      head->next=NULL;
   }
   else
   {
      temp=head;
      while(temp->next!=NULL)
      temp=temp->next;
      temp2=new node;
      temp2->data=item;
      temp2->next=NULL;
      temp->next=temp2;
   }
   cout<<" New Node Inserted successfully at the end"<<endl;
   cout<<"New List:"<<endl;
   print();
}

void ADT_class::popFront()
{
   cout<<"The list before deletion"<<endl;
   print();
   temp=head;
   if(temp==NULL)
   {
      cout<<"No data is present"<<endl;
      return;
   }
   head=temp->next;
   delete temp;
}

void ADT_class::popBack()
{
   cout<<"The list before deletion:"<<endl;
   print();
   temp=head;
   if(temp==NULL)
   {
      cout<<" There is no data in the list"<<endl;
      return;
   }
   if(temp->next==NULL)
   {
      head=temp->next;
      delete temp;
      return;
   }
   while(temp->next->next!=NULL)
      temp=temp->next;
   temp->next=NULL;
   return;
}

void  ADT_class::print()
{
   temp=head;
   if(temp==NULL)
   {
      cout<<"The list is Empty"<<endl;
      return;
   }
   while(temp!=NULL)
   {
      cout<<temp->data<<"->";
      temp=temp->next;
   }
   cout<<"NULL"<<endl;
}

void ADT_class::reverseList()
{
   node *head2;
   head2=head;
   node* prev = NULL;
   node* current = head2;
   node *next;
   while (current != NULL)
   {
      next = current->next;
      current->next = prev;   
      prev = current;
      current = next;
   }
   head=prev;
   print();
}

int ADT_class::size()
{
   int count=0;
   node *temp2;
   temp2=head;
   if (temp2 == NULL)
   {
      cout<<"List is Empty"<<endl;
      return -1;
   }
   while (temp2->next != NULL)
   {
      temp2 = temp2->next;
      count++;
   }
   return 1+count;
}

int ADT_class::mtoLastElement(int m)
{
   temp=head;
   while(temp != NULL)
   {
      m = temp->data;
   temp = temp->next;
   }
   return m;
}


void ADT_class::insert(int value,int position)
{
   node *temp1;
   temp=head;
   if(temp1==NULL)
   {
      temp1= new node;
      temp1->data=value;
      temp1->next=NULL;
      head=temp1;
      return;
    }
   for(int i=0;((i<position)&&(temp->next!=NULL)) ;i++)
   {
      if(i==(position-1))
      {
         temp1= new node;
         temp1->data= value;
         temp1->next=temp->next;
         temp->next=temp1;
      }
      temp=temp->next;
   }
   cout<<"New List:"<<endl;
   print();
}