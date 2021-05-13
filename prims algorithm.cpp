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
			cout<<"\t"<<current->x <<" --> ";
		}
		cout<<current->x<<endl;
	}
	return;
}
class graph
{
	int vertex;
	sll* S;
	int *parent;
	int *key;
	public:
		graph(int ver)
		{
			vertex=ver;
			S=new sll[vertex];	
		}
		void input();
		void graphdisplay();
		void mst_prims();
		void display_prims();	
};
class priorityqueue
{
	int heapsize;	
	int **array;
	public:	
		priorityqueue(int ver) //storing vertex and there respective weights in v*2 matrix
		{
			heapsize=0;
			array=new int*[ver];
			for(int i=0;i<ver;i++)
			{
				array[i]=new int[2]; 
			}
		}
		void insert(int value, int key);
		void min_heapify(int id);	
		int min_heap();			
		bool isempty();
		int index(int ver);
		void decreaseKey(int z, int key);    // here z is for vetex
		friend class graph;
};
void swapping(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
int priorityqueue:: index(int ver){
	for(int i =0; i<heapsize;i++)
	{
		if(array[i][0] == ver)
			return i;
	}
	return -1;
}

bool priorityqueue :: isempty()
{
	while (heapsize == 0){
		return true;
	}
	return false;
}
void priorityqueue::min_heapify(int id)
{
	int left = (2*id);
	int right = (2*id)+1;
	int smallest;
	if((left <= heapsize) && (array[left][left]) < array[id][left])
	{
		smallest = left;
	}
	else
	{
		smallest = id;
	}
	if((right <= heapsize) && (array[right][left]) < array[smallest][left])
	{
		smallest = right;
	}
	if(smallest !=id)
	{
		swapping(array[smallest] , array[id]);
		min_heapify(smallest);
	}	
}
int priorityqueue::min_heap()
{
	if(heapsize==0)
	{
		cout<<"\nHEAP UNDERFLOW";
		return 0;
	}
	int min = array[0][0];
	array[0]= array[heapsize-1];
	heapsize --;
	min_heapify(0);
	return min;
}
void priorityqueue::decreaseKey(int v, int key)
{	
	int a ;
	array[v][1] = key;
	if(v%2==0){
		a=v/2-1;
	}
	else{
		a=v/2;
	}
	while(v>0 && (array[a][1] > array[v][1]))
	{
		swapping(array[a],array[v]);
		v = a;
		if(v%2 == 0){
			a=v/2-1;
		}
		else{
			a=v/2;
		}
	}
}
void priorityqueue:: insert(int value, int key)
{
	array[heapsize][0] = value;
	array[heapsize][1] = key;
	
	heapsize++;
	int i= heapsize-1;

	decreaseKey(heapsize-1,key);
}
void graph::display_prims()
{
	cout<<"\n\nMINIMUM SPANNING TREE ::";
	cout<<"\n------------------------\n\tEdge\t\tWeight ";
	for(int i=1;i<vertex;i++)
	cout<<"\n"<<parent[i]+1<<" to " <<i+1<< "\t\t"<< key[i];
	
	int wt=0;
	for(int i =1; i <vertex; i++)
	{
		wt +=key[i];
	}
	cout<<"\n\nTotal cost for MST using PRIM's Alogirthm :: "<< wt;
}

void graph :: input()
{
	int a,wt;
	for(int i = 0;i < vertex;i++)
	{
		cout<<"\nEnter the no. of edges connected with the vertex "<<i+1<<" ::\t";
		cin>>a;
		int z;
		for(int j =0;j<a;j++)
		{
			cout<<"\nEnter the adjacent vertice and weight of vertex "<<i+1<<" ::\t";	
			cin>>z>>wt;
		
			S[i].insertathead(z,wt);
		}	
		S[i].insertathead(i+1);
	}	
}
void graph::graphdisplay()
{
	cout<<"\n\n----------------- ADJACENT LIST --------------------";
	for(int i =0; i < vertex;i++)
	{
		cout<<endl;
		S[i].display_sll();
	}
}
void graph::mst_prims()
{
	priorityqueue pq(vertex);
	parent =  new int[vertex];
	key=new int[vertex];
	for(int i =0; i<vertex;i++)
	{
		key[i] = INT_MAX;
		parent[i]=0;
	}
	key[0]=0;
	for(int i =0;i<vertex;i++)
		pq.insert(i,key[i]);
		
	while(!pq.isempty())
	{
		int b = pq.min_heap();
		node*current=S[b].head;
		while(current!=0)
		{
			int c=(current->x-1);
			if(pq.index(c) >= 0 &&(current->weight < key[c]))
			{
				int y=pq.index(c);
				parent[c] = b;
				key[c]=current->weight;
				pq.decreaseKey(y,key[c]);
			}
			current=current->next;
		}
	}
	graphdisplay();
}
int main()
{	
	int vertex;
	cout<<"\n----------------------- PRIMS'S ALGORITHM ------------------------------------------\n";
	cout<<"\nENTER THE NUMBER OF VERTICES ::\t";
	cin>>vertex;
	cout<<"\nTHE VERTICES ARE ::\t";
	for(int i=0; i<vertex; i++)
	{
		cout<<i+1<<" ";
	}
	graph obj(vertex);
	
	obj.input();
	obj.mst_prims();
	obj.display_prims();
}
