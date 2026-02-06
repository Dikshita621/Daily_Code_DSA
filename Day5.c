/*Problem: A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.

Input:
- First line: integer p (number of entries in server log 1)
- Second line: p sorted integers representing arrival times from server 1
- Third line: integer q (number of entries in server log 2)
- Fourth line: q sorted integers representing arrival times from server 2)

Output:
- Print a single line containing all arrival times in chronological order, separated by spaces

Example:
Input:
5
10 20 30 50 70
4
15 25 40 60

Output:
10 15 20 25 30 40 50 60 70

Explanation: Compare the next unprocessed arrival time from both logs and append the earlier one to the final log until all entries are processed*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int p;
    cin >> p;
    vector<int> log1(p);
    for(int i = 0; i < p; i++) {
        cin >> log1[i];
    }
    int q;
    cin >> q;
    vector<int> log2(q);
    for(int i = 0; i < q; i++) {
        cin >> log2[i];
    }
    
    vector<int> merged;
    int i = 0, j = 0;
    while(i < p && j < q) {
        if(log1[i] <= log2[j]) {
            merged.push_back(log1[i++]);
        } else {
            merged.push_back(log2[j++]);
        }
    }
    while(i < p) merged.push_back(log1[i++]);
    while(j < q) merged.push_back(log2[j++]);
    
    for(int k = 0; k < merged.size(); k++) {
        cout << merged[k];
        if(k < merged.size() - 1) cout << " ";
    }
    cout << endl;
    return 0;
}
