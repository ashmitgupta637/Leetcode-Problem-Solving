class Solution {
private:
    bool valid(int nx, int ny, vector<string>& classroom) {
        int n = classroom.size();
        int m = classroom[0].size();

        return nx >= 0 && nx < n &&
               ny >= 0 && ny < m;
    }

public:
    using VB = vector<bool>;
    using VVB = vector<VB>;
    using VVVB = vector<VVB>;
    using VVVVB = vector<VVVB>;

    struct State {
        int row;
        int col;
        int energLeft;
        int collectedMask;
    };

    using vi = vector<int>;
    using vii = vector<vi>;

    vii directions = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };

    int minMoves(vector<string>& classroom, int energy) {

        int n = classroom.size();
        int m = classroom[0].size();

        int sx = 0;
        int sy = 0;

        int maxEnergy = energy;

        int litterbit[20][20];

        int littercnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                litterbit[i][j] = -1;

                if (classroom[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }
                else if (classroom[i][j] == 'L') {
                    litterbit[i][j] = littercnt++;
                }
            }
        }

        int allCollected = (1 << littercnt) - 1;

        if (littercnt == 0)
            return 0;

        // [row][col][energy][mask]
        VVVVB visited(
            n,
            VVVB(
                m,
                VVB(
                    maxEnergy + 1,
                    VB(1 << littercnt, false) // bitmask 
                )
            )
        );

        queue<State> q;

        q.push({sx, sy, maxEnergy, 0});  // intial store kr diya queu me

        visited[sx][sy][maxEnergy][0] = true;

        int moves = 0;

        while (!q.empty()) {

            int currsize = q.size();

            while (currsize--) {

                State curr = q.front();
                q.pop();

                if (curr.collectedMask == allCollected) {
                    return moves;
                }

                if (curr.energLeft == 0) {
                    continue;
                }

                for (auto& dir : directions) {

                    int nextRow = curr.row + dir[0];
                    int nextCol = curr.col + dir[1];

                    if (!valid(nextRow, nextCol, classroom))
                        continue;

                    char cell = classroom[nextRow][nextCol];

                    if (cell == 'X')
                        continue;

                    int nextEnergy = curr.energLeft - 1;
                    int nextcollectedMask = curr.collectedMask;

                    if (cell == 'R') {
                        nextEnergy = maxEnergy;
                    }
                    else if (cell == 'L') {
                        nextcollectedMask |=      // 'OR' kr diya uske baad bit ko 0 to 1 set kr diya  to collect the litter 
                            (1 << litterbit[nextRow][nextCol]);
                    }

                    if (!visited[nextRow][nextCol]
                                  [nextEnergy]
                                  [nextcollectedMask]) {

                        visited[nextRow][nextCol]
                               [nextEnergy]
                               [nextcollectedMask] = true;

                        q.push({
                            nextRow,
                            nextCol,
                            nextEnergy,
                            nextcollectedMask
                        });
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};