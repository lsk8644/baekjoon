#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 100001
using namespace std;

vector<pair<int,pair<int,int>>> V;
int parent[MAX];
int n,m,a,b,c,sum,node;
int find(int x);
void merge(int x,int y);

int main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin>>n>>m;
  for (int i=1;i<=m;i++)
  {
    cin>>a>>b>>c;
    V.push_back({c,{a,b}});
  }
  sort(V.begin(),V.end());
  for (int i=1;i<=n;i++)
    parent[i]=i;
  for (int i=0;i<V.size();i++)
  {
    if (node==n-2)
      break;
    int cost=V[i].first;
    int start=V[i].second.first;
    int end=V[i].second.second;
    start=find(start);
    end=find(end);
    if (start!=end) {
      merge(start,end);
      node++;
      sum+=cost;
    }
  }
  cout<<sum;
}

int find(int x)
{
  if (parent[x]==x)
    return x;
  return parent[x]=find(parent[x]);
}

void merge(int x,int y)
{
  if (x>y)
    parent[x]=y;
  else
    parent[y]=x;
}