#include<iostream>
using namespace std;

class node
{
	node* prev;
	double val;
	node* next;
	
	public:
		node(node* ptr=0,double a=0,node* ptr1=0)
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
		void add(node* ptr,double a);
		void insertathead(double a);
		void insertattail(double a);
		double remove(node* ptr);
		double removefromhead();
		double removefromtail();
		void sort();
		void move(double ar[],int& i);
		void print();
};

void DLL::add(node* ptr,double a)
{
	node* current=ptr->prev;
	current->next=ptr->prev=new node(current,a,ptr);
	return;
}

void DLL::insertathead(double a)
{
	add(head->next,a);
	return;
}

void DLL::insertattail(double a)
{
	add(tail,a);
	return;
}

double DLL::remove(node* ptr)
{
	node* current=ptr->prev;
	ptr->next->prev=current;
	current->next=ptr->next;
	double temp=ptr->val;
	delete ptr;
	return temp;
}

double DLL::removefromhead()
{
	if(head->next!=tail)
	{
		return remove(head->next);
	}
	return -1;
	
}

double DLL::removefromtail()
{
	if(head->next!=tail)
	{
		return remove(tail->prev);
	}
	return -1;
}

void DLL::sort()
{
	if(head->next!=tail)
	{
		double key;
		node* current=head->next->next;
		node* temp;
		while(current!=tail)
		{
			key = current->val;
			temp = current->prev;
			while(temp!=head && temp->val>key)
			{
				temp->next->val = temp->val;
				temp = temp->prev;
			}
			temp->next->val = key;
			current = current->next;
		}		
	}	
}

void DLL::move(double ar[],int& i)
{
	node *current = head->next;
	while(current!=tail)
	{
		ar[i++]=current->val;
		current=current->next;
	}
}

void DLL::print()
{
	if(head->next!=tail)
	{
		node* current=head->next;
		while(current!=tail)
		{
			cout<<current->val<<" ";
			current=current->next;
		}
		cout<<endl;
	}
	return;
}

void display(double ar[],int n)
{
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<ar[i]<<" ";
	}
	cout<<endl;
}

void bucket_sort(double ar[],int size)
{
	DLL *d = new DLL[size];
	
	for(int i=0;i<size;i++)
	{
		int pos = ar[i]*size;
		d[pos].insertattail(ar[i]);
	}
	for(int i=0;i<size;i++)
	{
		d[i].print();
	}
	for(int i=0;i<size;i++)
	{
		d[i].sort();
	}
	cout<<"Sorted lists";
	for(int i=0;i<size;i++)
	{
		d[i].print();
	}
	int a = 0;
	for(int i=0;i<size;i++)
	{
		d[i].move(ar,a);
	}
    
}

int main()
{
	int n;
	double *ar;
	cout<<"------------------------BUCKET SORT------------------------\n";
	cout<<"Enter the size of the array: ";
	cin>>n;
	ar=new double[n];
	cout<<"Enter the values of the array: ";
	for(int i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	cout<<"Entered array is: ";
	display(ar,n);
	bucket_sort(ar,n);
	cout<<"Array after sorting: ";
	display(ar,n);
}
