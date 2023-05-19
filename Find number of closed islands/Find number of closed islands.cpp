//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    int dx[4] = {1,-1,0,0}; int dy[4] = {0,0,1,-1};
    
    bool isValid(int r,int c, int n, int m){
      
        if(r>=0 and c>=0 and r<n and c<m) return true; 
        return false;
    }
    
  
    void dfs(vector<vector<int>>& mat, int &n, int &m,vector<vector<bool>>& vis,int r,int c){
        
        for(int i=0;i<4;++i){
            int nr = r + dx[i], nc = c + dy[i];
          
            if(isValid(nr,nc,n,m) and !vis[nr][nc] and mat[nr][nc]==1){
                vis[nr][nc] = true;
                dfs(mat,n,m,vis,nr,nc);
            }
        }
    }
    
    int closedIslands(vector<vector<int>>& mat, int N, int M) {
        // Code here
        vector<vector<bool>> vis(N,vector<bool>(M,false));
      
        for(int i=0;i<M;++i){
            if(mat[0][i]==1 and !vis[0][i])
                dfs(mat,N,M,vis,0,i);
                
            if(mat[N-1][i]==1 and !vis[N-1][i])
                dfs(mat,N,M,vis,N-1,i);
        }
        
        for(int i=0;i<N;++i){
            if(mat[i][0]==1 and !vis[i][0])
                dfs(mat,N,M,vis,i,0);
                
            if(mat[i][M-1]==1 and !vis[i][M-1])
                dfs(mat,N,M,vis,i,M-1);
        }
        
        int cnt = 0;
        for(int i=1;i<N-1;++i){
            for(int j=1;j<M-1;++j){
                if(mat[i][j]==1 and !vis[i][j]){
                    dfs(mat,N,M,vis,i,j);
                    ++cnt;
                }
            }
        }
        return cnt;
        
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends
