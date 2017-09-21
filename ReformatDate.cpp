#include <iostream>
#include <string>

using namespace std;

string reformatDate(string oldDate)
{
    int day = stoi (oldDate, nullptr, 10);
    int pos = oldDate.find(" ");
    
    string days;
    
    oldDate = oldDate.substr(pos+1);
    
    int nextPos = oldDate.find(" ");
    
    string month = oldDate.substr(0, nextPos);
    string temp = oldDate.substr(nextPos+1);
    
    int year = stoi(temp, nullptr, 10);
    
    if(month.compare("Jan") == 0)
        month = "01";
    
    else if(month.compare("Feb") == 0)
        month = "02";  
    
    else if(month.compare("Mar") == 0)
        month = "03";  
    
    else if(month.compare("Apr") == 0)
        month = "04";  
    
    else if(month.compare("May") == 0)
        month = "05";  
    
    else if(month.compare("Jun") == 0)
        month = "06";  
   
    else if(month.compare("Jul") == 0)
        month = "07";  
    
    else if(month.compare("Aug") == 0)
        month = "08";  
    
    else if(month.compare("Sep") == 0)
        month = "09";  
    
    else if(month.compare("Oct") == 0)
        month = "10";  
    
    else if(month.compare("Nov") == 0)
        month = "11";  
    
    else if(month.compare("Dec") == 0)
        month = "12";  
    
    if(day == 1)
        days = "01";
    
    else if(day == 2)
        days = "02";
    
    else if(day == 3)
        days = "03";                                                  
    
    else if(day == 4)
        days = "04";
    
    else if(day == 5)
        days = "05";
    
    else if(day == 6)
        days = "06";
    
    else if(day == 7)
        days = "07";
    
    else if(day == 8)
        days = "08";
    
    else if(day == 9)
        days = "09";
    
    else
        days = to_string(day);                          
       
    string output = to_string(year) + " - " + month + " - " + days;
    return output;
}

int main()
{
    string dateString;
    cout << "Enter the date (Ex: 1st Mar 1984): ";
    getline(cin, dateString);
    cout << "The reformatted date is: " << reformatDate(dateString) << endl;
}
