class Solution {
public:

    bool isValid(vector<vector<char>>& board, int x, int y, char c) {
        for (int i = 0; i < 9; i++) {
            if (board[i][y] == c) return false;
        }
        for (int j = 0; j < 9; j++) {
            if (board[x][j] == c) return false;
        }
        int smi = x / 3 * 3;
        int smj = y / 3 * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[smi + i][smi + j] == c) return false;
            }
        }
        return true;
    }

    void suduko(vector<vector<char>>& board, int i, int j) {

        if (i == board.size()) return;

        int nj = 0, ni = 0;
        if (j == board[0].size() - 1) {
            ni = i + 1;
            nj = 0;
        }
        else {
            nj = j + i;
            ni = i;
        }

        if (board[i][j] != '.') {
            suduko(board, ni, nj);
        }
        else {
            for (char c = '1'; c <= '9'; c++) {
                if (isValid(board, i, j, c)) {
                    board[i][j] = c;
                    suduko(board, ni, nj);
                    board[i][j] = '.';
                }
            }
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        suduko(board, 0, 0);
    }
};