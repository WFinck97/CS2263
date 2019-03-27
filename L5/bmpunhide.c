// bmpunhide.c
#include "bmpfunc.h"
void BMP_unhide(BMP_Image *img){
	int pxl;
	
	for (pxl = 0; pxl < (img -> data_size); pxl += 3)
	  {
	    unsigned char red   = img -> data[pxl + 2];
	    unsigned char green = img -> data[pxl + 1];
	    unsigned char blue  = img -> data[pxl];
	    if (redmin > red) { redmin = red; }
	    if (redmax < red) { redmax = red; }
	    if (greenmin > green) { greenmin = green; }
	    if (greenmax < green) { greenmax = green; }
	    if (bluemin > blue) { bluemin = blue; }
	    if (bluemax < blue) { bluemax = blue; }
	  }
}