N, K = map(int, input().split())
infected = [0]*(N+1)

def infect(num, size, array):
    if num > size or array[num] == 1:
        return array
    if num <= size:
        array[num] = 1
    infect(num*2, size, array)
    infect(num//3, size, array)

infect(K, N, infected)
for i in range(1, N+1):
    if infected[i] != 0:
        N -=1

print(N)