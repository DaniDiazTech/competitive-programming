s, m = list(map(int, input().split()))
# N = 1000003
N = 40
ans = s

for i in range(2, N):
    mult = 1
    k = 0
    for j in range(1, 42):
        mult *= i
        if (mult >= s):
            k = j
            break
    x = mult // i

    l = -1
    r = i + 1
    while (l + 1 < r):
        m = (l + r) // 2

        if ((x * m) >= s):
            r = m
        else:
            l = m

    cnt = r + (i * (k - 1)) + (m * (k - 1))
    print(cnt)
    ans = min(ans, cnt)

print(ans)
