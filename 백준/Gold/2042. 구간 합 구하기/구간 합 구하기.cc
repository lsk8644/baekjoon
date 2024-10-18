#include <iostream>
#define MAX 1000001
using namespace std;

long long N,M,K,leaf=1;
long long a,b,c;
long long brr[MAX];
long long arr[MAX*3];
long long init(int node,int left,int right);
void update(int node,int start,int end,int index,long long diff);
long long Sum(int L, int R, int nodeNum, int start, int end);

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++)
        cin >> brr[i];

    init(1,1,N);

    for (int i = 0; i < M + K; i++)
    {
        cin >> a >> b >> c;
        long long diff = 0;
        if (a==1)
        {
            diff = c - brr[b];
            brr[b] = c;
            update(1,1,N,b,diff);
        }
        else if (a==2)
        {
            cout << Sum(b,c,1,1,N) << "\n";
        }
    }
}

long long init(int node,int start,int end)
{
    if (start==end)
        return arr[node]=brr[start];
    int mid=(start+end)/2;
    return arr[node]=init(node*2,start,mid)+init(node*2+1,mid+1,end);
}

void update(int node,int start,int end,int index,long long diff)
{
    if (end < index || index < start)
        return;
    arr[node] += diff;
    if (start != end)
    {
        int mid = (start + end) / 2;
        update(2 * node, start, mid, index, diff);
        update(2 * node + 1, mid + 1, end, index, diff);
    }
}

long long Sum(int L, int R, int nodeNum, int start, int end)
{
    if(R < start || end < L)
        return 0;
    if(L <= start && end <= R)
        return arr[nodeNum];
    int mid = (start + end) / 2;
    return Sum(L, R, nodeNum*2, start, mid) + Sum(L, R, nodeNum*2+1, mid+1, end);
}