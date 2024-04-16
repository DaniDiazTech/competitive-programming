t = int(input())

for _ in range(t):
    a, b, l = map(int, input().split())
    s = set()
    for x in range(21):
        for y in range(21):
            div = (a ** x) * (b ** y)
            if (l % div == 0):
                s.add(l / div)

    print(len(s))