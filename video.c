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
   // Calculate frame sizes
    int frameSizeColorBits = w * h * 24; // 24 bits per pixel for colored frames
    int frameSizeBWBits = w * h * 8;    // 8 bits per pixel for black-and-white frames

    // Calculate the total number of frames for each section
    int totalFramesMovie = durationMovie * fps;
    int totalFramesCredits = durationCredits * fps;

    // Calculate the total size in bits
    float totalSizeBits = (totalFramesMovie * frameSizeColorBits) + (totalFramesCredits * frameSizeBWBits);

    // Convert the size based on the unit
    if (strcmp(unit, "bt") == 0) {
        // Return size in bits
        return totalSizeBits;
    } else if (strcmp(unit, "ko") == 0) {
        // Convert bits to kilobits
        return totalSizeBits / 1024.0;
    } else if (strcmp(unit, "mo") == 0) {
        // Convert bits to megabits
        return totalSizeBits / (1024.0 * 1024.0);
    } else if (strcmp(unit, "go") == 0) {
        // Convert bits to gigabits
        return totalSizeBits / (1024.0 * 1024.0 * 1024.0);
    } else {
        // If the unit is not recognized, return 0
        return 0;
}
