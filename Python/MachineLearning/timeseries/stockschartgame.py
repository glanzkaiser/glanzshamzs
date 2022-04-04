import matplotlib.pyplot as plt
import pandas as pd
import datetime
import matplotlib.dates as mdates
sns.set()

nintendo = pd.read_csv('NTDOY.csv')
nintendo.head()
nintendo['timestamp'] = pd.to_datetime(nintendo['Date'])
signal = np.copy(nintendo.Close.values)

activision = pd.read_csv('ATVI.csv')
activision.head()
activision['timestamp'] = pd.to_datetime(activision['Date'])
signal = np.copy(activision.Close.values)

ttwo = pd.read_csv('TTWO.csv')
ttwo.head()
ttwo['timestamp'] = pd.to_datetime(ttwo['Date'])
signal = np.copy(ttwo.Close.values)

ea = pd.read_csv('EA.csv')
ea.head()
ea['timestamp'] = pd.to_datetime(ea['Date'])
signal = np.copy(ea.Close.values)

fig, ax = plt.subplots()
ax.plot(ttwo['timestamp'], ttwo['Close'], color='g', label='Take-Two Interactive')
ax.plot(activision['timestamp'], activision['Close'], color='b', label='Activision Blizzard')
ax.plot(nintendo['timestamp'], nintendo['Close'], color='r', label='Nintendo')
ax.plot(ea['timestamp'], ea['Close'], color='y', label='Electronic Arts')

ax.format_xdata = mdates.DateFormatter('%Y(%D)')
plt.xticks(rotation=45)
plt.xlabel('Earth Year')
plt.ylabel('Stocks Price (USD)') 
plt.legend()                              
plt.show()
