/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        int m = image.size();
        int n = image[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,0));
        queue<pair<int,int>>t;
        visited[sr][sc] = true;
        t.push(make_pair(sr,sc));
        while(!t.empty())
        {
            pair<int,int>q;
            q=t.front();
            t.pop();
            if(q.first + 1 < m && image[q.first+1][q.second] == image[sr][sc] && visited[q.first+1][q.second] == false)
            {
                visited[q.first+1][q.second] = true;
                image[q.first+1][q.second] = newColor;
                t.push(make_pair(q.first+1,q.second));
            }
            if(q.second + 1 < n && image[q.first][q.second+1] == image[sr][sc] && visited[q.first][q.second + 1] == false)
            {
                visited[q.first][q.second + 1] = true;
                image[q.first][q.second + 1] = newColor;
                t.push(make_pair(q.first,q.second + 1));
            }
            if(q.first - 1 >= 0 && image[q.first-1][q.second] == image[sr][sc] && visited[q.first-1][q.second] == false)
            {
                visited[q.first - 1][q.second] = true;
                image[q.first - 1][q.second] = newColor;
                t.push(make_pair(q.first-1,q.second));
            }
            if(q.second - 1 >= 0 && image[q.first][q.second-1] == image[sr][sc] && visited[q.first][q.second-1] == false)
            {
                visited[q.first][q.second - 1] = true;
                image[q.first][q.second - 1] = newColor;
                t.push(make_pair(q.first,q.second -1));
            }
        }
        image[sr][sc] = newColor;
        return image;
    }
