/**
 * Given an array, answer multiple queries where each query provides a range [L, R], and we need to find the sum of elements in that range.
*/


#include <bits/stdc++.h>
using namespace std;

struct Query {
    int l, r, idx;
};

bool compare(Query &a, Query &b) {
    int block_a = a.l / sqrtN;
    int block_b = b.l / sqrtN;
    if (block_a != block_b) 
        return block_a < block_b;
    return a.r < b.r;
}

class MoAlgorithm {
public:
    MoAlgorithm(int n, int q, vector<int>& arr, vector<Query>& queries) 
        : n(n), q(q), arr(arr), queries(queries) {
        answers.resize(q);
        sqrtN = sqrt(n); // sqrt decomposition block size
    }
    
    void solve() {
        sort(queries.begin(), queries.end(), compare);
        int currentL = 0, currentR = -1;
        int currentSum = 0;
        
        for (auto &query : queries) {
            int L = query.l;
            int R = query.r;
            int idx = query.idx;

            // Move the current range to the query's range [L, R]
            while (currentR < R) currentSum += arr[++currentR];
            while (currentR > R) currentSum -= arr[currentR--];
            while (currentL < L) currentSum -= arr[currentL++];
            while (currentL > L) currentSum += arr[--currentL];
            
            // Store the result for this query
            answers[idx] = currentSum;
        }
    }
    
    void printAnswers() {
        for (int answer : answers) {
            cout << answer << "\n";
        }
    }

private:
    int n, q, sqrtN;
    vector<int>& arr;
    vector<Query>& queries;
    vector<int> answers;
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    
    vector<Query> queries(q);
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        queries[i] = {l - 1, r - 1, i}; // converting to 0-indexed
    }
    
    MoAlgorithm mo(n, q, arr, queries);
    mo.solve();
    mo.printAnswers();

    return 0;
}
