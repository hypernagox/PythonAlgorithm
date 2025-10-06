import math

def convert(n: int, k: int) -> str:
    if k < 2:
        raise ValueError("k must be >= 2")  # k==1 무한루프 방지
    if n == 0:
        return "0"
    res = []
    while n > 0:
        res.append(str(n % k))
        n //= k
    return ''.join(reversed(res))

def is_prime(n: int) -> bool:
    if n < 2:
        return False
    if n % 2 == 0:
        return n == 2
    r = int(math.isqrt(n))
    for i in range(3, r + 1, 2):
        if n % i == 0:
            return False
    return True

def solution(n: int, k: int) -> int:
    s = convert(n, k)
    ans = 0
    cur = []
    for ch in s:
        if ch == '0':
            if cur:
                val = int(''.join(cur))
                if is_prime(val):
                    ans += 1
                cur.clear()
        else:
            cur.append(ch)
    if cur:
        if is_prime(int(''.join(cur))):
            ans += 1
    return ans

