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

int minnimum(int ar[],int n)
{
	int min=ar[0];
	for(int i=1;i<n;i++)
	{
		if(min>ar[i])
		{
			min=ar[i];
		}
	}
	return min;
}

void count_sort(int ar[],int n)
{
	int min = minnimum(ar,n);
	int max = maximum(ar,n);
	int size = (max-min)+1;
	int *temp=new int[size];
	for(int i=0;i<size;i++)
	{
		temp[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		temp[ar[i]-min]++;
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
		ar1[temp[ar[i]-min]++]=ar[i];
	}
	for(int i=0;i<n;i++)
	{
		ar[i]=ar1[i];
	}
	return;

}

int main()
{
	int n;
	int *ar;
	cout<<"------------------------COUNT SORT------------------------\n";
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
	count_sort(ar,n);
	cout<<"Array after sorting: ";
	display(ar,n);
	
	
}
