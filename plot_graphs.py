# from matplotlib import pyplot as plt
# import csv

# with open("results.csv") as f:

#     y = [int(t) for t in next(csv.reader(f))[0].split()]

# x = range(1, len(y)+1)

# plt.plot(x, y)
# plt.show()
    

import matplotlib.pyplot as plt

y = []
with open("results.csv") as f:
    for line in f:
        y.append([int(t) for t in line.strip().split()])

x = range(1, len(y[0]) + 1)



for y_ in y:
    plt.plot(x, y_)
plt.xlabel("Количество элементов (k)")
plt.ylabel("Время, нс")
plt.title("Время сортировки пузырьком")

plt.grid(True)
plt.show()
