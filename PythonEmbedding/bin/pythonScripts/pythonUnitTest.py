import numpy as np
import time

n = 100
a = np.ones((n,n))
b = np.ones((n,n))
c = np.zeros((n,n))

def pyMatrixMult():    
    for i in range(n):
        for j in range(n):
            for k in range(n):
                c[i][j] += a[i][k] * b[k][j]

start_time = time.time()
pyMatrixMult()
end_time = time.time()
print(f"Time taken for Matrix multiplication in Python: {end_time - start_time} sec." )