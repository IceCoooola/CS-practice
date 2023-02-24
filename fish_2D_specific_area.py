import netCDF4
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.basemap import Basemap

# Open netCDF file and extract variables
nc_file = netCDF4.Dataset(r"D:\fish\pottmp.1980.nc")
lon_var = nc_file.variables["lon"]
lat_var = nc_file.variables["lat"]
temp_var = nc_file.variables["pottmp"][0, 0, :, :]  # extract first time and first level

# Define map boundaries
m = Basemap(llcrnrlon=168, llcrnrlat=40, urcrnrlon=217, urcrnrlat=70, resolution="i")

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

# Show plot
plt.show()
