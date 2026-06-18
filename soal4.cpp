#include <iostream>
#include <vector>

using namespace std;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int R, C;
int FR, FC;
int totalPaths = 0;

// Fungsi rekursif DFS
void solveDFS(int r, int c, vector<vector<int>>& grid) {
    if (r == FR && c == FC) {
        totalPaths++;
        return;
    }

    // Tandai sedang dikunjungi
    grid[r][c] = -1; 

    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr >= 0 && nr < R && nc >= 0 && nc < C) {
            // Cukup periksa apakah nilainya 0 (jalan yang valid dan belum dilewati)
            if (grid[nr][nc] == 0) {
                solveDFS(nr, nc, grid);
            }
        }
    }

    // BACKTRACKING: Kembalikan ke jalan yang bisa dilewati
    grid[r][c] = 0; 
}

int main() {
    if (!(cin >> R >> C)) return 0;

    vector<vector<int>> grid(R, vector<int>(C));

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }

    int SR, SC;
    cin >> SR >> SC >> FR >> FC;

    // Memulai DFS
    solveDFS(SR, SC, grid);

    cout << totalPaths << "\n";

    return 0;
}