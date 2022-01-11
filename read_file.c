/**
 * Author:    Zuzanna Wieczorek
 * Created:   11.01.2022
 * Description: Program reads hdf5 file and saves plot in png format
 **/

#include <stdio.h>
#include <stdlib.h>
#include "hdf5.h"

#define DATA_FILE    "H-H2_LOSC_4_V1-842665984-4096.hdf5"
#define DATASET      "/strain/Strain"
#define N            16777216
#define M            1000   
int main (void){
    hid_t       file, space, dset, datatype, class;
    herr_t      status;
    float       rdata[N];  
    // create file and dataset
    file = H5Fopen (DATA_FILE, H5F_ACC_RDONLY, H5P_DEFAULT);
    dset = H5Dopen (file, DATASET, H5P_DEFAULT);
    // read data from file into rdata
    status = H5Dread (dset,  H5T_NATIVE_FLOAT, H5S_ALL, H5S_ALL, H5P_DEFAULT,rdata);

    status = H5Dclose (dset);
    status = H5Fclose (file);

    // make plot in gnuplot
    FILE *gnuplot = popen("gnuplot", "w");
    if (!gnuplot) {
        perror("popen");
        exit(EXIT_FAILURE);
    }
    int start = N / 2;
    int end = start + M;

    fprintf(gnuplot, "set terminal png size 1200,400\nset output 'plot.png'\nset title 'LIGO'\nset xlabel 'time'\nset ylabel 'strain'\nset xtics %d,200,%d\nplot '-' u 1:2 t 'data' w lp\n", start, end);
    for (int i = start; i < end; ++i) {
        fprintf(gnuplot,"%d %.18e\n", i, rdata[i]);
    }
    fprintf(gnuplot, "e\n");
    fflush(gnuplot);

    pclose(gnuplot);

    return 0;
}
