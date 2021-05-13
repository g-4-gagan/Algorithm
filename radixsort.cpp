#include<iostream>
using namespace std;

void swap(int &a,int &b)
{
	a=a+b;
	b=a-b;
	a=a-b;
}

void display(int ar[],int n)
{
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<ar[i]<<" ";
	}
	cout<<endl;
}

int maximum(int ar[],int n)
{
	int max=ar[0];
	for(int i=1;i<n;i++)
	{
		if(max<ar[i])
		{
			max=ar[i];
		}
	}
	return max;
}

void count_sort(int ar[],int n,int e)
{
    int size = 10;
	int *temp=new int[size];
	for(int i=0;i<size;i++)
	{
		temp[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		temp[(ar[i]/e)%10]++;
	}
	int a=temp[0];
	temp[0]=0;
	for(int i=1;i<size;i++)
	{
		swap(temp[i],a);
		a+=temp[i];
	}
	int *ar1=new int[n];
	for(int i=0;i<n;i++)
	{
		ar1[temp[(ar[i]/e)%10]++]=ar[i];
	}
	for(int i=0;i<n;i++)
	{
		ar[i]=ar1[i];
	}
	return;

}

void radix_sort(int ar[],int size)
{
	int max = maximum(ar,size);
	for(int i=1;i<=max;i*=10)
	{
		count_sort(ar,size,i);
	}
}

int main()
{
	int n;
	int *ar;
	cout<<"------------------------RADIX SORT------------------------\n";
	cout<<"Enter the size of the array: ";
	cin>>n;
	ar=new int[n];
	cout<<"Enter the values of the array: ";
	for(int i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	cout<<"Entered array is: ";
	display(ar,n);
	radix_sort(ar,n);
	cout<<"Array after sorting: ";
	display(ar,n);
}
