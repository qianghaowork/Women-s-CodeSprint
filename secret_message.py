import sys

n = int(input())

A = []
inp = []
for _ in range(n):
    s = input()
    inp.append(s)

inp = list(set(inp))

for s in inp:
    A.append( ( "".join(sorted(s)), s))

n = len(inp)
A = sorted(A)
answer = []
maxlen = 0
temp = []
for i in range(0,n):
    if i and A[i-1][0]!=A[i][0]:
        maxlen = max(maxlen, len(temp))
        answer.append(temp)
        temp = []
    temp.append(A[i][1])

if (len(temp)):
    maxlen = max(maxlen, len(temp))
    answer.append(temp)
    
print(len(answer))
for i in range(0,len(answer)):
    answer[i] = sorted(answer[i])[::-1]

answer = sorted(answer)

for s in answer:
    if maxlen == len(s):
        print(" ".join(s))
