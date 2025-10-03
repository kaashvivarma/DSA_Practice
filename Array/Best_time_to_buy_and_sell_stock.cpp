#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int optimal(vector<int> arr){
    int profit=0;
    int mini=arr[0];
    for(int i=1;i<arr.size();i++){
        int cost=arr[i]-mini;
        profit=max(profit,cost);
        mini=min(mini,arr[i]);
    }
    return profit;
}

int main(){
    vector<int> arr={7,1,5,3,6,4};
    int ans=optimal(arr);
    cout<<ans;
}