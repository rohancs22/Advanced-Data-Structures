//============================================================================
// Name        : obst.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
const int n=4;

struct node
{
	int no;
	node *left,*right;
};

class entry
{
	float c,w;
	int r;

	entry()
	{
		c=w=0.0;
		r=0;
	}

public:
	friend class obst;
};

class obst
{
public:
	node *root;
	entry table[10][10];
	int p[n+1],q[n+1],data[n];

	obst()
	{
		root=NULL;
	}
	void input()
	{
		p[0]=0;
		cout<<"\nEnter 4 Successful probabilities:";
		for(int i=1;i<=n;i++)
		{
			cin>>p[i];
		}
		cout<<"\nEnter 5 unsuccessful probabilities:";
		for(int i=0;i<=n;i++)
		{
			cin>>q[i];
		}
		cout<<"\nEnter 4 data elements:";
		for(int i=1;i<=n;i++)
		{
			cin>>data[i];
		}
	}

	void create()
	{
		int j,m,min,k,var;
		for(int i=0;i<n;i++)
		{
			table[i][i].w=q[i];
			table[i][i].c=0.0;
			table[i][i].r=0;
			table[i][i+1].w=q[i]+p[i+1]+q[i+1];
			table[i][i+1].c=q[i]+p[i+1]+q[i+1];
			table[i][i+1].r=i+1;
		}
		table[n][n].w=q[n];
		table[n][n].c=0.0;
		table[n][n].r=0;

		for(int i=2;i<=n;i++)
		{
			for(j=0;j<=(n-i);j++)
			{
				min=99;
				m=i+j;

				table[j][m].w=table[j][m-1].w+p[m]+q[m];

				for(k=j+1;k<=m;k++)
				{
					if(min>(table[j][k-1].c+table[k][m].c))
					{
						min=table[j][k-1].c+table[k][m].c;
						var=k;
					}
				}
				table[j][m].r=var;
				table[j][m].c=min+table[j][m].w;
			}
		}
	}

	void display()
	{
		cout<<"\nTabel: [Weight  Root  Cost]\n";
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=n;j++)
			{
				cout<<"("<<i<<" , "<<j<<")->[";
				cout<<table[i][j].w<<"  ";
				cout<<table[i][j].r<<"  ";
				cout<<table[i][j].c<<" ";
				cout<<" ]\t";
			}
			cout<<"\n";
		}
	}

	node* createTree(int i,int j,node *t)
	{
		if(i!=j)
		{
			int k=table[i][j].r;
			if(t==NULL)
			{
				root=t=new node();
				t->no=data[k];
				t->left=createTree(i,k-1,NULL);
				t->right=createTree(k,j,NULL);
				return t;
			}
			else
				return NULL;
		}
		return NULL;
	}

	void inorder(node *n)
	{
		if(n)
		{

			inorder(n->left);
			cout<<"<-"<<n->no<<"->";
			inorder(n->right);
		}

	}
};

int main() {
	obst o;
	o.input();
	o.create();
	o.display();
	node *r=o.createTree(0,n,NULL);
	cout<<"\nInorder=";
	o.inorder(r);
	return 0;
}
