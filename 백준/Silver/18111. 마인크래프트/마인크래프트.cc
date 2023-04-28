#include <iostream>

using namespace std;

int N, M, B;
int map[257] = {0,};

int main() {
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N >> M >> B;    

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int n;
            cin >> n;
            map[n]++;
        }
    }

    long long ans_time = 99999999;
    long long time;
    long long ans_height = 0;
    long long sum_block, sub_block;

    for (int i = 0; i < 257; i++) {
        sum_block = 0;
        sub_block = 0;

        for (int j = 0; j < i; j++) {
            sum_block +=  ((i - j) * map[j]);
        }
        for (int j = i + 1; j < 257; j++) {
            sub_block += ((j - i) * map[j]);
        }

        if (sum_block <= sub_block + B) {
            time = sum_block + sub_block * 2;
            if (time <= ans_time) {
                ans_time = time;
                ans_height = i;
            }
        }
    }

    cout << ans_time << " " << ans_height;
}