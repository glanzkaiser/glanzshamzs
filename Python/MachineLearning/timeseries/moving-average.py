import matplotlib.pyplot as plt
import numpy as np
import seaborn as sns
import pandas as pd
import datetime
import matplotlib.dates as 
sns.set()

dis = pd.read_csv('DIS.csv')
dis.head()
dis['timestamp'] = pd.to_datetime(dis['Date'])

signal = np.copy(dis.Close.values)

def moving_average(signal, period):
    buffer = [np.nan] * period
    for i in range(period,len(signal)):
        buffer.append(signal[i-period:i].mean())
    return buffer
ma_7 = moving_average(signal, 7)
ma_14 = moving_average(signal, 14)
ma_21 = moving_average(signal, 21)
ma_100 = moving_average(signal, 100)


plt.figure(figsize=(15, 7))
plt.plot(np.arange(len(dis.Close)), dis.Close, label ='close DIS')
plt.plot(np.arange(len(dis.Close)), ma_7, label = 'ma 7 DIS')
plt.plot(np.arange(len(dis.Close)), ma_14, label = 'ma 14 DIS')
plt.plot(np.arange(len(dis.Close)), ma_21, label = 'ma 21 DIS')
plt.plot(np.arange(len(dis.Close)), ma_100, label = 'ma 100 DIS')
ax.plot(dis['timestamp'], dis['Close'])
ax.format_xdata = mdates.DateFormatter('%Y(%D)')
plt.xticks(rotation=45)
plt.xlabel('Earth Year')
plt.ylabel('DIS Price') 

plt.legend()
plt.show()

