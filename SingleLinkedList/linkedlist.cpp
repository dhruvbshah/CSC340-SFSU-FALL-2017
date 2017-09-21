#include "Linkedlist.h"

// Methods
void ADT_class::pushFront()
{
   if (head == NULL)
   {
      create();
      head = temp;
      temp1 = head;
   }
   else
   {
      create();
      temp->next = head;
      head->prev = temp;
      head = temp;
   }
}

void ADT_class::pushBack()
{
   if (head == NULL)
   {
      create();
      head = temp;
      temp1 = head;
   }
   else
   {
      create();
      temp1->next = temp;
      temp->prev = temp1;
      temp1 = temp;
   }
}

void ADT_class::insert()
{
   int pos, i = 2;
   cout<<"Enter position In which Position Element inserted"<<endl;
   cin>>pos;
   temp2=head;
   
   if((pos < 1) || (pos >= count + 1))
   {
      cout<<"Position out of Limit to insert"<<endl;
      return;
   }

   if((head==NULL)&&(pos != 1))
   {
      cout<<"list is Empty cannot insert other than 1st position"<<endl;
      return;
   }

   if((head==NULL)&&(pos==1))
   {
      create();
      head = temp;
      temp1 = head;
      return;
   }
   else
   {
      while (i < pos)
      {
         temp2 = temp2->next;
         i++;
      }

      create();
      temp->prev = temp2;
      temp->next = temp2->next;
      temp2->next->prev = temp;
      temp2->next = temp;
   }
}

void ADT_class::popFront()
{
   int i=1,pos;
   cout<<"Enter position to delete the Element"<<endl;
   cin>>pos;
   temp2 = head;
   if ((pos < 1) || (pos >= count + 1))
   {
      cout<<" Position out of range to delete"<<endl;
      return;
   }
   if (head == NULL)
   {
      cout<<"list is Empty "<<endl;
      return;
   }
   else
   {
      while(i<pos)
      {
         temp2 = temp2->next;
         i++;
      }
      if (i == 1)
      {
         if (temp2->next == NULL)
         {
            cout<<"Node is deleted from list"<<endl;
            free(temp2);
            temp2 = head;
            head = NULL;
            return;
         }
      }
      if (temp2->next == NULL)
      {
         temp2->prev->next = NULL;
         free(temp2);
         cout<<"Node is deleted from list"<<endl;
         return;
      }
      temp2->next->prev = temp2->prev;
      if (i != 1)
         temp2->prev->next = temp2->next;
      if (i == 1)
         head= temp2->next;
      cout<<" Node is deleted"<<endl;
      free(temp2);
   }
   count--;
}

void ADT_class::print()
{
   temp2=head;
   if (temp2 == NULL)
   {
      cout<<"List is Empty"<<endl;
      return;
   }
   cout<<"List Of All Data Items in List is:"<<endl;
   while (temp2->next != NULL)
   {
      cout<<temp2->n<<"->";
      temp2 = temp2->next;
   }
   cout<<temp2->n<<"->NULL"<<endl;
}

int ADT_class::size()
{
   int count=0;
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

void ADT_class::reverseList(int head2)
{
   if (temp2 != NULL)
   {
      head2 = temp2->n;
      temp2 = temp2->next;
      reverseList(head2);
      cout<<head2<<"->";
   }
}

int  ADT_class::mtoLastElement(int head2)
{
   if (temp2 != NULL)
   {
      head2 = temp2->n;
      temp2 = temp2->next;
      mtoLastElement(head2);
   }
   return head2;
}

void ADT_class::create()
{
   int data;
   temp =(struct node *)malloc(1*sizeof(struct node));
   temp->prev = NULL;
   temp->next = NULL;
   cout<<"Enter value of node :"<<endl;
   cin >> data;
   temp->n = data;
   count++;
}