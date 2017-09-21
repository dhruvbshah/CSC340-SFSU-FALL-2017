#include "linkedlist.cpp"

// Created to basically test DoubleLinkedList

int main()
{
   ADT_class obj;
   int opt,size2=0,pos=0,data2;
   
   while(1)
   {
      cout<<"Implementation of Double linkted List ADT to store Collection of Doubles"<<endl;
      cout<<"1. Insert Node at Front-end"<<endl;
      cout<<"2 Insert Node at Last-end"<<endl;
      cout<<"3. Delete Node at Front-end"<<endl;
      cout<<"4. Delete Node at Back-end"<<endl;
      cout<<"5. Insert New Node at position"<<endl;
      cout<<"6. Deletes The Duplicate Element From The List"<<endl;
      cout<<"7. Returns The Last Element of The List"<<endl;
      cout<<"8. Determines The Size Of List:"<<endl;
      cout<<"9. printlay All Dataitems"<<endl;
      cout<<"10. Reversing of a nexted list"<<endl;
      cout<<"11. Exit \n"<<endl;
      cout<<"Slect Any choice : "<<endl;
      
      cin >> opt;

      switch (opt)
      {
         case 1:
            cout<<"Enter the Data To insert at Front-end:"<<endl;
            cin>>data2;
            obj.pushFront(data2);
         break;

         case 2:
            cout<<"Enter the Data To insert at Back-end:"<<endl;
            cin>>data2;
            obj.pushBack(data2);
         break;

         case 3:
            obj.popFront();
         break;

         case 4:
            obj.popBack();
         break;
   
         case 5:
            cout<<"Enter the position to insert the New Node:"<<endl;
            cin>>pos;
            cout<<"Enter The Data"<<endl;
            cin>>data2;
            obj.insert(data2,pos);
         break;

         case 6:
            //delete_duplicate();
         break;

         case 7:
            temp=head;
            cout<<"The Last Elemnt is:"<<obj.mtoLastElement(temp->data)<<endl;
         break;
         
         case 8:
            size2=obj.size();
            if(size2!=0)
            cout<<"The Size of List:"<<size2;
         break;

         case 9:
            cout<<"The Data Element Present in the list "<<endl;
            obj.print();
         break;

         case 10:
            temp=head;
            if (temp == NULL)
               cout<<"List is empty"<<endl;
            else
            {
               cout<<"Reverse order of linked list is"<<endl;
               obj.reverseList();
            }
         break;

         case 11:
            exit(0);
         default:

         cout<<"Wrong choice Select Correct Option"<<endl;

      }

   }
   return 0;
}