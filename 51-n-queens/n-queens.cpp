class Solution {
public:
  bool isSafe(vector<string>&board,int n,int row,int col)
{
    //Horizontal
    for(int i = 0;i<n;i++)
    {
        if(board[row][i] == 'Q')

            return false;
    }
    //vertical
    for(int i = 0;i<row;i++)
    {
        if(board[i][col] == 'Q')
        return false;
    }
    //left diagonal

    for(int i = row,j = col;i>=0 && j>=0;i--,j--)
    {
        if(board[i][j] == 'Q')return false;
    }
    //right diagonals
    for(int i = row,j=col;i>=0&&j<n;i--,j++)
    {
        if(board[i][j] == 'Q')return false;
    }
    return true;
}
   void nQueens(vector<string>&board,int n,vector<vector<string>>&ans,int row)
   {
        if(row == n)
        {
            ans.push_back(board);
            return;
        }
        for(int j = 0; j<n;j++)
        {
            if(isSafe(board,n,row,j))
            {
                board[row][j] = 'Q';
                nQueens(board,n,ans,row+1);
                board[row][j] = '.';

            }
        }
   }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        vector<vector<string>>ans;
        nQueens(board,n,ans,0);
        return ans;
    }
};