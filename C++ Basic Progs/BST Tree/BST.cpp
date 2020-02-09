//BST Tree - Working Model Final
/KaalaSenapati

#include<iostream>
#include<string.h>

using namespace std;

class node
{
	public:
	string word,w;
	string meaning,m;
	node *left, *right;
	node *root, *mroot;

	node()
	{
		root=NULL;
	}

	node* insert(node *root1)
	{

		if(root1==NULL)
		{
			root1=new node;
			root1->word=w;
			root1->meaning=m;
			root1->left=NULL;
			root1->right=NULL;
			cout<<"\nWord Entered Successfully.\n";
			return root1;
		}

		else if(w < root1->word)
		{
			root1->left=insert(root1->left);
			return root1;
		}

		else if(w > root1->word)
		{
			root1->right=insert(root1->right);
			return root1;
		}

		else
			cout<<"\nDuplicate Word Entered.\n";
	}

	void create()
	{
		char ch;
		int a=1;
		jmp:
		cout<<"\n\n"<<a<<". \n";
		cout<<"\nEnter Word : ";
		cin>>w;
		cout<<"\nEnter Meaning : ";
		cin>>m;
		root=insert(root);
		cout<<"\nDo you want to add another node ?\n";
		cin>>ch;
		a++;
		if(ch=='y'||ch=='Y')
			goto jmp;
	}

	void display(node* root1)
	{
    	if (root1!=NULL)
    	{
        	display(root1->left);
        	cout<<"\n"<<root1->word<<" :: "<<root1->meaning<<endl;
        	display(root1->right);
    	}
    }

    void search()
    {
    	string key;
    	node *p=root;
    	int i=1,flag=0;
    	cout<<"\nEnter word to search : ";
    	cin>>key;
    	while(p!=NULL)
    	{
    		if(key==p->word)
    		{
    			cout<<"\nWord found. Comparisions required : "<<i<<endl;
    			flag=1;
    			break;
			}
			else if(key < p->word)
				p=p->left;
			else
				p=p->right;
			i++;
		}
		if(flag==0)
			cout<<"\nWord not found.\n";

	}

	node* deletion(node* root1,string key)
	{
		node *temp,*p;
		if(root1==NULL)
		{
			cout<<"\nWord not found in database.\n";
			return root1;
		}
		else if(key < root1->word)
		{
			root1->left=deletion(root1->left, key);
			return root1;
		}
		else if(key > root1->word)
		{
			root1->right=deletion(root1->right, key);
			return root1;
		}

			if(root1->left==NULL && root1->right==NULL)
			{
				temp=root1;
				delete temp;
				cout<<"\nWord deleted successfully.\n";
				return root1;
			}
			else if(root1->left==NULL)
			{
				temp=root1;
				root1=root1->right;
				delete temp;
				cout<<"\nWord deleted successfully.\n";
				return root1;
			}
			else if(root1->right==NULL)
			{
				temp=root1;
				root1=root1->left;
				delete temp;
				cout<<"\nWord deleted successfully.\n";
				return root1;
			}
			else
			{
				temp=root1;
				p=root1->right;
				while(p->left!=NULL)
					p=p->left;
				p->left=root1->left;
				root1=root1->right;
				delete temp;
				cout<<"\nWord deleted successfully.\n";
				return root1;
			}
	}

	node* mirror(node *root1)
	{
		node *p;
		if(root1==NULL)
    	    return NULL;
    	p=new node;
	    p->word=root1->word;
    	p->meaning=root1->meaning;
	    p->left=mirror(root1->right);
	    p->right=mirror(root1->left);
	    return p;
    }

    int height(node *root1)
	{
		int hl,hr;
		if(root1==NULL)
		    return 0;
		if(root1->left==NULL && root1->right==NULL)
		    return 1;
		hl=height(root1->left);
		hr=height(root1->right);
		if(hl>hr)
		    return (hl+1);
		return (hr+1);
	}
};

int main()
{
	node n;
	int c;
	string key;
	do
	{
		cout<<"\n*****Binary Search Tree*****\n";
		cout<<"\n1. Create\n2. Insert\n3. Display\n4. Search\n5. Delete\n6. Mirror\n7. Height of tree\n8. Exit\nEnter your choice : ";
		cin>>c;
		switch (c)
		{
			case 1 : n.create();
					 break;

			case 2 : cout<<"\nEnter Word : ";
					 cin>>n.w;
					 cout<<"\nEnter Meaning : ";
					 cin>>n.m;
					 n.root=n.insert(n.root);
					 break;

			case 3 : n.display(n.root);
					 break;

			case 4 : n.search();
					 break;

			case 5 : cout<<"\nEnter word to delete : ";
					 cin>>key;
					 n.root=n.deletion(n.root,key);
					 n.display(n.root);
					 break;

			case 6 : n.mroot=n.mirror(n.root);
					 n.display(n.mroot);
					 break;

			case 7 : cout<<"\nHeight of tree : "<<n.height(n.root);
					 break;

			case 8 : break;

			default : cout<<"\nInvalid choice. Please try again.\n";
					 break;
		}
	}while(c!=8);
		return 0;
}
