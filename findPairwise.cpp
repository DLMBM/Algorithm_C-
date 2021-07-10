#include<iostream>
#include<vector>

using namespace std;

long long findPairwise( const vector<int>& number )
{
int i,j;
long long result=0;

for(i=0;i<number.size();i++)
{
  for(j=i+1;j<number.size();j++)
  {
    if((long long)number[i]*number[j]>result)
    {
      result= (long long)number[i]*number[j];
    }
  }
}
return result;
}

int main(){

int size;
cin>>size;

vector<int> number(size);
for(int i=0;i<size;i++)
  cin>>number[i];

long long result =findPairwise( number);
cout<<result<<endl;


}
