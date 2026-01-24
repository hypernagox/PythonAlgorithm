#include <iostream>
int main(void)
{
    int n, ans=0;
    std::cin>>n;
    for (int i = 1; i <= n; i++)
    {
        ans += i;
    }
    std::cout<<ans;
}