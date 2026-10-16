#!/usr/bin/env python3


def stride(shape: list, element_size: int) -> list:
    strides = []

    stride = element_size
    for i in range(len(shape)):
        strides.insert(0, stride)
        stride *= shape[(len(shape) - 1) - i]
    
    return strides


if __name__ == "__main__":
    shape = [3, 4]
    element_size = 4
    stride = stride(shape, element_size)
    print(stride)
