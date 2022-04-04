import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
import seaborn as sns
import datetime
import matplotlib.dates as mdates
sns.set()

aapl = pd.read_csv('AAPL.csv')
aapl.head()
aapl['timestamp'] = pd.to_datetime(aapl['Date'])
signal = np.copy(aapl.Close.values)

amzn = pd.read_csv('AMZN.csv')
amzn.head()
amzn['timestamp'] = pd.to_datetime(amzn['Date'])
signal = np.copy(amzn.Close.values)

fb = pd.read_csv('FB.csv')
fb.head()
fb['timestamp'] = pd.to_datetime(fb['Date'])
signal = np.copy(fb.Close.values)

goog = pd.read_csv('GOOG.csv')
goog.head()
goog['timestamp'] = pd.to_datetime(goog['Date'])
signal = np.copy(goog.Close.values)

intc = pd.read_csv('INTC.csv')
intc.head()
intc['timestamp'] = pd.to_datetime(intc['Date'])
signal = np.copy(intc.Close.values)

msft = pd.read_csv('MSFT.csv')
msft.head()
msft['timestamp'] = pd.to_datetime(msft['Date'])
signal = np.copy(msft.Close.values)

fig, ax = plt.subplots()
ax.plot(aapl['timestamp'], aapl['Close'], color='g', label='Apple')
ax.plot(amzn['timestamp'], amzn['Close'], color='b', label='Amazon')
ax.plot(fb['timestamp'], fb['Close'], color='r', label='Meta Platforms')
ax.plot(goog['timestamp'], goog['Close'], color='m', label='Google')
ax.plot(intc['timestamp'], intc['Close'], color='y', label='Intel')
ax.plot(msft['timestamp'], msft['Close'], color='k', label='Microsoft')

ax.format_xdata = mdates.DateFormatter('%Y(%D)')
plt.xticks(rotation=45)
plt.xlabel('Earth Year')
plt.ylabel('Stocks Price (USD)') 
plt.legend()                              
plt.show()
