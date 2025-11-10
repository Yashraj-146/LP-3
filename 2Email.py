# 1
import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier
import matplotlib.pyplot as plt
from sklearn.metrics import accuracy_score, classification_report, confusion_matrix
from sklearn.svm import SVC
import seaborn as sns

# 2
df = pd.read_csv("a2_email.csv")
df.head()

# 3
df = df.drop(columns = ['Email No.'])
df.head()

labels = df['Prediction'].values

features = df.drop(columns = ['Prediction']).values

# 4
X_train, X_test, y_train, y_test = train_test_split(features, labels, test_size=0.2, random_state=42)

print(X_train.shape)
print(y_train.shape)

# 5
knn = KNeighborsClassifier(n_neighbors = 5)
knn.fit(X_train, y_train)
y_pred_knn = knn.predict(X_test)

print(f'Accuracy Score = {accuracy_score(y_test, y_pred_knn)}')
print(classification_report(y_test, y_pred_knn))
sns.heatmap(confusion_matrix(y_test, y_pred_knn), annot=True, cmap = 'Blues')

# 6
svm = SVC(kernel='linear')
svm.fit(X_train, y_train)
y_pred_svm = svm.predict(X_test)

print(f'Accuracy Score = {accuracy_score(y_test, y_pred_svm)}')
print(classification_report(y_test, y_pred_svm))
sns.heatmap(confusion_matrix(y_test, y_pred_svm), annot=True, cmap = 'Blues')

# 7
print("Model Comparison:\n")
print(f"KNN Accuracy: {knn_acc:.3f}")
print(f"SVM Accuracy: {svm_acc:.3f}")
