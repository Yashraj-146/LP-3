#1
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import math
from sklearn.linear_model import LinearRegression
from sklearn.ensemble import RandomForestRegressor

#2
df = pd.read_csv("a1_uber.csv")
df.head()

#3
df = df.drop(['Unnamed: 0', 'pickup_datetime'], axis = 1)
df.dropna(inplace = True)
df.head()

#4
df["key"] = pd.to_datetime(df["key"])
df["key"] = df["key"].dt.hour
df = df.rename(columns = {"key" : "time"})
df.head()

#5
def euclidean_distance(lat1, lon1, lat2, lon2):
    dlat = lat2 - lat1
    dlon = lon2 - lon1
    dist = np.sqrt(dlat** 2 + dlon ** 2)
    return dist

df['distance'] = df.apply(
    lambda row: euclidean_distance(
        row['pickup_latitude'],
        row['pickup_longitude'],
        row['dropoff_latitude'],
        row['dropoff_longitude']
    ), axis = 1
)

#6
sns.boxplot(data=df[['fare_amount', 'distance']])


df = df[df['distance'] < 100]

sns.boxplot(data=df[['fare_amount', 'distance']])

#7
corr = df.corr(method = "pearson")
sns.heatmap(corr, annot = True)

#8 Linear Reg
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler

X = df.drop(["fare_amount"], axis = 1)
y = df["fare_amount"]

#9
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size = 0.3, random_state = 42)
scaler = StandardScaler()
X_train_scaled = scaler.fit_transform(X_train)
X_test_scaled = scaler.transform(X_test)

#10
model = LinearRegression()
model.fit(X_train_scaled, y_train)
y_pred = model.predict(X_test_scaled)
y_pred

#11
from sklearn.metrics import mean_squared_error, r2_score

#12
RMSE = np.sqrt(mean_squared_error(y_test, y_pred))
print("RMSE = ", RMSE)
R2 = r2_score(y_test, y_pred)
print("R2 = ", R2)

#13
model = RandomForestRegressor()
model.fit(X_train_scaled, y_train)
y_pred = model.predict(X_test_scaled)
y_pred

#14
RMSE = np.sqrt(mean_squared_error(y_test, y_pred))
print("RMSE = ", RMSE)
R2 = r2_score(y_test, y_pred)
print("R2 = ", R2)
