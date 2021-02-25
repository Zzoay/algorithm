
import numpy as np


def softmax(x):
    return np.exp(x) / np.sum(np.exp(x), axis=0)


def softmax_mod(x):
    ma = np.max(x)
    return softmax(x-ma)


x = np.array([1, 2, 3, 4])
np.testing.assert_array_almost_equal(softmax(x), softmax_mod(x))
print(softmax(x))
print(softmax_mod(x))

