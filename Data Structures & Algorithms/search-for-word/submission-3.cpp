class Solution {
public:
    int m, n;

    bool search(int i, int j, vector<vector<char>>& board,
                string &word, int len) {

        if(len == word.size()) return true;

        int dx[] = {0, -1, 0, 1};
        int dy[] = {-1, 0, 1, 0};

        for(int k = 0; k < 4; k++) {

            int x = i + dx[k];
            int y = j + dy[k];

            if(x < 0 || x >= m || y < 0 || y >= n)
                continue;

            if(board[x][y] == word[len]) {

                char btrack = board[x][y];

                board[x][y] = '#';

                if(search(x, y, board, word, len + 1))
                    return true;

                board[x][y] = btrack;
            }
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {

        m = board.size();
        n = board[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(board[i][j] == word[0]) {

                    char btrack = board[i][j];
                    board[i][j] = '#';

                    if(search(i, j, board, word, 1))
                        return true;

                    board[i][j] = btrack;
                }
            }
        }

        return false;
    }
};