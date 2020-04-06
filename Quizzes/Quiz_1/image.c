#include <stdio.h>
#include <stdlib.h>

typedef struct _image {
    int rows;
    int cols;
    int **pixels;
} Image;

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

Image* imageAlloc(int rows, int cols) {
    Image* p = malloc(sizeof(Image));
    p->rows = rows;
    p->cols = cols;
    p->pixels = malloc(sizeof(int*)*rows);
    for(int i = 0; i < rows; i++) {
        p->pixels[i] = malloc(sizeof(int)*cols);
    }
    return p;
}

void imageInit(Image *image) {
    for(int i = 0; i < image->rows; i++) {
        for(int j = 0; j < image->cols; j++) {
            image->pixels[i][j] = rand() % 256;
        }
    }
}

int pixelAvg(Image *image, int row, int col) {
    int pixel_ru = row-1;
    int pixel_rd = row+1;
    int pixel_cl = col-1;
    int pixel_cr = col+1;
    int average = 0;
    int count = 0;
    if(pixel_ru < 0) {
        pixel_ru = row;
    } 
    if(pixel_rd > image->rows) {
        pixel_rd = row;
    }
    if(pixel_cl < 0) {
        pixel_cl = col;
    }
    if(pixel_cr > image->cols) {
        pixel_cr = col;
    }
    for(int i = pixel_ru; i < pixel_rd; i++) {
        for(int j = pixel_cl; j < pixel_cr; j++) {
            average += image->pixels[i][j];
            count++;
        }
    }
    average = average/count;
    return average;
}

Image* imageBlur(Image *image) {
    Image* Blur = imageAlloc(image->rows, image->cols);
    for(int i = 0; i < image->rows; i++) {
        for(int j = 0; j < image->cols; j++) {
            Blur->pixels[i][j] = pixelAvg(image,i,j);
        }
    }
    return Blur;
}

void imageFree(Image *image) {
    for(int i = 0; i < image->rows; i++) {
        free(image->pixels[i]);
    }
    free(image->pixels);
    free(image);
}

int main(void) {
    Image* created_image = imageAlloc(5,5);
    Image* image_blur = imageBlur(created_image);
    imageFree(created_image);
    imageFree(image_blur);
}



/*
for(int i = 0; i < image->rows; i++) {
    for(int j = 0; j < image->cols; j++) {
        free(image->pixels[i][j]);
    }
}
*/