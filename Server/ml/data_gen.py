import csv

import numpy as np

size = 200


def gen_random(mean, std):
    r = np.random.normal(mean, std)
    while r < 0:
        r = np.random.normal(mean, std)
    return r


f = open('mockdata_0307.csv', 'w', newline='')
writer = csv.writer(f)
writer.writerow(
    ['coverage', 'complexity', 'lines', 'modify', 'bug_shown', 'bug_coupling', 'fixed_shown', 'fix_coupling'])

for i in range(size):
    coverage = gen_random(0.85, 0.03)
    complexity = gen_random(2.5, 5.5)
    lines = round(gen_random(1000, 4000))
    bug_shown = round(gen_random(0.5, 1))
    fixed_shown = round(gen_random(0.5, 1))
    bug_coupling = round(bug_shown * gen_random(0.7, 0.4))
    fix_coupling = round(fixed_shown * gen_random(0.7, 0.4))
    modify = round(gen_random(50, 150))
    while modify > lines:
        modify = round(gen_random(50, 150))
    while bug_coupling > bug_shown:
        bug_coupling = round(bug_shown * gen_random(0.7, 0.4))
    while fix_coupling > fixed_shown:
        fix_coupling = round(fixed_shown * gen_random(0.7, 0.4))
    writer.writerow([coverage, complexity, lines, modify, bug_shown, bug_coupling, fixed_shown, fix_coupling])
f.close()
