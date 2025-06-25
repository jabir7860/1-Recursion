class Solution {
public:
    bool fun(int i, int j, vector<vector<char>>& board, string& word, int index, int n, int m) {
        if (index == word.length()) return true;

        if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] != word[index]) return false;

        char temp = board[i][j];  // store current character
        board[i][j] = '#';        // mark as visited

        bool found = fun(i+1, j, board, word, index+1, n, m) ||
                     fun(i-1, j, board, word, index+1, n, m) ||
                     fun(i, j+1, board, word, index+1, n, m) ||
                     fun(i, j-1, board, word, index+1, n, m);

        board[i][j] = temp;  // unmark (backtrack)
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (fun(i, j, board, word, 0, n, m)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
