#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void backtrack(string currentNum, int currentSwap, unordered_set<string> visited[], int& maxNum, int maxSwap) {
    // base case
    if(currentSwap == maxSwap){
        maxNum = max(maxNum, stoi(currentNum));
        return;
    }
    
    // pruning
    if(visited[currentSwap].count(currentNum)) return;
    else visited[currentSwap].insert(currentNum);
    
    // repeat
    int len = currentNum.size();
    for(int i = 0; i < len-1; i++){
        for(int j = i+1; j < len; j++){
            swap(currentNum[i], currentNum[j]);
            backtrack(currentNum, currentSwap + 1, visited, maxNum, maxSwap);
            swap(currentNum[i], currentNum[j]);
        }
    }
}

void solve(int tc){
    cout << "#" << tc << " ";
    
    string number;
    cin >> number;
    
    int maxSwap;
    cin >> maxSwap;
    
    int maxNum = 0;
    unordered_set<string> visited[11];
    
    backtrack(number, 0, visited, maxNum, maxSwap);
    cout << maxNum << "\n";
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	int test_case;
	int T;
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        solve(test_case);
	}
	return 0;
}