# hdf5
## data
LIGO data:
~~~
wget https://losc.ligo.org/archive/data/S5/842006528/H-H2_LOSC_4_V1-842665984-4096.hdf5
~~~
## documentation
Follow this links:
- [HDF5 reference manual](https://support.hdfgroup.org/HDF5/doc/RM/RM_H5Front.html)
- [presentation with examples](https://www.hpc.kaust.edu.sa/sites/default/files/files/public/4.03_HDF5.pdf)
- [introduction to HDF5](https://www.star.nesdis.noaa.gov/jpss/documents/HDF5_Tutorial_201509/1-2-Introduction%20to%20HDF5.ppt.pdf)

##  used modules
~~~
module use /apps/modulefiles/
module load common/compilers/intel
module load common/libs/hdf5/1.8.12/sequential/intel/13.1.3
~~~

## compilation
~~~
h5cc-64 -std=c99 file.c -o out
~~~

## view hdf5 files
Show header only
~~~
h5dump -H <file_name>
~~~
Show specific dataset
~~~
h5dump -d /groupA/groupB <file_name>
~~~
