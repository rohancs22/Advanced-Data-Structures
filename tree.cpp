//============================================================================
// Name        : tree.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
#include <stack>
using namespace std;
int counti=-1,countl=0;//count=0;

struct node
{
	int data;
	node *right,*left;
};

class tree
{
	stack <node *> s1,s2;
public:
	node *root,*temp;

	tree()
	{
		root=NULL;
		temp=NULL;
	}

	node* create()
	{
		node *newnode=new node;
		cout<<"\nEnter the data:";
		cin>>newnode->data;
		newnode->left=NULL;
		newnode->right=NULL;
		return newnode;
	}

	void construct()
	{
		temp=root;
		if(root==NULL)
		{
			temp=create();
			root=temp;
			temp=root;
			cout<<"\nNode Inserted!\n";
			return;
		}
		else
		{
			char c;
			int flag=0;
			while(flag==0)
			{
				cout<<"\nEnter the side of "<<temp->data<<" you want to insert the node:(left-l)(right-r)";
				cin>>c;
				if(c=='l')
				{
					if(temp->left==NULL)
					{
						node *lchild=create();
						temp->left=lchild;
						flag=1;
						cout<<"\nNode Inserted!\n";

					}
					else
					{
						temp=temp->left;
					}



				}
				else if(c=='r')
				{
					if(temp->right==NULL)
					{
						node *rchild=create();
						temp->right=rchild;
						flag=1;
						cout<<"\nNode Inserted!\n";

					}
					else
						temp=temp->right;
				}
			}
		}
	}

	void preorder(node *n)
	{
		if(n)
		{
			cout<<"<-"<<n->data<<"->";
			preorder(n->left);
			preorder(n->right);
		}

	}

	void inorder(node *n)
	{
		if(n)
		{

			inorder(n->left);
			cout<<"<-"<<n->data<<"->";
			inorder(n->right);
		}

	}

	void postorder(node *n)
	{
		if(n)
		{

			postorder(n->left);
			postorder(n->right);
			cout<<"<-"<<n->data<<"->";
		}

	}

	int height(node *root)
	{
		if(root==NULL)
			return 0;
		else
			return (1+max(height(root->left),height(root->right)));
	}

	void count_nodes(node *n)
	{
		if(n)
		{
			if(n->right || n->left)
				counti++;
			else
				countl++;
			//count++;
			count_nodes(n->left);
			count_nodes(n->right);
		}

	}

	void displayc()
	{
		count_nodes(root);
		cout<<"\nTotal Nodes="<<count;
		cout<<"\nLeaf Nodes="<<countl;
		cout<<"\nInternal nodes="<<counti;
	}

	node *mirror(node *n)
	{
		node *current=new node;
		if(!n)
		{
			return NULL;
		}
		else
		{
			current->left=mirror(n->right);
			current->right=mirror(n->left);
			current->data=n->data;
			return current;
		}
	}
	node* operator=(node *n)
	{
		node *newnode=new node;
		if(!n)
			return NULL;
		else
		{
			newnode->left=(n->left);
			newnode->right=(n->right);
			newnode->data=n->data;
			return newnode;
		}
	}

	void erase(node *n)
	{
		if(n)
		{
			erase(n->left);
			erase(n->right);
			cout<<"\nDeleted node="<<n->data;
		}
		root=NULL;
	}

	void non_preorder(node *n)
	{
		while(n || !s1.empty())
		{
			if(n)
			{
				cout<<"<-"<<n->data<<"->";
				s1.push(n);
				n=n->left;
			}
			else
			{
				n=s1.top();
				s1.pop();
				n=n->right;
			}
		}
	}

	void non_inorder(node *n)
	{

		while(n || !s1.empty())
		{
			if(n)
			{

				s1.push(n);
				n=n->left;
			}
			else
			{
				n=s1.top();
				s1.pop();
				cout<<"<-"<<n->data<<"->";
				n=n->right;
			}
		}
	}

	void non_postorder(node *n)
	{
		if(!n)
			return;
		s1.push(n);
		node *current=new node;

		while(!s1.empty())
		{
			current=s1.top();
			s1.pop();
			s2.push(current);
			if(current->left)
			{
				s1.push(current->left);
			}
			if(current->right)
			{
				s1.push(current->right);
			}
		}
		while(!s2.empty())
		{
			current=s2.top();
			s2.pop();
			cout<<"<-"<<current->data<<"->";
		}
	}

};

int main() {
	int no,h,ch;
	tree t,co,mi;
	cout<<"\nEnter the number of nodes you want to insert:";
	cin>>no;
	for(int i=0;i<no;i++)
	{
		t.construct();
	}
	do
	{
		cout<<"\n1.Construct \n2.Preorder \n3.Inorder \n4.Postorder \n5.Mirror Image \n6.Copy Tree \n7.Height \n8.Count Nodes \n9.Erase nodes \n10.Exit";
		cout<<"\nEnter your choice:";
		cin>>ch;
		switch(ch)
		{
		case 1:
			cout<<"\nEnter the number of nodes you want to insert:";
			cin>>no;
			for(int i=0;i<no;i++)
			{
				t.construct();
			}
			break;

		case 2:
			cout<<"\nPreorder=";
			t.preorder(t.root);
			cout<<"\nNon recursive Preorder=";
			t.non_preorder(t.root);
			break;

		case 3:
			cout<<"\nInorder=";
			t.inorder(t.root);
			cout<<"\nNon recursive Inorder=";
			t.non_inorder(t.root);
			break;

		case 4:
			cout<<"\nPostorder=";
			t.postorder(t.root);
			cout<<"\nNon recursive Postorder=";
			t.non_postorder(t.root);
			break;

		case 5:
			mi.root=mi.mirror(t.root);
			cout<<"\nInorder of original tree=";
			t.inorder(t.root);
			cout<<"\nInorder of mirror=";
			mi.inorder(mi.root);
			break;

		case 6:
			co=t;
			cout<<"\nInorder of copied=";
			co.inorder(co.root);
			break;

		case 7:
			h=t.height(t.root);
			cout<<"\nHeight:"<<h;
			break;

		case 8:
			t.displayc();
			break;

		case 9:
			t.erase(t.root);
			cout<<"\nTree is empty!";
			break;
		}
	}while(ch!=10);

	return 0;
}
