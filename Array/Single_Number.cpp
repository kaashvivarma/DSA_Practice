#include <iostream>
#include <vector>
using namespace std;
int Single(vector<int>& arr){
    int xor1=0;
    for (int i=0;i<arr.size();i++){
        xor1=xor1^arr[i];
    }
    return xor1;
}

int main(){
    vector<int> arr={1,1,2,2,3,4,4,5,5};
    
    int ans=Single(arr);
    cout<<ans;
}