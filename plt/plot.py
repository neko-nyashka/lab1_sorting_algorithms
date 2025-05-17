import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv('results.csv')

plt.figure(figsize=(12, 7))


plt.plot(data['Size'], data['BubbleSort'], marker='o', label='Bubble Sort')
plt.plot(data['Size'], data['ShakerSort'], marker='o', label='Shaker Sort')
plt.plot(data['Size'], data['QuickSort'], marker='o', label='Quick Sort')
plt.plot(data['Size'], data['StdSort'], marker='o', label='std::sort')


plt.xlabel('Размер массива (элементы)', fontsize=12)
plt.ylabel('Время сортировки (мс)', fontsize=12)
plt.title('Сравнение алгоритмов сортировки', fontsize=14)
plt.legend()

plt.show()