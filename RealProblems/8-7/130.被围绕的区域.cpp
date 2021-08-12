/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class Solution {
public:
    int row,col;
    void dfs(vector<vector<char>>& board,int x,int y){
        if(x<0||x>=row||y<0||y>=col||(board[x][y]!='O')){
            return;
        }
        board[x][y]='A';
        dfs(board,x+1,y);
        dfs(board,x-1,y);
        dfs(board,x,y+1);
        dfs(board,x,y-1);
    }
    void solve(vector<vector<char>>& board) {
        row=board.size();
        if(row==0) return ;
        col=board[0].size();
        for(int i=0;i<row;i++){
            dfs(board,i,0);
            dfs(board,i,col-1);
        }
        for(int i=1;i<col-1;i++){
            dfs(board,0,i);
            dfs(board,row-1,i);
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]=='A'){
                    board[i][j]='O';
                }else if(board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};
// @lc code=end

