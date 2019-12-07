# s = "    words and 987"
# s = ''.join(s.split())
# lst = list(s)
# print(lst)
# print(''.join(lst))
def myAtoi(str):
    res = []
    lst = list(str.strip())
    print(lst)
        
    if len(lst) == 0:
        return 0
            
    i = 0
    flag = 1
    if lst[0] == "+":
        i += 1
    elif lst[0] == "-":
        flag = -1
        i += 1
        
    while i < len(lst):
        if lst[i].isdigit():
            res.append(lst[i])
            i += 1
            # elif lst[i] == " ":
            #     i += 1
        else:
            break
    print(i)
    print(res)
                
    if len(res) == 0:
        return 0

       
    res_num = int(''.join(res))
    if res_num > 2 ** 31:
        if flag == 1:
            return 2 ** 31 - 1
        elif flag == -1:
            return 2 ** 31 * flag
    else:
        return res_num * flag
print(myAtoi("   -42"))