rt, rj, st, sj = map(float, input().split())

pt = (rt - 1) / st
pj = (rj - 1) / sj

if (pt < pj):
    print("TAOYUAN")
elif (pj < pt):
    print("JAKARTA")
else:
    print("SAME")
