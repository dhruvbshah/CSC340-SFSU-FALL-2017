/* File: MaxTime.cpp
      Name: Dhruv Shah
      Class: CSC 340
      Date: 2nd July 2017
      
      ReadMe:
      Given four digits, find the maximum valid time that can be displayed on a 
      digital clock (in 24-hour format) using those digits. 

      For example, given digits 1,8,3,2 the maximum valid time is "23:18". 
      Note that "28:31" is not a valid time.

      Write a function: string MaxTime(int A, int B, int C, int D); that, given four integers 
      A,B,C,D, returns the maximum valid time in string format "HH:MM" or 
      "NOT POSSIBLE" if it is not possible to display a valid time.

      Examples: 
      Given 1,8,3,2, the function MaxTime shoud return "23:18".
      Given 2,4,0,0 the funtion should return "20:40".
      Given 3,0,7,0 the function should return "07:30"
      Given 9,1,9,7 the function should return "NOT POSSIBLE". Since there is no possible valid time.
      
      Assume that: A,B,C,D are integers with in the range [0..9]
      In your solution, focus on correctness as well as the performance of your solution. 
      Try to achieve O(n) if possible rather than O(n^2) solution.*/
      
      //Header File
      #include <iostream>
      
      using namespace std;
      
      string MaxTime (int,int,int,int);//MaxTime function

      int main()
      {
         int a,b,c,d; //initializes abcd to store values in 
         int digit[4]; //stores abcd

         cout <<"\nEnter the four digits : ";
         cin >> a >> b >> c >> d; //stores the numbers
  
        cout << MaxTime (a,b,c,d);//returns the time 
         
        return 0;
      }//ends main

      string MaxTime (int A,int B,int C,int D)
      {
         //assigns ABCD 
         int digit[4];
            digit[0]= A;
            digit[1]= B;
            digit[2]= C;
            digit[3]= D;
         
         //temporary and count varibales to store data
         int temp = 0;
         int count=0;
         
         //intializes digitABCD to store an array to maximize the O(n)
         int digitA=0;
         int digitB=0;
         int digitC=0;
         int digitD=0;

         for(int A = 0; A < 4; A++)
         {
            for (int B = 0; B < 4; B++)
            {
               for (int C = 0; C < 4; C++)
               {
                  for (int D = 0; D < 4; D++)
                  {
                     if (A!=B && A!=C && A!=D
                           && B!=C && B!=D && C!=D)
                     {
                        if ( (10 * digit[C] + digit[D]) < 60) 
                        {
                           int cal = (10 * digit[A] + digit[B]) * 60 
                                       + (10 * digit[C] + digit[D]);
                           if (cal <= 1439)
                           {
                              count++;//increments count
                              if (temp < cal)//checks if temp < cal
                              {
                                 temp = cal;
                                 
                                 digitA = digit[A];
                                 digitB = digit[B];
                                 digitC = digit[C];
                                 digitD = digit[D];
                              }//ends if statement to check temp < cal
                           }// ends if statment if <= 1439
                        }//ends if statement to calculate < 60
                     }//ends to check if each of the digits are not equal to each other not
                  }//ends for loop for D
               }//ends for loop for C
            }//ends for loop for B
         }//ends for loop for A

         if (count == 0)
         {
            return "Not Possible";
         }//ends if statement
         else 
         {
         cout << "\n" << digitA << "" << digitB << " : " << digitC << "" << digitD;
         }//ends else statement
         
         return 0;
      }// ends MaxTime method