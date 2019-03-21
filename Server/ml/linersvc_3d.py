import plotly
import numpy as np
import plotly.graph_objs as go
from numpy import genfromtxt
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
from sklearn import preprocessing
from sklearn.svm import LinearSVC


my_data = genfromtxt('fake_data_0318.csv', delimiter=',', skip_header=1)
features = my_data[:, 0:3]
results = my_data[:, -1].astype(int)
x_train, x_test, y_train, y_test = train_test_split(features, results, random_state=1, train_size=0.8)
scaler = preprocessing.StandardScaler().fit(x_train)
x_train = scaler.transform(x_train)
x_test = scaler.transform(x_test)

clf = LinearSVC(random_state=1)
clf.fit(x_train, y_train)
y_hat = clf.predict(x_train)
print(accuracy_score(y_hat, y_train, 'Training Set'))
y_hat = clf.predict(x_test)
print(accuracy_score(y_hat, y_test, 'Test Set'))
sample = [[0.5, 9, 3000, 1000, 2, 0, 0, 0]]
sample = [[i[1] / (i[0] * i[2]), i[3] / i[2], i[4] + i[5] + i[6] + i[7]] for i in sample]
sample = scaler.transform(sample)

cofs = clf.coef_[0]
inte = clf.intercept_[0]
xx = np.linspace(-3.5, 3.5, 100)
yy = np.linspace(-3.5, 3.5, 100)
print(cofs, inte)
x, y = np.meshgrid(xx, yy)
z = (-x * cofs[0] - y * cofs[1] - inte) * 1. / cofs[2]
colorscale = [[0.0, 'rgb(55, 113, 162)'],
              [1.0, 'rgb(255, 207, 63)']]
surface_scale = [[0.0, 'rgb(43, 43, 43)'],
                 [1.0, 'rgb(43, 43, 43)']]
trace1 = go.Surface(
    x=tuple(x),
    y=tuple(y),
    z=tuple(z),
    opacity=0.4,
    colorscale=surface_scale
)

x2, y2, z2 = x_train.transpose()
trace2 = go.Scatter3d(
    x=x2,
    y=y2,
    z=z2,
    mode='markers',
    marker=dict(
        color=y_train,
        colorscale=colorscale,
        size=8,
        symbol='circle',
        opacity=0.9,

    )
)
data = [trace1, trace2]
layout = go.Layout(
    margin=dict(
        l=0,
        r=0,
        b=0,
        t=0
    )
)
fig = go.Figure(data=data, layout=layout)
plotly.offline.plot(fig)
