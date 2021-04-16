#include<bits/stdc++.h>
using namespace std;

//Customise comparison function based on frequency of salary and index 
bool comp(pair<int,int> p1,pair<int,int> p2){
    if(p1.second>p2.second)
        return true;
    else if(p1.second==p2.second && p1.first < p2.first)
        return true;
    return false;
}

int main() {
    int n,i;
    cin>>n;
    //salary input by user for n employees
    int salary[n];

    //create a map to store frequency of salary
    unordered_map<int,int> salaryMap;

    for(i=0;i<n;i++){
        cin>>salary[i];
        salaryMap[salary[i]]++;
    }
    //Salary array of n employees with index and frequency information
    vector< pair<int,int> > salaryArray;

    // salaryMap[salary[i]] is basically give us the frequency of salary owned by employee I.
    for(i=0;i<n;i++){
        salaryArray.push_back({i+1,salaryMap[salary[i]]});
    }
    //sort the salary Array based on customise sort
    sort(salaryArray.begin(),salaryArray.end(),comp);

    //Print out the employees based on salary in decending order and if both employees salary is same then ties break with the indexes.
    for(int i=0;i<n;i++){
        cout<<salaryArray[i].first<<" "<<salaryArray[i].second<<endl;
    }
}