# https://www.hackerrank.com/challenges/missing-numbers/problem
#!/bin/python3

import sys

def missingNumbers(arr, brr):

    miss = [0] * 10000
    result = []
    for i in range(len(brr)):
        miss[brr[i]] += 1
    for i in range(len(arr)):
        miss[arr[i]] -= 1
    for i in range(len(miss)):
        if miss[i] != 0:
            result.append(i)
    return result

    # Complete this function

if __name__ == "__main__":
    n = int(input().strip())
    arr = list(map(int, input().strip().split(' ')))
    m = int(input().strip())
    brr = list(map(int, input().strip().split(' ')))
    result = missingNumbers(arr, brr)
    print (" ".join(map(str, result)))


#!/bin/python3

import sys

def missingNumbers(arr, brr):

    return # missingNumber as acsending order

if __name__ == "__main__":
    n = int(input().strip())
    arr = list(map(int, input().strip().split(' ')))
    m = int(input().strip())
    brr = list(map(int, input().strip().split(' ')))
    result = missingNumbers(arr, brr)
    print (" ".join(map(str, result)))


