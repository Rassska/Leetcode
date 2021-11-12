class Solution {
public:
    
    void flip (std::vector<std::vector<char>>& board, int i, int j) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != 'O') {
            return;
        } 
        if (board[i][j] == 'O') 
            board[i][j] = '$';
        
        flip(board, i + 1, j);
        flip(board, i - 1, j);
        flip(board, i, j + 1);
        flip(board, i, j - 1);
        
    }
    
    void solve(vector<vector<char>>& board) {
        
        for (std::size_t i = 0; i < board.size(); i++) {
            for (std::size_t j = 0; j < board[i].size(); j++) {
                if ((i == 0 || i == board.size() - 1 || j == 0 || j == board[i].size() - 1) && board[i][j] == 'O') {
                    flip(board, i, j);
                }
            }
        }
         for (std::size_t i = 0; i < board.size(); i++) {
            for (std::size_t j = 0; j < board[i].size(); j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
        
        for (std::size_t i = 0; i < board.size(); i++) {
            for (std::size_t j = 0; j < board[i].size(); j++) {
                if (board[i][j] == '$') {
                    board[i][j] = 'O';
                }
            }
        }
        
    }
};