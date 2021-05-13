#include<iostream>
#include<stdlib.h>
using namespace std;

void display(int ar[],int n)
{
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<ar[i]<<" ";
	}
	cout<<endl;
}

void swap(int &a,int &b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}

int random(int p,int r)
{
	int x=( rand() % (r-p) ) + p;
	return x;
}

int partition(int A[],int p,int r)
{
	int x;
	x=A[r];
	int i=p;
	int j;
	for(j=p;j<r;j++)
	{
		if(A[j] <= x)
		{
			swap(A[i++],A[j]);
		}
	}
	swap(A[i],A[r]);
	
	return i;
}

int r_partition(int A[],int p,int r)
{
	int i = random(p,r);
	swap(A[r],A[i]);
	
	return partition(A,p,r);
}

int randomized_select(int ar[],int p,int r,int x)
{
	if(p==r)
	{
		return ar[p];
	}
	int q = r_partition(ar,p,r);
	int k = q-p+1;
	if(x==k)
	{
		return ar[q];
	}
	else if(x<k)
	{
		return randomized_select(ar,p,q-1,x);
	}
	else
	{
		return randomized_select(ar,q+1,r,x-k);
	}
}

int main()
{
	int n,x,out;
	int *ar;
	cout<<"Enter the size of the array: ";
	cin>>n;
	ar = new int[n];
	cout<<"Enter the elemnets of the array: ";
	for(int i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	cout<<"Entered array is: ";
	display(ar,n);
	cout<<"Enter the sorted position of element: ";
	cin>>x;
	out = randomized_select(ar,0,n-1,x);
	cout<<"The element is: "<<out;
	return 0;	
}
