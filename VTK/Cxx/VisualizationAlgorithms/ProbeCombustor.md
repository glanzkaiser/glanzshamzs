### Description

Probing obtains dataset attributes by sampling one dataset (the input) with a set of points (the probe). Probing is also called “resampling.” Examples include probing an input dataset with a sequence of points along a line, on a plane, or in a volume. The result of the probing is a new dataset (the output) with the topological and geometric structure of the probe dataset, and point attributes interpolated from the input dataset. Once the probing operation is completed, the output dataset can be visualized with any of the appropriate techniques in VTK.

This example illustrates the details of the probing process. For every point in the probe dataset, the location in the input dataset (i.e., cell, subcell, and parametric coordinates) and interpolation weights are determined. Then the data values from the cell are interpolated to the probe 
point. Probe points that are outside the input dataset are assigned a nil (or appropriate) value. This process repeats for all points in the probe dataset.

!!! info
    See [Figure 9-19](../../../VTKBook/09Chapter9/#Figure%209-19) in [Chapter 9](../../../VTKBook/09Chapter9) The [VTK Textbook](../../../VTKBook/01Chapter1).
