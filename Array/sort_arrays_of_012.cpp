#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//brute approach would be to sort and return=== TC=(NLOGN), SC=O(N)

vector<int> better(vector<int> arr){
    int cnt0=0;
    int cnt1=0;
    int cnt2=0;
    for (int i=0;i<arr.size();i++){
        if(arr[i]==0){
            cnt0++;
        }
        else if(arr[i]==1){
            cnt1++;
        }
        else{
            cnt2++;
        }
    }
    for(int i=0;i<cnt0;i++){
        arr[i]=0;
    }
    for(int i=cnt0;i<cnt0+cnt1;i++){
        arr[i]=1;
    }
    for(int i=cnt0+cnt1;i<cnt0+cnt1+cnt2;i++){
        arr[i]=2;
    }
    return arr;
}// TC=O(2N)

vector<int> optimal(vector<int> arr){
    int low=0;
    int mid=0;
    int high=arr.size()-1;
    while(mid<=high){
        if (arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else if(arr[mid]==2){
            swap(arr[mid],arr[high]);
            high--;
        }

    }
    return arr;

}//TC=O(N)
int main(){
    vector<int> arr={0,1,2,0,1,2,1,2,0,0,0,1};
    vector<int> ans=optimal(arr);
    for(int x:ans){
        cout<<x<<" ";
    }
}