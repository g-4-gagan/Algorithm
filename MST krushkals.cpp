#include<iostream>
using namespace std;
class node
{
	int x;
	int weight;
	node* next;
	public:
		node(int value=0, int w =0, node* ptr=0)
		{	
			x=value;
			weight = w;
			next=ptr;		
		}
		node(int value,node* ptr =0)
		{
			x=value;
			next=ptr;
		}
		friend class graph;
		friend class sll;
};
class sll
{	
	node *head;
	public:
		sll(node* ptr=0)					
		{
			head=ptr;
		}
		~sll();
		void insertathead(int x);
		void insertathead(int x, int wt);
		void display_sll();	
		
		friend class graph;
		friend class union_find;
};
sll::~sll()
{
	node *current;
	while(head)
	{
		current=head->next;
		delete head;
		head=current;
	}
}
void sll::insertathead(int x, int wt)
{
	head=new node(x,wt,head);
}
void sll::insertathead(int x)
{
	head=new node(x,head);
}
void sll::display_sll()
{
	if(head)
	{	node*current=head;
		for(current=head;current->next;current=current->next)
		{
			cout<<current->x <<" --> ";
		}
		cout<<current->x<<endl;
	}
	return;
}
class graph
{
	int vertex;
	sll* S;
	int edge;
	public:
		graph(int ver)
		{
			vertex=ver;
			S=new sll[vertex];
			edge = 0;	
		}
		graph(int ver, int e)
		{
			vertex=ver;
			S=new sll[vertex];
			edge = e;
		}
		void input();
		void graphdisplay();
		void mst_kruskal();
		
		friend class union_find;	
};

class union_find
{
	int*array;
	int* size;
	int n;
	public :
		union_find(int ver)
		{
			array=new int[n];
			size=new int[n];
			n=ver;
		
		}
		void makeset();
		int findset(int i);
		void Union(int u,int v);
		
		friend class sll;
		friend class graph;
};
void sort( int array[][3], int size)
{
	for (int i =0;i<size-1;i++)
	{
		for(int j=i+1;j<size;j++)
		{
			if(array[i][2] > array[j][2])
			{
				swap(array[i][0] ,array[j][0]);
				swap(array[i][1] ,array[j][1]);
				swap(array[i][2] ,array[j][2]);
			}
		}
	}
}

void graph :: input()
{
	int a,b,wt;
	for(int i = 0;i < edge;i++)
	{
		cout<<"Enter both vertices having edge "<<i+1<<" in between followed by weight: ";
		cin>>a>>b>>wt;
		if(a<=vertex&&b<=vertex)
		{
		  S[a-1].insertathead(b,wt);
		  S[b-1].insertathead(a,wt);
    	}
    	else{
    		cout<<"Input node not exist.\n";
    		i--;
		}
	}
	for(int i=0;i<vertex;i++)
	{
		S[i].insertathead(i+1);
	}	
}
void graph::graphdisplay()
{
	cout<<"\n\n----------------- ADJACENT LIST OF GRAPH--------------------";
	for(int i =0; i < vertex;i++)
	{
		cout<<endl;
		S[i].display_sll();
	}
}

void union_find :: makeset()
{
	for(int i=0;i<n;i++)
	{
		array[i]=i+1;
		size[i]=1;
	}
}

int union_find::findset(int i)
{
	return array[i-1];
}

void union_find::Union(int u, int v)
{
	int a,b;
	int array1=array[u-1],array2=array[v-1];
	if(size[u-1] >= size[v-1])
	{
		a=u-1;
		b=v-1;
	}
	else
	{
		a=v-1; 									
		b=u-1;
	}
	int c=array[b];
	array[b] = array[a];
	for(int i=0; i<n;i++)
	{
		if(array[i] == c)
		{
			array[i] =array[a];
		}
		if(array[i] == array1 || array[i]==array2)
		{
			size[i] = size[a]+size[b];
		}
	}
}

void graph::mst_kruskal()
{
	int n=edge;
	int A[vertex-1][3], V[n][3];
	int u,v,a,b,i=0;
	
	for(int j=0;j<vertex;j++)
	{
		node* current;
		for(current=S[j].head;current!=0;current=current->next)
		{
			if(current->x > j+1)
			{
				V[i+j][0] = j+1;
				V[i+j][1] = current->x;
				V[i+j][2] = current->weight;
				i++;
			}
		}
		i--;
	}
	sort(V,n);
	cout<<"\n\nEDGES SORTED ACCORDING TO THE COST ::\n-------------------------------------------\nSOURCE\tDEST.\tWEIGHT \n";
	for(int i=0;i<edge;i++)
	{
		for(int j=0;j<3;j++)
			cout<<V[i][j]<<" \t";
		cout<<"\n";
	}
	
	union_find Q(vertex);
	Q.makeset();
	int k =0;
	for(int i=0;i<edge;i++)
	{
		a=V[i][0];
		b=V[i][1];
			if(Q.findset(a) != Q.findset(b))
			{
				A[k][0]=V[i][0];
				A[k][1]=V[i][1];
				A[k][2]=V[i][2];
				Q.Union(a,b);
				k++;
			}
	}
	int cost = 0;
	cout<<"\n\nKRUSKAL MST :: \n-------------------------\nEDGE \t\t COST \n-----\t\t ------ \n\t";
	for(int i=0;i<vertex-1;i++)
	{
		cost+=A[i][2];
		cout<<"\n";
		for(int j=0;j<3;j++)
		{
			if(j ==0)
			cout<<"(" << A[i][0]<< ",";
			else if(j ==1)
			cout<<A[i][1] << ") ---> \t\t";
			else
			cout<<A[i][2];
		}
	}
	cout<<"\n\nTOTAL COST :: "<<cost;	
}

int main()
{
	cout<<"\n----------------------- KRUSKAL'S ALGORITHM -------------------------------------------\n";
	int vertex,edge;
	int *array;
	cout<<"\nENTER THE NO. OF VERTICES :: \t";
	cin>>vertex;
	cout<<"\nENTER THE NO. OF EDGES :: \t";
	cin>>edge;
	
	array=new int[vertex];
	graph obj(vertex,edge);
	obj.input();
	obj.graphdisplay();
	obj.mst_kruskal();
}
