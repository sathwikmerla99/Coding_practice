/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

//BST IMPLEMENTATION
#include <iostream>

using namespace std;


    void dfs(vector<vector<int>>& graph,vector<vector<int>>&paths,vector<int>path,int src, int dst)
    {
        path.push_back(src);
        if(src == dst)
        {
            paths.push_back(path);
            return;
        }
        
        for(auto child = graph[src].begin(); child!=graph[src].end(); child++)
        {
            dfs(graph,paths,path,*child,dst);
        }
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        vector<vector<int>>paths;
        vector<int>path;
        int n = graph.size();
        dfs(graph,paths,path,0,n-1);
     return paths;   
    }
