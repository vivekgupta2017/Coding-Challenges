//Non Indented Code
#include<iostream>
#include<string.h>
using namespace std;
class Prims{
 char city[10][20];
 int g[10][10];
 int v,e;
   struct dist{
   int start,end,cost;
   }dist[10];
 public:
 Prims(int x, int y){
 v=x; e=y;
 for(int i=0; i<v; i++)
 for(int j=0; j<v; j++)
 g[i][j]=0;
 }
 void createGraph();
 void display();
 void mst();
};
void Prims :: createGraph(){
 int i,j,cost;
 char ans[5];
 for(i=0; i<v; i++){
 cout<<"\n Enter city :";
 cin>>city[i];
 }
 for(i=0; i<v; i++){
  for(j=0; j<v; j++){
  if(g[i][j]==0){
  cout<<"\n Edge exists between "<<city[i]<<"-"<<city[j]<<" : Y/N?";
  cin>>ans;
  if(strcmpi(ans,"Y")==0){
   cout<<"\n Enter cost :";
   cin>>cost;
   g[i][j]=g[j][i]=cost;
   }
   else
   g[i][j]=g[j][i]=0;
   }
  }
  }
}
void Prims :: display(){
 int i,j;
 for(i=0; i<v; i++)
 cout<<"\t"<<city[i];
 cout<<"\n";
 for(i=0; i<v; i++){
 cout<<city[i]<<"\t";
 for(j=0; j<v; j++)
 cout<<g[i][j]<<"\t";
 cout<<"\n";
 }
}
void Prims :: mst(){
  int a[10],i,j,temp,temp1,min,cnt;
  for(i=0; i<v; i++)
  a[i]=0;
  a[0]=1;
  cnt=0;
  while(cnt<v-1){
   min=999;
   for(i=0; i<v; i++){
    if(a[i]==1){
	j=0;
	while(j<v){
	  if(g[i][j]>=min || g[i][j]==0)
	  j++;
	  else if(g[i][j]<min){
	       min=g[i][j];
	       temp=i;
	       temp1=j;
	       }
	    }
	}
     }

     a[temp1]=1;
     dist[cnt].start=temp;
     dist[cnt].end=temp1;
     dist[cnt].cost=min;
     ++cnt;
     g[temp][temp1]=g[temp1][temp]=1000;
  }
   cout<<"\n --- All Details ---";
   for(i=0; i<v-1; i++)
   cout<<"\n start ="<<city[dist[i].start]<<", End = "<<city[dist[i].end]<<", Cost ="<<dist[i].cost;
}
int main(){
 Prims p(4,5);
 p.createGraph();
 p.display();
 p.mst();
 return 0;
}
