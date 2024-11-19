#include <string.h>
#include "config/video.h"

// Parameters:
//   w: width of the image
//   h: height of the image
//   durationMovie: duration in seconds of the movie (colored image)
//   durationCredits: duration in seconds of the credits (black/white image)
//   fps: Frames per second of the video
//   unit: Unit of the output value. It could be 'bt' (bits), 'ko' (kilobits), 'mo' (megabits), 'go' (gigabits)
// Return value:
//   Video size (based on the unit passed as a parameter)

float video(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {
    // Calculate frame sizes
    long long frameSizeColorBits = (long long)w * h * 24; // 24 bits per pixel for colored frames
    long long frameSizeBWBits = (long long)w * h * 8;     // 8 bits per pixel for black/white frames

    // Calculate total frames
    long long totalFramesMovie = (long long)durationMovie * fps;
    long long totalFramesCredits = (long long)durationCredits * fps;

    // Calculate total size in bits
    long long totalSizeBits = (totalFramesMovie * frameSizeColorBits) + (totalFramesCredits * frameSizeBWBits);

    // Convert based on the unit
    if (strcmp(unit, "bt") == 0) {
        return (float)totalSizeBits; // Return size in bits
    } else if (strcmp(unit, "ko") == 0) {
        return (float)totalSizeBits / 8192.0; // Convert bits to kilobytes (1 kilobyte = 8192 bits)
    } else if (strcmp(unit, "mo") == 0) {
        return (float)totalSizeBits / (8192.0 * 1024.0); // Convert bits to megabytes
    } else if (strcmp(unit, "go") == 0) {
        return (float)totalSizeBits / (8192.0 * 1024.0 * 1024.0); // Convert bits to gigabytes
    } else {
        return 0; // Invalid unit
    }
}
