# # def maxSubArray(nums):

# #     n = len(nums)
# #     for i in range(1, n):
# #         if nums[i-1] > 0:
# #             nums[i] += nums[i-1]
# #     return max(nums)
    
# # print(maxSubArray([-2,1,-3,4,-1,2,1,-5,4]))

# import sys
# def change():
#     pp = float(sys.argv[1])
#     cp = float(sys.argv[2])
#     dif = cp - pp

#     if dif < 0:
#         return "ERROR"
        
#     if dif == 0:
#         return "ZERO"

#     if  dif < 0.05:
#         n = int(dif / 0.01)   #cp % 0.01 must be an int
#         return str(n) + "PENNY"
        
#     if dif == 0.05:
#         return 'NICKEL'
        
#     if  0.05 < dif < 0.10:
#         n = int((dif -0.05) / 0.01)
#         res = 'NICKEL'+", " + str(n) + "PENNY"
#         return res
        
#     if dif == 0.10:
#         return 'DIME'
        
#     if 0.1 < dif < 0.25:
#         n = int(dif // 0.1)
#         m = int((dif - n * 0.1) // 0.05)
#         p = int((dif - n * 0.1 - m * 0.05) // 0.01)
#         return str(n) * "DIME" +"," + m * "NICKEL" +", " + p * "PENNY"
    
#     if dif == 0.25:
#         return "QUARTER"
        
#     if 0.25 < dif < 0.5:
#         n = int((dif - 0.25) // 0.05)
#         m = (0.5 - 0.25 - 0.05 * n) // 0.01
#         return str(n) * "DIME" +"," + m * "NICKEL" +", " + p * "PENNY"

# print(change())

def month_pay(loan, years, rate, down):
    n = 12 * years
    monthly_rate = rate / 12 / 100
    
    pay =(monthly_rate * (loan - down)) / (1 - (1 + monthly_rate) ** (-n))
    
    total_pay = pay * n 
    total_interest = total_pay - loan 
    
    return pay,total_interest

print(month_pay(30000, 10, 6, 5000))