//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

/* ================================================================= CODE SOLUTION ==================================================== */
class Solution {
  public:
  
    bool isSafe(int new_x, int new_y, vector<vector<int>> &mat, vector<vector<bool>> &visited, int n){
        // out of bounds 
        if(new_x < 0 || new_y < 0 || new_x >= n || new_y >= n){
            return false;
        }
        
        // already visited
        if(visited[new_x][new_y] == true){
            return false;
        }
        
        // blocked movement
        if(mat[new_x][new_y] == 0){
            return false;
        }
        
        // remaining valid cases
        return true;
    }
  
    void solve(vector<vector<int>> &mat, vector<vector<bool>> &visited, int n, vector<string> &ans, int source_x, int source_y, int destination_x, int destination_y, string output){
        /* base case */
        if(source_x == destination_x && source_y == destination_y){
            // reached destination
            ans.push_back(output);
            return;
        }
        
        /* recursion case: up, down, left, right */
        // case-1: up- (i-1, j)
        int new_x = source_x - 1;
        int new_y = source_y;
        if(isSafe(new_x, new_y, mat, visited, n)){
            visited[new_x][new_y] = true;
            solve(mat,visited,n,ans,new_x,new_y,destination_x,destination_y,output+"U");
            // backtracking: we have to mark the visited part back as false
            visited[new_x][new_y] = false;
        }
        
        // case-2: down- (i+1, j)
        new_x = source_x + 1;
        new_y = source_y;
        if(isSafe(new_x, new_y, mat, visited, n)){
            visited[new_x][new_y] = true;
            solve(mat,visited,n,ans,new_x,new_y,destination_x,destination_y,output+"D");
            // backtracking: we have to mark the visited part back as false
            visited[new_x][new_y] = false;
        }
        
        // case-3: left- (i, j-1)
        new_x = source_x;
        new_y = source_y-1;
        if(isSafe(new_x, new_y, mat, visited, n)){
            visited[new_x][new_y] = true;
            solve(mat,visited,n,ans,new_x,new_y,destination_x,destination_y,output+"L");
            // backtracking: we have to mark the visited part back as false
            visited[new_x][new_y] = false;
        }
        
        // case-4: right- (i, j+1)
        new_x = source_x;
        new_y = source_y+1;
        if(isSafe(new_x, new_y, mat, visited, n)){
            visited[new_x][new_y] = true;
            solve(mat,visited,n,ans,new_x,new_y,destination_x,destination_y,output+"R");
            // backtracking: we have to mark the visited part back as false
            visited[new_x][new_y] = false;
        }
    }  
  
    vector<string> findPath(vector<vector<int>> &mat) {
        /* size of maze */
        int n = mat.size();
        
        /* vector creation */
        vector<string> ans;
        vector<vector<bool> > visited(n, vector<bool>(n,0)); // 2-d array
        
        /* source and destination coordinates */
        int source_x = 0;
        int source_y = 0;
        int destination_x = n-1;
        int destination_y = n-1;
        
        /* the place where rat is at the start */
        visited[0][0] = true;
        
        /* answer string */
        string output = "";
        
        /* importance case: rat starting position is blocked */
        if(mat[0][0] == 0){
            return ans;
        }
        
        /* calling main function */
        solve(mat, visited, n, ans, source_x, source_y, destination_x, destination_y, output);
        return ans; // ans has to be taken 'by reference': to affect original value
    }
};

/* ================================================================= CODE SOLUTION ==================================================== */

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        vector<string> result = obj.findPath(mat);
        sort(result.begin(), result.end());

        if (result.empty())
            cout << "[]";
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
