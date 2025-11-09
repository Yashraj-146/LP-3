#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Knapsack {
    public:
    int knapsack(int W, vector<int>& wt, vector<int>& val, int n) {
        vector<vector<int> > dp(n + 1, vector<int>(W + 1, 0));

        for(int i = 1; i <= n; i++) {
            for(int w = 1; w <= W; w++) {
                int notTake = dp[i-1][w];
                int take = INT_MIN;

                if(wt[i-1] <= w) {
                    take = val[i-1] + dp[i-1][w - wt[i-1]];
                }
                dp[i][w] = max(take, notTake);
            }
        }
        return dp[n][W];
    }

    void solve() {
        int n, W;
        cout<<"Enter number of items: ";
        cin>>n;

        vector<int> wt(n), val(n);
        cout<<"Enter values of items: "<<endl;
        for(int i = 0; i < n;i++) {
            cin>>val[i];
        }
        cout<<"Enter weights of items: "<<endl;
        for(int i = 0; i < n; i++) {
            cin >> wt[i];
        }

        cout<<"Enter knapsack total weight: ";
        cin>>W;

        cout<<"Max value in knapsack is = "<<knapsack(W, wt, val, n)<<endl;
    }
};

int main() {
    Knapsack k;
    k.solve();

    return 0;
}
