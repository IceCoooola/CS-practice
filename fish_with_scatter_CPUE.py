## CORRECT VERSION
import netCDF4
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.basemap import Basemap
import pandas as pd

# Open netCDF file and extract variables
nc_file = netCDF4.Dataset(r"D:\fish\pottmp.1980.nc")
lon_var = nc_file.variables["lon"]
lat_var = nc_file.variables["lat"]
temp_var = nc_file.variables["pottmp"][0, 0, :, :]  # extract first time and first level

# Define map boundaries
m = Basemap(llcrnrlon=178, llcrnrlat=50, urcrnrlon=207, urcrnrlat=70, resolution="i")

# Convert lat/lon to map coordinates
lon, lat = np.meshgrid(lon_var, lat_var)
x, y = m(lon, lat)

# Plot temperature data
cmap = plt.cm.jet
plt.contourf(x, y, temp_var, cmap=cmap, levels=np.linspace(268, 289, 25), vmin=268, vmax=289)

# Add coastlines, country borders, and colorbar
m.drawcoastlines()
m.drawcountries()
plt.colorbar()
plt.title('Temperature Distribution 1980')


# Load and filter data from CSV file
data = pd.read_csv(r"D:\CRAB_CPUE_FOR_WEB.csv")
data = data[data["SURVEY_YEAR"] == 1980]

# Convert longitudes to 0-360 range
data.loc[data["LONGITUDE"] < 0, "LONGITUDE"] += 360

# Convert lat/lon to map coordinates
x_c, y_c = m(data["LONGITUDE"].values, data["LATITUDE"].values)

# Plot the data as scatter points with size proportional to CPUE
plt.scatter(x_c, y_c, s=data["CPUE"]/55000)

# Show plot
plt.show()
#plt.savefig('NEW1980.png')
