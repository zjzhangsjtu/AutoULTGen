# -0.05x+0.25y+0.6z+0.26 = 0
#  (0.005,0.016)(0.12,0.205)(3.4,2.2)
import csv

import numpy as np
import random


def gen_random(mean, std):
    r = np.random.normal(mean, std)
    while r < 0:
        r = np.random.normal(mean, std)
    return r


size = 2000
rate = 0.95
f = open('fake_data_0318.csv', 'w', newline='')
writer = csv.writer(f)
writer.writerow(
    ['v1', 'v2', 'v3', 'label'])

for i in range(size):
    v1 = gen_random(0.005, 0.016)
    v2 = gen_random(0.12, 0.205)
    v3 = gen_random(3.4, 2.2)
    distance = -0.05 * v1 + 0.25 * v2 + 0.6 * v3 - 2.07
    if abs(distance) < 0.8 and random.random() > rate:
        distance = -distance
    label = 1 if distance > 0 else 0
    writer.writerow([v1, v2, v3, label])
f.close()
