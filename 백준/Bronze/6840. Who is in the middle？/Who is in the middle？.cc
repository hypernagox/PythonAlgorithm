#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);   cout.tie(NULL);
    
    int num[3];
    for (int i = 0; i < 3; i++) 
    {
        cin >> num[i];
    }
    sort(num, num + 3);

    cout << num[1] << endl;
}