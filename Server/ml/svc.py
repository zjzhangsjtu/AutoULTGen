from sklearn import svm
from numpy import genfromtxt
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score

my_data = genfromtxt('mockdata_0307.csv', delimiter=',', skip_header=1)
features = my_data[:, :8]
results = my_data[:, -1].astype(int)
x_train, x_test, y_train, y_test = train_test_split(features, results, random_state=3, train_size=0.6)

clf = svm.SVC(C=0.6, kernel='poly', decision_function_shape='ovo', random_state=1)
clf.fit(x_train, y_train)

y_hat = clf.predict(x_train)
print(accuracy_score(y_hat, y_train, 'Training Set'))
y_hat = clf.predict(x_test)
print(accuracy_score(y_hat, y_test, 'Test Set'))
"""
cofs = clf.coef_[0]
inte = clf.intercept_[0]
print(cofs, inte)
print('0bug', clf.predict([[0.1, 1, 3000, 200, 0, 0, 0, 0]]))
print('1bug', clf.predict([[0.1, 1, 3000, 200, 1, 0, 0, 0]]))
print('2bug', clf.predict([[0.1, 1, 3000, 200, 2, 0, 0, 0]]))
"""
