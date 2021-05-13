#include <bits/stdc++.h>
using namespace std;
 
int max(int a, int b)
{
    return (a > b) ? a : b;
}

void find_path(int ar[][100],int x,int y,int wt[],int val[])
{
	if(x==0||y==0)
	{
		return;
	}
	else if(ar[x-1][y]==ar[x][y])
	{
		find_path(ar,x-1,y,wt,val);
	}
	else
	{
		find_path(ar,x-1,y-wt[x-1],wt,val);
		cout<<wt[x-1]<<"\t"<<val[x-1]<<endl;
	}
}
 
int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n + 1][100];
 
    for(i = 0; i <= n; i++)
    {
        for(w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] +
                                K[i - 1][w - wt[i - 1]],
                                K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
//    for(i = 0; i <= n; i++)
//    {
//        for(w = 0; w <= W; w++)
//        {
//        	cout<<K[i][w]<<"  ";
//        }
//        cout<<endl;
//    }
    cout<<"\nWeights and values that are included in optimal solution:-\n\nWeight\tValue\n-------\t------\n";
    find_path(K,n,W,wt,val);
    return K[n][W];
}
 
int main()
{
	cout<<"------------------- KNAPSACK -------------------"<<endl;
	cout<<"\nEnter the numbers of inputs: ";
	int n,W;
	cin>>n;
	int *val = new int[n];
	int *wt = new int[n];
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the weight and value of "<<i+1<<" : ";
		cin>>wt[i]>>val[i];
		
	} 
	cout<<"\nEnter the maximum weight to be taken: ";
	cin>>W;
     
    cout<<"\nThe maximum value for given weights will be: "<< knapSack(W, wt, val, n);
     
    return 0;
}
