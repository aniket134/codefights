std::vector<std::vector<int>> roadsBuilding(int cities, std::vector<std::vector<int>> roads) {
  using namespace std;
  vector<vector<bool>> matrix(cities, vector<bool>(cities, false));
  for(auto road: roads){
    matrix[road[0]][road[1]] = true;
    matrix[road[1]][road[0]] = true;
  }

  vector<vector<int>> res;
  for(int i=0;i<cities;i++){
    for(int j=0;j<cities;j++){
      if(i!=j && !matrix[j][i] && !matrix[i][j]){
	res.push_back({i, j});
	matrix[i][j] = true;
	matrix[j][i] = true;
      }
    }
  }
  return res;
}
