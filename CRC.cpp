#include<iostream>
using namespace std;
class CRC
{
 public:
 int dr[50],dd[50],m,n,r1[50],i,j;
 int * divide(int dr[],int dd[])
 {
 int i,q[50],j,c[50],r[50],count=0;
 for(i=0;i<n;i++)
  r1[i]=dd[i];
 for(i=0;i<m;i++)
 {
  if(dr[0]==r1[0]==1)
   q[i]=1;
  else
   q[i]=0;
  
  if(q[i]==1) 
   { 
    for(j=0;j<n;j++) 
	 {
      c[j]=dr[j];
	  if(c[j]==r1[j])
	    r[j]=0;
	  else
	    r[j]=1;
	 }
   }
  else
   {
    for(j=0;j<n;j++)
     {
	  c[j]=0;
	  if(c[j]==r1[j])
	    r[j]=0;
	  else
	    r[j]=1;
	 }
   }
  for(j=0;j<n-1;j++)
   r1[j]=r[j+1];
  r1[n-1]=dd[n+count];
  count++;
 }
 return r1;	
}    
};
 int main()
 {
 int* r2;
 CRC o1;
 int c=0;
 int i,j;
 cout<<"Enter the size of dividor\n";
 cin>>o1.n;
  
 cout<<"Enter the size of dividend\n";
 cin>>o1.m;
  
 cout<<"Enter the divisor\n";
 for(i=0;i<o1.n;i++)
  cin>>o1.dr[i];
 
 cout<<"Enter the dividend\n";
 for(i=0;i<o1.m;i++)
  cin>>o1.dd[i];  

 for(i=0;i<o1.n-1;i++)
  o1.dd[o1.m+i]=0;
 
 r2=o1.divide(o1.dr,o1.dd);
 
 cout<<"The Remainder is : ";
 for(i=0;i<o1.n-1;i++)
  cout<<*(r2+i);
 cout<<endl;
 for(i=0;i<o1.n-1;i++)
  o1.dd[o1.m+i]=*(r2+i);
 
 r2=o1.divide(o1.dr,o1.dd);
 for(i=0;i<o1.n-1;i++)
  if(*(r2+i)!=0)
   {
    c=1;
    break;
   }
 if(c==0)
  cout<<"CORRECT.\n";
 else
  cout<<"INCORRECT.\n";
 return 0;
}

