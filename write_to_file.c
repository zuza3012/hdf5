/**
 * Author:    Zuzanna Wieczorek
 * Created:   11.01.2022
 * Description: Program creates hdf5 file
 **/

#include <stdio.h>
#include <stdlib.h>
#include "hdf5.h"

#define DATA_FILE "wieczorek_data.hdf5" 
#define N            1000
   
int main (void){
    hid_t       file, dspace, dset;
    herr_t      status;
    hsize_t     dims[1];
    float       wdata[N];  
    
    dims[0] = N;

    // fill array
    for(int i = 0; i < N; i++){
        wdata[i] = i;
    }

    // create file
    file = H5Fcreate(DATA_FILE, H5F_ACC_TRUNC, H5P_DEFAULT, H5P_DEFAULT);
    
    // create dataspace for dataset
    dspace = H5Screate_simple(1, dims, NULL);    
    
    // create dataset
    dset = H5Dcreate(file,"dset",H5T_IEEE_F64LE, dspace, H5P_DEFAULT, H5P_DEFAULT, H5P_DEFAULT);
    
    // write to dataset   
    status = H5Dwrite(dset, H5T_NATIVE_FLOAT, H5S_ALL, H5S_ALL, H5P_DEFAULT,wdata);

    status = H5Dclose (dset);
    status = H5Fclose (file);

    return 0;
}
