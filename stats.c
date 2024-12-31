#include <stdio.h>
#include <vips/vips.h>


int main(int argc, char *argv[]){
    VipsImage *img;
    int w, h;

    if(argc != 2){
        printf("usage: %s infile\n",argv[0]);
        return 1;
    }

    if (VIPS_INIT(argv[0]))
        vips_error_exit("unable to start VIPS");

    img = vips_image_new_from_file(argv[1],NULL);
    
    w = vips_image_get_width(img);
    h = vips_image_get_height(img);

    printf("image dimensions: %d x %d\n",w,h);

    vips_shutdown();

    return 0;    
}