#include<bits/stdc++.h>
using namespace std;




#define MOD 1000000007

//to store factorial
long long f[500005];
long long  pow(long long  n,long long  p ,long long  modulo=MOD){
 long long result2 =1;
 while(p)
 {
  if(p&1){
  result2=(result2*n)%modulo;
  }
  n=(n*n)%modulo;
  p>>=1;
 }
 
 return result2%modulo;

}

long long  mod_inv(long long  n,long long  modulo=MOD){



 return pow(n,modulo-2,modulo);
}
long long  nCr(long long  n, long long  r, long long  modulo=MOD){
if(r==0){

return 1;
}

else{


return (((f[n]*mod_inv(f[n-r]))%modulo)*mod_inv(f[r]))%modulo;


}
}

int main(){
ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 int t;
 cin>>t;
 f[0]=f[1]=1;


 for(int i=2;i<500005;i++){

  f[i]=(1ll*f[i-1]*i)%MOD;

 }


 while(t--){

  long long  n;

  cin>>n;

  long long  a[n+1];
  map<long long ,long long > mp;
  for(int i=0;i<n;i++){
   cin>>a[i];
   mp[a[i]]++;
  }
  long long  cnt[n+3],mrx[n+1];
  for(int i=0;i<=n+1;i++){
          cnt[i]=mrx[i]=1;
  }

  for(auto x:mp)
  {
    
   long long  sum=1;
   for(int j=1;j<=x.second;j++)
   {
                  sum+=nCr(x.second,j);



      sum=  sum % MOD;
          cnt[j]*=sum;

        cnt[j]= cnt[j]%MOD; 


   }
   mrx[x.second+1]*=sum;

   mrx[x.second+1]%=MOD;
  }

  long long  mul=1;
  for(int i=1;i<=n;i++)
  {
     mul*=mrx[i];

   mul%=MOD;


         cnt[i]*=mul;

          cnt[i]%=MOD;  
  }
  

  for(int i=1;i<=n;i++)
  { 
   long long  res=0,ans,sum=1;
  

    for(int j=1;j<=mp[i];j++)
   {
    long long  temp;
              ans=nCr(mp[i],j);
                temp=ans;
              sum+=ans;
              sum%=MOD;
              cnt[j]=(cnt[j]*mod_inv(sum))%MOD;
              ans*=cnt[j];
              ans%=MOD;
              cnt[j]=(cnt[j]*(sum-temp+MOD)%MOD)%MOD;
              res+=ans;
              res%=MOD;
             }
   


   cout<<res%MOD<<" ";
  }
  cout<<"\n";

  

 }
return 0;
}