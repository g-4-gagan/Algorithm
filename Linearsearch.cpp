#include<iostream>
using namespace std;

void display(int ar[],int n)
{
	cout<<"\nThe array entered is: ";
	for(int i=0;i<n;i++)
	{
		cout<<ar[i]<<" ";
	}
	cout<<endl;
}
int check(int x,int j,int ar[])
{
	int f=1;
	for(int i=0;i<j;i++)
	{
		if(ar[i]==x)
		{
			f=0;
			break;
		}
	}
	return f;
}
void input(int ar[],int n)
{
	int x;
	int flag;
	for(int i=0;i<n;)
	{
		cout<<"Enter element at index "<<i<<" : ";
		cin>>x;
		flag=check(x,i,ar);
		if(flag==1)	
			ar[i++]=x;
		else 
			cout<<"\nDuplicate value hence discarded\n";	
	}
}

void find(int k,int n,int ar[])
{
	int c=0;
	int index;
	int f=0;
	for(int i=0;i<n;i++)
	{
		c++;
		if(ar[i]==k)
		{
			index=i;
			f=1;
			break;
		}
	}
	if(f==1)
		{
			cout<<"\nNumber found at index: "<<index<<endl;
			cout<<"Total comparisons: "<<c<<endl;
		}
	else
		cout<<"\nNumber not found!!";
}
int main()
{
	int n;
	cout<<"Enter the size: ";
	cin>>n;
	int *ar;
	ar=new int[n];
	input(ar,n);
	display(ar,n);
	int x;
	cout<<"Enter the element to be searched: ";
	cin>>x;
	find(x,n,ar); 
	return 0; 
}
