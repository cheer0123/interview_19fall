# new = {1:2, 2:1, 3:4}


# print(new.values())
# print(new.items())
# print(new.keys())
# new[4] = 1
# print(new)
# print(new[4])

m = [[1,2,3],[4,5,6],[7,8,9]]
# m = list(zip(*m))
# print(list(zip(*m)))
# print(m)
n = len(m)
a = m

for i in range(n):
    for j in range(n):
        print(a)
        m[i][j] = a[n-j-1][i]
print(m)
