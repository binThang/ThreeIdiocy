A,B,C,N = map(int, input().strip().split())
DP_N = [False] * (N+1)

DP_N[A] = True
DP_N[B] = True
DP_N[C] = True

for i in range(N+1):
    if i-A >= 0:
        if DP_N[i-A] == True:
            DP_N[i] = True
    if i-B >= 0:
        if DP_N[i-B] == True:
            DP_N[i] = True
    if i-C >= 0:
        if DP_N[i-C] == True:
            DP_N[i] = True
print('1') if  DP_N[-1] == True else print('0')