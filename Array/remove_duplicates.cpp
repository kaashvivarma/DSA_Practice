#include <iostream>
using namespace std;
#include <vector>
#include <set>
#include <algorithm>

void better_remove_duplicate(vector<int>& arr){
    sort(arr.begin(),arr.end());
    vector<int> ans;
    for(int i=1;i<arr.size();i++){
        if(arr[i]!=arr[i-1]){
            ans.push_back(arr[i]);
        }
    }
    for(int x:ans){
        cout<<x<<" ";
        
    }
    cout<<endl;
}// TC: O(NLOGN)); SC=O(N)

void  brute_remove_duplicate(vector<int>& arr){
    set<int> st;
    for(int i=0;i<arr.size();i++){
        st.insert(arr[i]);
    }
    vector<int> ans(st.begin(),st.end());
    for(int x:ans){
        cout<<x<<" ";
        
    }
    cout<<endl;
}//TC=O(N_LOGN), SC=O(2N)

void optimal_remove_duplicate(vector<int>& arr){
    int i=0;
    int j=1;
    vector<int> ans;
    while (j<arr.size()){
        if(arr[i]==arr[j]){
            j++;
        }
        else{
            ans.push_back(arr[i]);
            i=j;
            j++;

        }
    }
    for(int x:ans){
        cout<<x<<" ";
        
    }
    cout<<endl;
}

int main(){
    vector<int> arr={1,1,2,2,2,3,3};
    better_remove_duplicate(arr);
    brute_remove_duplicate(arr);
    optimal_remove_duplicate(arr);

}