#include <iostream>
#include <vector>
#include <map>
using namespace std;

//brute force would be to apply nested loops to count the number of elements and return the one that occurs > n/2 times
// TC=O(N)

int better(vector<int> arr){
    map<int,int> cnt;
    for(int i=0;i<arr.size();i++){
        if(cnt.find(arr[i])!=cnt.end()){
            cnt[arr[i]]++;
        }
        else{
            cnt[arr[i]]=1;
        }
    }
    for(auto &p:cnt){
        if (p.second>arr.size()/2){
            return p.first;
        }
        
    }
    return -1;
}

int optimal(vector<int> arr){
    int cnt=0;
    int el;
    for(int i=0;i<arr.size();i++){
        if(cnt==0){
            cnt=1;
            el=arr[i];
        }
        else if(arr[i]==el){
            cnt++;
        }
        else{
            cnt--;
        }
    }
    int c=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==el) c++;
    }
    if (c>arr.size()/2) return el;
    return -1;
}

int main(){
    vector<int> arr={2,2,3,3,1,2,2,3,3,3,3};
    int ans=optimal(arr);
    cout<<ans;

}