#include <iostream>
using namespace std;
int inOrder[100001];
int postOrder[100001];
int inOrderMap[100001];
void findPreOrder(int inStart, int inEnd, int postStart, int postEnd) noexcept
{
    if (inStart > inEnd || postStart > postEnd) return;
    int root = postOrder[postEnd];
    cout << root << ' ';
    int inRootIndex = inOrderMap[root];
    int leftSubtreeSize = inRootIndex - inStart;
    findPreOrder(inStart, inRootIndex - 1, postStart, postStart + leftSubtreeSize - 1);
    findPreOrder(inRootIndex + 1, inEnd, postStart + leftSubtreeSize, postEnd - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> inOrder[i];
        inOrderMap[inOrder[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        cin >> postOrder[i];
    }
    findPreOrder(0, n - 1, 0, n - 1);
    cout << '\n';
}