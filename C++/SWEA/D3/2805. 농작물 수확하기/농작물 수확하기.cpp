#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void solve(int tc){
    int N;
    cin >> N;

    int middleIdx = N / 2;
    int sum = 0;
    
    char ch;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> ch;
            int cost = ch - '0';
            
            if (abs(i - middleIdx) + abs(j - middleIdx) <= middleIdx) {
                sum += cost;
            }
        }
    }
    
    cout << "#" << tc << " " << sum << "\n";
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    for(int tc = 1; tc <= T; tc++){
        solve(tc);
    }
    
    return 0;
}