import numpy as np

# dot product/inner product
a = np.array([1,8,8,2])
b = np.array([1,8,5,5])

# sum of the products of the corresponding entries 
# multiply each corresponding elements and then take the sum

print('Vector a:')
print(a)
print('Vector b:')
print(b)

# formula with numpy :)
# dot = np.dot(a,b)

# step by step manually
c = a * b
print('a * b: ')
print(c)

print('a . b: ')
d = np.sum(c)
print(d)
