bool namingRoads(std::vector<std::vector<int>> roads) {
  using namespace std;
  map<int,map<int,bool>> m;
  for(auto road: roads){
    int r_id = road[2];
    m[road[0]][r_id] = true;
    m[road[1]][r_id] = true;

    if(m[road[0]].find(r_id-1) != m[road[0]].end()) return false;
    if(m[road[0]].find(r_id+1) != m[road[0]].end()) return false;
    if(m[road[1]].find(r_id-1) != m[road[1]].end()) return false;
    if(m[road[1]].find(r_id+1) != m[road[1]].end()) return false;
  }
  return true;
}
