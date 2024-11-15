#include <string.h>
#include "config/video.h"
// Parameters:
//   w: width of the image
//   h: height of the image
//   durationMovie: duration in second of movie (colored image)
//   durationCredits: duration in second of credit (image Black/White)
//   unit: Unit of the output value. It could be 'bt' byte, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   colored video size (based on the unit passed parametter)
float video(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {
   
    int frameSizeColorBits = w * h * 24; 
    int frameSizeBWBits = w * h * 8;   


    int totalFramesMovie = durationMovie * fps;
    int totalFramesCredits = durationCredits * fps;

    float totalSizeBits = (totalFramesMovie * frameSizeColorBits) + (totalFramesCredits * frameSizeBWBits);

    
    if (strcmp(unit, "bt") == 0) {
 
        return totalSizeBits;
    } else if (strcmp(unit, "ko") == 0) {

        return totalSizeBits / 1024.0;
    } else if (strcmp(unit, "mo") == 0) {

        return totalSizeBits / (1024.0 * 1024.0);
    } else if (strcmp(unit, "go") == 0) {
     
        return totalSizeBits / (1024.0 * 1024.0 * 1024.0);
    } else {
    
        return 0;
}
