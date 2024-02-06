// Keep it up Champ ;)
// leetcode problem 46
// same as dfs code
#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

 
void PrintVector(vector<vector<int>> arr){
    for(int i = 0 ; i < arr.size() ; i++) {
        if(arr[i].size() == 0){
            cout << "null ";
        }
        else{
            cout << " { " ;
            for ( int j = 0 ; j < arr[i].size() ; j++){
                    cout << arr[i][j] << " ";
            }cout<< "} , ";  
        }
    }cout << endl<<endl;
}


void solve(vector<vector<int>>& ans ,vector<int>& nums, int i ){

    if(i >= nums.size()){
        ans.push_back(nums);
        return ;
    }

    for(int j = i ; j < (nums.size()) ; j++){

        swap(nums[i], nums[j]);
        solve(ans , nums , i+1);

        // back-tracking
        swap(nums[i], nums[j]);
    }
}

vector<vector<int>> permu(vector<int> nums){

    vector<vector<int>> ans;

    solve(ans , nums , 0);
    return ans;
}

int main() {

    vector<int> nums = {1,2,3};

    vector<vector<int>> ans = permu(nums);
    PrintVector(ans);

    return 0;

}