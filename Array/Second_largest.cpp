#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int brute_second_largest(vector<int> arr){
    sort(arr.begin(),arr.end());
    for(int i=arr.size()-2;i>=0;i--){
        if(arr[i]!=arr[arr.size()-1]){
            return arr[i];
        }
        else{
            continue;
        }
    }
    return -1;
    
}
 int better_second_largest(vector<int> arr){
    int maxi=INT_MIN;
    int second=INT_MIN;
    for(int i=0;i<arr.size();i++){
        if (arr[i]>maxi){
            maxi=arr[i];
        }
    }
    for(int i=0;i<arr.size();i++){
        if(arr[i]>second && arr[i]<maxi){
            second=arr[i];
        }
    }
    return second;
 }
 int optimal_second_largest(vector<int> arr){
    int largest=arr[0];
    int second=INT_MIN;
    for(int i=1;i<arr.size();i++){
        if(arr[i]>largest){
            second=largest;
            largest=arr[i];
        }
        else if(arr[i]<largest && arr[i]>second){
            second=arr[i];
        }
    }
    return second;

 }

int main(){
    vector<int> arr={1,2,4,7,7,5};
    int ans1=brute_second_largest(arr);
    int ans2=better_second_largest(arr);
    int ans3=optimal_second_largest(arr);

    cout<<ans1<<" "<<ans2<<" "<<ans3<<endl;


}