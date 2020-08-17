#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(int i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
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
      int c,r;
      cin>>c>>r;
      int c1,r1;
      if(c<10){
          c1 = 1;
      }else if(c%9 ==0){
          c1 = c/9;
      }else {
          c1 = (c/9 )+ 1;
      }
      if(r<10){
          r1 = 1;
      }else if(r%9 ==0){
          r1 = r/9;
      }else {
          r1 = (r/9 )+ 1;
      }
        //cout<<c1<<" " << r1<<endl;
        if(c1<r1){
            cout<<0<<" "<<c1<<endl;
        }else{
            cout<<1<<" "<<r1<<endl;
        }

    }

    return 0;
}