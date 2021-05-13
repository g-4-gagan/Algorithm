#include<iostream>
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
		void inputnodes();
		void display();
		
};

void graph::inputnodes(){
	for(int i=0;i<v;i++)
	{
		int n;
		cout<<"Enter the number of nodes connected with vertex "<<i+1<<": ";
		cin>>n;
		if(n){
		cout<<"Enter the connected nodes: ";
		int p;
		for(int j=0;j<n;j++)
		{
			cin>>p;
			d[i].insertattail(p);
		}
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

int main()
{
	int n;
	cout<<"Enter the number of vertices in the Graph: ";
	cin>>n;
	graph g(n);
	g.inputnodes();
	g.display();
		
	
}
