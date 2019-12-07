import numpy 
def matrixMul(a, n):
    if(n == 1):
        return a
    else:
            tempArr = a
            for i in range(1, n-1):
                tempArr = numpy.matmul(a, tempArr)
            return tempArr