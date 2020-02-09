//This Expression does not support bracket rules.
#include<iostream>
#include<string>
#include<stack>
using namespace std;

class node
{
	public:
	node *left,*right;
	char value;
	node *root;
	
	string newexp;
	int priority(char c)
	{
		if(c=='/')
			return 3;
		if(c=='*')
			return 2;
		if(c=='+')
			return 1;
		if(c=='-')
			return 1;
		return -1;
	}
	
	node* constructTree(string exp) 
	{ 
		stack <node*> s; 
		node *t, *t1, *t2, *t3;
		int lp=0;
	  	cout<<"\n\n";
		for (int i=0; i<exp.length(); i++) 
		{
			int p=priority(exp[i]);
			
		    if (p<0) 
		    { 
		        t = newNode(exp[i]); 
		        s.push(t);
		        //cout<<"\nPush alpha : "<<exp[i]<<endl;
		    } 
		    else 
		    { 
		        t = newNode(exp[i]);
		        if(p>lp)
		        {
		        	lp=p;
		        	s.push(t);
		        	//cout<<"\nPush high pri : "<<exp[i]<<"\tnew pri : "<<lp<<endl;
	        	}
	        	else
	        	{
	        		lp=p;
	        		while(1)
	        		{
			    		t1 = s.top(); 
				    	s.pop(); 
				    	t2 = s.top(); 
				    	s.pop();
				    	t3 = s.top(); 
				    	s.pop(); 
				    	t2->right = t1; 
				    	t2->left = t3;
				    	//cout<<"\nIn while loop : \n";
				    	//display(t2);
				    	//cout<<"\n";
				    	if(s.empty()==1)
				    		break;
				    	s.push(t2);
	        		}
	        		s.push(t2);
	        		//cout<<"Push low pri : "<<exp[i]<<"\tnew pri : "<<lp<<endl;
		        	s.push(t);
	        	}
		   }
		}
		while(1)
		{
			t1 = s.top(); 
			s.pop(); 
			t2 = s.top(); 
			s.pop();
			t3 = s.top(); 
			s.pop(); 
			t2->right = t1; 
			t2->left = t3;
			//cout<<"\nIn while loop : \n";
			//display(t2);
			//cout<<"\n";
			if(s.empty()==1)
				break;
			s.push(t2);
		}
		return t2; 
	}
	node* newNode(char v) 
	{ 
		node *temp = new node; 
		temp->left = temp->right = NULL; 
		temp->value = v; 
		return temp; 
	}
	
	void displaypost(node *root)
	{
		if(root==NULL)
			return;
		display(root->left);
		display(root->right);
		cout<<root->value;
	}
	
	void display(node* root) 
	{ 
		if (root == NULL) 
		    return; 
	  
		stack <node*> s1;
		stack <node*> s2;
	   
		s1.push(root); 
		node* temp; 
	  
		while (!s1.empty()) 
		{
		
		    temp = s1.top();
		    s1.pop(); 
		    s2.push(temp); 
	  
		    if (temp->left) 
		        s1.push(temp->left); 
		    if (temp->right) 
		        s1.push(temp->right); 
		} 
	  
		while (!s2.empty()) 
		{ 
		    temp = s2.top();
		    s2.pop(); 
		    cout<<temp->value; 
		} 
	} 
};


int main()
{
	node n;
	string exp;
	cout<<"\nEnter expression to evaluate : ";
	cin>>exp;
	//exp="a-b*c-d/e+f";
	n.root = n.constructTree(exp);
	//cout<<"\n\n\n";
	n.display(n.root);
	return 0;
}
