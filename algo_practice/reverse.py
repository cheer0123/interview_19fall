# def reverse(x):
#     def reversePositive():
#         if x >= 0:
#             length = len(str(x))
#             y = (x % 10) * (10 ** (length - 1))
#             for i in range(2, length + 1):
#                 tem = (x % (10 ** i) - x % (10 ** (i - 1))) // (10 ** (i - 1))
#                 print(tem)
#                 y += tem * (10 ** (length - i))
#         return y
#     if x < 0:
#         x = -x

#         print(- reversePositive())


# reverse(-1230)

a = [1,2]
b = tuple(a)
print(b)
