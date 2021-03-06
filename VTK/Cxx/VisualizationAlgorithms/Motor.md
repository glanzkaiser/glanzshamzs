### Description

This is an example of texture clipping using a transparent texture map. The motor shown consists of five complex parts, some of which are hidden by the outer casing. To see the inside of the motor, we define an implicit clipping function. This function is simply the intersection of two planes to form a clipping "corner". The object **vtkImplicitTextureCoords** is used in combination with this implicit function to generate texture coordinates. These objects are then rendered with the appropriate texture map and the internal parts of the motor can be seen.

The texture map consists of three regions (as described previously in the chapter). The concealed region is transparent. The transition region is opaque but with a black (zero intensity) color. The highlighted region is full intensity and opaque. As can be seen from the result , the boundaries appear as black borders giving a nice visual effect.

Note the use of vectors in the C++ version and lists in the Python version to reduce repetitious code.

!!! info
    See [Figure 9-53](../../../VTKBook/09Chapter9/#Figure%209-53) in [Chapter 9](../../../VTKBook/09Chapter9) The [VTK Textbook](../../../VTKBook/01Chapter1).
