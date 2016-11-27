std::vector<std::vector<std::vector<bool>>> financialCrisis(std::vector<std::vector<bool>> roadRegister) {
  using namespace std;
  int N = roadRegister.size();
  vector<vector<vector<bool>>> res(N, vector<vector<bool>>(N-1, vector<bool>(N-1, false)));
  for(int i=0;i<N;i++){
    for(int r=0;r<N;r++){
      for(int c=0;c<N;c++){
	if(r==i || c==i) continue;
	int tr = r<i ? r : r-1;
	int tc = c<i ? c : c-1;
	res[i][tr][tc] = roadRegister[r][c];
      }
    }
  }
  return res;
}
