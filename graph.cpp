//============================================================================
// Name        : queue.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stack>
#include <cstring>
#define max 10
using namespace std;


//int n=10;
class node
{
	char city[20];
	int time1;
	node *next;
	int visited;

public:
	friend class graph;

	node()
	{
		strcpy(city," ");
		next=NULL;
		time1=-1;
		visited=0;
	}

	node(char city1[20],int t)
	{
		strcpy(this->city,city1);
		next=NULL;
		time1=t;
		visited=0;
	}

};

stack <char*> s1;

class graph
{
	node *head[max];
	int n;
public:
	graph(int num)
		{
			n=num;
			for(int i=0;i<n;i++)
			{
				head[i]=NULL;
			}
		}

	int getindex(char c[20])
	{
		for(int i=0;i<n;i++)
		{
			if(strcmp(head[i]->city,c)==0)
				return i;
		}
		return -1;
	}

	void insert(char s_city[20],char d_city[20],int cost)
	{
		node *source;
		node *dest=new node(d_city,cost);
		int in=getindex(s_city);
		if(head[in]==NULL)
		{
			head[in]=dest;
		}
		else
		{
			source=head[in];
			while(source->next!=NULL)
			{
				source=source->next;
			}
			source->next=dest;
		}
	}

	void insert_undirected(char s_city[20],char d_city[20],int cost)
	{
		node *source;
		node *dest=new node(d_city,cost);
		node *dest2=new node(s_city,cost);

		int ind=getindex(s_city);
		int ind2=getindex(d_city);
		if(head[ind]==NULL && head[ind2]==NULL)
		{
			head[ind]=dest;
			head[ind2]=dest2;
		}
		else if(head[ind]==NULL && head[ind2]!=NULL)
		{
			head[ind]=dest;
			source=head[ind2];
			while(source->next!=NULL)
				source=source->next;
			source->next=dest2;
		}
		else if(head[ind]!=NULL && head[ind2]==NULL)
		{
			head[ind2]=dest2;
			source=head[ind];
			while(source->next!=NULL)
				source=source->next;
			source->next=dest;
		}
		else
		{
			source=head[ind];
			while(source->next!=NULL)
				source=source->next;
			source->next=dest;

			source=head[ind2];
			while(source->next!=NULL)
				source=source->next;
			source->next=dest2;
		}
	}

	void getdata(int graph_type)
	{
		char s_city[20],d_city[20],temp[20];
		int weight,nf;
		cout<<"\nEnter city details:";
		for(int i=0;i<n;i++)
		{
			head[i]=new node();
			cout<<"\nEnter the city name:";
			cin>>temp;
			strcpy(head[i]->city,temp);
		}
		cout<<"\nEnter the number of routes you want to insert:";
		cin>>nf;
		for(int i=0;i<nf;i++)
		{
			cout<<"\nEnter source city:";
			cin>>s_city;
			cout<<"\nEnter destination city:";
			cin>>d_city;
			cout<<"\nEnter the time required to travel from "<<s_city<<" to "<<d_city<<" :";
			cin>>weight;
			if(graph_type==1)
				insert(s_city,d_city,weight);
			else
				insert_undirected(s_city,d_city,weight);
		}
	}

	void dfs()
	{
		char c[20];
		node *v=head[0];
		s1.push(v->city);
		while(!s1.empty())
		{
			strcpy(c,s1.top());
			s1.pop();
			int i=getindex(c);
			v=head[i];
			if(!v->visited)
			{
				v->visited=1;
				cout<<v->city<<"->";
				while(v->next!=NULL)
				{
					s1.push(v->next->city);
					v=v->next;
				}
			}
		}
	}

	void indegree()
	{
		int count;
		node *temp;
		for(int i=0;i<n;i++)
		{
			count=0;
			for(int j=0;j<n;j++)
			{
				temp=head[j]->next;
				while(temp!=NULL)
				{
					if(strcmp(temp->city,head[i]->city)==0)
					{
						count++;
					}
					temp=temp->next;
				}
			}
			cout<<"\nIndegree of "<<head[i]->city<<"="<<count;
		}
	}

	void outdegree()
	{
		int count;
		node *temp;
		for(int i=0;i<n;i++)
		{
			count=0;
			temp=head[i]->next;
			while(temp!=NULL)
			{
				count++;
				temp=temp->next;
			}
			cout<<"\nOutDegree of "<<head[i]->city<<"="<<count;
		}
	}
	void degree()
	{
		int count;
		node *temp;
		for(int i=0;i<n;i++)
		{
			count=0;
			temp=head[i]->next;
			while(temp!=NULL)
			{
				count++;
				temp=temp->next;
			}
			cout<<"\nDegree of "<<head[i]->city<<"="<<count;
		}
	}

	void delete_edge(char city[20],char str[20])
		{
			node *current;
			int c;
			for(int i=0;i<n;i++)
			{
				if(strcmp(str,head[i]->city)==0)
				{
					c=i;
					break;
				}
				else
				{
					c=-1;
				}
			}
			if(c==-1)
			{
				return;
			}
			node *ptr=head[c];
			while(strcmp(ptr->city,city)!=0 && ptr->next!=NULL)
			{
				current=ptr;
				ptr=ptr->next;
			}
			if(ptr->next!=NULL)
			{
				current->next=ptr->next;
				delete ptr;
			}
			else
			{
				cout<<"\nEdge not found!!";
			}
		}
	void delete_city()
		{
			int c;
			char str[20];
			cout<<"Enter the city to be deleted\n";
			cin>>str;
			for(int i=0;i<n;i++)
			{
				cout<<"...........";
				if(strcmp(str,head[i]->city)==0)
				{
					c=i;
					cout<<"......"<<c;
					break;
				}
				else
				{
					c=-1;
				}
			}
			if(c==-1)
			{
				cout<<"City not available\n";
			}
			else
			{
				cout<<"//////";
				 node *ptr=head[c]->next;
				head[c]->next=NULL;
				delete ptr;
				delete head[c];

				for(int i=c+1;i<n;i++)
				{
					head[i-1]=head[i];
				}
			}
			n=n-1;

			for(int i=0;i<n;i++)
			{
				if(i==c)
					continue;
				delete_edge(str,head[i]->city);
			}
		}

};

int main() {
	int nodes,ch;
	cout<<"\nEnter the number of cities:";
	cin>>nodes;
	graph g(nodes);
	cout<<"\nEnter the type of the graph:\n1.Directed \n2.Undirected";
	cin>>ch;
	g.getdata(ch);

	g.delete_edge("m","p");
	g.delete_city();
	cout<<"DFS=\n";
	g.dfs();
	g.indegree();
	g.outdegree();
	return 0;
}
