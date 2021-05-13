#include<iostream>
using namespace std;

void sort(int **ar,int n)
{
	for (int i =1;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(ar[i][1] > ar[j][1])
			{
				swap(ar[i][0] ,ar[j][0]);
				swap(ar[i][1] ,ar[j][1]);
				swap(ar[i][2] ,ar[j][2]);
			}
		}
	}
	
}

int maximum(int a,int b)
{
	if(a>b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

class weightedschedule
{
	int **ar;
	int size;
	int *m;
	
	public:
		weightedschedule(int n)
		{ 
			size = n+1;
			m = new int[n+1];
			ar = new int*[size];
			for(int i=0;i<size;i++)
			{
				ar[i] = new int[4];
			}
		}
		void input();
		void find_solution(int x);
		void calcopt();
		void display();
};

void weightedschedule::input()
{
	int a,b,c;
	cout<<endl;
	ar[0][0]=0;
	ar[0][1]=0;
	ar[0][2]=0;
	for(int i=1;i<size;i++)
	{
		cout<<"Enter the Start time, End time and Weight of Schedule "<<i<<" : ";
		cin>>a>>b>>c;
		ar[i][0]=a;
		ar[i][1]=b;
		ar[i][2]=c;
	}
}

void weightedschedule::find_solution(int x)
{
	if(x!=0)
	{
		if((ar[x][2]+m[ar[x][3]])>m[x-1])
		{
			find_solution(ar[x][3]);
			cout<<"Schedule "<<x<<" :\t\t"<<ar[x][0]<<"\t "<<ar[x][1]<<"\t\t"<<ar[x][2]<<endl;
		}
		else
		{
			find_solution(x-1);
		}
	}
}

void weightedschedule::calcopt()
{
	sort(ar,size);
	cout<<"\nSchedules after sorting on the basis of finish time: \n";
	display();
	ar[0][3]=0;
	for(int i=1;i<size;i++)
	{
		for(int j=i-1;j>=0;j--)
		{
			if(ar[j][1]<=ar[i][0])
			{
				ar[i][3]=j;
				break;
			}
		}
	}
	cout<<"\nValue of parent of each schedule: \n";
	for(int i=1;i<size;i++)
	{
		cout<<"p("<<i<<") : "<<ar[i][3]<<endl;
	}
	m[0]=0;
	for(int i=1;i<size;i++)
	{
		m[i]= maximum((ar[i][2]+m[ar[i][3]]),m[i-1]);		
	}
	cout<<"\nOptimal value at each schedule: \n";	
	for(int i=1;i<size;i++)
	{
		cout<<"m("<<i<<") : "<<m[i]<<endl;
	}
	cout<<"\nSolution for weighted scheduling algorithm: \n";
	cout<<"\t\t Start Time\tEnd Time\tWeight\n";
	find_solution(size-1);
	cout<<"\nOptimal Solution of the problem is: "<<m[size-1];
}

void weightedschedule::display()
{
	cout<<endl;
	cout<<"\t\t Start Time\tEnd Time\tWeight\n";
	for(int i=1;i<size;i++)
	{
		cout<<"Schedule "<<i<<" :\t\t"<<ar[i][0]<<"\t "<<ar[i][1]<<"\t\t"<<ar[i][2]<<endl;		
	}
}

int main()
{
	cout<<"-------------------- WEIGHTED INTERVAL SCHEDULING --------------------";
	cout<<endl<<"Enter the number of schedules: ";
	int n;
	cin>>n;
	weightedschedule *w = new weightedschedule(n);
	w->input();
	w->display();
	w->calcopt();
	cout<<"\n\nProgram Successfully Executed!!";
}
