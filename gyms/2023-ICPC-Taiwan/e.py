a, b, m = map(int, input().split())

def mod(n):
  return ((n % m) + m) % m

dp = {}
dp[0] = 2
dp[1] = a

def f(n):
  if n in dp:
    return dp[n]

  if (n % 2 == 0):
    x = mod(f(n // 2))
    dp[n] = mod(x * x - 2)
  else:
    dp[n] = mod(f(n // 2) * f(1 + n // 2) - a)
  return dp[n]

print(f(b))