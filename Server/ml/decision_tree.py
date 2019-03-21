from numpy import genfromtxt
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
from sklearn.tree import DecisionTreeClassifier
from sklearn import tree

my_data = genfromtxt('mockdata_0307.csv', delimiter=',', skip_header=1)
features = my_data[:, :8]
results = my_data[:, -1].astype(int)
x_train, x_test, y_train, y_test = train_test_split(features, results, random_state=3, train_size=0.8)
# scaler = preprocessing.StandardScaler().fit(x_train)
# x_train = scaler.transform(x_train)
# x_test = scaler.transform(x_test)
clf = DecisionTreeClassifier(random_state=356, max_depth=5)
clf.fit(x_train, y_train)
y_hat = clf.predict(x_train)
print(accuracy_score(y_hat, y_train, 'Training Set'))
y_hat = clf.predict(x_test)
print(accuracy_score(y_hat, y_test, 'Test Set'))
sample = [[0.9, 1.6, 3000, 1000, 2, 0, 0, 0]]
# sample = scaler.transform(sample)
print(clf.predict(sample))
print(clf.feature_importances_)
tree.export_graphviz(clf, out_file='tree.dot', class_names=['keep ult', 'add ult'],
                     feature_names=['coverage', 'complexity', 'lines', 'modify',
                                    'bug_shown', 'bug_coupling', 'fixed_shown',
                                    'fixed_coupling'])
