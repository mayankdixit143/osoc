#include<iostream>
using namespace std;
int main()
{ 
  char a[50];
  int n,i,j,count=0;
  cout<<"Enter the no. of alphabets in the string\n";
  cin>>n;
  
  cout<<"Enter the string\n";
  for(i=0;i<n;i++)
  {
    cin>>a[i];
  }
  
  for(i=0,j=n-1;i<n,j>0;i++,j--)
	{
	  if(a[i]==a[j])
	  {
	    count=1;
	    break;
      }
	}
      if(count==1)
	  cout<<"Yes it is a palindrome";
	  else
	  cout<<"No it is not a palindrome";
}

