//============================================================================
// Name        : heapify.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

class heap
{
public:
	int n,n1,a[10],maxtree[10],mintree[10];

	heap()
	{
		n=-1;
		n1=-1;
		for(int i=0;i<10;i++)
		{
			maxtree[i]=0;
			mintree[i]=0;
		}
	}

	void input()
	{
		int no;
		cout<<"\nEnter the number of students you want to enter:";
		cin>>no;
		cout<<"\nEnter the marks of "<<no<<"students:";
		for(int i=0;i<no;i++)
		{
			cin>>a[i];
		}
		for(int i=0;i<no;i++)
		{
			minheap(a[i]);
		}
		for(int i=0;i<no;i++)
		{
			maxheap(a[i]);
		}
		cout<<"\nMinimum marks="<<mintree[0];
		cout<<"\nMaximum marks="<<maxtree[0];
		for(int i=0;i<no;i++)
		{
			cout<<maxtree[i]<<endl;
		}
		cout<<"............................";
		for(int i=0;i<no;i++)
		{
			cout<<mintree[i]<<endl;
		}

	}

	void minheap(int item)
	{
		n=n+1;
		int ptr=n,par;
		while(ptr>0)
		{
			par=(ptr-1)/2;
			if(item>=mintree[par])
			{
				mintree[ptr]=item;
				return;
			}
			mintree[ptr]=mintree[par];
			ptr=par;
		}
		mintree[ptr]=item;
	}

	void maxheap(int item)
	{
		n1=n1+1;
		int ptr=n1,par;
		while(ptr>0)
		{
			par=(ptr-1)/2;
			if(item<=maxtree[par])
			{
				maxtree[ptr]=item;
				return;
			}
			maxtree[ptr]=maxtree[par];
			ptr=par;
		}
		maxtree[ptr]=item;
	}
};

int main() {
	heap h;
	h.input();

	return 0;
}
