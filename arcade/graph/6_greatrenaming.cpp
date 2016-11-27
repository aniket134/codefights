std::vector<std::vector<bool>> greatRenaming(std::vector<std::vector<bool>> roadRegister) {
  using namespace std;
  int N = roadRegister.size();
  vector<vector<bool>> res(N, vector<bool>(N, false));
  for(int r=0;r<N;r++){
    for(int c=0;c<N;c++){
      int tr = r==N-1 ? 0 : r+1;
      int tc = c==N-1 ? 0 : c+1;
      res[tr][tc] = roadRegister[r][c];
    }
  }
  return res;
}
