t = int(input())

for i in range(t):
    n, p, r = map(int, input().split())

    p = 1 + p / 100

    l = 1
    h = 100

    while l  + 1 < h:
        m = (l + h) // 2
        if (p < (r / n ) ** (1/m)):
            h = m
        else:
            l = m

    print(f"Case {i + 1}: {l}")
