//Directed Graph. For undirected, set both directions

#include<iostream>
using namespace std;

class bhoot
{
	public:
	int n;
	char ch;
	bhoot* v[20];
	bhoot* e[20];
	bool data[20];
	int arr[20][20];

	/*	bhoot()
	{
		for(int i=0;i<20;i++)
		{
			v[i]=new bhoot;
			v[i]=NULL;
			data[i]=0;
		}
	}
	*/

	void getdata()
	{
		cout<<"\nEnter number of vertices :";
		cin>>n;
	}

	void calc()
	{
		char a='A',b;
		for(int i=0;i<n;i++)
		{
			b='A';
			v[i]=new bhoot;
			for(int j=0;j<n;j++)
			{
			cout<<"\nDoes vertice "<<a<<" have an edge to "<<b<<" ? ";
			cin>>ch;
			if(ch=='y'||ch=='Y'||ch=='1')
				{
					v[i]->data[j]=true;
					arr[i][j]=1;
					//v[j]->data[i]=true; //undirected.
					v[i]->e[j]=v[j];
					cout<<"Edge entered successfully.\n";
				}
			else
				{
					v[i]->data[j]=false;
					arr[i][j]=0;
					//v[j]->data[i]=true; //undirected.
					v[i]->e[j]=NULL;
				}
				b++;
			}
			a++;
		}
	}

	void displaymat()
	{
		cout<<"\nAdjacency Matrix : \n\n\t";
		int k;
		char ch='A';
		for(k=0;k<n;k++)
		{
			cout<<ch;
			cout<<"\t";
			ch++;
		}
		cout<<endl;
		ch='A';
		for(int i=0;i<n;i++)
		{
			cout<<ch;
			for(int j=0;j<n;j++)
				cout<<"\t"<<arr[i][j];
			cout<<endl;
			ch++;
		}
	}

	void displaylist()
	{
		cout<<"\nAdjacency List : \n\n";

		char a='A',b;
		for(int i=0;i<n;i++)
		{
			b='A';
			cout<<a<<" : ";
			for(int j=0;j<n;j++)
			{
				if(v[i]->data[j] || v[i]->e[j]!=NULL)
					cout<<" "<<b<<" ,";
				b++;
			}
			cout<<"\b \b";
			cout<<endl;
			a++;
		}
	}

};

int main()
{
	bhoot b;
	b.getdata();
	b.calc();
	b.displaymat();
	b.displaylist();
	return 0;
}


