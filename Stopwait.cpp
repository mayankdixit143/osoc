#include<iostream.h>
#include<stdlib.h>

struct packet
{ 
 int info[10];
};
 
struct frame
{ 
  int frame_no;
 int seq_no;
 
};
 
class sender
{
public:

packet p1;
frame f1;
int l;
 void network_layer();
 void data_link_layer();
 void physical_layer();
 };
 
void sender::network_layer()
{ l=0;
 cout<<"\n===NETWORK LAYER===;\n";
 cout<<"Enter the length of Packet info:=\n ";
 cin>>l;
 cout<<"Enter the packet info:=\n ";
 for(int i=0;i<l;i++)
  cin>>p1.info[i];
 cout<<" Packet send from network layer to data link layer\n";
 cout<<endl;
 }
 
 void sender::data_link_layer()
 {
  cout<<"===DATA LINK LAYER===\n";
  cout<<"\nEnter frame_no:(0/1):= ";
  cin>>f1.frame_no;
  f1.seq_no=rand();
  cout<<"seq_no:== "<<f1.seq_no<<endl;
  cout<<"value of l:"<<l<<endl;
  cout<<" FRAME== "<<f1.frame_no<<"|"<<f1.seq_no<<"|";
  for(int i=0;i<l;i++)
   {cout<<p1.info[i];}
   cout<<endl;
  cout<<"frame send from data link layer to physical layer;\n";
  }
 
 void sender::physical_layer()
 {
  cout<<"\n===PHYSICAL LAYER===\n";
  cout<<"Frame passed from physical layer to next hop:\n";
  cout<<endl;
  }
  
  
 class receiver
 {
 public:
  
  
  void phy_layer();
  void data_layer(sender s1);
  void nw_layer(sender s1);
  
  };
  
  
void receiver::phy_layer()
{
 cout<<"\n===PHYSICAL LAYER===:\n";
 cout<<"Frame received \n";
 cout<<"Frame now passed to data link layer of receiver :\n"; 
  }
  
 void receiver::data_layer(sender s1)
 {
  cout<<"\n===DATA LINK LAYER===\n";
  
  
  cout<<"Frame Information: "<<s1.f1.frame_no<<"|"<<s1.f1.seq_no<<"|";
  for(int i=0;i<s1.l;i++)
   { cout<<s1.p1.info[i];}
   cout<<endl;
   cout<<"Frame passed to network layer: \n";
   }
  
  
 void receiver::nw_layer(sender s1)
 {cout<<"\n===NETWORK LAYER===";
 cout<<"\n THE PACKET INFO: ";
 for(int l=0;l<s1.l;l++)
 cout<<s1.p1.info[l];
 } 


int main()
{
sender s;
receiver r;
int choice,ack_no;
char ch;
do
{
s.network_layer();
s.data_link_layer();
s.physical_layer();
cout<<endl;
cout<<"===*RECEIVER SIDE*===";
cout<<"\nDo u want to (1.)keep the packet or (2.)dicard it:==(1/2):: ";
cin>>choice;
switch(choice)
{
case 1:
if(s.f1.frame_no==0)
ack_no=1;
else
ack_no=0;
cout<<"\nacknowledgement no :"<<ack_no<<endl;
r.phy_layer();
r.data_layer(s);
r.nw_layer(s);
break;
case 2:
cout<<"\nframe discarded";
cout<<"\nTIME OUT";
cout<<"\nRESENDING the packet";
break;
}
cout<<"\n do u want to enter again:=";
cin>>ch;
}while(ch=='y'||ch=='Y');
return 0;
}





