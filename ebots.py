import numpy as np 
from random import randint
import time

def run(): 
    N = 100
    x = [[],[],[],[],[]] 
    c = [0.03, -0.03, 0.999999, -0.9999999, 0.0]
    y, z = [], []

    for i in range(5): 
        for j in range(N):
            x[i].append(np.uint8(randint(0,256)))

    for n in range(N): 
        tempY = c[0]*x[0][n] + c[1]*x[1][n] + c[2]*x[2][n] + c[3]*x[3][n] + c[4]*x[4][n]
                
        if tempY>0: 
            y.append(tempY)
            z.append(
                c[4]*x[0][n] + c[3]*x[1][n] + c[2]*x[2][n] + c[1]*x[3][n] + c[0]*x[4][n]
            )

    # for i in range(len(y)): 
    #     print("y @ {}: {}, z: {}".format(i,y[i],z[i]))

if __name__ == "__main__":
    start = time.time()
    run()
    end = time.time() 
    print('Python runtime: {} nanoseconds'.format(((end-start)*(10**9))))