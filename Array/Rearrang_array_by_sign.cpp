//VARIETY 1: positives==negatives
//Solve variety 2 (positives!=negatives) using brute force

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> brute(vector<int> arr){
    vector<int> pos;
    vector<int> neg;
    for(int i=0;i<arr.size();i++){
        if(arr[i]<0){
            neg.push_back(arr[i]);
        }
        else{
            pos.push_back(arr[i]);
        }
    }
    for(int i=0;i<arr.size()/2;i++){
       arr[2*i]=pos[i];
       arr[2*i+1]=neg[i];
    }

    return arr;
}//TC-O(2N), SC=O(N)

vector<int> optimal(vector<int> arr){
    int even=0;
    int odd=1;

    while(even<arr.size() && odd<arr.size()){
        if (arr[even]>0){
            even+=2;
        }
        if(arr[odd]<0){
            odd+=2;
        }
        else if(arr[even]<0 && arr[odd]>0){
            swap(arr[even],arr[odd]);
            even+=2;
            odd+=2;
        }
    }
    return arr;


}


int main(){
    vector<int> arr={3,1,-2,-5,2,-4};
    vector<int> ans=optimal(arr);
    for(int x:ans){
        cout<<x<<" ";
    }
}