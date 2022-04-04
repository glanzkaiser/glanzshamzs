import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
sns.set()

k = pd.read_csv('K.csv')
k.head()

import statsmodels.api as sm

# multiplicative
freq = 15
signal = k.Close.values
res = sm.tsa.seasonal_decompose(signal, freq=freq, model="multiplicative")
fig, (ax1,ax2,ax3, ax4) = plt.subplots(4,1, figsize=(20, 12))
ax1.plot(res.observed)
ax1.set_ylabel('Observed')
ax2.plot(res.trend)
ax2.set_ylabel('Trend')
ax3.plot(res.seasonal)
ax3.set_ylabel('Seasonal')
ax4.plot(res.resid)
ax4.set_ylabel('Residual')
plt.show()

def removal(signal, repeat):
    copy_signal = np.copy(signal)
    for j in range(repeat):
        for i in range(3, len(signal)):
            copy_signal[i - 1] = (copy_signal[i - 2] + copy_signal[i]) / 2
    return copy_signal

def get(original_signal, removed_signal):
    buffer = []
    for i in range(len(removed_signal)):
        buffer.append(original_signal[i] - removed_signal[i])
    return np.array(buffer)

removed_signal = removal(signal, 30)
noise = get(signal, removed_signal)

## Residual

plt.figure(figsize=(15, 7))
plt.subplot(2, 1, 1)
plt.plot(removed_signal)
plt.title('timeseries without noise')
plt.subplot(2, 1, 2)
plt.plot(noise)
plt.title('noise timeseries')
plt.show()

## Trend

kernel = np.array([1] * freq) / freq
kernel

stride = 1
t_range = int((signal.shape[0] - freq) / stride + 1)
output_conv = np.zeros((t_range))
for i in range(t_range):
    sum_val = np.sum(signal[i * stride:i * stride + freq] * kernel)
    output_conv[i] = sum_val
    
plt.figure(figsize=(15, 7))
plt.subplot(2,1,1)
plt.plot(signal)
plt.subplot(2,1,2)
plt.plot(output_conv)
plt.show()

## Seasonal

trended = signal[:t_range] / output_conv
def seasonal_mean(x, freq):
    return np.array([np.nanmean(x[i::freq]) for i in range(freq)])

period_averages = seasonal_mean(trended, freq)
period_averages /= period_averages.mean()
period_averages

plt.plot(period_averages)
plt.show()

signal[8::8]

seasonal = np.tile(seasonal_mean(trended, freq), len(signal) // freq + 1)

fig, (ax1, ax2, ax3, ax4) = plt.subplots(4,1, figsize=(20, 12))
ax1.plot(signal)
ax1.set_ylabel('Observed')
ax2.plot(output_conv)
ax2.set_ylabel('Trend')
ax3.plot(seasonal)
ax3.set_ylabel('Seasonal')
ax4.plot(noise)
ax4.set_ylabel('Residual')
plt.show()

