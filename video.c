#include <string.h>
#include "config/video.h"

// Parameters:
//   w: width of the image
//   h: height of the image
//   durationMovie: duration in seconds of the movie (colored image)
//   durationCredits: duration in seconds of the credits (black/white image)
//   unit: Unit of the output value. It could be 'bt' (bits), 'ko' (kilobits), 'mo' (megabits), 'go' (gigabits)
// Return value:
//   Colored video size (based on the unit passed as a parameter)

float video(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {
    // Calculate frame sizes
    long long frameSizeColorBits = (long long)w * h * 24; 
    long long frameSizeBWBits = (long long)w * h * 8;

    // Calculate total frames
    long long totalFramesMovie = (long long)durationMovie * fps;
    long long totalFramesCredits = (long long)durationCredits * fps;

    // Calculate total size in bits
    float totalSizeBits = (totalFramesMovie * frameSizeColorBits) + (totalFramesCredits * frameSizeBWBits);

    // Convert based on the unit
    if (strcmp(unit, "bt") == 0) {
        return totalSizeBits;
    } else if (strcmp(unit, "ko") == 0) {
        return totalSizeBits / 1024.0;
    } else if (strcmp(unit, "mo") == 0) {
        return totalSizeBits / (1024.0 * 1024.0);
    } else if (strcmp(unit, "go") == 0) {
        return totalSizeBits / (1024.0 * 1024.0 * 1024.0);
    } else {
        return 0; // Invalid unit
    }
}
