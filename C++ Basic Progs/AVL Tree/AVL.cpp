//Menu is not made.
//KaalaSenapati
#include<iostream>
using namespace std;


class avl
{
	public:

	avl *left,*right;
	string key,meaning;
	int height;
	avl* root;

	avl()
	{
		root=NULL;
	}

	int ht(avl *root)
	{
		if(root==NULL)
			return 0;
		return root->height;
	}


	avl* rrotate(avl* root)
	{
		avl* temp1=root->left;
		avl* temp2=temp1->right;
		temp1->right=root;
		root->left=temp2;

		root->height=max(ht(root->left),ht(root->right)+1);
		temp1->height=max(ht(temp1->left),ht(temp1->right)+1);
		return temp1;
	}

	avl* lrotate(avl* root)
	{
		avl* temp1=root->right;
		avl* temp2=temp1->left;
		temp1->left=root;
		root->right=temp2;

		root->height=max(ht(root->left),ht(root->right)+1);
		temp1->height=max(ht(temp1->left),ht(temp1->right)+1);
		return temp1;
	}

	void search(avl *root)
    {
    	string key;
    	avl *p=root;
    	int i=1,flag=0;
    	cout<<"\nEnter word to search : ";
    	cin>>key;
    	while(p!=NULL)
    	{
    		if(key==p->key)
    		{
    			cout<<"\nWord found. Comparisions required : "<<i<<endl;
    			flag=1;
    			break;
			}
			else if(key < p->key)
				p=p->left;
			else
				p=p->right;
			i++;
		}
		if(flag==0)
			cout<<"\nWord not found.\n";

	}

	int balfac(avl* root)
	{
		if(root==NULL)
			return 0;
		return (ht(root->left)-ht(root->right));
	}

	void predisplay(avl* root)
	{
		if(root!=NULL)
		{
			cout<<root->key<<"\t"<<root->meaning<<endl;
			predisplay(root->left);
			predisplay(root->right);
		}
	}

	void indisplay(avl* root)
	{
		if(root!=NULL)
		{
			indisplay(root->left);
			cout<<root->key<<"\t"<<root->meaning<<endl;
			indisplay(root->right);
		}
	}

	void postdisplay(avl* root)
	{
		if(root!=NULL)
		{
			postdisplay(root->left);
			postdisplay(root->right);
			cout<<root->key<<"\t"<<root->meaning<<endl;
		}
	}

	int max(int a,int b)
	{
		return (a>b)? a:b;
	}

	avl* insert(avl *root, string key, string mean)
	{
		if(root==NULL)
		{
			//cout<<"\nIN NEW";
			root=new avl;
			root->key=key;
			root->meaning=mean;
			root->right=NULL;
			root->left=NULL;
			root->height=1;
			//cout<<"\nEXIT NEW";
			return root;
		}

		else if(key<root->key)
			root->left=insert(root->left,key,mean);

		else if(key>root->key)
			root->right=insert(root->right,key,mean);

		else
			return root;

		root->height=1+max(ht(root->left),ht(root->right));
		int bal=balfac(root);

		//LLR
		if(bal>1 && key < root->left->key)
			return rrotate(root);

		//LRR
		if(bal>1 && key > root->left->key)
		{
			root->left=lrotate(root->left);
			return rrotate(root);
		}

		//RRR
		if(bal<-1 && key > root->right->key)
			return lrotate(root);

		//RLR
		if(bal<-1 && key < root->right->key)
		{
			root->right=rrotate(root);
			return lrotate(root);
		}

		return root;
	}

	avl* deletion(avl* root,string key)
	{
		avl *temp,*p;
		if(root==NULL)
		{
			cout<<"\nWord not found in database.\n";
			return root;
		}
		else if(key < root->key)
		{
			root->left=deletion(root->left, key);
		}
		else if(key > root->key)
		{
			root->right=deletion(root->right, key);
		}
		else
		{

			if((root->left==NULL)||(root->right==NULL))
			{
				avl *temp=root->left? root->left : root->right;

				if(temp==NULL)
				{
					temp=root;
					root=NULL;
				}
				else
					*root=*temp;
				delete(temp);
			}
			else
			{
				avl *temp=minval(root->right);
				root->key=temp->key;
				root->right=deletion(root->right,temp->key);
			}
		}

		if(root==NULL)
			return root;


		root->height=1+max(ht(root->left),ht(root->right));
		int bal=balfac(root);

		//LLR
		if(bal>1 && balfac(root->left) >= 0)
			return rrotate(root);

		//LRR
		if(bal>1 && balfac(root->left) < 0)
		{
			root->left=lrotate(root->left);
			return rrotate(root);
		}

		//RRR
		if(bal<-1 && balfac(root->right) <= 0)
			return lrotate(root);

		//RLR
		if(bal<-1 && balfac(root->right) >= 0)
		{
			root->right=rrotate(root);
			return lrotate(root);
		}
		return root;
	}

	avl* minval(avl* root)
	{
		avl* curr=root;
		while(curr->left!=NULL)
			curr=curr->left;
		return curr;
	}

};

int main()
{
	avl k;
	string key,mean;
	char ch;
	up:
	cout<<"\nEnter word : ";
	cin>>key;
	cout<<"\nEnter meaning :";
	cin>>mean;
	k.root=k.insert(k.root,key,mean);
	cout<<"\nElement Inserted.\nDo you want to insert another element? (Y/N)";
	cin>>ch;
	if(ch=='y'||ch=='Y'||ch=='1')
		goto up;
	cout<<"\nPREORDER\n";
	k.predisplay(k.root);
	cout<<"\nINORDER\n";
	k.indisplay(k.root);
	cout<<"\nPOSTORDER\n";
	k.postdisplay(k.root);

	k.search(k.root);

	cout<<"\nPREORDER\n";
	k.predisplay(k.root);
	cout<<"\nINORDER\n";
	k.indisplay(k.root);
	cout<<"\nPOSTORDER\n";
	k.postdisplay(k.root);

	cout<<"\nEnter element to delete : ";
	cin>>key;
	k.root=k.deletion(k.root,key);

	cout<<"\nPREORDER\n";
	k.predisplay(k.root);
	cout<<"\nINORDER\n";
	k.indisplay(k.root);
	cout<<"\nPOSTORDER\n";
	k.postdisplay(k.root);
	return 0;
}





//END
