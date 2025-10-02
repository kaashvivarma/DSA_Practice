#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int brute(vector<int> arr,int k){
    int maxi=0;
    for (int i=0;i<arr.size();i++){
        int sum=arr[i];
        for(int j=i+1;j<arr.size();j++){
            sum+=arr[j];
            if(sum<k){
                continue;
            }
            else if (sum>k){
                break;
            }
            else{
                maxi=max(maxi,j-i+1);
            }

        }
    }
    return maxi;
} //TC: O(N^2); SC: O(1)

int better(vector<int> arr, int k){
    map<long long,int> pref;
    long long sum=0;
    int maxi=0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        if (sum==k){
            maxi=max(maxi,i+1);
        }
        long long rem=sum-k;
        if(pref.find(rem)!=pref.end()){
            int len=i-pref[rem];
            maxi=max(maxi,len);
        }
        if(pref.find(sum)==pref.end()){
            pref[sum]=i;
        }
    }
    return maxi;
}// O(NLOGN) (ORDERED MAP); O(NX1) (UNORDERED NO COLLISIONS); O(N^2) (UNORDERED WORST CASE)

int optimal(vector<int> arr, int k){
    int i=0;
    int j=1;
    int sum=arr[i];
    int maxlen=0;
    while(j<arr.size()){
        
        if(sum==k){
            maxlen=max(maxlen,j-i+1);
        }
        else if (i<=j && sum>k){
            sum-=arr[i];
            i++;
        }
        j++;
        sum+=arr[j];
    }
    return maxlen;
}// O(2N)


int main(){
    vector<int> arr={1,2,3,1,1,1,1,3,3};
    int k=6;
    int ans1=brute(arr,k);
    int ans2=better(arr,k);
    int ans3=optimal(arr,k);
    cout<<ans3;

}