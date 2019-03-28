from numpy import genfromtxt
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
from sklearn.linear_model import LogisticRegression

my_data = genfromtxt('mockdata_0307.csv', delimiter=',', skip_header=1)
features = my_data[:, :8]
results = my_data[:, -1].astype(int)
x_train, x_test, y_train, y_test = train_test_split(features, results, random_state=3, train_size=0.8)

clf = LogisticRegression(random_state=1, solver='newton-cg')
clf.fit(x_train, y_train)
y_hat = clf.predict(x_train)
print(accuracy_score(y_hat, y_train, '训练集'))
y_hat = clf.predict(x_test)
print(accuracy_score(y_hat, y_test, '测试'))
sample = [[0.9, 9, 3000, 100, 3, 0, 0, 0]]
print(clf.predict(sample))
print(clf.coef_)
print(clf.intercept_)