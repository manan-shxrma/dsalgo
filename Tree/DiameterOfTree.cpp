// This program can calculate the diameter of a given tree using two dfs searches
// The tree should be given in adjacency list format
#include <bits/stdc++.h> 
#define vi vector <int>
#define vll vector <long long>
#define pi pair <int,int>
typedef long long ll;
using namespace std;
vi adj[200020];
int b,c,ans;
int temp1=0, temp2=0;
int gcd(int a, int b)
{
    if (a == 0)
    return b;
    return gcd(b % a, a);
}
ll ncr(int n, int r)
{
    if (n < r) return 0;
    long long p = 1, k = 1;
    if (n - r < r)
        r = n - r;
    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;
            long long m = __gcd(p, k);
            p /= m;
            k /= m;
            n--;
            r--;
        }
    }
    else
        p = 1;
    return p;
}
template <typename T>
vector <T> vcreate(int n){
    vector <T> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    return v;
}
void dfs(int s, int e, int depth){
    if(temp1 < depth){
        temp1 = depth;
        b = s;
    }
    for(auto u: adj[s]){
        if(u==e) continue;
        dfs(u,s,depth+1);
    }
}
void dfs1(int s, int e, int depth){
    if(temp2 < depth){
        temp2 = depth;
        c = s;
    }
    for(auto u: adj[s]){
        if(u==e) continue;
        dfs1(u,s,depth+1);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
    for (int i = 0; i < n-1; i++)
    {
        int x,y ; cin>>x>>y;
        x--;y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    b=0;
    dfs(0,-1,0);
    dfs1(b,-1,0);
    cout<<temp2<<endl;
    return 0;
    }