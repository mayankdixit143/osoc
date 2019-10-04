#include<iostream.h>
class binary
{ public:
 int q[20],div[20], dividend[20],r[50];
 int n,m;
 void input()
 {
   cout<<"enter the size of divisor";
   cin>>n;
   cout<<"enter the divisor(in binary)";
   for(int i=0; i<n;i++)
   {
     cin>>div[i];
	
   }
   cout<<"\nenter the size of dividend\n";
   cin>>m;
   cout<<"\nenter the dividend(in binary)";
   for(int i=0; i<m;i++)
   {
     cin>>dividend[i];
	
   }
 }
 void divide()
 {
 for(int i=0;i<m-1;i++)
 {
 if(div[0]==dividend[i])
 q[i]=1;
 else q[i]=0;
 if(q[i]==1)
 {
  for(int j=0;j<n;j++)
  {
   if(div[j]==dividend[j])
   {
    r[j]=0;
   }
   else
      r[j]=1;
	}
   }
   else
   {
   for(int j=0;j<n;j++)
   {
    if(dividend[j]==0)
	r[j]=0;
	else
	 r[j]=1;
}
 }
	
	
 }

 }
 void display()
 {
  cout<<"quotient is \n";
  for(int i=0;i<m-1;i++)
  {
  cout<<"\n"<<q[i];
  }
   cout<<"remainder is \n";
  for(int i=0;i<m-1;i++)
  {
  cout<<"\n"<<r[i];
  }
 }
};
int main()
{
 binary b;
 b.input();
 b.divide();
 b.display();
}
 

