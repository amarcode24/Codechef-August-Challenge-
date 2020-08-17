#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef vector<int>		vi;
typedef vector<pii>		vpii;
typedef vector<vi>		vvi;
//=======================
const int MOD = 1'000'000'007;
const int N = 2e6+13, M = N;
//=======================
//vi g[N];
//int a[N];
//int n, m, k;
//=======================


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t ;
    cin >> t;
    while(t--) {
     ll int n,k;
      cin>>n>>k;
       ll int p[n];
       fo(i,n){
           cin>>p[i];
       }
       ll int a[n],b[n];
       fo(i,n){
           a[i]=k/p[i];
           b[i]=k%p[i];
       }
      ll int min = 1000000000;
     ll int result; 
      fo(i,n){
          if(b[i]==0 && a[i]<min){
              min = a[i];
              result = k/a[i];
          }
      } 

   if(min ==1000000000){
       cout<<-1<<endl;
   }else{
       cout<<result<<endl;
   }



    }

    return 0;
}