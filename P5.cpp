#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
    ll n,k;
    cin>>n>>k;
    ll a[n+1];
    map<ll, ll>m;
    ll result =0,t=1;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        }
    ll column[n+1][n+1]={0};
        
    for(ll i=0;i<n;i++){
    for(ll j=0 ;j<n;j++){
                column[i][j]=0;
            }
        }
    for(ll i =0;i<n;i++){
        m.clear();
        for(ll j=i;j<n;j++){
            column[i][j]= (j==0)?0:column[i][j-1];
            if(m.count(a[j])){
                if(m[a[j]]==1){
                    column[i][j]++;
                }
             column[i][j]++;
                }
     m[a[j]]++;
            }
        }
 result = 1000000000000000000;
     ll tab = 100;
        ll dp[101][1001]={0};
for(int i =0;i<=tab;i++){
            for(ll j=0;j<=tab;j++){
                dp[i][j]=0;
    }
        }
      for(ll i =0;i<n+1;i++){
            dp[1][i]=column[0][i-1];
        }
for(ll i =2;i<=tab ;i++){
            dp[i][1]=0;
        }
        
 for(ll i=2;i<=tab;i++){
for(ll j=2;j<=n;j++){
               ll b2 = 1000000000000000000;
      for(ll k=1;k<j;k++){
                    b2 = min (b2,dp[i-1][k] + column[k][j-1]);
                }
       dp[i][j]=b2;
            }
        }
for(tab =1;tab<=100;tab++){
 result = min(tab*k+dp[tab][n],result);
        }
cout<<result<<endl;

}
return 0;
    }