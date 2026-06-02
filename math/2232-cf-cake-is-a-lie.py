from math import gcd

def extended_gcd(a, b):
    if b == 0:
        return (a, 1, 0)

    g, x1, y1 = extended_gcd(b, a % b)

    x = y1
    y = x1 - (a // b) * y1

    return (g, x, y)


t = int(input())

for _ in range(t):
    n, a, b, k = map(int, input().split())

    g = gcd(a, b)

    if k % g:
        print(0)
        continue

    a1 = a // g
    b1 = b // g
    k1 = k // g

    _, inv, _ = extended_gcd(b1, a1)
    inv %= a1

    x0 = (k1 * inv) % a1

    max_x = k // b

    if x0 > max_x:
        print(0)
        continue

    best_x = x0

    ans = min(n, (n + best_x) // (best_x + 1))
    print(ans)