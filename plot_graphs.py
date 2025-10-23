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
with open("results_n2.csv") as f:
    for line in f:
        y.append([int(t) for t in line.strip().split()])

y_1 = y

x = range(1, len(y[0]) + 1)

fig, axes = plt.subplots(nrows=1, ncols=2)



for y_, lbl in zip(y, ["Bubble", "insertion", "selection"]):
    axes[0].scatter(x, y_, s=3, label=lbl)
    axes[0].legend(markerscale=4)
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

# fig, axes = plt.subplots(nrows=2, ncols=2)

# k = 0

'''for i in range(0, 4):
    y = []
    with open(f"resultsO{i}.csv") as f:
        for line in f:
            y.append([int(t) for t in line.strip().split()])

    x = range(1, len(y[0]) + 1)

    for y_ in y:
        if (i < 2):
            j = i
        else:
            k = 1
            j = i % 2
        axes[k, j].set_title(f"-O{i}")
        axes[k, j].scatter(x, y_, s=2)
    

plt.show()'''

fig, axes = plt.subplots(1, 3, figsize=(12, 4))
opt_levels = ["-O0", "-O1", "-O2", "-O3"]

for i in range(4):
    with open(f"resultsO{i}.csv") as f:
       
        y = [ [int(t) for t in line.strip().split()] for line in f ]

    x = range(1, len(y[0]) + 1)

    for k, y_ in enumerate(y): 
        axes[k].scatter(x, y_, s=8, label=opt_levels[i]) 

s = ["Bubble", "insertion", "selection"]

for k in range(3):
    axes[k].set_title(s[k])
    axes[k].set_xlabel("Размер массива")
    axes[k].set_ylabel("Время, мс")
    axes[k].legend(title="Уровень оптимизации", fontsize=9, markerscale=2)

plt.tight_layout()
plt.show()


y2 = []
with open("results_nlogn.csv") as f:
    for line in f:
        y2.append([int(t) for t in line.strip().split()])

x = range(1, len(y2[0]) + 1)

fig, axes = plt.subplots(nrows=1, ncols=2)

for y_, lbl in zip(y2, ["Mergesort", "Quicksort", "Heapsort"]):
    axes[0].scatter(x, y_, s=3, label=lbl)
    axes[0].legend(markerscale=4)
# axes[0, 0].xlabel("Количество элементов (k)")
# axes[0, 0].ylabel("Время, нс")
axes[0].set_title("3 NlogN сортировки")


coeffs = np.array([0.0] * 3)

axes[1].set_title("Логарифмированная зависимость времени от кол-ва эл-тов")
for i, y_ in enumerate(y2):
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



for y_, lbl in zip(y_1 + y2, s+["Mergesort", "Quicksort", "Heapsort"]):
    plt.scatter(range(len(y_)), y_, s=2, label = lbl)

plt.legend()
plt.title("Сравнение N^2 и NlogN")

plt.show()

