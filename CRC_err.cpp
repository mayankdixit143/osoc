#include <iostream.h>
#include <conio.h>
 
int main()
{
    int i,j,k,l;
     
    //Get Frame
    int fs;
    cout<<"\n Enter Frame size: ";
    cin>>fs;
     
    int f[20];
     
    cout<<"\n Enter Frame:";
    for(i=0;i<fs;i++)
    {
        cin>>f[i];
    }
 
    //Get Generator
    int gs;
    cout<<"\n Enter Generator size: ";
    cin>>gs;
     
    int g[20];
     
    cout<<"\n Enter Generator:";
    for(i=0;i<gs;i++)
    {
        cin>>g[i];
    }
 
    cout<<"\n ===Sender Side:===";
    cout<<"\n Frame: ";
    for(i=0;i<fs;i++)
    {
        cout<<f[i];
    }
    cout<<"\n Generator :";
    for(i=0;i<gs;i++)
    {
        cout<<g[i];
    }
 
    //Append 0's
    int rs=gs-1;
    cout<<"\n Number of 0's to be appended: "<<rs;
    for (i=fs;i<fs+rs;i++)
    {
	
        f[i]=0;
    }
 
    int temp[20];
  for(i=0;i<20;i++)
 {
   temp[i]=f[i];
 }
 
    cout<<"\n Message after appending 0's :";
    for(i=0; i<fs+rs;i++)
    {
        cout<<temp[i];
    }

    //Division
    for(i=0;i<fs+rs;i++)
    {
        j=0;
        k=i;
        //check whether it is divisible or not
		if((fs+rs)-k<gs)
		break;
		else
		{
        if (temp[k]>=g[j])
        {
            for(j=0,k=i;j<gs;j++,k++)
            {
                if((temp[k]==1 && g[j]==1) || (temp[k]==0 && g[j]==0))
                {
                    temp[k]=0;
                }
                else
                {
                    temp[k]=1;
                }
            }
        }
		} 
    }
	cout<<"\nCRC: ";
	for(int l=fs;l<fs+rs;l++)
	{
	cout<<temp[l];
	f[l]=temp[l];
       }
 
 
    cout<<"\n Frame with CRC: ";
    
    for(i=0;i<fs+rs;i++)
    {
        temp[i]=f[i];
    }
	for(i=0;i<fs+rs;i++)
    {
        cout<<temp[i];
    }
	
    
	char e; int b;
	cout<<"Do u want to generate error? (y/n)";
	cin>>e;
	if(e=='y'|| e=='Y')
	{cout<<"which bit u want to change? ";
	 cin>>b;
	 if(temp[b-1]==1)
	  {temp[b-1]=0;}
	  else
	  {temp[b-1]=1;}
	   cout<<" frame with error : ";
     for(i=0;i<fs+rs;i++)
    {
        cout<<temp[i];
    }
	}
	
 cout<<"\n ===Receiver side=== : ";
    cout<<"\n Received Frame: ";
    for(i=0;i<fs+rs;i++)
    {
        cout<<temp[i];
    }
 
    
 
    //Division
    for(i=0;i<fs+rs;i++)
    {
        j=0;
        k=i;
        //check whether it is divisible or not
		if((fs+rs)-k<gs)
		break;
		else
		{
        if (temp[k]>=g[j])
        {
            for(j=0,k=i;j<gs;j++,k++)
            {
                if((temp[k]==1 && g[j]==1) || (temp[k]==0 && g[j]==0))
                {
                    temp[k]=0;
                }
                else
                {
                    temp[k]=1;
                }
            }
        }
		} 
    }
 
    cout<<"\n Remainder: ";
	
int flag=0;
  
  
	for(i=fs;i<fs+rs;i++)
	{
	cout<<temp[i];
	if(temp[i]==1)
	flag=1;
	//break;
	
	}
 
    if(flag==0)
    {
        cout<<"\n Since Remainder Is 0 Hence Message Transmitted From Sender To Receiver Is Correct";
    }
    else
    {
        cout<<"\n Since Remainder Is Not 0 Hence Message Transmitted From Sender To Receiver Contains Error";
    }
    getch();
}

