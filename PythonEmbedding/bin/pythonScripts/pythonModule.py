import cppmath  # Importing C++ functions as library
import numpy as np
import time

def sayHello():
    print("[Python] sayHello()")

def add(a,b):
    return a + b


def calculate(n):
    return cppmath.sqr(n) # Calling C++ function

print (calculate(6))

cppmath.mult()


n = 100
a = np.ones((n,n))
b = np.ones((n,n))
c = np.zeros((n,n))

def pyMatrixMult():        
    start_time = time.time()
    for i in range(n):
        for j in range(n):
            for k in range(n):
                c[i][j] += a[i][k] * b[k][j]
    end_time = time.time()
    print(f"Time taken for Matrix multiplication in Python: {end_time - start_time} sec." )

