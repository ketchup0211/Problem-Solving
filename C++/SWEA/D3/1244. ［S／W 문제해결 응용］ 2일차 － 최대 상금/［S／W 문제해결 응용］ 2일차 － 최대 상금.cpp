#include<iostream>
#include<bits/stdc++.h>

using namespace std;
void solve(int tc){
    cout << "#" << tc << " ";
    
    string number;
    cin >> number;
    
    int maxSwap;
    cin >> maxSwap;
    
    int maxNum = 0;
    unordered_set<string> visited[11];
    auto backtrack = [&](auto& self, string currentNum, int currentSwap) -> void {
        //	base case
        if(currentSwap == maxSwap){
            maxNum = max(maxNum, stoi(currentNum));
            return;
        }
        
        //pruning
        if(visited[currentSwap].count(currentNum)) return;
        else visited[currentSwap].insert(currentNum);
        
        //repeat
        int len = number.size();
        for(int i = 0; i < len-1; i++){
            for(int j = i+1; j < len; j++){
                swap(currentNum[i], currentNum[j]);
                self(self, currentNum, currentSwap+1);
                swap(currentNum[i], currentNum[j]);
            }
        }
    };
    backtrack(backtrack, number, 0);
    cout << maxNum << "\n";
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	int test_case;
	int T;
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
        solve(test_case);
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			 이 부분에 여러분의 알고리즘 구현이 들어갑니다.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}