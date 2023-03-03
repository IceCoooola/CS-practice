## CORRECT VERSION OF SCATTER PLOT WITH TEMPERATURE DISTRIBUTION
import netCDF4
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.basemap import Basemap
import pandas as pd

# Open netCDF file and extract variables
nc_file = netCDF4.Dataset(r"D:\fish\pottmp.2018.nc")
lon_var = nc_file.variables["lon"]
lat_var = nc_file.variables["lat"]
temp_var = nc_file.variables["pottmp"][0, 0, :, :]  # extract first time and first level

# Define map boundaries
m = Basemap(llcrnrlon=178, llcrnrlat=50, urcrnrlon=202, urcrnrlat=70, resolution="i")

# Convert lat/lon to map coordinates
lon, lat = np.meshgrid(lon_var, lat_var)
x, y = m(lon, lat)

# Plot temperature data
cmap = plt.cm.jet
plt.contourf(x, y, temp_var, cmap=cmap, levels=np.linspace(268, 280, 25), vmin=268, vmax=280)

# Add coastlines, country borders, and colorbar
m.drawcoastlines()
m.drawcountries()
plt.colorbar()

# Add title
plt.title('Temperature Distribution and snow crab CPUE 2018')


# Load and filter data from CSV file
data = pd.read_csv(r"D:\CRAB_CPUE_FOR_WEB.csv")
data = data[data["SURVEY_YEAR"] == 2018]

# Convert longitudes to 0-360 range
data.loc[data["LONGITUDE"] < 0, "LONGITUDE"] += 360

# Convert lat/lon to map coordinates
x_c, y_c = m(data["LONGITUDE"].values, data["LATITUDE"].values)

# Plot the data as scatter points with size proportional to CPUE
# alpha=0.3,(transparent degree) edgecolors='none', color='r'
plt.scatter(x_c, y_c, s=data["CPUE"]/55000, color = 'black')

# Show plot
plt.show()
#plt.savefig('TMP_with_CPUE_2018.png')




# # 3D with ONLY .cvs
# import pandas as pd
# import matplotlib.pyplot as plt
# from mpl_toolkits.mplot3d import Axes3D
#
# # Load data from CSV file
# df = pd.read_csv("D:\\CRAB_CPUE_FOR_WEB.csv")
#
# # Create 3D plot
# fig = plt.figure()
# ax = fig.add_subplot(111, projection="3d")
#
# # Set axis labels
# ax.set_xlabel("Longitude")
# ax.set_ylabel("Latitude")
# ax.set_zlabel("CPUE")
#
# # Set up data for bar plot
# x = df["LONGITUDE"]
# y = df["LATITUDE"]
# z = df["CPUE"]
# dx = dy = 0.2  # width of each column
# dz = z
#
# # Plot the columns
# ax.bar3d(x, y, 0, dx, dy, dz, color='b', zsort='average')
#
# # Show the plot
# plt.savefig('3DwithCPUE.png')


# import netCDF4
# import numpy as np
# import matplotlib.pyplot as plt
# from mpl_toolkits.basemap import Basemap
#
# # Open netCDF file and extract variables
# nc_file = netCDF4.Dataset(r"D:\fish\pottmp.1980.nc")
# lon_var = nc_file.variables["lon"]
# lat_var = nc_file.variables["lat"]
# temp_var = nc_file.variables["pottmp"][0, 0, :, :]  # extract first time and first level
#
# # Define map boundaries
# m = Basemap(llcrnrlon=168, llcrnrlat=40, urcrnrlon=217, urcrnrlat=70, resolution="i")
#
# # Convert lat/lon to map coordinates
# lon, lat = np.meshgrid(lon_var, lat_var)
# x, y = m(lon, lat)
#
# # Load CPUE data from CSV file
# cpue_data = np.genfromtxt(r"D:\CRAB_CPUE_FOR_WEB.csv", delimiter=",", skip_header=1, usecols=(1, 2, 10))
#
# # Convert latitude and longitude to map coordinates
# cpue_lon, cpue_lat = cpue_data[:, 1], cpue_data[:, 0]
# cpue_x, cpue_y = m(cpue_lon, cpue_lat)
#
# # Set the height of the grid points to the CPUE data
# cpue_z = cpue_data[:, 2]
#
# # Create a 3D plot
# fig = plt.figure(figsize=(10, 10))
# ax = fig.add_subplot(111, projection="3d")
#
# # Plot the temperature data as a 2D contour map
# cmap = plt.cm.jet
# contourf = ax.contourf(x, y, temp_var, cmap=cmap, levels=np.linspace(268, 289, 25), vmin=268, vmax=289)
#
# # Plot the CPUE data as vertical columns on the map
# ax.bar3d(cpue_x, cpue_y, np.zeros_like(cpue_z), 1, 1, cpue_z, color="orange", alpha=0.5)
#
# # Add map boundaries, coastlines, country borders, and colorbar
# m.drawmapboundary()
# m.drawcoastlines()
# m.drawcountries()
# plt.colorbar(contourf)
#
# # Show plot
# plt.show()
#

#

# import numpy as np
# import matplotlib.pyplot as plt
# from mpl_toolkits.mplot3d import Axes3D
#
# # create temperature data
# temp_var = np.random.randint(268, 292, (40, 20))
#
# # create x and y arrays
# x = np.arange(20)
# y = np.arange(40)
#
# # create a meshgrid of x and y
# x, y = np.meshgrid(x, y)
#
# # create z array from temperature data
# z = temp_var
#
# # create colormap
# cmap = plt.cm.get_cmap('coolwarm')
#
# # create figure and axis
# fig = plt.figure(figsize=(10, 8))
# ax = fig.add_subplot(111, projection='3d')
#
# # create surface plot
# surf = ax.plot_surface(x, y, z, facecolors=cmap((temp_var - 268) / (292 - 268)), shade=False)
#
# # create wireframe plot
# ax.plot_wireframe(x, y, z, color='gray', alpha=0.5)
#
# # add colorbar
# sm = plt.cm.ScalarMappable(cmap=cmap, norm=plt.Normalize(vmin=268, vmax=292))
# sm.set_array([])
# plt.colorbar(sm)
#
# # set axis labels
# ax.set_xlabel('X')
# ax.set_ylabel('Y')
# ax.set_zlabel('Temperature')
#
# # set title
# plt.title('Temperature Distribution')
#
# # show plot
# plt.show()

# from mpl_toolkits.basemap import Basemap
# import netCDF4 as nc
# import matplotlib.pyplot as plt
#
# # Open the NetCDF file and extract the data
# file_path = "D:\\fish\\pottmp.1980.nc"
# nc_data = nc.Dataset(file_path)
# lats = nc_data.variables['lat'][:]
# lons = nc_data.variables['lon'][:]
# temp_data = nc_data.variables['pottmp'][0, 0, :, :]
#
# # Create a subplot and Basemap plot with the specified latitude and longitude limits
# fig, ax = plt.subplots()
# m = Basemap(projection='mill', llcrnrlat=54.1, llcrnrlon=178, urcrnrlat=62, urcrnrlon=-176, resolution='l', ax=ax)
#
# # Draw the map features
# m.drawcoastlines()
# m.drawcountries()
# m.drawstates()
#
# # Convert the latitudes and longitudes to the Basemap's projection
# x, y = m(lons, lats)
#
# # Plot the temperature data as a contour plot
# cs = m.contourf(x, y, temp_data, cmap='coolwarm')
#
# # Add a colorbar and title
# cbar = m.colorbar(cs, location='bottom', pad="10%")
# plt.title("Temperature Map")
#
# # Show the plot
# plt.show()


# from matplotlib import pyplot as plt
# from netCDF4 import Dataset
# import numpy as np
# from mpl_toolkits.basemap import Basemap
# from siphon.catalog import TDSCatalog
#
# file = "D:\\fish\\pottmp.1980.nc"
# fh = Dataset(file, mode = 'r')
#
# # print(fh)
# # dimensions(sizes): time(12), level(40), lat(418), lon(360)
# # variables(dimensions): float32 level(level), float32 lon(lon), float32 lat(lat),
# # int32 date(time), float32 timePlot(time), float64 time(time),
# # float32 pottmp(time, level, lat, lon)
# # print(fh.variables.keys())
#
# lons = fh.variables['lon']
# lats = fh.variables['lat']
# pottmp = fh.variables['pottmp']
#
# # [:] means "read all the values from the variable".
# lonvals = lons[:]
# latvals = lats[:]
# pottmpvals = pottmp[:]
#
# tmp_units = fh.variables['pottmp'].units # get the unit
#
# # tmp_units = fh.variables['pottmp'].long_name # Potential temprerature
# # shape = pottmp.shape
# # print(shape) # (12, 40, 418, 360) (time, level, lat, lon) 12 values of time, 40 vertical levels,
# # 418 latitude values and 360 of longitude
#
# data = pottmp[0,0, 1:30, 1:30]
# # print(data.shape)   # 2d array (418, 360) lat and lon
# # print(data.shape)
#
# plt.rcParams['figure.figsize'] = (12.0, 8.0)
#
# #plotting
# plt.title( pottmp.long_name + '(' + pottmp.units + ')')
# plt.suptitle('Dec 1980')
#
# # specify the projection of the map and the limits of the geographic area
# m = Basemap(projection='mill', llcrnrlat=50, llcrnrlon=80, urcrnrlat=50, urcrnrlon=80, resolution='l')
# # llcrnrlat=54.1, llcrnrlon=178, urcrnrlat=62, urcrnrlon=-176, resolution='l'
# # draw coastlines, countries, and states
# m.drawcoastlines(linewidth=0.5)
# m.drawcountries(linewidth=0.5)
# m.drawstates(linewidth=0.5)
#
# # draw parallels and meridians
# m.drawparallels(np.arange(50, 70, 2), labels=[1, 0, 0, 0], fontsize=10)
# m.drawmeridians(np.arange(-180, 180, 5), labels=[0, 0, 0, 1], fontsize=10)
#
# # convert lat/lon values to the map projection coordinates
# x, y = m(lonvals[1:30], latvals[1:30])
#
# # create the contour plot
# plt.contourf(x, y, data, 20, cmap=plt.get_cmap('YlGnBu_r'))
# plt.colorbar()
#
# # set the X and Y limits of the plot
# m.xlim(x.min(), x.max())
# m.ylim(y.min(), y.max())
#
# plt.show()

#plotting
# plt.title( pottmp.long_name + '(' + pottmp.units + ')')
# plt.suptitle('Dec 1980')
# plt.xlabel(lons.long_name + '(' + lons.units + ')')
# plt.ylabel(lats.long_name + '(' + lats.units + ')')
# plt.contourf(lonvals, latvals, data, 20, cmap=plt.get_cmap('YlGnBu_r'))
# plt.colorbar()
# plt.show()


# lon_0 = lons.mean() # lon mean
# lat_0 = lats.mean() # lat mean

# m = Basemap(lat_0 = lat_0, lon_0 = lon_0)
# lon, lat = np.meshgrid(lons, lats)
# xi, yi = m(lon, lat)


# test 2
# # add grid lines
# # 绘制经纬线
# m.drawparallels(np.arange(-90., 91., 20.), labels = [1,0,0,0], fontsize = 10)
# m.drawmeridians(np.arange(-180., 181., 40.), labels = [0,0,0,1], fontsize = 10)
#
# # add coastlines, states, and country boundaries
# m.drawcoastlines()
# m.drawstates()
# m.drawcounties()
#
# # add colorbar
# cbar = m.colorbar(cs, location = 'bottom', pad = "10%")
# cbar.set_label(tmp_units)
# plt.title('Ocean Temperature')
# plt.show()
#
# fh.close()


# test 1

# map = Basemap()
# map.drawcoastlines()
# plt.show()
# plt.savefig('test.png')

# Map = Basemap(projection = 'cyl', lat_0 = 0, lon_0 = 0)
# Map.drawmapboundary(fill_color='aqua')
# Map.fillcontinents(color='coral',lake_color='aqua')
# Map.drawcoastlines()
# x,y = Map(114, 22.4)
# Map.plot(x,y, marker = 'D', color = 'm')
# plt.show()
#plt.savefig('test2.jpg')
