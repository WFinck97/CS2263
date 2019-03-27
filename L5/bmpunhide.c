// bmpunhide.c
#include "bmpfunc.h"
void BMP_unhide(BMP_Image *img){
	int pxl;
	unsigned char min = 0;
	// keep only green pixels
	for (pxl = 0; pxl < (img -> data_size); pxl += 3)
	  {
	    //get rid of red pixels
	    img -> data[pxl + 2] = min;
	    //get rid of blue pixels
	    img -> data[pxl] = min;
	  }
}