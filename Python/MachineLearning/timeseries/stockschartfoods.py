import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
import seaborn as sns
import datetime
import matplotlib.dates as mdates
sns.set()

gis = pd.read_csv('GIS.csv')
gis.head()
gis['timestamp'] = pd.to_datetime(gis['Date'])
signal = np.copy(gis.Close.values)

k = pd.read_csv('K.csv')
k.head()
k['timestamp'] = pd.to_datetime(k['Date'])
signal = np.copy(k.Close.values)

khc = pd.read_csv('KHC.csv')
khc.head()
khc['timestamp'] = pd.to_datetime(khc['Date'])
signal = np.copy(khc.Close.values)

mdlz = pd.read_csv('MDLZ.csv')
mdlz.head()
mdlz['timestamp'] = pd.to_datetime(mdlz['Date'])
signal = np.copy(mdlz.Close.values)

nsrgy = pd.read_csv('NSRGY.csv')
nsrgy.head()
nsrgy['timestamp'] = pd.to_datetime(nsrgy['Date'])
signal = np.copy(nsrgy.Close.values)

ul = pd.read_csv('UL.csv')
ul.head()
ul['timestamp'] = pd.to_datetime(ul['Date'])
signal = np.copy(ul.Close.values)

fig, ax = plt.subplots()
ax.plot(gis['timestamp'], gis['Close'], color='g', label='General Mills')
ax.plot(mdlz['timestamp'], mdlz['Close'], color='b', label='Mondelez International')
ax.plot(k['timestamp'], k['Close'], color='r', label='Kellog')
ax.plot(khc['timestamp'], khc['Close'], color='m', label='Kraft Heinz')
ax.plot(nsrgy['timestamp'], nsrgy['Close'], color='y', label='Nestle')
ax.plot(ul['timestamp'], ul['Close'], color='k', label='Unilever')

ax.format_xdata = mdates.DateFormatter('%Y(%D)')
plt.xticks(rotation=45)
plt.xlabel('Earth Year')
plt.ylabel('Stocks Price') 
plt.legend()                              
plt.show()
