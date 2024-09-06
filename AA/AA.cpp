//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <ranges>
//using namespace std;
//struct B {
//    int score;
//    bool flag = false;
//    B()noexcept = default;
//    B(const B& a)noexcept :score{ a.score }, flag{ false } {}
//    auto operator<=>(const B& a)const noexcept { return score <=> a.score; }
//};
//
//int n;
//int res;
//B board[20][20];
//bool c;
//bool IsSame(const vector<vector<B>>& a, const vector<vector<B>>& b)
//{
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j)
//        {
//            if (a[i][j].score != b[i][j].score)return false;
//        }
//    }
//    return true;
//}
//void GoLeft(B board[20][20])
//{
//    for (int i = 0; i < n; ++i) {
//        for (int j = 1; j < n; ++j) {
//            int k = j;
//            if (!board[i][k].score)continue;
//            while (k > 0 && board[i][k].score) {
//                if (board[i][k - 1].score == board[i][k].score && !board[i][k - 1].flag) {
//                    board[i][k - 1].score *= 2;
//                    board[i][k].score = 0;
//                    board[i][k - 1].flag = true;
//                    c = true;
//                    break;
//                }
//                else if (board[i][k - 1].score == 0) {
//                    board[i][k - 1].score = board[i][k].score;
//                    board[i][k].score = 0;
//                }
//                else
//                    break;
//                c = true;
//                --k;
//            }
//        }
//    }
//}
//void GoRight(B board[20][20])
//{
//    for (int i = 0; i < n; ++i) {
//        for (int j = n - 2; j >= 0; --j) {
//            int k = j;
//            if (!board[i][k].score)continue;
//            while (k < n - 1 && board[i][k].score) {
//                if (board[i][k + 1].score == board[i][k].score && !board[i][k + 1].flag) {
//                    board[i][k + 1].score *= 2;
//                    board[i][k].score = 0;
//                    board[i][k + 1].flag = true;
//                    c = true;
//                    break;
//                }
//                else if (board[i][k + 1].score == 0) {
//                    board[i][k + 1].score = board[i][k].score;
//                    board[i][k].score = 0;
//                }
//                else
//                    break;
//                c = true;
//                ++k;
//            }
//        }
//    }
//}
//void GoUp(B board[20][20])
//{
//    for (int i = 0; i < n; ++i) {
//        for (int j = 1; j < n; ++j) {
//            int k = j;
//            if (!board[k][i].score)continue;
//            while (k > 0 && board[k][i].score) {
//                if (board[k - 1][i].score == board[k][i].score && !board[k - 1][i].flag) {
//                    board[k - 1][i].score *= 2;
//                    board[k][i].score = 0;
//                    board[k - 1][i].flag = true;
//                    c = true;
//                    break;
//                }
//                else if (board[k - 1][i].score == 0) {
//                    board[k - 1][i].score = board[k][i].score;
//                    board[k][i].score = 0;
//                }
//                else
//                    break;
//                c = true;
//                --k;
//            }
//        }
//    }
//}
//void GoDown(B board[20][20])
//{
//    for (int i = 0; i < n; ++i) {
//        for (int j = n - 2; j >= 0; --j) {
//            int k = j;
//            if (!board[k][i].score)continue;
//            while (k < n - 1 && board[k][i].score) {
//                if (board[k + 1][i].score == board[k][i].score && !board[k + 1][i].flag) {
//                    board[k + 1][i].score *= 2;
//                    board[k][i].score = 0;
//                    board[k + 1][i].flag = true;
//                    c = true;
//                    break;
//                }
//                else if (board[k + 1][i].score == 0) {
//                    board[k + 1][i].score = board[k][i].score;
//                    board[k][i].score = 0;
//                }
//                else
//                    break;
//                c = true;
//                ++k;
//            }
//        }
//    }
//}
//void(*Move[4])(B board[20][20]) = { GoLeft,GoRight,GoUp,GoDown };
//
//int GetMax(B board[20][20])
//{
//    int max_v = -1;
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j) {
//            max_v = max(max_v, board[i][j].score);
//            board[i][j].flag = false;
//        }
//    }
//    return max_v;
//}
//int cpy(B a[20][20], B b[20][20])
//{
//    int max_v = -1;
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j) {
//            a[i][j] = b[i][j];
//            a[i][j].flag = false;
//        }
//    }
//    return max_v;
//}
//int threshold_value[11];
//void go(B b[20][20], int N = 0)
//{
//    int val = GetMax(b);
//
//    if (val <= threshold_value[N]) return; 
//
//    if (10 == N) {
//        res = max(res, val);
//        int v = res;
//        while (N> 0) {
//            threshold_value[N--] = v;
//            v /= 2;
//        }
//        return;
//    }
//    for (int i = 0; i < 4; ++i)
//    {
//        B temp[20][20];
//        c = false;
//        cpy(temp, b);
//        Move[i](temp);
//        if (!c)
//        {
//           // res = max(res, GetMax(temp));
//            continue;
//        }
//        else
//            go(temp, N + 1);
//    }
//}
//int main()
//{
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL); cout.tie(NULL);  
//    cin >> n;
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j)
//            cin >> board[i][j].score;
//    }
//    go(board);
//    cout << max(res,GetMax(board));
//}
#include <iostream>
#include <algorithm>
using namespace std;
int sudoku[9][9];
pair<int, int> nokori[81];
int cnt;
bool Check(int r,int c)
{
	for (int i = 0; i < 9; ++i) {
		if (sudoku[r][c] == sudoku[r][i] && c != i)return false;
		if (sudoku[r][c] == sudoku[i][c] && r != i)return false;
	}
	const int ry = (r * 3) / 3;
	const int rx = (c * 3) / 3;
	for (int y = ry; y < ry + 3; ++y) {
		for (int x = rx; x < rx + 3; ++x) {
			if (r == y && x == c)continue;
			if (sudoku[r][c] == sudoku[y][x])return false;
		}
	}
	return true;
}
void go(int n = 0)
{
	if (n == cnt) {
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				cout << sudoku[i][j] << ' ';
			}
			cout << '\n';
		}
		exit(0);
	}
	for (int i = n; i < cnt; ++i) {
		for (int j = 1; j <= 9; ++j) {
			const auto [y, x] = nokori[i];
			sudoku[y][x] = j;
			if (!Check(y, x))
			{
				sudoku[y][x] = 0;
				
			}
			else
				go(n + 1);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			int c; cin >> c;
			if (c==0)
				nokori[cnt++] = { i,j };
			else
				sudoku[i][j] = c;
		}
	}
	go();
}
