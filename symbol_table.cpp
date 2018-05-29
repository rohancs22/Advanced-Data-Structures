//============================================================================
// Name        : hashing.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
using namespace std;

struct node
{
	char key[20],value[20];
	int flag,empty;
};

class hash
{
	node n[10];
public:

hash()
{
	for(int i=0;i<10;i++)
	{
		n[i].flag=-1;
		n[i].empty=0;
		strcpy(n[i].key," ");
		strcpy(n[i].value," ");
	}
}

void no_replace()
{
	int len=0,index;
	char k[20],v[20];
	cout<<"\nEnter the key and its value:";
	cin>>k>>v;
	for(int i=0;i<strlen(k);i++)
	{
		len+=k[i];
	}
	//cout<<len;
	index=len%10;
	if(n[index].empty==0)
	{
		strcpy(n[index].key,k);
		strcpy(n[index].value,v);
		n[index].empty=1;
	}
	else
	{
		int s=index;
		while(n[s].empty!=0)
		{
			s=(s+1)%10;
		}
		strcpy(n[s].key,k);
		strcpy(n[s].value,v);
		n[s].empty=1;
		while(n[index].flag!=-1)
		{
			index=n[index].flag;
		}
		n[index].flag=s;

	}
}

void replace()
{
	int len=0,index,ind;
	char k[20],v[20];
	cout<<"\nEnter the key and its value:";
	cin>>k>>v;
	for(int i=0;i<strlen(k);i++)
	{
		len+=k[i];
	}
	index=len%10;
	if(n[index].empty==0)
	{
		strcpy(n[index].key,k);
		strcpy(n[index].value,v);
		n[index].empty=1;
	}
	else
	{
		len=0;
		char temp[20];
		strcpy(temp,n[index].key);
		for(int i=0;i<strlen(temp);i++)
		{
			len+=temp[i];
		}
		ind=len%10;
		if(ind!=index)
		{
			int s=index;
			while(n[s].empty!=0)
			{
				s=(s+1)%10;
			}
			strcpy(n[s].key,n[index].key);
			strcpy(n[s].value,n[index].value);
			n[s].empty=1;
			n[ind].flag=s;
			while(n[index].flag!=-1)
			{
				index=n[index].flag;
			}
			n[index].flag=s;


			strcpy(n[index].key,k);
			strcpy(n[index].value,v);
			n[index].empty=1;
			n[index].flag=-1;

		}
		else
		{
			int s=index;
			while(n[s].empty!=0)
			{
				s=(s+1)%10;
			}
			strcpy(n[s].key,k);
			strcpy(n[s].value,v);
			n[s].empty=1;
			while(n[index].flag!=-1)
			{
				index=n[index].flag;
			}
			n[index].flag=s;

		}
	}
}

void search()
{
	int len=0,index,ind;
	char k[20],v[20];
	cout<<"\nEnter the key you want to search:";
	cin>>k;
	for(int i=0;i<strlen(k);i++)
	{
		len+=k[i];
	}
	index=len%10;
	if(strcmp(n[index].key,k)==0)
	{
		cout<<"Key Found!!!";
		cout<<"\nValue="<<n[index].value;
	}
	else if(n[index].flag==-1)
	{
		cout<<"\nKey Not Found!!!";
	}
	else
	{
		while(n[index].flag!=-1 || strcmp(n[index].key,k)==0)
		{
			if(strcmp(n[index].key,k)==0)
			{
				cout<<"Key Found!!!";
				cout<<"\nValue="<<n[index].value;
				return;
			}
			index=n[index].flag;

		}
		cout<<"\nKey Not found!!!";
	}
}

void deleteHash()
{
	int len=0,index,ind;
		char k[20],v[20];
		cout<<"\nEnter the key you want to search:";
		cin>>k;
		for(int i=0;i<strlen(k);i++)
		{
			len+=k[i];
		}
		index=len%10;
		if(strcmp(n[index].key,k)==0)
		{
			n[index].flag=-1;
			n[index].empty=0;
			strcpy(n[index].key," ");
			strcpy(n[index].value," ");
		}
		else if(n[index].flag==-1)
		{
			cout<<"\nKey Not Found!!!";
		}
		else
		{
			while(n[index].flag!=-1 || strcmp(n[index].key,k)==0)
			{
				if(strcmp(n[index].key,k)==0)
				{
					n[ind].flag=n[index].flag;
					n[index].flag=-1;
					n[index].empty=0;
					strcpy(n[index].key," ");
					strcpy(n[index].value," ");

					return;
				}
				ind=index;
				index=n[index].flag;

			}
			cout<<"\nKey Not found!!!";
		}
}

void display()
{
	for(int i=0;i<10;i++)
	{
		cout<<i<<" --- "<<n[i].key<<" --- "<<n[i].value<<" --- "<<n[i].flag<<endl;
	}
}

};

int main() {
	hash h;
	for(int i=0;i<9;i++)
		h.no_replace();
	h.display();
	//h.search();
	h.deleteHash();
	h.display();
	return 0;
}
