#include<bits/stdc++.h>
using namespace std;
long long int sting(long long int bee_sting,int cr,vector<long long int> xl_set[]){

    vector<long long int> xl = xl_set[cr];

    for(long long int i=0;i<xl.size() && bee_sting>0 ;i++){

        long long int temp = min(xl[i],bee_sting);
        xl[i] = xl[i] - temp;
        bee_sting = bee_sting - temp;
    }
    if(bee_sting>0){
        return 0;
    }
long long int k = xl.size();

    //combining the stings in order to successfully do my sting operation 
    long long int sting1 = 0,sting2 =0,sting3 =0; 
    
   
    for (int i=0; i<k; i++){
        sting1 += xl[i]; 
    }
    //formed the 2nd sting 
     long long int xt[k+1];
    for (long long int i=0; i<k; i++) 
    { 
        xt[i] = xl[i]*(sting1-xl[i]); 
        sting2 += xt[i]; 
    } 
    //dividing because its been calculated times 2 , which is quite obvious here 
    sting2 /= 2; 

     
    for (long long int i=0; i<k; i++) {
        sting3 += xl[i]*(sting2-xt[i]);
    } 
        //dividing because its been calculated times 3 , which is quite obvious here 

    sting3 /= 3; 
//finally i solve my first ever dp problem , by going through a sting operation 





    return sting3;
}
int main() {
    long long int t;
    cin>>t;

    while(t--){
       long long int n,c,k;
       cin>>n>>c>>k;
       
       unordered_map<long long int,int> cr[c+1];
       

       for(int i=1;i<=n;i++){
           long long int a,b,gx;
           cin>>a>>b>>gx;
           cr[gx][a]++;
       }

       long long int m_f[k+1][c+1];

       long long int V[c+1]={0};
       for(long long int i=1;i<=c;i++){
           cin>>V[i];
       }
       
       vector<long long int> xl[c+1];
for(long long int i=1;i<=c;i++){
           vector<long long int> xl_set;
           for(auto it : cr[i]){
               xl_set.push_back(it.second);
           }
         
         
         //sorting the vector so as to get the min. valaues 
         
          sort(xl_set.begin(),xl_set.end());
           xl[i] = xl_set;
       }
       //initialising the dp of size k+1,c+1
       long long int dp[k+1][c+1];

long long int lrm;

       for(int i=0;i<=k;i++){
           for(long long int j=0;j<=c;j++){
               dp[i][j] = LLONG_MAX;
               if(j==0){
                   dp[i][j]=0;
               }

               m_f[i][j] = -1;
           }
       }

       for(long long int i=0;i<=k;i++){
           //more two loops
           for(long long int j=1;j<=c;j++){



               //3rd loop to do the sting operation
               lrm= i/V[j];
               for(long long int kx=0;kx<=lrm;kx++){
                   long long int vrm = kx*V[j];
                  if(m_f[kx][j]==-1){
                      //doing the sting operation

                       m_f[kx][j] = sting(kx,j,xl);
                  }

                   dp[i][j] = min(dp[i][j] , dp[i-vrm][j-1] + m_f[kx][j] );
               }
           }
       }

      cout<<dp[k][c]<<endl;
    }
  return 0;
}