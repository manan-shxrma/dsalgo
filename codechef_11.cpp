/*
Problem Code:
WEIRDSUBARR
Contest Code:
START61D
Submission by
aditya_ch03
*/


#include <bits/stdc++.h>
using namespace std;
long long a[200001],b[200001];
int main() {
    int t;cin>>t;
    while(t--){
        long long n;cin>>n;
       // vector<long long> a(n+1),b(n+1);
        for(long long i = 1;i<=n;++i){
            cin>>a[i];
        }
        if(n==1){
            cout<<"1"<<endl;
            continue;
        }
        for(long long i = 2;i<=n;++i){
            b[i] = a[i] < a[i-1];
        }
        vector<pair<bool,long long>> k;
        k.push_back({b[2],1});
        for(long long i = 3;i<=n;++i){
            if(b[i] == k[k.size()-1].first){
                k[k.size()-1].second++;
            }
            else{
                k.push_back({b[i],1});
            }
        }
        k.push_back({0,0});
        long long ans = 0;
        for(long long i = 0;i<k.size()-1;++i){
            ans += k[i].second*(k[i].second+1)/2;
        }
        for(long long i = 0;i<k.size()-1;++i){
            if(k[i].first == 1){
                ans += k[i].second*k[i+1].second;
            }
        }
        cout<<ans + n<<endl;
    }
    return 0;
}