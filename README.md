# Star Extractor

This utility is a module for a Nanosatellite star tracker. A Star Tracker aims to provide the satellite with its attitude in Euclidean at a low cost, significantly lower than traditional star tracker used on larger satellites. This module determines the possible combinations of star triads given an image file.

## Dependencies

OpenCV [3.2](http://opencv.org/opencv-3-2.html)

## Algorithm

The star extraction is done through blob analysis using OpenCV. Given an image from the satellite's camera feed, we load the image into a buffer, and do some preprocessing on the image to reduce the noise before doing the blob analysis.

* Load image into buffer
* Apply greyscale mask
* Convert into binary matrix
* Determine blobs in the matrix
* Determine all 3 way combinations

### Combinations

The number star triads is determined by the following:

![combinations][http://www.mathwords.com/b/b_assets/binomial%20coefficient%20formula.gif]

Where r = 3 and n is the total number of stars found. A *threshhold* is defaulted to 25 stars per frame as this yields 2300 combinations of stars. More than enough to find a match in our dataset.
