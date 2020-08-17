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
      int t;
      cin>>t;
      while(t--){
          string s,p;
          cin>>s;
          cin>>p;
          int count1[26]= {0};
          int count2[26]={0};
          for(int i=0;i<s.length();i++){
              count1[s[i] - 97]++;
          }
          for(int i=0;i<p.length();i++  ){
              count2[p[i] - 97]++;
          }
          sort(s.begin(),s.end());
          fo(i,26){
              count1[i]= count1[i]- count2[i];
          }
          
          
         vector<char>result;
         int flag =0;
         int f1=0, f2=0,f3=0,f4=0;
         char x;
         x= p[0];
         if(p.length()>1){
         for(int i =1;i<p.length();i++){
             if(p[i]!=p[0] || i== p.length() -1 ){
                 x = p[i];
                  break;
             }
         }
         }
         if(x > p[0]){
             f1 =1;
         }else {
             f1=0;
         }
         if(f1==1){
         for(int i =0;i<s.length();i++){
             if(s[i]== p[0] && count1[s[i] - 97]>0){
                 result.push_back(s[i]);
                 count1[s[i]-97]--;
                 }
             else if (s[i]== p[0] && count1[p[0]-97]==0 && flag == 0){
                 for(int i =0;i<p.length();i++){
                     result.push_back(p[i]);
                     flag =1;
                 }
             }
             
             else if (s[i]== p[0] && count1[p[0]-97]==0 && flag == 1){
                 continue;
                 }
                 
             else if(s[i]!=p[0] && count1[s[i]-97] >0 ){
                 result.push_back(s[i]);
                 count1[s[i]-97]--;
             }
             
             else if (s[i]!= p[0]&& count1[s[i]-97]==0){
                 continue;
             }
             
         }
         }
         else{
             for(int i =0;i<s.length();i++){
             if(s[i]== p[0] &&flag ==0 ){
                 for(int i =0;i<p.length();i++){
                     result.push_back(p[i]);
                     flag =1;
                 }
                 }
             else if (s[i]== p[0] && count1[p[0]-97]>0){
                 result.push_back(s[i]);
                 count1[s[i]-97]--;
             }
             
             else if (s[i]== p[0] && count1[p[0]-97]==0 && flag == 1){
                 continue;
                 }
                 
             else if(s[i]!=p[0] && count1[s[i]-97] >0 ){
                 result.push_back(s[i]);
                 count1[s[i]-97]--;
             }
             
             else if (s[i]!= p[0]&& count1[s[i]-97]==0){
                 continue;
             }
             
         }
       }
      

      
           
          for(auto it:result){
              cout<<it;
          }
          cout<<endl; 
        
       
      }
      

    return 0;
}