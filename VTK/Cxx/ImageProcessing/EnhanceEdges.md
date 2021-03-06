### Description

High-pass filters can also be used to compress the range of an image. Since low frequencies account for much of the dynamic range of an image but carry little information, a high-pass filter can significantly decrease an image’s scalar range and emphasize hidden details. The Laplacian filter, which is a second derivative operation, is one implementation of a high-pass filter. It eliminates constant and low frequencies leaving only high-frequency edges. The output of the Laplacian can be subtracted from the original image to produce edge enhancement or sharpening of an image.

This example subtracts the Laplacian (middle) from the original image (left) resulting in edge enhancement or a sharpening operation (right).

!!! info
    See [this figure](../../../VTKBook/10Chapter10/#Figure%2010-9) in [Chapter 10](../../../VTKBook/10Chapter10) the [VTK Textbook](../../../VTKBook/01Chapter1).
