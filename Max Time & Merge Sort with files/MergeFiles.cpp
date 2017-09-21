/* File Name: MergeFiles.cpp
   Name: Dhruv Shah
   Class: CSC 340
   Date: 2nd July 2017
   
   ReadMe:
   File I/Os: Given two text files, each of which contains a sorted list of integers 
   (one integer per line) in non-decreasing order, write a C++ program to merge these two 
   input files into a third file in which all the numbers remain their sorted order. 
   Your program will include the main() function and another function that merges the two files. 
   Specifically, the main() function will ask a user to type in the names of the two input files. 
   It will then call the merging function to merge the two files. Finally, it informs the user the 
   name of the merged file. Note that you are not allowed to first load all the numbers in the two 
   files into an array or vector then apply a sorting algorithm to this array.
   
   The Program Output the sorted merge file as "File3.txt"*/
   

   //Header files
   #include <iostream>
   #include <fstream>
   #include <string>

   using namespace std;
   
   /*mergeFiles() method contains two string variables as arguments
      and returns a string value*/


   //function 
   string mergeFiles (string file1, string file2);

   //main function
   int main()
   {
     //declares three string variables
     string stringIn1, stringIn2, stringOut;

     cout << "This programm mergers two sorted files into one sorted file!";
     cout << endl << endl;

     //user enters the two files name
     cout << "Enter the first file name: ";
     cin >> stringIn1;

     cout << "Enter the second file name: ";
     cin >> stringIn2;

     //calls the mergeFiles method 
     //returns value into a string variable
     stringOut = mergeFiles (stringIn1, stringIn2);

     //prints the merge file name
     cout << "Merged File is: " << stringOut << endl;

     system("pause");
     return 0;
   } //end main


   //merges two sorted files data into one file in sorted order
   string mergeFiles(string file1, string file2)
   {
     //creates the two input file objects
     ifstream inFile1(file1);
     ifstream inFile2(file2);

     //assign the output string file name
     string outfile = "File3.txt";

     //create the output file object
     ofstream outFile(outfile);

     //declare two integers to hold the values from the file
     int value1, value2;

     //if any of the files are not opening then print the error message
     if (!inFile1.is_open() || !inFile2.is_open() || !outFile.is_open())
     {
          cout << "Unable to open file(s)\n";
          system("pause");
          return 0;
     } //end if statement

     //if opens then read the data sort it and write the data
     //into the output file
     else
     {
          //read first values from both the files
          inFile1 >> value1;
          inFile2 >> value2;

          //while loop
          while (!inFile1.eof() && !inFile2.eof())
          {
              /*if the value1 is lesser than value2
                  puts the value1 into file*/

              if (value1 <= value2)
              {
                   outFile << value1 << endl;
                   inFile1 >> value1;
              }//end if statement

              //if not put value2 into the file
              else
              {
                   outFile << value2 << endl;
                   inFile2 >> value2;
              }//end else statement
          }// end while loop

          /*if any files data is left out than it writes
           the values directly into the file*/
          while (!inFile1.eof())
          {
              outFile << value1 << endl;
              inFile1 >> value1;
          }// end while loop

          while (!inFile2.eof())
          {
              outFile << value2 << endl;
              inFile2 >> value2;
          }// end while loop
     }// end else statement

     //return the output file name
     return outfile;
   }// end mergeFiles method