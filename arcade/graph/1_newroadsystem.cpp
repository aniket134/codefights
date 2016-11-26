bool newRoadSystem(std::vector<std::vector<bool>> roadRegister) {
  using namespace std;
  vector<int> counts(roadRegister.size(),0);
  for(int i=0;i<roadRegister.size();i++){
    for(int j=0;j<roadRegister[0].size();j++){
      if(roadRegister[i][j]){
	counts[i]--;
	counts[j]++;
      }
    }
  }
  for(int i=0;i<counts.size();i++){
    if(counts[i]!=0) return false;
  }
  return true;
}
