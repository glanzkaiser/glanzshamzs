import matplotlib.pyplot as plt

X = [1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946]
Y = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21]

#scatter plot
plt.scatter(X, Y, s=60, c='red', marker='^')

#change axes ranges
plt.xlim(0,100)
plt.ylim(0,11000)

#add title
plt.title('Golden Ratio')

#add x and y labels
plt.xlabel('Index')
plt.ylabel('Fibonacci')

#show plot
plt.show()
