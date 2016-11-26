bool efficientRoadNetwork(int n, std::vector<std::vector<int>> roads) {
  using namespace std;
  vector<vector<bool>> matrix(n, vector<bool>(n, false));
  vector<vector<int>> distances(n, vector<int>(n, 0));
  for(int i=0;i<roads.size();i++){
    matrix[roads[i][0]][roads[i][1]]=true;
    matrix[roads[i][1]][roads[i][0]]=true;
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(matrix[i][j]){
	distances[i][j]=1; distances[j][i]=1;
      }
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(i==j) continue;
      if(distances[i][j]==1){
	for(int k=0;k<n;k++){
	  if(matrix[j][k] && !matrix[i][k]){
	    distances[i][k] = 2; distances[k][i] = 2;
	  }
	}
      }
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(i==j) continue;
      if(distances[i][j]>2) return false;
      if(distances[i][j]==0) return false;
    }
  }
  // TLE
  // for(int i=0;i<n;i++){
  //     for(int j=0;j<n;j++){
  //         if(i==j || !matrix[i][j]) continue;
  //         distances[i][j] = 1; distances[j][i] = 1;
  //         dfs(j, i, 1, matrix, distances);
  //     }
  // }
  return true;
}

// void dfs(int city, int src, int len, std::vector<vector<bool>>& matrix, std::vector<vector<int>>& distances){
//     len = len+1;
//     for(int i=0;i<matrix.size();i++){
//         if(i==city || !matrix[city][i]) continue;
//         if(distances[i][src]>0 && distances[i][src]<len) continue;
//         distances[src][i] = len; distances[i][src] = len;
//         dfs(i, src, len, matrix, distances);
//     }
// }
