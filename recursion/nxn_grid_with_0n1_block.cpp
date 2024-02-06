/*
Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

*/

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

// WORKS ON IF RAT IS ALLOWED TO GO DOWN AND RIGHT
/*
void NoOfRoutes(vector<vector<int>>& path , int rows , int columns , string& opt ,vector<string>& ans){

    if(rows <= 0 && columns <= 0){
        reverse(opt.begin() , opt.end());
        ans.push_back(opt);
        reverse(opt.begin() , opt.end());
        return ;
    }

    if(columns < path[0].size() &&  rows < path.size()){
    int x = path[rows][columns];
    if (path[rows][columns] == 0) return ;

        opt.push_back('R');
        NoOfRoutes(path , rows,columns-1 , opt );
        opt.pop_back();

        opt.push_back('D');
        NoOfRoutes(path , rows -1,columns , opt );
        opt.pop_back();

    }
}

*/

// WORKDS FOR ALL DIRECTION
bool IsSafeToGO(vector<vector<int>>& path , int rows , int cols , vector<vector<int>>& visited  ,vector<string>& ans){
    if((rows>= 0 && rows < path.size()) && (cols>= 0 &&path[0].size()) && visited[rows][cols] != 1 && path[rows][cols] != 0){
    
        return true;
    }
    return false;
}

void PathFinder(vector<vector<int>>& path , int rows , int cols , string& opt, vector<vector<int>>& visited ,vector<string>& ans){

    if(rows == path.size() -1 && cols == path[0].size()-1){
        ans.push_back(opt);
        return ;
    }

    visited[rows][cols] = 1 ;

    // going down
    int newrows =  rows+1 ; // intilizing new variale for rows and columns are nessecary as it is updated multiple times
    int newcols =  cols ;
    if(IsSafeToGO(path , newrows, newcols,visited , ans)){
        opt.push_back('D');
        PathFinder(path , newrows,newcols , opt ,visited , ans);
        opt.pop_back();
    }

    // Going Right
    newrows = rows;
    newcols = cols+1;
    if(IsSafeToGO(path , newrows, newcols ,visited , ans)){
        opt.push_back('R');
        PathFinder(path , newrows,newcols , opt ,visited , ans);
        opt.pop_back();
    }

    // Going Up 
    newrows = rows-1;
    newcols = cols;
    if(IsSafeToGO(path , newrows, newcols,visited , ans)){
        opt.push_back('U');
        PathFinder(path , newrows,newcols , opt ,visited , ans);
        opt.pop_back();
    }

    // Going Left
    newrows = rows;
    newcols = cols-1;
    if(IsSafeToGO(path , newrows, newcols,visited , ans)){
        opt.push_back('L');
        PathFinder(path , newrows,newcols , opt ,visited , ans);
        opt.pop_back();
    }
    
    visited[rows][cols] = 0;
    
}

vector<string> RatRoute(vector<vector<int>>& path , int size){

    // size is sent because a n x n matrix is sent so rows == cols

    int rows = size-1;
    int columns = size-1;

    
    string opt;
    vector<string> ans;

    // checking if first and last cell is not blocked
    if(path[rows][columns] == 0 || path[0][0] == 0 ) return ans;

    // // FOR ONLY DOWN AND RIGHT ALLOWRD
    // NoOfRoutes(path , rows ,columns, opt) ;
    
    // FOR ALL DIRECTIONS

    // 1st create a vector which stores the visited mark of movement
    vector<vector<int>> visited  = path;

    // 2nd mark all visited - 0
    for(int i = 0 ; i <= rows ; i++){
        for(int j = 0 ; j <= columns ; j++){
            visited[i][j] = 0;
        }
    }
    // 3rd calling func
    PathFinder(path , 0,0 , opt,visited , ans);

    // 4th Sort the vector to return in lexicographically increasing order. 
    sort(ans.begin() , ans.end());

    // 5th - final return the ans vector
    return ans;
} 

int main() {

    vector<vector<int>> path = {{1, 0, 0, 0},
                                {1, 1, 0, 1}, 
                                {1, 1, 0, 0},
                                {0, 1, 1, 1}};

    // vector<vector<int>> path = {{1, 1, 1 },{1, 0, 1 },{1, 0, 1}};

    // vector<vector<int>> path = {{1, 0, 1, 0},
    //                             { 0, 0, 1, 1},
    //                             { 0, 1, 0, 1},
    //                             { 0, 0, 1, 1}};


    int rows = path.size(); // for 4X4 vector , rows is 4 
    int columns = path[0].size();

    vector<string> LocalAnswer = RatRoute(path , rows);
    printAr(LocalAnswer);

    return 0;

}