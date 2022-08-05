#include<bits/stdc++.h>
using namespace std;

void printSubset(vector<int>& subset){
    int n = subset.size();
    for(int i=0;i<n;i++){
        cout<<subset[i]<<" ";
    }cout<<"\n";
}
int solveSubsets(vector<int>& arr,int target,int index,vector<int>& subset){
    if(target == 0){
        printSubset(subset);
        return 1;
    }
    if(target < 0 || index < 0)return 0;
    int ans1,ans2;
    subset.push_back(arr[index]);
    ans1 = solveSubsets(arr,target-arr[index],index-1,subset);
    subset.pop_back();
    ans2 = solveSubsets(arr,target,index-1,subset);
    return ans1 + ans2;
}

int subsets(vector<int>& arr,int target){
    int index = arr.size()-1;
    vector<int> subset;
    return solveSubsets(arr,target,index,subset);
}

int main(){
    vector<int> arr = {1,3,4,6,9,7,5,2};
    int target = 9;
    int ans = subsets(arr,target);
    cout<< "total number of solutions are : "<<ans;
}
