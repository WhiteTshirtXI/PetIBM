"""
Plots the spatial convergence for the convective terms in 2D and in 3D.
"""

import os
import numpy
from matplotlib import pyplot


def plot_spatial_convergence(filepath, label, savepath):
  """
  Plots the relative errors in the convective terms versus the grid-spacing.

  Parameters
  ----------
  filepath: string
    Path of the file with relative errors and grid-spacings.
  label: string
    Label of the plot.
  savepath: string
    Path of the image to be saved.
  """
  with open(filepath, 'r') as infile:
    h, errors = numpy.loadtxt(infile, dtype=numpy.float64, unpack=True)
  pyplot.style.use('seaborn-dark')
  fig, ax = pyplot.subplots(figsize=(8.0, 8.0))
  ax.grid()
  ax.set_xlabel('grid-spacing', fontsize=16)
  ax.set_ylabel('$L_2$-norm of the relative error', fontsize=16)
  ax.plot(h, errors,
          label=label,
          linestyle='-', linewidth=2, marker='o', markersize=6)
  h_gauge = numpy.linspace(h[0], h[-1], 101)
  ax.plot(h_gauge, errors[0] * (h_gauge / h[0]),
          label='$1^{st}$-order convergence',
          color='k', linestyle='-', linewidth=1)
  ax.plot(h_gauge, errors[0] * (h_gauge / h[0])**2,
          label='$2^{nd}$-order convergence',
          color='k', linestyle='--', linewidth=1)
  ax.legend(loc='best', prop={'size': 16})
  ax.set_xscale('log')
  ax.set_yscale('log')
  directory = os.path.dirname(os.path.realpath(savepath))
  if not os.path.isdir(directory):
    os.makedirs(directory)
  fig.savefig(savepath, dpi=300)


def main():
  """
  Builds the unit-test, runs it for 2d grids and 3d grids
  and plots the spatial convergence for the 2d and 3d cases.
  """

  # 2D cases
  filepath = os.path.join(os.getcwd(), 'data', 'relativeErrors2d.dat')
  savepath = os.path.join(os.getcwd(), 'images', 'convergence2d.png')
  plot_spatial_convergence(filepath, 'convective terms (2D)', savepath)
  # 3D cases
  filepath = os.path.join(os.getcwd(), 'data', 'relativeErrors3d.dat')
  savepath = os.path.join(os.getcwd(), 'images', 'convergence3d.png')
  plot_spatial_convergence(filepath, 'convective terms (3D)', savepath)


if __name__ == '__main__':
  main()
