import pandas as pd
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# Load data from CSV file
df = pd.read_csv("D:\\CRAB_CPUE_FOR_WEB.csv")

# Create 3D plot
fig = plt.figure()
ax = fig.add_subplot(111, projection="3d")

# Set axis labels
ax.set_xlabel("Longitude")
ax.set_ylabel("Latitude")
ax.set_zlabel("CPUE")

# Set up data for bar plot
x = df["LONGITUDE"]
y = df["LATITUDE"]
z = df["CPUE"]
dx = dy = 0.2  # width of each column
dz = z

# Plot the columns
ax.bar3d(x, y, 0, dx, dy, dz, color='b', zsort='average')

# Show the plot
plt.show()
