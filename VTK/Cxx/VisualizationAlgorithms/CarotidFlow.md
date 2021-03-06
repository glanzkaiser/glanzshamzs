### Description

This example generates streamtubes of blood velocity. an isosurface of speed provides context. The starting positions for the streamtubes were determined by experimenting with the data. Because of the way the data was measured and the resolution of the velocity field, many streamers travel outside the artery. This is because the boundary layer of the blood flow is not captured due to limitations in data resolution. Consequently, as the blood flows around curves, there is a component of the velocity field that directs the streamtube outside the artery. As a result it is hard to find starting positions for the streamtubes that yield interesting results. The examples uses the source object vtkPointSource in combination with vtkThresholdPoints to work around this problem. vtkPointSource generates random points centered around a sphere of a specified radius. We need only find an approximate position for the starting points of the streamtubes and then generate a cloud of random seed points. vtkThresholdPoints is used to cull points that may be generated outside the regions of high flow velocity.

!!! cite
    See [*3D Phase Contrast MRI of Cerebral Blood Flow and Surface Anatomy*](http://marchingcubes.org/images/c/c6/3DPhaseContrastMRIofCerebralBloodFlowandSurfaceAnatomy.pdf) for background.

!!! info
    See [Figure 6-44](../../../VTKBook/06Chapter6/#Figure%206-44) in [Chapter 6](../../../VTKBook/06Chapter6) the [VTK Textbook](../../../VTKBook/01Chapter1).
