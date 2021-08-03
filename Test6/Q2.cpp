#include<bits/stdc++.h>
using namespace std;
int arr[101][101];
bool isValid(int i,int j,int n,int m){
    if(i<0 || i>n-1 || j<0 || j>m-1)
        return false;
    return true;
}
void dfs(int i,int j,int n,int m){
    arr[i][j] = 2;
    int x[4] = {-1,0,1,0};
    int y[4] = {0,-1,0,1};
    
    for(int z = 0 ; z<4 ; z++){
        if(isValid(i+x[z],j+y[z],n,m)){
            if(arr[i+x[z]][j+y[z]] == 0){
                dfs(i+x[z],j+y[z],n,m);
            } if(arr[i+x[z]][j+y[z]] == 1){
                arr[i+x[z]][j+y[z]] = 2;
            }
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<101;i++){
        for(int j=0;j<101;j++){
            arr[i][j]=-1;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0){
                dfs(i,j,n,m);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    queue<pair<pair<int,int>,int>> q;
    map<pair<int,int> , int > myMap;
    for(int i=0;i<n;i++){
        if(arr[i][0]==1){
            q.push({{i,0},0});
        }
    }
    int ans = INT_MAX;
    while(!q.empty()){
        int distance = q.front().second;
        pair<int,int> p = q.front().first;

        int xi = p.first;
        int yj = p.second;

        q.pop();
        if(p.second == m-1 ){
            ans = min(ans,distance);
        }
        else {
            int x[4] = {-1,0,1,0};
            int y[4] = {0,-1,0,1};
    
            for(int z = 0 ; z<4 ; z++){
                if(isValid(xi+x[z],yj+y[z],n,m)){
                    if(arr[xi+x[z]][yj+y[z]] == 1){
                        if(myMap.find({xi+x[z] , yj+ y[z]}) == myMap.end() ){
                            myMap[{xi+x[z] , yj+ y[z]}] = distance + 1;
                            q.push({{xi+x[z] , yj+ y[z]},distance+1});
                        }else{
                            if(distance + 1 < myMap[{xi+x[z] , yj+ y[z]}]){
                                myMap[{xi+x[z] , yj+ y[z]}] = distance + 1;
                                q.push({{xi+x[z] , yj+ y[z]},distance+1});
                            }
                        }
                    }
                }
            }
        }
    }
    if(ans == INT_MAX){
        cout<<-1<<endl;
    }else{
        cout<<ans<<endl;
    }

}