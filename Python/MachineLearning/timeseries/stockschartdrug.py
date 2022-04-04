import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
import seaborn as sns
import datetime
import matplotlib.dates as mdates
sns.set()

gsk = pd.read_csv('GSK.csv')
gsk.head()
gsk['timestamp'] = pd.to_datetime(gsk['Date'])
signal = np.copy(gsk.Close.values)

pfe = pd.read_csv('PFE.csv')
pfe.head()
pfe['timestamp'] = pd.to_datetime(pfe['Date'])
signal = np.copy(pfe.Close.values)

mrk = pd.read_csv('MRK.csv')
mrk.head()
mrk['timestamp'] = pd.to_datetime(mrk['Date'])
signal = np.copy(mrk.Close.values)

lly = pd.read_csv('LLY.csv')
lly.head()
lly['timestamp'] = pd.to_datetime(lly['Date'])
signal = np.copy(lly.Close.values)

bmy = pd.read_csv('BMY.csv')
bmy.head()
bmy['timestamp'] = pd.to_datetime(bmy['Date'])
signal = np.copy(bmy.Close.values)

fig, ax = plt.subplots()
ax.plot(gsk['timestamp'], gsk['Close'], color='g', label='GlaxoSmithKline')
ax.plot(lly['timestamp'], lly['Close'], color='b', label='Eli Lilly')
ax.plot(bmy['timestamp'], bmy['Close'], color='r', label='Bristol-Myers Squibb Company')
ax.plot(mrk['timestamp'], mrk['Close'], color='m', label='Merck')
ax.plot(pfe['timestamp'], pfe['Close'], color='y', label='Pfizer')

ax.format_xdata = mdates.DateFormatter('%Y(%D)')
plt.xticks(rotation=45)
plt.xlabel('Earth Year')
plt.ylabel('Stocks Price (USD)') 
plt.legend()                              
plt.show()
