import random
import unittest

N = 1024

A = [[random.randint(1, 100) for i in range(N)]for j in range(N)]
B = [[random.randint(1, 100) for i in range(N)]for j in range(N)]
C = [[0 for i in range(N)]for j in range(N)]

# GEMM
for i in range(N):
    for j in range(N):
        for k in range(N):
            C[i][j] += A[i][k] * B[k][j]

if __name__ == "__main__":
    import numpy as np
    E = np.array(A)
    F = np.array(B)

    G = E @ F

    import unittest

    # correctness check
    class TestGEMM(unittest.TestCase):
        def test(self):
            self.assertTrue(np.allclose(G, C))

    unittest.main()
