//============================================================================
// Name        : deque.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct node
{
	int data;
	node *left,*right;
	int lflag,rflag;
};

class tbt
{
public:
	node *root,*temp;
	tbt()
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
	void insert()
	{
		node *nn=create();
		int f=0;
		temp=root;
		if(root==NULL)
		{
			root=nn;
			nn->left=NULL;
			nn->right=NULL;
			nn->lflag=1;
			nn->rflag=1;
		}
		else
		{
			while(f==0)
			{
			if(temp->data>nn->data)
			{
				if(temp->lflag==0)
				{
					temp=temp->left;
				}
				else
				{
					nn->left=temp->left;
					nn->lflag=1;
					nn->right=temp;
					nn->rflag=1;
					temp->left=nn;
					temp->lflag=0;
					f=1;
				}
			}

			else if(temp->data<nn->data)
			{
				if(temp->rflag==0)
				{
					temp=temp->right;
				}
				else
				{
					nn->right=temp->right;
					nn->rflag=1;
					nn->left=temp;
					nn->lflag=1;
					temp->right=nn;
					temp->rflag=0;
					f=1;
				}
			}
			else
			{
				cout<<"\nData already exists!!!";
			}
		}
		}
	}

	node *successor(node *n)
	{
		node *t;
		if(n->rflag==1)
			return n->right;
		else
		{
			t=n->right;
			while(t->lflag==0)
			{
				t=t->left;
			}
			return t;
		}
	}

	node *predecessor(node *n)
	{
		node *t;
		if(n->lflag==1)
		{
			return n->left;
		}
		else
		{
			t=n->left;
			while(t->rflag==0)
			{
				t=t->right;
			}
			return t;
		}
	}

	void inorder()
	{
		node *t=root;
		while(t->lflag==0)
		{
			t=t->left;
		}
		while(t!=NULL)
		{
			cout<<"\n"<<t->data;
			t=successor(t);
		}
	}

	void preorder()
	{
		node *s=root;
		int flag=0;
		cout<<"\n"<<s->data;
		while(s->right!=NULL)
		{
			while(s->lflag==0 && flag==0)
			{
				s=s->left;
				cout<<"\n"<<s->data;
			}
			if(s->rflag)
			{
				s=s->right;
				flag=1;
			}
			else
			{
				s=s->right;
				cout<<"\n"<<s->data;
				flag=0;
			}
		}
	}

	node * search(int key)
		{
			node *parent;
			temp=root;
			parent=root;

			int count=0;

			int flag=0;
			while(temp && flag==0)
			{
			if(temp->data==key)
			{
			flag=1;
			}
			else if(temp->data>key)
			{
				parent=temp;
				temp=temp->left;
			}
			else
			{
				parent=temp;
				temp=temp->right;

			}
			count++;
			}
			if(flag==1)
			{

				return parent;
			}
			else
			{

				return parent;
			}
		}

		void delete_node()
		{
			node *temp1,*child,*pre,*suc;
			int key;
			cout<<"\nEnter the keyword you want to delete:";
			cin>>key;
			node *p;

			if(root->data==key)
			{
					temp1=root;
			}
			else
			{
				p=search(key);
					if(p->left)
					{
						if(p->left->data==key)
						{
							temp1=p->left;
						}
					}
					if(p->right)
					{
						if(p->right->data==key)
						{
							temp1=p->right;
						}
					}
			}
					if(temp1)
					{
						if(temp1->lflag==1 && temp1->rflag==1)
						{
							if(p->right==temp1)
							{
								p->rflag=1;
								p->right=temp1->right;
							}
							else
							{
								p->lflag=1;
								p->left=temp1->left;
							}
						}
					}
//.......................................node has 1 child..................................
					pre=predecessor(temp1);
					suc=successor(temp1);

					if(temp1->lflag==1 && temp1->rflag==0)
					{
						child=temp1->right;
						if(p->right==temp1)
							p->right=child;
						else
							p->left=child;
						suc->left=pre;
					}
					if(temp1->lflag==0 && temp1->rflag==1)
					{
						child=temp1->left;
						if(p->right==temp1)
							p->right=child;
						else
							p->left=child;
						pre->right=suc;
					}

					cout<<"\nNode deleted:"<<temp1->data;

	//...............................node has 2 children......................
				if(temp1->lflag==0 && temp1->rflag==0)
				{
					suc=successor(temp1);

					node *ps=search(suc->data);
					temp1->data=suc->data;
					if(suc)
					{
						if(suc->lflag==1 && suc->rflag==1)
						{
								if(ps->right==suc)
								{
										ps->rflag=1;
										ps->right=suc->right;
								}
								else
								{
										ps->lflag=1;
										ps->left=suc->left;

								}
								goto del;
						}
					}
					//one child
					node *pree=predecessor(suc);
					node *succ=successor(suc);

					if(suc->lflag==1 && suc->rflag==0)
					{
						child=suc->right;
						if(ps->right==suc)
								ps->right=child;
						else
							ps->left=child;
						succ->left=pree;
					}
					if(suc->lflag==0 && suc->rflag==1)
					{
							child=suc->left;
							if(ps->right==suc)
								ps->right=child;
							else
								ps->left=child;
							pree->right=succ;
					}


					del:delete suc;
					}
				}




};

int main() {
	tbt t;
	int no;
	cout<<"\nEnter the number of nodes you want to insert:";
	cin>>no;
	for(int i=0;i<no;i++)
	{
		t.insert();
	}
	cout<<"\nInorder=";
	t.inorder();
	cout<<"\nPreorder=";
	t.preorder();
	t.delete_node();
	cout<<"\nInorder=";
	t.inorder();
	t.delete_node();
	cout<<"\nInorder=";
	t.inorder();
	t.delete_node();
	cout<<"\nInorder=";
	t.inorder();
	return 0;
}
