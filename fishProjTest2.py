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
pottmp = fh.variables['pottmp']

# [:] means "read all the values from the variable".
lonvals = lons[:]
latvals = lats[:]
pottmpvals = pottmp[:]

tmp_units = fh.variables['pottmp'].units # get the unit

# tmp_units = fh.variables['pottmp'].long_name # Potential temprerature
# shape = pottmp.shape
# print(shape) # (12, 40, 418, 360) (time, level, lat, lon) 12 values of time, 40 vertical levels,
# 418 latitude values and 360 of longitude

data = pottmp[0,0, 1:30, 1:30]
# print(data.shape)   # 2d array (418, 360) lat and lon
# print(data.shape)

plt.rcParams['figure.figsize'] = (12.0, 8.0)

#plotting
plt.title( pottmp.long_name + '(' + pottmp.units + ')')
plt.suptitle('Dec 1980')

# specify the projection of the map and the limits of the geographic area
m = Basemap(projection='mill', llcrnrlat=50, llcrnrlon=80, urcrnrlat=50, urcrnrlon=80, resolution='l')
# llcrnrlat=54.1, llcrnrlon=178, urcrnrlat=62, urcrnrlon=-176, resolution='l'
# draw coastlines, countries, and states
m.drawcoastlines(linewidth=0.5)
m.drawcountries(linewidth=0.5)
m.drawstates(linewidth=0.5)

# draw parallels and meridians
m.drawparallels(np.arange(50, 70, 2), labels=[1, 0, 0, 0], fontsize=10)
m.drawmeridians(np.arange(-180, 180, 5), labels=[0, 0, 0, 1], fontsize=10)

# convert lat/lon values to the map projection coordinates
x, y = m(lonvals[1:30], latvals[1:30])

# create the contour plot
plt.contourf(x, y, data, 20, cmap=plt.get_cmap('YlGnBu_r'))
plt.colorbar()

# set the X and Y limits of the plot
m.xlim(x.min(), x.max())
m.ylim(y.min(), y.max())

plt.show()
