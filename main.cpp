#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;

ll n;
vl T, P;
vl dp;

ll solve(ll from) {
  if (from >= n) return 0;

  if (dp[from] < 0) {
    dp[from] = 0;
    if (from + T[from] <= n) {
      dp[from] = max(solve(from + 1), P[from] + solve(from + T[from]));
    } else {
      dp[from] = solve(from + 1);
    }
  }

  return dp[from];
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n;
  T = vl(n + 1);
  P = vl(n + 1);
  for (auto i = 0; i < n; ++i) {
    cin >> T[i] >> P[i];
  }
  dp = vl(n + 1, -1);
  dp[n] = 0;

  cout << solve(0);

  return 0;
}