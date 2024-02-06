// Keep it up Champ ;)
// Leetcode Problem 17
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>

using namespace std;

const vector<string> master = {"","","abc" , "def" , "ghi" , "jkl" , "mno" ,  "pqrs" , "tuv" , "wxyz"};

// Print Result 
void PrintVector(vector<string> arr){
    for(int i = 0 ; i < arr.size() ; i++) {
        if(arr[i] == ""){
            cout << "null ";
        }
        else{
            cout << arr[i]<< " ";
        }
    }cout << endl<<endl;
}


// Recursive Approach
void solve(vector<string>& FinalString , string& s , string& opt , int i  ){

    /// base case 
    if ( i >= s.length()){
        FinalString.push_back(opt);
        return ;
    }

    string sub_str = s.substr(i, 1);
    int masterkey = stoi(sub_str);
    // OR 
    // int masterkey = s[i] - '0' ;
    string level = master[masterkey];

    for(auto j : level){
        opt.push_back(j);
        solve(FinalString, s, opt, i+1);
        opt.pop_back();
    }
}
vector<string> Phone( string& digits){

    
    vector<string> FinalString;
    string opt ;

    solve(FinalString, digits , opt, 0);

    return FinalString;
}


// Iterative Approach
vector<string> Cominations(string& digits){

    vector<string> FinalString;
    if(digits.length() == 0 ) return FinalString;

    FinalString.push_back("");

    for(auto digit : digits){
        vector<string> temp;
        int key = digit - '0';
        for (auto level : master[key]){
            for (auto result : FinalString){
                temp.push_back(result + level);
            }
        }
        FinalString = temp;
    }

    return FinalString;
}

// Main FUunctionS
int main() {
    
    string digits = "234";

    vector<string> ansRec  = Phone(digits);
    PrintVector(ansRec);

    vector<string> ansIter  = Phone(digits);
    PrintVector(ansIter);

    return 0;

}


// HOW ITERATIVE APPROACH WORKS 
/*
Explanation with sample input "234"

Initial state:

result = {""}
Stage 1 for number "1":

result has {""}
candiate is "abc"
generate three strings "" + "a", ""+"b", ""+"c" and put into tmp,
tmp = {"a", "b","c"}
swap result and tmp (swap does not take memory copy)
Now result has {"a", "b", "c"}
Stage 2 for number "2":

result has {"a", "b", "c"}
candidate is "def"
generate nine strings and put into tmp,
"a" + "d", "a"+"e", "a"+"f",
"b" + "d", "b"+"e", "b"+"f",
"c" + "d", "c"+"e", "c"+"f"
so tmp has {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" }
swap result and tmp
Now result has {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" }
Stage 3 for number "3":

result has {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" }
candidate is "ghi"
generate 27 strings and put into tmp,
add "g" for each of "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"
add "h" for each of "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"
add "h" for each of "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"
so, tmp has
{"adg", "aeg", "afg", "bdg", "beg", "bfg", "cdg", "ceg", "cfg"
"adh", "aeh", "afh", "bdh", "beh", "bfh", "cdh", "ceh", "cfh"
"adi", "aei", "afi", "bdi", "bei", "bfi", "cdi", "cei", "cfi" }
swap result and tmp
Now result has
{"adg", "aeg", "afg", "bdg", "beg", "bfg", "cdg", "ceg", "cfg"
"adh", "aeh", "afh", "bdh", "beh", "bfh", "cdh", "ceh", "cfh"
"adi", "aei", "afi", "bdi", "bei", "bfi", "cdi", "cei", "cfi" }
Finally, return result.

*/