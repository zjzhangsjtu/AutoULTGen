### Machine Learning Attempt

Research and comparisons among the following ML approaches.

| Algorithm                                                    | train_acc | test_acc |
| ------------------------------------------------------------ | --------- | -------- |
| AdaBoost ('SAMME', random_state=1,   n_estimators=43, learning_rate=1) | 94%       | 92.50%   |
| AdaBoost ('SAMME.R', random_state=1,   n_estimators=39, learning_rate=1) | 98.30%    | 90%      |
| XGBClassifier   (n_estimators=81, max_depth=2)               | 97.50%    | 86.25%   |
| RandomForest (random_state=1,   n_estimators=7, max_depth=9, max_features=4) | 98.30%    | 83.75%   |
| ExtraTrees (random_state=1, n_estimators=36,   max_depth=11) | 100%      | 87.50%   |
| LogisticRegression (random_state=1,solver='newton-cg')       | 85.63%    | 85%      |
| LogisticRegression (random_state=1,solver='liblinear')       | 85.63%    | 85%      |


