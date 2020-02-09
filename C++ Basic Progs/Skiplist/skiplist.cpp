//Skiplist LVL 100
//KaalaSenapati
#include<iostream>
using namespace std;

class node
{
	public:
	node *head;
	node *next,*skip;
	node *p,*temp;
	int val;
	int n;
	
	node()
	{
		head=NULL;
	}
	
	void create(int data)
	{
		p=new node;
        p->val=data;
        p->next=NULL;

        if(head==NULL)
        	head=p;
        else
        {
    		temp=head;
            while(temp->next!=NULL)
            	temp=temp->next;
            temp->next=p;
    	}
    	cout<<"\nValue inserted.\n";
	}
       
	void skipl()
	{
		cout<<"\nEnter the order of skiplist : ";
		cin>>n;
		int i=0;
		temp=head;
		for(p=head;p!=NULL;p=p->next)
		{
			if(i%n==0)
			{
				temp->skip=p;
				p->skip=NULL;
				temp=p;
			}
			i++;
		}
		cout<<"\nSkiplist of order "<<n<<" is generated.\n";
	}
	

	void display()
	{
		cout<<"\nNormal list : \n";
		
		p=head;
		cout<< p->val;
		p=p->next;
		for(;p!=NULL;p=p->next)
			cout<<" -> "<<p->val;
			
		cout<<endl;
		
		
		
		cout<<"\nSkiplist : \n";
		
		p=head;
		cout<< p->val;
		p=p->skip;
		for(;p!=NULL;p=p->skip)
			cout<<" -> "<<p->val;
			
		cout<<endl;
		
	}
	
	void search(int key)
	{
		int flag=0;
		temp=head;
		for(temp=head; temp->skip->val <= key;temp=temp->skip)
		{
			if(temp->skip==NULL)
				break;
		}

		for(p=temp ;p!=temp->skip ; p=p->next)
		{
			if(p->val==key)
			{
				flag=1;
				break;
			}
		}
		
		if(flag==1)
			cout<<"\nElement found.\n";
		else
			cout<<"\nElement not found.\n";
	}
};

int main()
{
	node s;
	
	int data;
	char ch;
	cout<<"\nCreating list : ";
	
	do
	{
		cout<<"Enter data : ";
		cin>>data;
		s.create(data);
		cout<<"\nDo you want to insert another element ? (Y/N)";
		cin>>ch;
	}
	while(ch=='y'|| ch=='Y'|| ch=='1');
	
	cout<<"\nElements inserted successfully.\n";
		
	s.skipl();
	
	s.display();
	
	cout<<"\nEnter key to search : ";
	cin>>data;
	
	s.search(data);
	
	return 0;
}





//End of prog
