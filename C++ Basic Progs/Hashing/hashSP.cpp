/*
	Consider telephone book database of N clients. Make use of a hashing table implementation to quickly lookup
	client's phone number.
*/


#include<iostream>
using namespace std;
#define KEY(x) x%10

struct node
	{
	string name,phnum;
	int key;
	node *next;
	}*hashing[10];


class Database
	{
	public:
	int sum(string name)
		{
		int sum =0;
		for(int i=0;name[i]!=NULL;i++)
		    sum = sum + name[i];
		return sum;
		}

	node* create()
	{
	node *temp = new (struct node);
	cout<<"Enter Name: \t";
	cin.ignore();
	getline(cin,temp->name);

	cout<<"Enter Phone Number: \t";
	getline(cin,temp->phnum);
	temp->next=NULL;
	int z=sum(temp->name);
	temp->key = KEY(z);
	return temp;
	}

	void position(node *p,int key)
	{
	if(!hashing[key])
            hashing[key] = p;
		else
		{
		node *q;
		q=hashing[key];
		while(q->next!=NULL)
		q=q->next;
		q->next = p;
		}
	}

void add()
	{
	node *p;
	p = create();
	position(p,p->key);
		while(p!=NULL)
		{
		cout<<p->name<<":"<<p->phnum<<" "<<"\n";
		p=p->next;
		}
	}


node* search(int key,string name)
	{
	node *p;
	p=hashing[key];
	while((p!=NULL)&&(name!=p->name))
	    p=p->next;
	return p;
	}
};

	int main()
	{
	Database obj;
	node n1;
	string a;
	int key;
	int ch;
	char choice,x;
	do
	{
	cout<<"\n======  M A I N  M E N U ========"<<endl;
	cout<<"\n1. Add Entry in hashing Table"<<endl;
	cout<<"\n2. Search a number"<<endl;
	cout<<"========================================"<<endl;
	cout<<"\nEnter your Choice : \t";
	cin>>ch;
	switch(ch)
	{
	case 1:
	{
	do
	{
	 obj.add();
	 cout<<"Do you want to Add more Entries?(y/n): \t";
	 cin>>x;
	}while(x=='y' || x=='Y');
	 break;
	}
	case 2:
	{
	 cout<<"Enter the name of the person :\t ";
	 cin.ignore();
	 getline(cin,a);
	 int z=obj.sum(a);
	 key = KEY(z);
	 node *p;
	 p=obj.search(key,a);
	 if(!p)
		cout<<"No such Entry in DataBase"<<endl;
	else
	{
        	cout<<"Name : "<<p->name<<endl;
	        cout<<"Phone Number : "<<p->phnum<<endl;
	}
	break;
	}
	default: cout<<"Invalid Entry"<<endl;
             break;
	}
	cout<<"Do you want to continue?(y/n):\t ";
	cin>>choice;
	}while(choice=='y' || choice=='Y');
	return 0;
}
