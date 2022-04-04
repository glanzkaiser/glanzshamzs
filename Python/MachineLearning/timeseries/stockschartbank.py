import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
import seaborn as sns
import datetime
import matplotlib.dates as mdates
sns.set()

jpm = pd.read_csv('JPM.csv')
jpm.head()
jpm['timestamp'] = pd.to_datetime(jpm['Date'])
signal = np.copy(jpm.Close.values)

c = pd.read_csv('C.csv')
c.head()
c['timestamp'] = pd.to_datetime(c['Date'])
signal = np.copy(c.Close.values)

gs = pd.read_csv('GS.csv')
gs.head()
gs['timestamp'] = pd.to_datetime(gs['Date'])
signal = np.copy(gs.Close.values)

wfc = pd.read_csv('WFC.csv')
wfc.head()
wfc['timestamp'] = pd.to_datetime(wfc['Date'])
signal = np.copy(wfc.Close.values)

fig, ax = plt.subplots()
ax.plot(jpm['timestamp'], jpm['Close'], color='g', label='JP Morgan Chase')
ax.plot(c['timestamp'], c['Close'], color='b', label='Citigroup')
ax.plot(gs['timestamp'], gs['Close'], color='r', label='Goldman Sachs')
ax.plot(wfc['timestamp'], wfc['Close'], color='y', label='Wells Fargo')

ax.format_xdata = mdates.DateFormatter('%Y(%D)')
plt.xticks(rotation=45)
plt.xlabel('Earth Year')
plt.ylabel('Stocks Price') 
plt.legend()                              
plt.show()
