### Description

This example takes advantage of the properties of implicit functions to select and cut data. In particular it uses the region separation property to select data. Selecting or extracting data with an implicit function means choosing cells and points (and associated attribute data) that lie within a particular region of the function. To determine whether a point x-y-z lies within a region, we simply evaluate the point and examine the sign of the result. A cell lies in a region if all its points lie in the region. Here, two ellipses are used in combination to select voxels within a volume dataset. Note that extracting data often changes the structure of the dataset. In this example the input type is a image data dataset, while the output type is an unstructured grid dataset.

!!! info
    See [Figure 6-24](../../../VTKBook/06Chapter6/#Figure%206-24) in [Chapter 6](../../../VTKBook/06Chapter6) the [VTK Textbook](../../../VTKBook/01Chapter1).
