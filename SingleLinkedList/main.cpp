#include "linkedlist.cpp"

// Created to basically test SinglyLinkedList
int main()
{
   ADT_class obj;
   int opt,size2=0;
   head= NULL;
   temp = temp1;
   temp1 = NULL;
   while(1)
   {
      cout<<"Implementation of Double Linked List ADT to store Collection of Integers"<<endl;
      cout<<"1. Insert Node at Front-end"<<endl;
      cout<<"2 Insert Node at Last-end"<<endl;
      cout<<"3. Delete Node at Front-end"<<endl;
      cout<<"4. Delete Node at Back-end"<<endl;
      cout<<"5. Insert New Node at position"<<endl;
      cout<<"6. Deletes The Duplicate Element From The List"<<endl;
      cout<<"7. Returns The Last Element of The List"<<endl;
      cout<<"8. Determines The Size Of List:"<<endl;
      cout<<"9. Display All Data items"<<endl;
      cout<<"10. Reversing of a linked list"<<endl;
      cout<<"11. Exit \n"<<endl;
      cout<<"Slect Any choice : "<<endl;
      cin >> opt;
      
      switch (opt)
      {
         case 1:
            obj.pushFront();
         break;
         
         case 2:
            obj.pushBack();
         break;

         case 3:
            obj.popFront();
         break;
         
         case 4:
            obj.insert();
         break;
         
         case 5:
            temp2=head;
            cout<<"The Last Elemnt is:"<<obj.mtoLastElement(temp2->n)<<endl;
         break;

         case 6:
            size2=obj.size();
            if(size2!=0)
            cout<<"The Size of List:"<<size2;
         break;

         case 7:
            obj.print();
         break;

         case 8:
            temp2 = head;
            if (temp2 == NULL)
               cout<<"List is empty"<<endl;
            else
            {
               cout<<"Reverse order of linked list is"<<endl;
               obj.reverseList(temp2->n);
            }
         break;

         case 9:
            exit(0);
         default:

         cout<<"Wrong choice Select Correct Option"<<endl;

      }

   }
   return 0;
}

