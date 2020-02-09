//KaalaSenapati
//Prims Algorithm via Linked List;
//Note : No display of graph only MST.
#include<iostream>
#include<string.h>
using namespace std;

class prims
{
    public:
    prims* v[10];//Store vertices;
    prims* e[10];//Store edge info;
    string city;//Store city name
    //prims* root;
    //prims* next;//To create and display MST
    int cost[10];//Store cost
    bool visit;//To determine if node has been visited
    int n;//Store no of vertices
    //prims *p;//Temp Node
    void accept()
    {
        cout<<"\nEnter no of vertices : ";
        cin>>n;
        for(int i=0;i<n;i++)
        {
            v[i]=new prims;
            cout<<"\nEnter city "<<i+1<<" : ";
            cin>>v[i]->city;
            v[i]->visit=false;
        }
        cout<<"\nCities entered successfully.\n";

        input();
    }

    void input()
    {
        char ch;
        int cst;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                ch=='n';
                cout<<"\nIs "<<v[i]->city<<" connected to "<<v[j]->city<<" ?(Y/N) : ";
                cin>>ch;
                if(ch=='Y'||ch=='y'||ch=='1')
                {
                    cout<<"Enter the cost of transmission : ";
                    cin>>cst;
                }
                else
                    cst=999;
                v[i]->cost[j]=cst;
                v[j]->cost[i]=cst;
            }
        }
        cout<<"\nGraph created successfully.\n";
        calc();
    }

    int visited()
    {
        for(int i=0;i<n;i++)
        {
            if(v[i]->visit==false)
                return 1;
        }
        return 0;
    }

    void calc()
    {
        v[0]->visit=true;
        int min;
        string name1,name2;
        int wt,c;
        int total=0;
        while(visited())
        {
            min=999;
            wt=0;
            name1=name2="\0";
            for(int j=0;j<n;j++)
            {
                if(v[j]->visit==true)
                {
                    for(int k=0;k<n;k++)
                    {
                        if(v[j]->cost[k] < min && v[k]->visit==false)
                        {
                         name1=v[j]->city;
                         name2=v[k]->city;
                         wt=v[j]->cost[k];
                         c=k;
                         min=wt;
                         //cout<<name1<<name2;
                        }
                    }
                }
            }
            v[c]->visit=true;
            if(name1!="\0")
            {
                cout<<" "<<name1<<" to "<<name2<<" : "<<wt<<endl;
                total=total+wt;
            }

        }
        cout<<"\nTotal MST cost : "<<total;


    }
}p;

int main()
{
    p.accept();
    return 0;
}
