#include <iostream>
#include <vector>
#include <climits>
using namespace std;


//brute approach would be to use 3 nested loops and go through every possible subarray and find out the maximum sum. TC=O(N^3)
//better approach would be to use 2 nested loops and add on to the sum at each step and compute maximum sum. TC=O(N^2)

int kadane_optimal(vector<int> arr){
    int i=0;
    int maxi=INT_MIN;
    int sum=0;
    int ansstart=-1;
    int ansend=-1;
    int start=0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];

        if(sum>maxi){
            maxi=sum;
            ansstart=start;
            ansend=i;

        }
        if(sum<0){
            sum=0;
            start=i+1;
        }
    }
    for(int i=ansstart;i<=ansend;i++){
        cout<<arr[i]<<" ";
    }
    return maxi;

}//TC=O(N)
int main(){
    vector<int> arr={-2,-3,4,-1,-2,1,5,-3};
    int ans=kadane_optimal(arr);
    cout<<ans;
}

