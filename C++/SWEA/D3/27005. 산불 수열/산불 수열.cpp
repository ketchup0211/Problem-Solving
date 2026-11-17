#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// 산불 수열의 항들을 저장할 배열 (N이 최대 1000이므로 1005 크기)
int A[1005];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int test_case;
	int T;
	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	//freopen("input.txt", "r", stdin);
	cin >> T;

	// --- [1] 산불 수열 미리 구하기 (Pre-computation) ---
	// 초기값 설정
	A[0] = 1;
	A[1] = 1;

	// i = 2부터 1000까지 A[i] 값을 차례대로 채워나갑니다.
	for (int i = 2; i <= 1000; ++i) {
		int candidate = 1; // 1부터 시작해서 조건에 맞는 최소의 양의 정수를 찾습니다.

		while (true) {
			bool isValid = true;

			// 가능한 모든 간격 k에 대해 검사
			// i - 2*k >= 0 이어야 하므로 2*k <= i 조건 만족
			for (int k = 1; 2 * k <= i; ++k) {
				// { A[i-2k], A[i-k], candidate } 가 등차수열을 이루는지 확인
				// 등차수열 조건: candidate - A[i-k] == A[i-k] - A[i-2k]
				// 이항하면: candidate == 2 * A[i-k] - A[i-2k]
				if (candidate == 2 * A[i - k] - A[i - k * 2]) {
					isValid = false; // 등차수열을 이루므로 이 candidate는 금지!
					break;
				}
			}

			if (isValid) {
				A[i] = candidate; // 금지 조건에 걸리지 않은 최소 수 확정
				break;
			}
			candidate++; // 다음 수 도전
		}
	}

	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{

		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   이 부분에 여러분의 알고리즘 구현이 들어갑니다.
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////

		int n;
		cin >> n;
		cout << A[n] << "\n";

	}
	return 0; //정상종료시 반드시 0을 리턴해야합니다.
}