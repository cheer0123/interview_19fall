def longestCommonPrefix(strs):

    shortest = sorted(strs, key = len)[0]
    flag = True
    i = 0
    
    while i < len(shortest) and flag == True:
        print("i", i)
        for s in strs:
            
            if s[i] != shortest[i]:
                print(s[i])
                flag = False
            else:
                i += 1
    print(i)
    if i == 0:
        return ""
    return shortest[:i]
    
print(longestCommonPrefix(["dog","racecar","car"]))