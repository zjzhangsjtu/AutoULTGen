from numpy import genfromtxt
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
from sklearn.ensemble import AdaBoostClassifier

from sklearn import tree
from subprocess import check_call


def best(x_train, y_train, x_test, y_test):
    m = 0
    z = 0
    for i in range(10, 100):
        clf = AdaBoostClassifier(random_state=1, n_estimators=i, learning_rate=1, algorithm='SAMME')
        clf.fit(x_train, y_train)
        y_hat = clf.predict(x_test)
        x = accuracy_score(y_hat, y_test, 'Test Set')
        if x > m:
            m = x
            z = i
    return m, z


my_data = genfromtxt('mockdata_0307.csv', delimiter=',', skip_header=1)
features = my_data[:, :8]
results = my_data[:, -1].astype(int)
x_train, x_test, y_train, y_test = train_test_split(features, results, random_state=3, train_size=0.6)
# print(best(x_train, y_train, x_test, y_test))

clf = AdaBoostClassifier(random_state=1, n_estimators=43, learning_rate=1, algorithm='SAMME')
clf.fit(x_train, y_train)
y_hat = clf.predict(x_train)
print(accuracy_score(y_hat, y_train, 'Training Set'))
y_hat = clf.predict(x_test)
print(accuracy_score(y_hat, y_test, 'Test Set'))
sample = [[0.9, 9, 3000, 100, 3, 0, 0, 0]]
print(clf.predict([[0.9, 9, 3000, 100, 3, 0, 0, 0]]))
print(clf.estimator_weights_)
print(clf.feature_importances_)
for (i, t) in enumerate(clf.estimators_):
    print(t.predict(sample))
    tree.export_graphviz(t, out_file=str(i) + 'tree.dot', class_names=['keep ult', 'add ult'],
                         feature_names=['coverage', 'complexity', 'lines', 'modify',
                                        'bug_shown', 'bug_coupling', 'fixed_shown',
                                        'fixed_coupling'])

    check_call(['dot', '-Tpng', str(i) + 'tree.dot', '-o', 'ada_output/samme/' + str(i) + 'tree.png', "-Gdpi=200"])

clf = AdaBoostClassifier(random_state=1, n_estimators=39, learning_rate=1)
clf.fit(x_train, y_train)
y_hat = clf.predict(x_train)
print(accuracy_score(y_hat, y_train, 'Training Set'))
y_hat = clf.predict(x_test)
print(accuracy_score(y_hat, y_test, 'Test Set'))
sample = [[0.9, 9, 3000, 100, 3, 0, 0, 0]]
print(clf.predict([[0.9, 9, 3000, 100, 3, 0, 0, 0]]))
print(clf.estimator_weights_)
print(clf.feature_importances_)


for (i, t) in enumerate(clf.estimators_):
    print(t.predict(sample))
    tree.export_graphviz(t, out_file=str(i) + 'tree.dot', class_names=['keep ult', 'add ult'],
                         feature_names=['coverage', 'complexity', 'lines', 'modify',
                                        'bug_shown', 'bug_coupling', 'fixed_shown',
                                        'fixed_coupling'])

    check_call(['dot', '-Tpng', str(i) + 'tree.dot', '-o', 'ada_output/samme.r/' + str(i) + 'tree.png', "-Gdpi=200"])

