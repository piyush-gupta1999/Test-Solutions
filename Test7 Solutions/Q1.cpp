#include<bits/stdc++.h>
using namespace std;

//If this function return true that means p1 will come first other p2 will come first in vector after sorting.
bool cmp(pair<int,int> &p1,pair<int,int> &p2){
    if(p1.second == p2.second){
        // If bit count is matching then we need to check which is higher in value
        return p1.first > p2.first;
    } 
    else{
        // If bit count is not matching that means whichever have higestest bit count will come first.
        return p1.second > p2.second;
    }
}
int countSetBits(int n)
{
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int main(){
    int n;

    // Read n numbers for user.
    cin>>n;

    // Store them in array instead of vector because you have defined size and you need another vector to store elements with there counts of 1.
    int arr[n];
    vector<pair<int,int>> v(n);

    /*Try to use 1 loop for 2 work at same time if possible like I did. 
        1. Take input from user in arr.
        2. Immediately count the number of 1 and push the count in new vector along with number itself.
    */
    for(int i=0;i<n;i++){
        cin>>arr[i];
        v[i]={arr[i],countSetBits(arr[i])};
    }
    /*Applying custom sort on my vector for desired result because 
    1. map won't work if we get two same numbers in array.
    2. multimap won't sort the second key based greate<int> sorting in current situation
    */ 
    sort(v.begin(),v.end(),cmp);
    
    int k;
    cin>>k;
    for(int i=0;i<k && i<n;i++){
        cout<<v[i].first<<" ";
    }
}
