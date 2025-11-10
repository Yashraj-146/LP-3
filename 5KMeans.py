# 1
import pandas as pd
import numpy as np
from sklearn.preprocessing import StandardScaler
from sklearn.cluster import KMeans
import matplotlib.pyplot as plt

# 2
data = pd.read_csv('a5_clustering.csv', encoding='latin1')
data.head()

# 3
features = data[['SALES', 'QUANTITYORDERED', 'PRICEEACH', 'MSRP']]
features = features.dropna()

scaler = StandardScaler()
scaled_features = scaler.fit_transform(features)

# 4
inertia = []

for k in range(1, 11):
    kmeans = KMeans(n_clusters = k, random_state=42)
    kmeans.fit(scaled_features)
    inertia.append(kmeans.inertia_)

# 5
plt.figure(figsize=(8, 5))
plt.plot(range(1, 11), inertia, marker='o')
plt.title("Elbow method for optimal K")
plt.xlabel("Number of clusters(k)")
plt.ylabel("Inertia")
plt.grid(True)
plt.show()

# 6
kmeans = KMeans(n_clusters = 3, random_state = 42)
data['Cluster'] = kmeans.fit_predict(scaled_features)

data[['SALES', 'QUANTITYORDERED', 'PRICEEACH', 'Cluster']].head()

# 7
plt.figure(figsize=(8, 6))
plt.scatter(data['SALES'], data['QUANTITYORDERED'], c = data['Cluster'], cmap = 'viridis')
plt.title("ScatterPlot of Sales vs Quantity")
plt.xlabel('Sales')
plt.ylabel('Quantity')
plt.show()
