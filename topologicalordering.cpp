#include<iostream>
#include<queue>
using namespace std;

class node
{
	node* prev;
	int val;
	node* next;
	
	public:
		node(node* ptr=0,int a=0,node* ptr1=0)
		{
			prev=ptr;
			val=a;
			next=ptr1;
			return;
		}
		friend class DLL;
		friend class graph;
};

class DLL
{
	node* head;
	node* tail;
	
	public:
		DLL()
		{
			head = new node(0,0,tail);
			tail= new node(head,0,0);
			head->next = tail;
			return;
		}
		void add(node* ptr,int a);
		void insertattail(int a);
		void print();
		friend class graph;
};

void DLL::add(node* ptr,int a)
{
	node* current=ptr->prev;
	current->next=ptr->prev=new node(current,a,ptr);
	return;
}

void DLL::insertattail(int a)
{
	add(tail,a);
	return;
}

void DLL::print()
{
	if(head->next!=tail)
	{
		node* current=head->next;
		while(current!=tail)
		{
			cout<<current->val;
			current=current->next;
			if(current!=tail)
			{
				cout<<"->";
			}
		}
		cout<<endl;
	}
	return;
}

class graph{
	DLL *d;
	int v;
	
	public:
		graph()
		{
			
		}
		graph(int n)
		{
			d = new DLL[n];
			v=n;
			for(int i=0;i<n;i++)
			{
				d[i].insertattail(i+1);
			}
		}
		int vertices()
		{
			return v;
		}
		void inputnodes(int n);
		void display();
		void topologicalordering();
};

void graph::inputnodes(int n){
	
	d = new DLL[n];
    v=n;
    for(int i=0;i<n;i++)
	{
		d[i].insertattail(i+1);
	}
	int e;
	cout<<"Enter the number of edges in the Graph: ";
	cin>>e;
	for(int i=0;i<e;i++)
	{
		cout<<"Enter both vertices having "<<i+1<<" edge from and to respectively: ";
		int a,b;
		cin>>a>>b;
		if(a<=n&&b<=n)
		{
		  d[a-1].insertattail(b);
    	}
    	else{
    		cout<<"Input node not exist.\n";
    		i--;
		}
	}
}

void graph::display(){
	cout<<endl;
	for(int i=0;i<v;i++)
	{
		d[i].print();		
	}
}

void graph::topologicalordering()
{
	cout<<"\nTopological ordering start:-\n\n";
	int *indegree = new int[v];
	for(int i=0;i<v;i++)
	{
		indegree[i]=0;
	}
	for(int i=0;i<v;i++)
	{
		node* temp = d[i].head->next->next;
		for(;temp!=d[i].tail;temp=temp->next)
		{
			indegree[temp->val-1]++;
		}
	}
	queue<int> q;
	for(int i=0;i<v;i++)
	{
		if(!indegree[i])
		{
			q.push(i);
		}
	}
	int count=0;
	while(!q.empty())
	{
		int n = q.front();
		q.pop();
		node* temp = d[n].head->next->next;
		for(;temp!=d[n].tail;temp=temp->next)
		{
			indegree[temp->val-1]--;
			if(!indegree[temp->val-1])
			{
				q.push(temp->val-1);
			}
		}
		cout<<n+1<<" ";
		count++;
	}
	if(count!=v)
	{
		cout<<"\n\nTopological ordering stopped due to acyclic graph!!!!";
	}	
}

int main()
{
    int ch,n;
    graph g;
    cout<<"Enter the number of vertices in the Graph: ";
	cin>>n;
	g.inputnodes(n);
	cout<<"The input Graph is: ";
	g.display();
    g.topologicalordering();
		
}
