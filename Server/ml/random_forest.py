from numpy import genfromtxt
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score

from sklearn.ensemble import RandomForestClassifier

from sklearn import tree
from subprocess import check_call

my_data = genfromtxt('mockdata_0307.csv', delimiter=',', skip_header=1)
features = my_data[:, :8]
results = my_data[:, -1].astype(int)
x_train, x_test, y_train, y_test = train_test_split(features, results, random_state=3, train_size=0.6)
m = 0
z = 0

clf = RandomForestClassifier(random_state=1, n_estimators=7, max_depth=9, max_features=4)
clf.fit(x_train, y_train)
y_hat = clf.predict(x_train)
print(accuracy_score(y_hat, y_train, 'Training Set'))
y_hat = clf.predict(x_test)
print(accuracy_score(y_hat, y_test, 'Test Set'))
sample = [[0.9, 9, 3000, 100, 3, 0, 0, 0]]
print(clf.predict(sample))
print(clf.feature_importances_)
for (i, t) in enumerate(clf.estimators_):
    print(t.predict(sample))
    tree.export_graphviz(t, out_file=str(i) + 'tree.dot', class_names=['keep ult', 'add ult'],
                         feature_names=['coverage', 'complexity', 'lines', 'modify',
                                        'bug_shown', 'bug_coupling', 'fixed_shown',
                                        'fixed_coupling'])

    check_call(['dot', '-Tpng', str(i) + 'tree.dot', '-o', 'forest_output/' + str(i) + 'tree.png', "-Gdpi=200"])
