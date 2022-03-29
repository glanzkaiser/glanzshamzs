import numpy as np
a = np.array([[7,8,9,10,11,12,13], [17,18,19,20,21,22,23]])
print(a)
print(a.sum(axis=None)) # overall sum
print(a.sum())
print(a.sum(axis=0)) # along the rows -> 1 sum entry for each column
print(a.sum(axis=1)) # along the columns -> 1 sum entry for each row

print(a.mean(axis=None)) # overall mean
print(a.mean())
print(a.mean(axis=0)) # along the rows -> 1 mean entry for each column
print(a.mean(axis=1)) # along the columns -> 1 mean entry for each row

# some more: std, var, min, max
