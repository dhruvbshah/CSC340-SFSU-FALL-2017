 /* File:RandomAccess.cpp
    Name: Dhruv Shah
    Class: CSC 340
    Date: July 2nd 2017
    
    3. Random accesses to a file.The file posted here on iLearn contains a 
    formatted list of 9999 integers that are randomly generated in the range 
    of [1,9999]. Each integer occupies one single line and takes 4 characters' 
    space per line. Alternatively, you can think that each number takes 5 characters' 
    space, four for the number and one for the newline character. Write a C++ program using 
    the seekg() and seekp() functions to insert the numbers 7777 through 7781 between the 
    6000-th and 6001-st numbers of the input file.

     Below are a few useful tips: 
      The tellg() and tellp() functions return the position of the current character in 
      an input stream or output stream, respectively. You are strongly recommended to use the 
      tellg() function to first learn about the starting position of each integer. 
      This will help you locate the exact starting position to insert the new numbers. You can 
      use the width() function to specify the number of characters you'd like an integer to occupy.
      
      In addition to the "output" operator (<<), you can also use the write() function to write to a file.
      Before you insert the numbers, you will need to first store all the numbers from the 6001-st number 
      in an internal data structure, e.g., array. Otherwise, some of them will be overwritten.
      
      Finally, always call the clear() function before calling the seekg() or seekp() function. Otherwise, you might encounter inexplicable behaviors.
      
      Requirements:
       You are not allowed to create or use any other files except the single input file.
       You must use seekg() or seekp() to directly identify the insertion point to insert the new numbers.*/

   //Header Files
   #include <iostream>
   #include <fstream>
   #include <iomanip>

   using namespace std;

   int main() 
   {
      int myArray[10000]; //my array initializer to store 9999 integers
      
      const int SKIP_NUM = 6000;//number in file to skip to
      
      int numBytes = 5;//bytes read as 4byte num + newline
      int product = (numBytes * SKIP_NUM);//to be used with seekp()
        
      fstream file("file1.txt"); //inputs file1.txt
      
     //exits the program if file does not open
      if (!file)
      {
         cout << "Cannot open file.\n";
         exit(1); 
      }//ends if statement
               
      int count = 0;// counter

     //it reads numbers inside the while loop
      while (!file.fail())
      {
         int num;
                
         file >> num;
         
         if (num == SKIP_NUM)
         {
            break;
         }//ends if statement
      }//ends while loop
        
     int numLoc = file.tellg();
     
     file >> myArray[count];//subscript out of range
     
     //inserts numbers inside the array and count keeps on adding it
     while(!file.fail())
     {
         count++;
         file >> myArray[count];
     }//ends while loop
        
     file.clear();
     file.seekp(product);/*using seekp() to directly identify the 
                            insertion point to insert the new numbers*/

     for (int i = 7777; i <= 7781; i++)
     {
         file << i << endl;
     }//ends for loop
     
     for (int i = 0; i < count; i++)
     {
         file << myArray[i] << endl;
     }//ends for loop
     
     cout << " Complete. ";
        
     file.close();//closes file

     return 0;
   }//ends int main()