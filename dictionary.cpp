//============================================================================
// Name        : dictionary.cpp
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
	char word[20],meaning[50];
	node *right,*left;
};

class binary_tree
{


public:
	node *temp,*root;
	binary_tree()
	{
		root=NULL;
		temp=NULL;
	}

	node* create()
	{
		node *newnode=new node;
		cout<<"\nEnter the keyword:";
		cin>>newnode->word;
		cout<<"Enter its meaning:";
		cin>>newnode->meaning;
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
			int flag=0;
			node *child=create();
			while(flag==0 && temp!=NULL)
			{

				if(strcmp(child->word,temp->word)<0)
				{
					if(temp->left==NULL)
					{
						temp->left=child;
						flag=1;
						cout<<"\nNode Inserted!\n";

					}
					else
					{
						temp=temp->left;
					}
				}
				else if(strcmp(child->word,temp->word)>0)
				{
					if(temp->right==NULL)
					{
						temp->right=child;
						flag=1;
						cout<<"\nNode Inserted!\n";
					}
					else
						temp=temp->right;
				}
				else
				{
					cout<<"\nKeyword already exists!!!";
					return;
				}
			}
		}
	}

	void update()
	{
		temp=root;
		int flag=0;
		char key[20];
		cout<<"\nEnter the keyword you want to update:";
		cin>>key;
		while(temp && flag==0)
		{
			if(strcmp(temp->word,key)==0)
			{
				flag=1;

			}
			else if(strcmp(temp->word,key)>0)
			{
				temp=temp->left;
			}
			else
			{
				temp=temp->right;
			}
		}
		if(flag==1)
		{
			cout<<"\nEnter the new meaning of "<<key<<":";
			cin>>temp->meaning;
		}
		else
		{
			cout<<"\nThe keyword doesn't exist!!!";
		}

	}

	void comparisons()
	{
		char key[20];
		cout<<"\nEnter the keyword you want to search:";
		cin>>key;
		temp=root;
		int flag=0,count=0;

		while(temp && flag==0)
		{
			count++;
			if(strcmp(temp->word,key)==0)
			{
				flag=1;

			}
			else if(strcmp(temp->word,key)>0)
			{
				temp=temp->left;
			}
			else
			{
				temp=temp->right;

			}
		}
		if(flag==1)
		{
			cout<<"\nKeyword found!!!";
			cout<<endl<<temp->word<<" = "<<temp->meaning;
			cout<<"\nComparisons required="<<count;
		}
		else
		{
			cout<<"\nThe keyword doesn't exist!!!";
		}

	}

	node* search(char key[20])
		{
			node *parent=root;
			temp=root;
			int flag=0,count=0;

			while(temp && flag==0)
			{
				count++;
				if(strcmp(temp->word,key)==0)
				{
					flag=1;

				}
				else if(strcmp(temp->word,key)>0)
				{
					parent=temp;
					temp=temp->left;
				}
				else
				{
					parent=temp;
					temp=temp->right;

				}
			}
			if(flag==1)
			{
				return parent;
			}
			else
			{
				cout<<"\nThe keyword doesn't exist!!!";
				return NULL;
			}

		}


	void inorder_asc(node *n)
	{
		if(n)
		{
			inorder_asc(n->left);
			cout<<n->word<<" : "<<n->meaning<<endl;
			inorder_asc(n->right);
		}
	}

	void inorder_desc(node *n)
	{
		if(n)
		{
			inorder_desc(n->right);
			cout<<n->word<<" : "<<n->meaning<<endl;
			inorder_desc(n->left);
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
			for(int i=0;i<strlen(n->word);i++)
				newnode->word[i]=n->word[i];
			for(int i=0;i<strlen(n->meaning);i++)
				newnode->meaning[i]=n->meaning[i];
			return newnode;
		}
	}

	void delete_node()
		{
			node *temp1;
			char key[20];
			cout<<"\nEnter the keyword you want to delete:";
			cin>>key;
			if(strcmp(root->word,key)==0)
			{
				temp1=root;
			}
			else
			{
			node *p=search(key);

			if(p->left)
			{
				if(strcmp(p->left->word,key)==0)
				{
					temp1=p->left;
				}
			}
			if(p->right)
			{
				if(strcmp(p->right->word,key)==0)
				{
					temp1=p->right;
				}
			}
			if(temp1)
			{
				if(temp1->left==NULL && temp1->right==NULL)
				{
					if(p->right==temp1)
						p->right=NULL;
					else
						p->left=NULL;
				}
			}
			//.......................................node has 1 child..................................

			if(temp1->left==NULL && temp1->right!=NULL)
			{
				if(p->right==temp1)
					p->right=temp1->right;
				else
					p->left=temp1->right;
			}
			if(temp1->left!=NULL && temp1->right==NULL)
			{
				if(p->right==temp1)
					p->right=temp1->left;
				else
					p->left=temp1->left;
			}
			}
			cout<<"\nNode deleted:"<<temp1->word;

			//...............................node has 2 children......................

			if(temp1->left!=NULL && temp1->right!=NULL)
			{
				node *t=temp1->left;
				while(t->right!=NULL)
				{
					t=t->right;
				}
				node *pa=search(t->word);
				for(int i=0;i<strlen(t->word);i++)
					temp1->word[i]=t->word[i];
				for(int i=0;i<strlen(t->meaning);i++)
					temp1->meaning[i]=t->meaning[i];
				if(t)
				{
					if(t->left==NULL && t->right==NULL)
					{
						if(pa->right==t)
							pa->right=NULL;
						else
							pa->left=NULL;
					}
				}

				if(t->left==NULL && t->right!=NULL)
				{
					if(pa->right==t)
						pa->right=t->right;
					else
						pa->left=t->right;
				}
				if(t->left!=NULL && t->right==NULL)
				{
					if(pa->right==t)
						pa->right=t->left;
					else
						pa->left=t->left;
				}
				delete t;

			}

		}


};

int main() {
	int no,ch;
	binary_tree b,ct;
	cout<<"\nEnter the number of nodes you want to insert:";
	cin>>no;
	for(int i=0;i<no;i++)
	{
		b.construct();
	}
	do
	{
		cout<<"\n1.Insert new node \n2.Display Ascending Order \n3.Display Descending order \n4.Search Element \n5.Delete Element \n6.Copy the dictionary \n7.Update meaning of key \n8.Exit";
		cout<<"\nEnter your choice:";
		cin>>ch;
		switch(ch)
		{
		case 1:
			b.construct();
			break;

		case 2:
			b.inorder_asc(b.root);
			break;

		case 3:
			b.inorder_desc(b.root);
			break;

		case 4:
			b.comparisons();
			break;

		case 5:
			b.delete_node();
			break;

		case 6:
			ct=b;
			cout<<"\nCopied dictionary:\n";
			ct.inorder_asc(ct.root);
			break;

		case 7:
			b.update();
			break;
		}
	}while(ch!=8);
	return 0;
}
