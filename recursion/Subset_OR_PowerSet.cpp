// Keep it up Champ ;)
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
            for ( int j = 0 ; j < arr[i].size() ; j++){
                    cout << arr[i][j] << " ";
            }cout<< "   ";  
        }
    }cout << endl<<endl;
}

// USING RECURSION 
void SetMaking(vector<int>& nums , vector<int>& output , int index , vector<vector<int>>& FinalArray ){
    if(index >= nums.size()){
        FinalArray.push_back(output);
        return ;
    }
     
    // excluding case 
    SetMaking(nums , output , index+1 , FinalArray);

    // Including the index case 
    output.push_back(nums[index]);
    SetMaking(nums , output , index+1 ,  FinalArray);
    output.pop_back(); // to return it back to the array we got before pushback new element 
    
}

vector<vector<int>> PowerSetCreation(vector<int>& nums ){
    vector<vector<int>> FinalArray;
    vector<int>  output;
    
    SetMaking(nums , output , 0 , FinalArray);
    return FinalArray;
}


// USING BITS MANUPULATION
vector<vector<int>> subset(vector<int> &nums ){
    vector<vector<int>> ans ; 
    int n = nums.size();

    // since nums = {1,2,3} 
    // n = (4-1) = 3 
    // number of elements in power set = 2^n  , another way of writing 2^n is 1 left-shift n time i.e. (1<<n) , this saves the time complexity.
    for(int i = 0; i < (1<<n); i++ ){ 

        vector<int> opt;
        
        // j represents the imdex of bit , if j = 1 -> {2} in {1,2,3} 
        // so if j is set bit that means only element at 1st index is selected and rest is neglected
        for (int j = 0 ; j < n ; j++){

            // incase of (1<<j)
            // (1<<0) = 001 
            // (1<< 1) = 010
            // (1<< 2 ) = 100
            // this way if & is true the number is pushed to opt vector 
            if((1<<j)&i){
                opt.push_back(nums[j]);
            }
        }
        ans.push_back(opt);
    }

    return ans;
}

int main() {

    vector<int> nums = { 1,2,3};

    // for recursion 
    cout << "Using Recursion "<< endl;
    vector<vector<int>> ansrr= PowerSetCreation(nums);
    PrintVector(ansrr);

    // for bit manipulations
    cout << "Using Bit Manipulation "<< endl;
    vector<vector<int>> ansbm =  subset(nums);
    PrintVector(ansbm);

    return 0;

}

