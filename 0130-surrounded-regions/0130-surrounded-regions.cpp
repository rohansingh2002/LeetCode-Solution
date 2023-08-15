class Solution {
public:
     void dfs(int row, int col, vector<vector<int>>&vis, vector<vector<char>>board){
        vis[row][col] = 1;
        int n = board.size();
        int m = board[0].size();
        
        int r[] = {-1 ,0 ,1, 0};
        int c[] = {0, 1 ,0, -1};
        
        for(int i = 0; i < 4; i++){
            int nrow = row + r[i];
            int ncol = col + c[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && board[nrow][ncol] == 'O' && vis[nrow][ncol] == 0){
                dfs(nrow,ncol,vis,board);
            }
        }
        
        
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int i = 0; i < n; i++){
            if(vis[i][0] == 0 && board[i][0] == 'O'){
                dfs(i,0,vis,board);
            }
        }
        for(int i = 0; i < n; i++){
            if(vis[i][m-1] == 0 && board[i][m-1] == 'O'){
               dfs(i,m-1,vis,board);
            }
        }
        for(int j = 0; j < m; j++){
            if(vis[0][j] == 0 && board[0][j] == 'O'){
               dfs(0,j,vis,board);
            }
        }
        for(int j = 0; j < m; j++){
            if(vis[n-1][j] == 0 && board[n-1][j] == 'O'){
                dfs(n-1,j,vis,board);
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j =  0; j < m; j++){
              if(vis[i][j] != 1 && board[i][j] == 'O'){
                  board[i][j] = 'X';
              }    
            }
        }
    }
};