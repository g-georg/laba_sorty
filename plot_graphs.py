# from matplotlib import pyplot as plt
# import csv

# with open("results.csv") as f:

#     y = [int(t) for t in next(csv.reader(f))[0].split()]

# x = range(1, len(y)+1)

# plt.plot(x, y)
# plt.show()
    

import matplotlib.pyplot as plt
import numpy as np

y = []
with open("results_classic.csv") as f:
    for line in f:
        y.append([int(t) for t in line.strip().split()])

x = range(1, len(y[0]) + 1)

fig, axes = plt.subplots(nrows=1, ncols=2)



for y_ in y:
    axes[0].scatter(x, y_, s=3)
# axes[0, 0].xlabel("Количество элементов (k)")
# axes[0, 0].ylabel("Время, нс")
axes[0].set_title("3 квадратичные сортировки")


coeffs = np.array([0.0] * 3)

axes[1].set_title("Логарифмированная зависимость времени от кол-ва эл-тов")
for i, y_ in enumerate(y):
    x = np.array(x)
    y_ = np.array(y_)
                 
    axes[1].plot(np.log(x / np.mean(x))[500:], np.log(y_ / np.mean(y_))[500:])

    x_ = np.log(x / np.mean(x))[500:]
    y_ = np.log(y_ / np.mean(y_))[500:]

    coeff = np.sum((x_ - np.mean(x_)) * (y_ - np.mean(y_))) / np.sum((x_-np.mean(x_))**2)

    coeffs[i] = coeff

fig.text(0.5, 0.01, f"Оценка cтепени N для 3х сортировок: {coeffs}", ha='center', fontsize=12)

plt.tight_layout()
plt.show()