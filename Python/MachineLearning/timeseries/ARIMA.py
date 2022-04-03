import matplotlib.pyplot as plt
import numpy as np
import seaborn as sns
import pandas as pd
import datetime
import matplotlib.dates as mdates
sns.set()

dis = pd.read_csv('DIS.csv')
dis.head()
dis['timestamp'] = pd.to_datetime(dis['Date'])

signal = np.copy(dis.Close.values)

def moving_average(signal, period):
    buffer = []
    for i in range(period, len(signal)):
        buffer.append(signal[i - period : i].mean())
    return buffer

def auto_regressive(signal, p, d, q, future_count = 10):
    """
    p = the order (number of time lags)
    d = degree of differencing
    q = the order of the moving-average
    """
    buffer = np.copy(signal).tolist()
    for i in range(future_count):
        ma = moving_average(np.array(buffer[-p:]), q)
        forecast = buffer[-1]
        for n in range(0, len(ma), d):
            forecast -= buffer[-1 - n] - ma[n]
        buffer.append(forecast)
    return buffer

future_count = 15

predicted_15 = auto_regressive(signal,15,1,2,future_count)
predicted_30 = auto_regressive(signal,30,1,2,future_count)

plt.figure(figsize=(15, 7))

plt.plot(signal, label = 'DIS')
plt.plot(predicted_15, label = 'ARIMA 15 MA')
plt.plot(predicted_30, label = 'ARIMA 30 MA')
plt.xlabel('Earth Year')
plt.ylabel('DIS Price') 
plt.legend()                              
plt.show()

fig, ax = plt.subplots()
ax.plot(dis['timestamp'], dis['Close'])
ax.format_xdata = mdates.DateFormatter('%Y(%D)')
plt.xticks(rotation=45)
plt.xlabel('Earth Year')
plt.ylabel('DIS Price') 
plt.legend()                              
plt.show()
