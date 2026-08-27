/*
 * @lc app=leetcode id=827 lang=cpp
 *
 * [827] Making A Large Island
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std  ; 
class DisjointSet{
    
public : 
    vector<int> rank , parent , size ; 
    DisjointSet(int n ){
        rank.resize(n+1 , 0) ; 
        parent.resize(n+1) ; 
        size.resize(n+1  , 1 )  ; 

        for(int i =0 ;i <= n  ; i++){
            parent[i] = i ; 
        }
    }

    int findUltimatePar(int node) {
        if(node == parent[node] ){
            return node ; 
        }
        return parent[node] = findUltimatePar(parent[node]) ; 
    }

    void UnionByRank(int u , int v){
        int ult_u = findUltimatePar(u) ; 
        int ult_v = findUltimatePar(v) ; 
        if(ult_u == ult_v){
            return ; 
        }

        if(rank[ult_u] < rank[ult_v]){
            parent[ult_u] = ult_v ; 
        }
        else if(rank[ult_u] > rank[ult_v]){
            parent[ult_v] =  ult_u ; 
        }

        else{
            parent[ult_u] = ult_v ; 
            rank[ult_v]++ ; 
        }
    }

    void UnionBySize(int u , int v ){
        int ult_u = findUltimatePar(u) ; 
        int ult_v = findUltimatePar(v) ; 

        if(ult_u == ult_v) return ; 

        if(size[ult_u]  >size[ult_v]){
            parent[ult_v]  = ult_u; 
            size[ult_u] += size[ult_v] ; 

        }else if(size[ult_u]   < size[ult_v]){
            parent[ult_u]  = ult_v ; 
            size[ult_v] += size[ult_u] ; 
        }
        else {
        // Handles both strictly smaller and equal sizes
        parent[ult_u] = ult_v;
        size[ult_v] += size[ult_u];
        }
    }
}; 
class Solution {

public:
    bool isvalid(int row , int col  , int n) {
        return row >= 0 && row <  n && col >=0 && col < n ; 
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size() ; 
        int delr[] = {-1 , 0 , 1 , 0 } ; 
        int delc[] = {0 , 1 , 0 , -1}  ; 
        DisjointSet ds(n*n) ; 
        for(int row = 0 ; row < n ; row++){
            for(int col = 0 ; col < n ; col++){
                if(grid[row][col] == 0) continue ; 
                for(int i = 0 ; i < 4 ; i++){
                    int nr = row + delr[i] ; 
                    int nc = col + delc[i] ; 
                    if(isvalid(nr , nc, n) && grid[nr][nc] ==1 ){
                        int node = row * n + col ; 
                        int adjnode = nr * n + nc  ; 
                        ds.UnionBySize(node , adjnode) ; 
                    } 
                } 
            }
        }

        int mx = 0 ; 
        for(int i = 0 ; i< n*n ; i++){
            mx = max(mx, ds.size[ds.findUltimatePar(i)]) ; 
        }
        for(int row =0  ; row < n ; row++){
            for(int col = 0 ; col < n ; col++){
                if(grid[row][col] == 1  ) continue; 
                unordered_set<int> components ;
                for(int i = 0 ; i< 4 ; i++){
                    int nr = row  + delr[i] ; 
                    int nc = col + delc[i] ;
                    if(isvalid(nr , nc , n) && grid[nr][nc] ==1 ){
                        int node = nr * n + nc ; 
                        components.insert(ds.findUltimatePar(node)) ; 
                    }
                }
                int totalsize = 1 ; 
                for(auto it : components){
                    totalsize += ds.size[it] ; 
                }
                mx = max(mx , totalsize) ; 
            }
        }

        

        return mx ; 
    }
};