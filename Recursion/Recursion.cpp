#include <iostream>
#include <string>

// all the comments are in Readme file

using namespace std;

static int sum = 0, i = 0, ways = 0;



bool isPalindrome (const string& input);
int digitSum (int input);
int waysToClimb (int numStairs) ;

int main()
{
  // palindrome main method
   cout << "*Checks if the string is palindrom or not*" << endl;
   
   string str;
   
   cout<<endl<<"Enter a string: ";
   getline (cin, str);
   
   bool flag=isPalindrome(str);
   if(flag==true)
      cout<<endl<<str<<" is palindrome";
   else
      cout<<endl<<str<<" is not a palindrome";
   
   cout<<endl;
   
  // ends palindrome main method
   
  
  // digitSum main method
   cout << endl;
   cout << "*Gives the sum of the digit*" << endl;
   
   int number;
   
   cout<<endl<<"Enter a number: ";
   cin>>number;
   
   int sum=digitSum(number);
   
   cout<<endl<<"Sum of digits: "<<sum;
   cout << endl;
   
  // ends digitSum
   
   
   // waysToClimb main method
   cout <<endl;
   cout << "*Checks  ways to  climb*" << endl;
   
   int stairs;
   
   cout<<endl<<"Enter the number of steps: ";
   cin>>stairs;
   
   int ways=waysToClimb(stairs);
   
   cout<<endl<<"Number of ways to climb: "<<ways;
   // ends waysToClimb main method
   return 0;
}

bool isPalindrome(const string& input) 
{   
  
   if(input[i]==input[input.size()-i-1])
   {
       i++;
       if(i<input.size())
         return isPalindrome(input);
        return true;
    }
    return false;
}

int digitSum(int input) 
{
   int reminder;
   if(input!=0)
   {
      reminder=input%10;
      sum+=reminder;
      digitSum(input/10);
   }
   return sum;
}


int waysToClimb(int numStairs) 
{
   if(numStairs==0)
   {
      return ways;
   }
   
   return ways+1;
}


