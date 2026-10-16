#!/usr/bin/env python3
import unittest

def stride(shape: list, element_size: int) -> list:
    strides = [0] * len(shape)

    stride = element_size
    for i in range(len(shape) - 1, -1, -1):
        strides[i] = stride
        stride *= shape[i]
    
    return strides

# tests
class TestStride(unittest.TestCase):
    def test_1d(self):
        self.assertEqual(stride([5], 4), [4])

    def test_2d(self):
        self.assertEqual(stride([3, 4], 4), [16, 4])

    def test_3d(self):
        self.assertEqual(stride([2, 2, 4], 4), [32, 16, 4])

if __name__ == "__main__":
    unittest.main()
