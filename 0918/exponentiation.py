import sys

n, m = map(int, sys.stdin.readline().split())

def calcPow(n, m):
  result = 1
  multiply = n
  mod = 10007
  while m > 0:
    if m % 2 == 1:
      result *= multiply
      result %= mod;
    multiply = ((multiply%mod)*(multiply%mod))%mod;
    m = m//2
  return result

print(calcPow(n, m))