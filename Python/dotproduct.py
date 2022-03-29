

# dot product/inner product
a = np.array([1,2])
b = np.array([3,4])

# sum of the products of the corresponding entries 
# multiply each corresponding elements and then take the sum

# cumbersome way for lists
dot = 0
for i in range(len(a)):
    dot += a[i] * b[i]
print(dot)

# easy with numpy :)
dot = np.dot(a,b)
print(dot)

# step by step manually
c = a * b
print(c)
d = np.sum(c)
print(d)

# most of these functions are also instance methods
dot = a.dot(b)
print(dot)
dot = (a*b).sum()
print=('Dot product: ')
print(dot)

# in newer versions
dot = a @ b
print(dot)

