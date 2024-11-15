#include <string.h>
#include "config/coloredBitmap.h"
// Parameters:
//   w: width of the image
//   h: height of the image
//   u: Unit of the output value. It could be 'bt' bits, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   colored image size Bitmap (based on the unit passed parametter)
float coloredBitmap(int w, int h, char* unit) {
   // YOUR CODE HERE - BEGIN
 // Calculate the size in bits (24 bits per pixel for colored image)
    float sizeInBits = (float)(w * h * 24);

    // Convert the size based on the unit
    if (strcmp(unit, "bt") == 0) {
        // If the unit is bits, return the size as is
        return sizeInBits;
    } else if (strcmp(unit, "ko") == 0) {
        // Convert bits to kilobits (1 kilobit = 1024 bits)
        return sizeInBits / 1024.0;
    } else if (strcmp(unit, "mo") == 0) {
        // Convert bits to megabits (1 megabit = 1024 * 1024 bits)
        return sizeInBits / (1024.0 * 1024.0);
    } else if (strcmp(unit, "go") == 0) {
        // Convert bits to gigabits (1 gigabit = 1024 * 1024 * 1024 bits)
        return sizeInBits / (1024.0 * 1024.0 * 1024.0);
    } else {
        // If the unit is not recognized, return 0
        return 0;
   // YOUR CODE HERE - END
}
