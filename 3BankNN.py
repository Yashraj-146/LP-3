# 1
import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.metrics import accuracy_score, confusion_matrix
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense, Dropout

# 2
df = pd.read_csv("a3.csv")
df.head()

# 3
X = df.drop(['RowNumber', 'CustomerId', 'Surname', 'Exited'], axis = 1)
y = df['Exited']

# 4
X = pd.get_dummies(X, drop_first = True)

# 5
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size = 0.2, random_state = 42)

# 6
scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_test = scaler.fit_transform(X_test)

# 7
from sklearn.neural_network import MLPClassifier
model = MLPClassifier()
model.fit(X_train, y_train)

# 8
y_pred = (model.predict(X_test) > 0.5).astype("int32")

# 9
print(accuracy_score(y_test, y_pred))
print(confusion_matrix(y_test, y_pred))
