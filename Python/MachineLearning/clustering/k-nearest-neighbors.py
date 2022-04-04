import numpy as np
import pandas as pd
from sklearn.preprocessing import MinMaxScaler
from sklearn.preprocessing import LabelEncoder
from sklearn.model_selection import train_test_split
import matplotlib.pyplot as plt
import seaborn as sns
sns.set()

df = pd.read_csv('Iris.csv')
Y = df.iloc[:,-1].values
df = df.iloc[:,1:-1]
df.head()

labels = np.unique(Y)
Y = LabelEncoder().fit_transform(Y)

def PCA(X, dimensions = 2):
    X = X - np.tile(np.mean(X, 0), (X.shape[0], 1))
    _, eigenvectors = np.linalg.eig(np.dot(X.T, X))
    Y = np.dot(X, eigenvectors[:, :dimensions])
    return Y

def euclidean_distance(x, y):
    return np.sqrt(np.sum(np.square(x-y)))

X = PCA(MinMaxScaler().fit_transform(df.values))
train_X, test_X, train_Y, test_Y = train_test_split(X, Y, test_size = 0.2)

class KNN:
    def __init__(self, k):
        self.K = k
    def _vote(self, label):
        counts = np.bincount(label)
        return np.argmax(counts)
    def predict(self, test_X, train_X, train_Y):
        Y = np.empty(test_X.shape[0])
        for i, test_sample in enumerate(test_X):
            idx = np.argsort([euclidean_distance(test_sample, x) for x in train_X])[:self.K]
            nearest_neighbors = np.array([train_Y[i] for i in idx])
            Y[i] = self._vote(nearest_neighbors)
        return Y
    
accuracy_test = np.mean(test_Y == KNN(5).predict(test_X, train_X, train_Y))

plt.figure(figsize=(15, 10))
x_min, x_max = X[:, 0].min() - .5, X[:, 0].max() + .5
y_min, y_max = X[:, 1].min() - .5, X[:, 1].max() + .5
h = 0.01
xx, yy = np.meshgrid(np.arange(x_min, x_max, h), np.arange(y_min, y_max, h))
Z = KNN(5).predict(np.c_[xx.ravel(), yy.ravel()], train_X, train_Y)
Z = Z.reshape(xx.shape)
plt.contourf(xx, yy, Z, cmap=plt.cm.Spectral, alpha = 0.5)
plt.scatter(X[:, 0], X[:, 1], c=Y, cmap=plt.cm.Spectral)
plt.title('decision boundary, accuracy validation: %f'%(accuracy_test))
plt.show()
