def determine(self, n, m):
    tem = self.convert(n， m) # 将十进制数转换成m进制数
    count = 0
    while count < 100:
        if self.is_palindrome(self.add(tem, tem.reverse(), m)):
            return True
    else:
        count += 1 
 return False


# 将十进制数转换成m制数
def convert(self, n, m): 
    if m <= 0:
        return
    ans = []
    while True:
        s = n//m
        y = n%m
        b += str(y)
        if s == 0:
            break
        n = s
    ans.reverse()
    return ''.join(ans)

# 判断一个string是否是回文：
def is_palindrome(self,s): 
    if len(s) <= 1:
        return True
    l = 0
    r = len(s) - 1
    while(l < r):
        if s[l] ==  s[r]:
            l += 1
            r -= 1
    else:
        return False
    return True

#求进制为m的数a, b 的和
def add(self, a, b, m):
    #a, b are strings
    la = list(a)
    lb = list(b)
    n = max(len(la), len(lb))
    la.rfill()
    lb.rfill()
    res = []
    carry = 0
    for i in range(n-1, -1, -1):
        if la[i] + lb[i] + carry >= m:
            carry = (la[i] + lb[i] + carry) // m
            res.insert(0, (la[i] + lb[i] + carry) % m)
        else:
            res.insert(0,la[i] + lb[i] + carry)
        carry = 0
        
    return ''join(res)  #m进制表示的a，b的和, 也是string