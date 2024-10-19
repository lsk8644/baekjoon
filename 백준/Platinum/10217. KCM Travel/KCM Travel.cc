#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX 101
#define INF 987654321
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> Q;

int dist[MAX][10001];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int N,M,K,T;
    int u,v,c,d;
    cin>>T;
    for (int i=0;i<T;i++)
    {
        cin>>N>>M>>K;
        vector<Q> V[MAX];
        priority_queue<Q> PQ;
        for (int i=0;i<K;i++)
        {
            cin>>u>>v>>c>>d;
            V[u].push_back({c,{v,d}});
        }
        for (int i = 0; i <= N; i++)
            sort(V[i].begin(),V[i].end());

        for(int i=0; i<=N; i++)
        {
            for(int j=0; j<=M; j++)
            {
                dist[i][j] =INF;
            }
        }
        dist[1][0]=0;
        PQ.push({0,{1,0}});

        while (!PQ.empty())
        {
            int cur=-PQ.top().first;                //총 금액 비용
            int C=PQ.top().second.first;            //출발 공항
            int distance=PQ.top().second.second;    //총 소요시간
            PQ.pop();
            if (dist[C][distance]<cur)
                continue;
            for (auto &p: V[C])
            {
                int W=p.first;       //비용
                int d=p.second.second;  //소요시간
                int next=p.second.first;   //다음 공항
                if (distance+W<=M)
                {
                    if (dist[next][distance+W]>cur+d)
                    {
                        dist[next][distance+W]=cur+d;
                        PQ.push({-dist[next][distance+W],{next,distance+W}});
                    }
                }
            }
        }
        int res=INF;
        for (int i=0;i<=M;i++)
            res=min(res,dist[N][i]);
        if (res==INF)
            cout<<"Poor KCM"<<"\n";
        else
            cout<<res<<"\n";
    }
}