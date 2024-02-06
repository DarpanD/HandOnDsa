 // Keep it up Champ ;)
 #include <iostream>
 #include <bits/stdc++.h>
 #include <vector>

 using namespace std;
 
 void printAr(vector<string>& ans){
    for(int i = 0 ; i <  ans.size() ; i++){
        cout << ans[i] << " ";
    }
    cout << endl<<endl;
}

 
   bool possible(int x, int y, vector<vector<int>> m, int n, vector<vector<int>> visited){
        if((x>=0 && x<n) && (y>=0 && y<n) && visited [x][y] == 0 && m[x][y] == 1 ){
            return true;
        }
        else{
            return false;
        }
    }
    
    void solve(vector<vector<int>> m, int n, vector<vector<int>> visited, string path, vector<string>& ans,
               int x, int y){
                   if(x == n-1 && y == n-1){
                       ans.push_back(path);
                       return ; 
                   }
                   
                   visited[x][y]=1;
                   
                   //movements :- Down,Up,Right,Left
                   
                   //Down:-
                   int newx = x+1;
                   int newy = y;
                   if(possible(newx, newy, m, n, visited)){
                       path.push_back('D');
                       solve(m, n, visited, path, ans, newx, newy);
                       path.pop_back();
                   }
                   
                   //Left:-
                   newx = x;
                   newy = y-1;
                   if(possible(newx, newy, m, n, visited)){
                       path.push_back('L');
                       solve(m, n, visited, path, ans, newx, newy);
                       path.pop_back();
                   }
                   
                   //Up:-
                   newx = x-1;
                   newy = y;
                   if(possible(newx, newy, m, n, visited)){
                       path.push_back('U');
                       solve(m, n, visited, path, ans, newx, newy);
                       path.pop_back();
                   }
                   
                   //Right:-
                   newx = x;
                   newy = y+1;
                   if(possible(newx, newy, m, n, visited)){
                       path.push_back('R');
                       solve(m, n, visited, path, ans, newx, newy);
                       path.pop_back();
                   }
                   
                   visited[x][y]=0;
               }
    

    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        
        if(m [0] [0] == 0){
            return ans;
        }
        
        int xind = 0;
        int yind = 0;
        
        vector<vector<int>> visited = m;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                visited [i][j] = 0;
            }
        }
        
        string path = "";
        
        solve(m, n, visited, path, ans, xind, yind);
        sort(ans.begin(), ans.end());
        return ans;     
    }
int main() {
 
     // vector<vector<int>> path = {{1, 0, 0, 0},
    //                             {1, 1, 0, 1}, 
    //                             {1, 1, 0, 0},
    //                             {0, 1, 1, 1}};

    vector<vector<int>> path = {{1, 1, 1 },{1, 0, 1 },{1, 0, 1}};

    // vector<vector<int>> path = {{1, 0, 1, 0},
    //                             { 0, 0, 1, 1},
    //                             { 0, 1, 0, 1},
    //                             { 0, 0, 1, 1}};


    int rows = path.size(); // for 4X4 vector , rows is 4 
    int columns = path[0].size();

    vector<string> LocalAnswer = findPath(path , rows);
    printAr(LocalAnswer);

 
    return 0;
 
 }