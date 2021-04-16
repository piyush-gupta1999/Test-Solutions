#include<bits/stdc++.h>
using namespace std;
#define m 10000000007

//Final complexity of code will be O(nlog(n)) which will be in time limit
int winningAmount(int score[],int n){

    //sort the array in O(nlogn) complexity
    sort(score,score+n);

    //create a min heap which will give you minimum value of all array in O(logn) dynamically
    priority_queue <int, vector<int>, greater<int> > minHeap;

    //create a max heap which will give you maximum value of all array in O(logn) dynamically
    priority_queue<int> maxHeap;
    for(int i=0;i<n;i++){
        maxHeap.push(score[i]);
        minHeap.push(score[i]);
    }

    int rounds=n-1,amount=0;

    //total rounds will be n-1
    while(rounds--){
        int minScore=0,maxScore=0,diff;

        //Get minimum element
        if(!minHeap.empty())
        {
            minScore=minHeap.top();

            //throw the minimum element out because we don't need it again
            minHeap.pop();
        }

        //Get Maximum Element
        if(!maxHeap.empty()){
            maxScore=maxHeap.top();
            //throw the maximum element out because we don't need it again
            maxHeap.pop();
        }       
       
        //Evaluate difference 
        diff=(maxScore-minScore);

        //calculate profit
        amount=(amount%m+diff%m)%m;

        //push the difference in both heaps because it will be the part of array in next iteration
        minHeap.push(diff);
        maxHeap.push(diff);
    }
    return amount;
}
int main() {
    int n,i;
    cin>>n;
    int score[n];
    for(i=0;i<n;i++){
        cin>>score[i];
    }
    cout<<winningAmount(score,n)<<endl;
}
