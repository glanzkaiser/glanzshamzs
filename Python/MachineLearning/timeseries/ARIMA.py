import matplotlib.pyplot as plt
import numpy as np
import seaborn as sns
import pandas as pd
import datetime
import matplotlib.dates as mdates
sns.set()

dis = pd.read_csv('DIS.csv')
dis.head()

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

formatter = mdates.DateFormatter("%Y") ### formatter of the date
locator = mdates.YearLocator() ### where to put the labels

predicted_15 = auto_regressive(signal,15,1,2,future_count)
predicted_30 = auto_regressive(signal,30,1,2,future_count)

plt.figure(figsize=(15, 7))
ax = plt.gca()
ax.xaxis.set_major_formatter(formatter) ## calling the formatter for the x-axis
ax.xaxis.set_major_locator(locator) ## calling the locator for the x-axis

plt.plot(signal, label = 'DIS')
plt.plot(predicted_15, label = 'ARIMA 15 MA')
plt.plot(predicted_30, label = 'ARIMA 30 MA')
plt.xlabel('Earth Year')
plt.ylabel('Price') 
plt.legend()
plt.show()

