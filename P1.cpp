#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--){
        int h,p;
            int flag = 0;
        cin>>h>>p;
        while(p!=0){
            h = h-p;
            if(h<=0){
                flag =1 ;
                break;
            }
            p =p/2;
            if(p==0){
                break;
            }
        }
        if(flag ==1){
        cout<<1<<endl;    
        }else{
            cout<< 0<<endl;
        }
        
        
    }
	return 0;
}