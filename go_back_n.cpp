#include<iostream.h>
struct packet
{ 
 int info; };
struct frame
{ int seq;
  int f; };
class sender
{ public:
  int n,sf,sn,z;
  void input()
  { sf=4;
    sn=8; }
  void network_layer()
  { packet i[50];
    cout<<"network layer: \n";
	cout<<"enter the size: ";
	cin>>n;
	for(int j=0;j<n;j++)
	{ cout<<"Enter the data: \n";
	  cin>>i[j].info; }
	cout<<"Packet sento the data link layer:\n";
	dll(i);
  }
  void dll(packet i[])
  { frame fr[50];
    cout<<"Packet received\n";
	for(int j=0;j<n;j++)
	{ cout<<"Enter the sequence \n";
	  cin>>fr[j].seq;
	  cout<<"Enter the frame:\n";
	  cin>>fr[j].f;
	}
	cout<<"frame generated\n";
	cout<<"frame transferred to physical layer\n";
	pl(i,fr);
  }
  void pl(packet i[],frame fr[])
  { cout<<"frame received\n";
    for(int j=0;j<n;j++)
	{ cout<<"frame j = "<<fr[j].f<<"\n";
	  cout<<"sequence = "<<fr[j].seq<<"\n";
	  cout<<"info = "<<i[j].info<<"\n";
	}
	cout<<"frame transfered to receiver\n";
	if(sf==sn)
	{ sn=15; }
	while(z!=sf)
	{ pl1(i[z],fr[z]);
	  z++; }
  }
  void pl1(packet &i,frame &fr)
  { int j;
    cout<<"frame received \n";
	cout<<"frame j = "<<fr.f<<"\n";
	cout<<"sequence = "<<fr.seq<<"\n";
	cout<<"info = "<<i.info<<"\n";
	cout<<"do u want to keep the frame \n";
	cout<<"1.To keep \n2.To destroy \n";
	cin>>j;
	if(j==2) 
	{ cout<<"time out\n";
	  network_layer(); }
	else 
	{ cout<<"Frame sent to dll\n";
	  dllr(i,fr); }
  }
  void dllr(packet &i,frame &fr)
  { int g,k;
    cout<<"Frame received \n";
	cout<<"frame j = "<<fr.f<<"\n";
	cout<<"sequence = "<<fr.seq<<"\n";
	cout<<"info = "<<i.info<<"\n";
	if(fr.f==0)
	{ cout<<"acknowledgement = 1\n"; }
	else 
	{ cout<<"acknowledgement = 0\n"; }
	cout<<"Do u want to send the acknowledgement(1/0) \n";
	cin>>k;
	if(k==0)
	{ cout<<"time out";
	  cout<<"Frame resending\n";
	  network_layer(); }
	else 
	{ cout<<"Frame send to network layer \n";
	  network_layerr(i,fr); }
  }
  void network_layerr(packet &i,frame &fr)
  { int j;
    cout<<"Frame received \n";
	cout<<"frmae j = "<<fr.f<<"\n";
	cout<<"sequence = "<<fr.seq<<"\n";
	cout<<"info = "<<i.info<<"\n";
	if(z==sf)
	{ sf++; }
	cout<<"Do u want to send data (1/0)\n";
	cin>>j;
	if(j==1)
	{ network_layer(); }
	else 
	{ cout<<"Data not sent\n";}
  }
};
int main()
{ cout<<"sf =4\n";
  cout<<"sn =8\n";
  sender s;
  s.input();
  s.network_layer();
  return 0;
}    	 	     	       	       	     	   	   
    
   
    
  

