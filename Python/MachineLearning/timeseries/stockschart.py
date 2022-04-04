import matplotlib.pyplot as plt
import numpy as np
import seaborn as sns
import pandas as pd
import datetime
import matplotlib.dates as mdates
sns.set()

disney = pd.read_csv('DIS.csv')
disney.head()
disney['timestamp'] = pd.to_datetime(disney['Date'])
signal = np.copy(disney.Close.values)

fig, ax = plt.subplots()
ax.plot(disney['timestamp'], disney['Close'])
ax.format_xdata = mdates.DateFormatter('%Y(%D)')
plt.xticks(rotation=45)
plt.xlabel('Earth Year')
plt.ylabel('DIS Price') 
plt.legend()                              
plt.show()
  
