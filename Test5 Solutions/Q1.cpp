#include<bits/stdc++.h>
using namespace std;
int visited[1000001];

int dfs(int source,vector<int> serverConnection[],vector<int> serverClientConnection[])
{
    visited[source]=1;
    int count=0;
    for(int i=0;i<serverConnection[source].size();i++){
        if(visited[serverConnection[source][i]]==0)
            count+=dfs(serverConnection[source][i],serverConnection,serverClientConnection);
    }
    return count+ serverClientConnection[source].size();
}

int main() {
    int server,client;
    cin>>server>>client;
    int SSC,SCC;
    cin>>SSC;
    vector<int> serverConnection[server+1];
    for(int i=0;i<SSC;i++){
        int s1,s2;
        cin>>s1>>s2;
        serverConnection[s1].push_back(s2);
        serverConnection[s2].push_back(s1);
    }
    cin>>SCC;
    vector<int> serverClientConnection[server+1];
    for(int i=0;i<SCC;i++){
        int s1,c1;
        cin>>s1>>c1;
        serverClientConnection[s1].push_back(c1);
    }
    int ans=0;
    memset(visited,0,sizeof(visited));
    for(int i=1;i<=server;i++){
        if(visited[i]==0)
            ans=max(ans,dfs(i,serverConnection,serverClientConnection));
    }
    cout<<ans<<endl;
}
