#include <bits/stdc++.h>
#define MAX 100000 + 10
using namespace std;

int main(){

    int t;

    scanf("%d", &t);

    int n,k;

    while(t--){

        scanf("%d %d", &n, &k);

        int d[MAX];
        int pesos[MAX];
        int dp[MAX];

        memset(pesos,0,sizeof pesos);
        memset(dp, 0, sizeof dp);

        for ( int i = 0; i < n; i++ ){

            scanf("%d", &d[i]);
        }

        int aux;

        for ( int i = 0; i < n; i++ ){

            scanf("%d", &aux);

            pesos[d[i]] = max(pesos[d[i]], aux);
        }

        int max_current = pesos[0];

        for ( int i = 0; i < d[n-1] + 1; i++ ){

            if ( i - k >= 0 ){

                max_current = max(max_current, pesos[i] + dp[i-k]);
            }else{

                max_current = max(max_current, pesos[i]);
            }

            dp[i] = max_current;
        }

        printf("%d\n", max_current);
    }

    return 0;
}

// #include <bits/stdc++.h>
// #define debug(x) cout << #x " = " << (x) << endl
// #define endl '\n'

// using namespace std;

// const int MN = 1000 * 1000 + 10;

// int main() {
//   ios_base::sync_with_stdio(false);cin.tie(NULL);
//   int tc; cin >> tc;
//   while (tc--) {
//     int n, k;
//     cin >> n >> k;
//     vector<int> dp(MN), r(MN), p(MN);
//     vector<int> t(n);
//     for (int i = 0; i < n; ++i) {
//       cin >> t[i];
//       r[t[i]] = 1;
//     }
//     for (int i = 0; i < n; ++i) {
//       int q; cin >> q;
//       p[t[i]] = q;
//     }

//     for (int i = n+n; i >= 0; --i) {
//       dp[i] = dp[i + 1];
//       if (r[i] && i + k < MN)
//         dp[i] = max(dp[i], p[i] + dp[i + k]);
//     }
//     cout << dp[0] << endl;
//   }

//   return 0;
// }