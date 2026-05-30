class Solution {
public:
    vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};

    int dfs(vector<vector<int>>& grid, int i, int j, int n, int m) {

        // Out of boundary contributes 1 to perimeter
        if(i < 0 || j < 0 || i >= n || j >= m)
            return 1;

        // Water contributes 1 to perimeter
        if(grid[i][j] == 0)
            return 1;

        // Already visited contributes 0
        if(grid[i][j] == -1)
            return 0;

        grid[i][j] = -1;

        int perimeter = 0;

        for(auto &d : dir) {
            perimeter += dfs(grid, i + d[0], j + d[1], n, m);
        }

        return perimeter;
    }

    int islandPerimeter(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 1) {
                    return dfs(grid, i, j, n, m);
                }
            }
        }

        return 0;
    }
};