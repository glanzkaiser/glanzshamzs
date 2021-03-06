### Description

Clipping is implemented in vtkClipPolyData . Each polygonal data primitive implements the operation in its Clip() method using case tables. vtkClipPolyData has methods to control whether an implicit function provides the scalar data or whether the dataset’s scalar data will be used. Compute*ScalarDataOn()* uses the implicit function and *ComputeScalarDataOff()* uses the dataset’s scalar data. Two output polygonal datasets are produced. These are accessed with *GetOutput()* and *GetClippedOutput()* methods. *GetOutput()* returns the polygonal data that is “inside” the clipping region while *GetClippedOutput()* returns polygonal data that is “outside” the region. (Note that *GenerateClippedOutputOn()* must be enabled if you are to get the clipped output.) The meaning of inside and outside can be reversed using the *InsideOutOn()*.

This example shows a plane of quadrilaterals clipped with a boolean implicit function.

!!! info
    See [Figure 9-48](../../../VTKBook/09Chapter9/#Figure%209-48) in [Chapter 9](../../../VTKBook/09Chapter9) The [VTK Textbook](../../../VTKBook/01Chapter1).
