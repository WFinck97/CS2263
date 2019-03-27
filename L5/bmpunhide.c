// bmpunhide.c
#include "bmpfunc.h"
void BMP_unhide(BMP_Image *img){
	int pxl;
	unsigned char min = 0;
	unsigned char threshold = 10;
	unsigned char max = 255;
	// keep only green pixels
	for (pxl = 0; pxl < (img -> data_size); pxl += 3)
	  {
	    //get rid of red pixels
	    img -> data[pxl + 2] = min;
	    //get rid of blue pixels
	    img -> data[pxl] = min;

	    // if pixel is green, fully brighten it
	    if(img -> data[pxl + 1] > threshold){
	    	img -> data[pxl + 1] = max;
	    }
	  }
}