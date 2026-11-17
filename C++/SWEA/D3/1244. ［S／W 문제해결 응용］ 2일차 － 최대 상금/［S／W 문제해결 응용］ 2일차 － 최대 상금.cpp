#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

// 1. max_answer에 참조자(&) 추가, visited를 배열([])로 받음
void backtrack(string current, int count, int max_swap, int& max_answer, unordered_set<string> visited[]) {
    if (count == max_swap) {
        max_answer = max(max_answer, stoi(current));
        return;
    }
    
    // 2. C++14 환경에 맞춰 .contains() 대신 .count() 사용
    if (visited[count].count(current)) return;
    visited[count].insert(current);
    
    int len = current.size();
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            swap(current[i], current[j]);
            // 3. 빠진 인자와 세미콜론 추가
            backtrack(current, count + 1, max_swap, max_answer, visited);
            // 4. 오타 수정 (currnet -> current)
            swap(current[i], current[j]);
        }
    }
}

void solve(int tc) {
    string nums = "";
    int max_swap;
    cin >> nums >> max_swap;
    
    unordered_set<string> visited[11];
    int max_answer = 0; // 최댓값을 저장할 변수
    
    backtrack(nums, 0, max_swap, max_answer, visited);
    
    // 5. 문제 출력 형식에 맞게 출력
    cout << "#" << tc << " " << max_answer << "\n";
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int test_case;
    int T;
    cin >> T;
    
    for (test_case = 1; test_case <= T; ++test_case) {
        solve(test_case);
    }
    return 0;
}