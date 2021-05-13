#include<iostream>
using namespace std;

void inputarray(int ar[],int n)
{
	for(int i=0;i<n;i++)
	{
		cin>>ar[i];
	}
}

void merging(int ar[],int l,int m,int r)
{
	int n1 = m - l + 1;
    int n2 = r - m;
 
    int L[n1], R[n2];
 
    for (int i = 0; i < n1; i++)
        L[i] = ar[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = ar[m + 1 + j];
 
    int i = 0;
    int j = 0;
    int k = l;
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            ar[k] = L[i];
            i++;
        }
        else {
            ar[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        ar[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        ar[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int ar[],int l,int r)
{
	if(l<r)
	{
		int mid = l+(r-l)/2;
		mergesort(ar,l,mid);
		mergesort(ar,mid+1,r);	
		merging(ar,l,mid,r);
	}
	return;
}

void printarray(int ar[],int n)
{
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<ar[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	int n;
	int *ar;
	cout<<"Enter the size of the array: ";
	cin>>n;
	ar = new int[n];
	cout<<"Enter the data of the array: ";
	inputarray(ar,n);
	cout<<"The entered array is: ";
	printarray(ar,n);
	mergesort(ar,0,n-1);
	cout<<"The Sorted array is: ";
	printarray(ar,n);
	
}
