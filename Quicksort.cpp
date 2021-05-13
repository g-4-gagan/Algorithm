#include<iostream>
#include<stdlib.h>
using namespace std;

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

int partition(int A[],int p,int r,int &comp)
{
	int x;
	x=A[r];
	int i=p-1;
	int j;
	int count=0;
	for(j=p;j<r;j++)
	{
		count++;
		if(A[j] <= x)
		{
			i=i+1;
			swap(A[i],A[j]);
		}
	}
	swap(A[i+1],A[r]);
	
	comp=comp+count;
	return (i+1);
}

int r_partition(int A[],int p,int r,int &comp)
{
	int i = random(p,r);
	swap(A[r],A[i]);
	
	return partition(A,p,r,comp);
}

void r_quicksort(int A[],int p,int r,int &comp)
{
	int q;
	if(p<r)
	{
		q=r_partition(A,p,r,comp);
		r_quicksort(A,p,q-1,comp);
		r_quicksort(A,q+1,r,comp);
	}
	
}

void display(int A[],int n,int &comp)
{
	cout<<"\n Sorted array : ";
	for(int i=0;i<n;i++)
		cout<<A[i]<<" ";
		
	cout<<"\n\n Total no. of comparisons  : "<<comp;
}

int main()
{
	int n;

		int comp=0;
		cout<<"\n Enter the array size : ";
		cin>>n;
		int A[n];
		
		cout<<" Enter the array elements : ";
		for(int i=0;i<n;i++)
			cin>>A[i];
		cout<<endl;
		
		r_quicksort(A,0,n-1,comp);	
		display(A,n,comp);	
		
	
	return 0;
}
