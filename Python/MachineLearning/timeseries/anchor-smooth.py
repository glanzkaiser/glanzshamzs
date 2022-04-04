import matplotlib.pyplot as plt
import numpy as np
import seaborn as sns
import pandas as pd
sns.set()

jpm = pd.read_csv('JPM.csv')
jpm.head()

def anchor(signal, weight):
    buffer = []
    last = signal[0]
    for i in signal:
        smoothed_val = last * weight + (1 - weight) * i
        buffer.append(smoothed_val)
        last = smoothed_val
    return buffer


signal = np.copy(jpm.Close.values)

anchor_3 = anchor(signal, 0.3)
anchor_5 = anchor(signal, 0.5)
anchor_8 = anchor(signal, 0.8)

plt.figure(figsize=(15, 7))
plt.plot(np.arange(len(jpm.Close)), jpm.Close, label ='close JPM')
plt.plot(np.arange(len(jpm.Close)), anchor_3, label = 'anchor 0.3 JPM')
plt.plot(np.arange(len(jpm.Close)), anchor_5, label = 'anchor 0.5 JPM')
plt.plot(np.arange(len(jpm.Close)), anchor_8, label = 'anchor 0.8 JPM')
plt.legend()
plt.show()
