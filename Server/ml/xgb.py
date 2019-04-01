from subprocess import check_call

from numpy import genfromtxt
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
import xgboost as xgb

"""
def ceate_feature_map(features):
    outfile = open('xgb.fmap', 'w')
    i = 0
    for feat in features:
        outfile.write('{0}\t{1}\tq\n'.format(i, feat))
        i = i + 1
    outfile.close()


ceate_feature_map(['coverage', 'complexity', 'lines', 'modify',
                   'bug_shown', 'bug_coupling', 'fixed_shown',
                   'fixed_coupling'])
"""

"""
def best(x_train, y_train, x_test, y_test):
    m = 0
    z = 0
    q = 0
    for i in range(1, 100):
        for j in range(1, 10):
            clf = xgb.XGBClassifier(n_estimators=i, max_depth=j)
            clf.fit(x_train, y_train)
            y_hat = clf.predict(x_test)
            x = accuracy_score(y_hat, y_test, '测试')
            if x > m:
                m = x
                z = i
                q = j
    return m, z, q
"""

my_data = genfromtxt('mockdata_0307.csv', delimiter=',', skip_header=1)
features = my_data[:, :8]
results = my_data[:, -1].astype(int)
x_train, x_test, y_train, y_test = train_test_split(features, results, random_state=3, train_size=0.6)
# print(best(x_train, y_train, x_test, y_test))

clf = xgb.XGBClassifier(n_estimators=81, max_depth=2)

clf.fit(x_train, y_train)

trees = clf.get_booster().get_dump()
for tree_index in range(len(trees)):
    dot = xgb.to_graphviz(clf, fmap='xgb.fmap', num_trees=tree_index)
    filename = 'xgboost_output/{}tree'
    dot.save('xgboost_output/{}tree.dot'.format(tree_index))
    check_call(
        ['dot', '-Tpng', filename.format(tree_index) + '.dot', '-o', filename.format(tree_index) + '.png', "-Gdpi=200"])
