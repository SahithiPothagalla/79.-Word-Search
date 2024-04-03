class Solution {
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int k) {
        int n = board.size();
        int m = board[0].size();
        
        if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] != word[k]) {
            return false;
        }
        
        if (k == word.size() - 1) {
            return true;
        }
        
        char temp = board[i][j];
        board[i][j] = ' ';  // Mark the current cell as visited
        
        bool found = dfs(board, word, i + 1, j, k + 1) ||
                     dfs(board, word, i - 1, j, k + 1) ||
                     dfs(board, word, i, j + 1, k + 1) ||
                     dfs(board, word, i, j - 1, k + 1);
        
        board[i][j] = temp;  // Restore the original value
        
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()) return false;

        int n = board.size();
        int m = board[0].size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0] && dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};
