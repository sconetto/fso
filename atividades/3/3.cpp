#include <bits/stdc++.h>
#define MAX 1000000

using namespace std;

void print_q(queue<int> fq) {
  while (!fq.empty()){
		cout << " " << fq.front();
		fq.pop();
	}
	cout<<endl;
  return;
}

int main(int argc, char const *argv[]) {
  // ios::sync_with_stdio(false);
  // cin.tie(NULL);
  int n;
  // cin >> n;
  scanf("%d", &n);
  vector<long> p(n);
  vector<pair<int, int>> results;
  for (size_t i = 0; i < n; i++)
    // cin >> p[i];
    scanf("%ld", &p[i]);
  
  int q(0);
  while(scanf("%d", &q) != EOF) {
    queue<int> fq;
    int pf(0);
    bitset<MAX> in;
    in.reset();
    if (q == 0)
      continue;
    for (size_t i = 0; i < n; i++) {
      if (fq.size() < q) {
        // ainda tem espaço na fila
        if (in[p[i]]) {
          // está na fila
        } else {
          pf++;
          in.flip(p[i]);
          fq.push(p[i]);
        }
      } else {
        // a fila está cheia
        if (in[p[i]]) {
          // está na fila
        } else {
          pf++;
          in.flip(fq.front());
          fq.pop();
          in.flip(p[i]);
          fq.push(p[i]);
        }
      }
    }
    cout << q << ' ' << pf << endl;
    results.push_back(make_pair(q, pf));
  }
  sort(results.begin(), results.end());
  int an(0), faults(MAX);
  for (size_t i = 0; i < results.size(); i++) {
    // cout << results[i].first << " " << results[i].second << endl;
    if (results[i].second < faults) {
      faults = min(faults, results[i].second);
    } else if (results[i].second > faults) {
      an = 1;
    }
  }
  if (an)
    cout << "Belady detectado" << endl;
  else
    cout << "Sem anomalia" << endl;
  return 0;
}
