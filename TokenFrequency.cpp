#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct TokenFreq
{
string token;
int freq;
};

void getLeastFreqLetter(string value)
{
   int Datas[27] = {0};
     
   for(int it = 0; it < value.size(); ++it)
   {
      if(value[it] >= 65 && value[it] <= 90)
      {
         value[it] += value[it] + 32;
      }
      
      if(value[it] >= 97 && value[it] <= 122)
      {
         Datas[value[it] - 97]++;
      }
   }
   
   int idMind = 0;
   
   for(int it = 1; it < 26; ++it)
   {
      if(Datas[idMind] > Datas[it])
      {
         idMind = it;
      }
   }

   cout << "Least Frequency " << (char)(idMind + 97) 
      << " and frequency is " << Datas[idMind] << endl;
}

vector<TokenFreq> getTokenFreq( string& sVal)
{
   int indexVal=0;

   vector<TokenFreq> TFreq;
   string token="";

   TFreq.push_back(TokenFreq());
   int f=0;
   int val=0;

   for(int k=0;k<sVal.length();k++)
   {
      if(sVal[k]==' ' || sVal[k]==',' || sVal[k]=='.' ||sVal[k]==';' || sVal[k]==':')
      {
         val=0;
         for(int it = 0; it<TFreq.size(); it++)
         {
            if(TFreq[it].token==token)
            {
               TFreq[it].freq++;
               val=1;
               token="";
            }
         }
   
         if(val==0)
         {
            f++;
            TFreq[indexVal].token=token;
            TFreq[indexVal].freq=1;
            indexVal++;
            TFreq.push_back(TokenFreq());
            token="";
         }
      }
      else
      {
         token=token+sVal[k];
      }
}
   val=0;
   for(int it = 0; it<TFreq.size(); it++)
   {
      if(TFreq[it].token==token)
      {
         TFreq[it].freq++;
         val=1;
         token="";
      }

   }

   if(val==0)
   {
      cout<<token;
      TFreq[indexVal].token=token;
      TFreq[indexVal].freq=1;
      indexVal++;
   }

   cout<<"\frequency"<<endl;
   for(int it = 0; it<TFreq.size()-1; it++)
   {
       cout<<TFreq[it].token<<": "<<TFreq[it].freq<<endl;
   }
   
   return TFreq;
}

int main()
{
   string sVal;
   vector<TokenFreq> TFreq1;
   vector<TokenFreq> TFreq2;
   cout<<"Enter the paragraph:"<<endl;
   getline(cin,sVal);
   TFreq1=getTokenFreq(sVal);
   getLeastFreqLetter(sVal);
   system("pause");
   return 0;
}