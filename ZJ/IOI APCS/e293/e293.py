prime = [2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97]

for i in range(int(input().strip())):
    n = int(input().strip())
    flag = 0
    for x in prime:
        if n % x == 0:
            print(x, end = ' ')
            flag = 1;
    if flag == 0:
        print('Terrible Silence...', end = '')
    print();