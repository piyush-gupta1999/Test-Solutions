#include<bits/stdc++.h>
#define m 1000000007
using namespace std;
int main(){

    int D,M,N;

    cin>>D>>M;

    int v[M];
    for(int i=0;i<M;i++){
        cin>>v[i];
    }
    sort(v,v+M);

    cin>>N;
    int td[N];

    for(int i=0;i<N;i++){
        cin>>td[i];
    }

    int dp[D+1];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int j=0;j<M;j++){
        for(int i=1;i<=D;i++){
            if(i-v[j]>=0){
                dp[i]= (dp[i]%m + dp[i-v[j]]%m)%m;
            }
        }
    }
    int ans =0;
    for(int i=0; i<N ; i++)
    {
       if(i==0){
           ans = dp[td[i]];
       }else{
           ans = (ans%m * dp[td[i]-td[i-1]]%m)%m;
       }
    }
    cout<<ans<<endl;
}