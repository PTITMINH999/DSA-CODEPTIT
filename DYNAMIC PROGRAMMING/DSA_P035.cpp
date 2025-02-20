#include <bits/stdc++.h>
using namespace std;

#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
#define fi first
#define se second

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;
int n,m,k;
vector<pii> edge[1001];
int c[20];
ll d[17][1001];
ll dp[1<<17][17];
void dijkstra(int x){
    for(int i=1;i<=n;i++){
        d[x][i] = LLINF;
    }
    d[x][c[x]] = 0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,c[x]});
    while(!pq.empty()){
        pii f = pq.top(); pq.pop();
        int kc = f.first;
        int u = f.second;
        if(kc > d[x][u]) continue;
        for(auto it : edge[u]){
            int v = it.first;
            int w = it.second;
            if(d[x][v] > d[x][u] + w){
                d[x][v] = d[x][u] + w;
                pq.push({ d[x][v] , v });
            }
        }
    }
}
void solve(){
    cin>>n>>m>>k;
    k++;
    // c ={1,2,5}
    c[0] = 1;
    for(int i=1;i<k;i++) cin>>c[i];
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edge[u].push_back({v,w});
    }
    for(int mask = 0; mask < (1<<k); mask++){
        for(int i=0;i<k;i++){
            dp[mask][i] = LLINF;
        }
    }

    for(int i=0;i<k;i++) dijkstra(i);
    dp[1][0] = 0;
    for(int mask = 0; mask < (1<<k); mask++){
        if(mask & 1){
            for(int u = 0; u < k;u++){
                // if((mask > 1) && u ==0 ) continue;
                // if(!(mask & 1)) continue;
                // if((mask & (1<<u)) ==0) continue;
                for(int v = 0;v < k;v++){
                    // if(u==v) continue;
                    // if(mask & (1 << v)) continue;
                    int next_mask = mask | (1<<v);
                    dp[next_mask][v] = min(dp[next_mask][v], dp[mask][u] + d[u][c[v]]);
                }
            }
        }
    }
    ll ans = LLINF;
    for(int i=1;i<k;i++){
        ans = min(ans, dp[(1<<k) - 1][i] + d[i][1]);
    }
    if(ans == LLINF) ans=-1;
    cout<<ans<<endl;
}
int main(){
    faster;
    int t =1;
    //cin>>t;
    while(t--){
        solve();
    }
}