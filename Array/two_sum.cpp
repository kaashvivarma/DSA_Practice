#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> brute(vector<int> arr, int k){
    vector<int> ans;
    for(int i=0;i<arr.size();i++){
       for(int j=i+1;i<arr.size();i++){
            if(arr[i]+arr[j]==k){
                ans.push_back(i);
                ans.push_back(j);
            }
        }
    }
    return ans;
}

vector<int> better(vector<int> arr,int k){
    vector<int> ans;
    unordered_map<int,int> map;
    for(int i=0;i<arr.size();i++){
        int comp=k-arr[i];
        if(map.find(comp)!=map.end()){
            ans.push_back(i);
            ans.push_back(map[comp]);
        }
        map[arr[i]]=i;
    }
    return ans;
}

vector<int> optimal(vector<int> arr,int k){
    vector<int> ans;
    sort(arr.begin(),arr.end());
    int i=0;
    int j=arr.size()-1;
    while(i<j){
        if(arr[i]+arr[j]==k){
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
        else if(arr[i]+arr[j]<k){
            i++;
        }
        else{
            j--;
        }
    }
    return {-1};



}
int main(){
    vector<int> arr={2,6,5,8,11};
    int k=14;
    vector<int> ans=optimal(arr,k);
    for(int x:ans){
        cout<<x;
    }
    
    
}
