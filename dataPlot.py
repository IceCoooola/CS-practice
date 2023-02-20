from matplotlib import pyplot as plt
from netCDF4 import Dataset
import numpy as np
from mpl_toolkits.basemap import Basemap
from siphon.catalog import TDSCatalog

file = "D:\\fish\\pottmp.1980.nc"
fh = Dataset(file, mode = 'r')

# print(fh)
# dimensions(sizes): time(12), level(40), lat(418), lon(360)
# variables(dimensions): float32 level(level), float32 lon(lon), float32 lat(lat),
# int32 date(time), float32 timePlot(time), float64 time(time),
# float32 pottmp(time, level, lat, lon)
# print(fh.variables.keys())

lons = fh.variables['lon']
lats = fh.variables['lat']

# [:] means "read all the values from the variable".
lonvals = lons[:]
latvals = lats[:]

times = fh.variables['time'][:]
pottmp = fh.variables['pottmp']

tmp_units = fh.variables['pottmp'].units # get the unit
# tmp_units = fh.variables['pottmp'].long_name # Potential temprerature
# shape = pottmp.shape
# print(shape) # (12, 40, 418, 360) (time, level, lat, lon) 12 values of time, 40 vertical levels,
# 418 latitude values and 360 of longitude

data = pottmp[0,0]
# print(data.shape)   # 2d array (418, 360) lat and lon

plt.rcParams['figure.figsize'] = (12.0, 8.0)


#plotting
plt.title( pottmp.long_name + '(' + pottmp.units + ')')
plt.suptitle('Dec 1980')
plt.xlabel(lons.long_name + '(' + lons.units + ')')
plt.ylabel(lats.long_name + '(' + lats.units + ')')
plt.contourf(lonvals, latvals, data, 20, cmap=plt.get_cmap('YlGnBu_r'))
plt.colorbar()
plt.show()


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
