#include <stdio.h>
#include <vips/vips.h>


int main(int argc, char *argv[]){
    VipsImage *img, *crop;
    int w, h, start_w, start_h, size_w, size_h;

    if(argc != 7){
        printf("usage: %s infile left top width height outfile\n",argv[0]);
        return 1;
    }

    if (VIPS_INIT(argv[0]))
        vips_error_exit("unable to start VIPS");

    img = vips_image_new_from_file(argv[1],NULL);
    
    w = vips_image_get_width(img);
    h = vips_image_get_height(img);

    printf("image dimensions: %d x %d\n",w,h);

    start_w = atoi(argv[2]);
    start_h = atoi(argv[3]);
    size_w = atoi(argv[4]);
    size_h = atoi(argv[5]);

    if(vips_crop(img, &crop, start_w, start_h, size_w, size_h, NULL)){
        vips_error_exit("unable to crop image");
    }

    vips_image_write_to_file(crop, argv[6], NULL);

    vips_shutdown();
    return 0;    
}