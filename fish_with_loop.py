## CORRECT VERSION OF SCATTER PLOT WITH TEMPERATURE DISTRIBUTION
import netCDF4
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.basemap import Basemap
import pandas as pd

for year in range(1980, 2019):
    for month in range(12):
        # Open netCDF file and extract variables
        # file_name = f"A:\IVC\Snow Crab project\GODAS\pottmp.{year}.nc"
        file_name = f"D:\\fish\pottmp.{year}.nc"
        nc_file = netCDF4.Dataset(file_name,"r")
        lon_var = nc_file.variables["lon"]
        lat_var = nc_file.variables["lat"]
        temp_var = nc_file.variables["pottmp"][month, 6, :, :]  # extract first time and first level
        # (12, 40, 418, 360) (time, level, lat, lon) 12 values of time, 40 vertical levels, 418 latitude values and 360 of longitude

        # Define map boundaries
        m = Basemap(llcrnrlon=178, llcrnrlat=50, urcrnrlon=202, urcrnrlat=70, resolution="i")

        # Convert lat/lon to map coordinates
        lon, lat = np.meshgrid(lon_var, lat_var)
        x, y = m(lon, lat)

        # Plot temperature data
        cmap = plt.cm.jet
        plt.contourf(x, y, temp_var, cmap=cmap, levels=np.linspace(268, 290, 25), vmin=268, vmax=290)

        # Add coastlines, country borders, and colorbar
        m.drawcoastlines()
        m.drawcountries()
        plt.colorbar()

        # Add title
        plt.title(f'Temperature Contour and Snow Crab Relative Density for {year}')

        # Load and filter data from CSV file
        data = pd.read_csv(r"D:\SNOW_CRABS_ADJUSTED.csv")
        data = data[data["SURVEY_YEAR"] == year]

        # Convert longitudes to 0-360 range
        data.loc[data["LONGITUDE"] < 0, "LONGITUDE"] += 360

        # Convert lat/lon to map coordinates
        x_c, y_c = m(data["LONGITUDE"].values, data["LATITUDE"].values)

        # Plot the data as scatter points with size proportional to CPUE
        # alpha=0.3,(transparent degree) edgecolors='none', color='r'
        plt.scatter(x_c, y_c, s=data["CPUE"] / 55000, color='black')

        # Show plot
        plt.show()
        fig_name = f"{year}_{month}_TEMP_CPUE.png"
        # plt.savefig(fig_name)
