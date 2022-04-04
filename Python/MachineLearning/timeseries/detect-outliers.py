import matplotlib.pyplot as plt
import numpy as np
import seaborn as sns
import pandas as pd
sns.set()

jpm = pd.read_csv('JPM.csv')
jpm.head()

signal = np.copy(jpm.Close.values)
std_signal = (signal - np.mean(signal)) / np.std(signal)

def detect(signal, treshold = 2.0):
    detected = []
    for i in range(len(signal)):
        if np.abs(signal[i]) > treshold:
            detected.append(i)
    return detected

outliers = detect(std_signal)

plt.figure(figsize=(15, 7))
plt.plot(np.arange(len(jpm.Close)), jpm.Close)
plt.plot(np.arange(len(jpm.Close)), jpm.Close, 'X', label='outliers',markevery=outliers, c='r')
plt.legend()
plt.show()
