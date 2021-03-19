import sys

f = [None] * 10001
f[0] = 0
f[1] = 1

cntlim = 2
sh = 2
cnt = 0
for i in range(2, 10001):
    cnt += 1
    f[i] = f[i - 1] + sh

    if cnt == cntlim:
        sh *= 2
        cnt = 0
        cntlim += 1


for s in sys.stdin:
    print(f[int(s.strip())])