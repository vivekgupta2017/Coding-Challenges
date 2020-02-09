//Integer TBT, change variables if needed to string.
//KaalaSenapati
#include<iostream>
using namespace std;

class node
{
	public:
	node *left,*right;
	int data;
	bool l,r;
};

class TBT
{
	public:
	node *root;

	TBT()
	{
		root = new node;
		root->right=root;
		root->left=root;
		root->l=1;
		root->data=9999;
	}

	void insert(int key)
	{
		node *p=root;
		for(;;)
		{
			if(p->data < key)
			{
				if(p->r)
					break;
				p=p->right;
			}

			else if(p->data > key)
			{
				if(p->l)
					break;
				p=p->left;
			}
		}

		node *temp = new node;
		temp->data=key;
		temp->r=temp->l=1;
		if(p->data < key)
		{
			temp->right=p->right;
			temp->left=p;
			p->right=temp;
			p->r=0;
		}
		else
		{
			temp->right=p;
			temp->left=p->left;
			p->left=temp;
			p->l=0;
		}
	}

	void display()
	{
		node *temp=root, *p;
		for(;;)
		{
			p=temp;
			temp=temp->right;
			if(!p->r)
				while(!temp->l)
					temp=temp->left;
			if(temp==root)
				break;
			cout<<temp->data<<" ";
		}
		cout<<endl;
	}
};

int main()
{
	TBT n;
	int key;
	char ch;
	upar:
	cout<<"\nEnter data : ";
	cin>>key;
	n.insert(key);
	cout<<"\nAdd another ? ";
	cin>>ch;
	if(ch=='y'||ch=='Y'||ch=='1')
		goto upar;
	cout<<"\nDisplay Tree : \n";
	n.display();
	return 0;
}



//end prog

