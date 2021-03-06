# !/usr/bin/env python
# -*- coding: utf-8 -*-

import vtkmodules.all as vtk


def main():
    colors = vtk.vtkNamedColors()

    colors.SetColor("BkgColor", [26, 51, 102, 255])

    parametricObjects = list()
    parametricObjects.append(vtk.vtkParametricBoy())
    parametricObjects.append(vtk.vtkParametricConicSpiral())
    parametricObjects.append(vtk.vtkParametricCrossCap())
    parametricObjects.append(vtk.vtkParametricDini())

    parametricObjects.append(vtk.vtkParametricEllipsoid())
    parametricObjects[-1].SetXRadius(0.5)
    parametricObjects[-1].SetYRadius(2.0)
    parametricObjects.append(vtk.vtkParametricEnneper())
    parametricObjects.append(vtk.vtkParametricFigure8Klein())
    parametricObjects.append(vtk.vtkParametricKlein())

    parametricObjects.append(vtk.vtkParametricMobius())
    parametricObjects[-1].SetRadius(2)
    parametricObjects[-1].SetMinimumV(-0.5)
    parametricObjects[-1].SetMaximumV(0.5)
    parametricObjects.append(vtk.vtkParametricRandomHills())
    parametricObjects[-1].AllowRandomGenerationOff()
    parametricObjects.append(vtk.vtkParametricRoman())
    parametricObjects.append(vtk.vtkParametricSuperEllipsoid())
    parametricObjects[-1].SetN1(0.5)
    parametricObjects[-1].SetN2(0.1)

    parametricObjects.append(vtk.vtkParametricSuperToroid())
    parametricObjects[-1].SetN1(0.2)
    parametricObjects[-1].SetN2(3.0)
    parametricObjects.append(vtk.vtkParametricTorus())
    parametricObjects.append(vtk.vtkParametricSpline())
    # Add some points to the parametric spline.
    inputPoints = vtk.vtkPoints()
    rng = vtk.vtkMinimalStandardRandomSequence()
    rng.SetSeed(8775070)
    for i in range(0, 10):
        rng.Next()
        x = rng.GetRangeValue(0.0, 1.0)
        rng.Next()
        y = rng.GetRangeValue(0.0, 1.0)
        rng.Next()
        z = rng.GetRangeValue(0.0, 1.0)
        inputPoints.InsertNextPoint(x, y, z)
    parametricObjects[-1].SetPoints(inputPoints)

    parametricFunctionSources = list()
    renderers = list()
    mappers = list()
    actors = list()
    textmappers = list()
    textactors = list()

    # Create one text property for all
    textProperty = vtk.vtkTextProperty()
    textProperty.SetFontSize(12)
    textProperty.SetJustificationToCentered()

    backProperty = vtk.vtkProperty()
    backProperty.SetColor(colors.GetColor3d("Tomato"))

    # Create a parametric function source, renderer, mapper, and actor
    # for each object
    for i in range(0, len(parametricObjects)):
        parametricFunctionSources.append(vtk.vtkParametricFunctionSource())
        parametricFunctionSources[i].SetParametricFunction(parametricObjects[i])
        parametricFunctionSources[i].SetUResolution(51)
        parametricFunctionSources[i].SetVResolution(51)
        parametricFunctionSources[i].SetWResolution(51)
        parametricFunctionSources[i].Update()

        mappers.append(vtk.vtkPolyDataMapper())
        mappers[i].SetInputConnection(parametricFunctionSources[i].GetOutputPort())

        actors.append(vtk.vtkActor())
        actors[i].SetMapper(mappers[i])
        actors[i].GetProperty().SetColor(colors.GetColor3d("Banana"))
        actors[i].GetProperty().SetSpecular(.5)
        actors[i].GetProperty().SetSpecularPower(20)
        actors[i].SetBackfaceProperty(backProperty)

        textmappers.append(vtk.vtkTextMapper())
        textmappers[i].SetInput(parametricObjects[i].GetClassName())
        textmappers[i].SetTextProperty(textProperty)

        textactors.append(vtk.vtkActor2D())
        textactors[i].SetMapper(textmappers[i])
        textactors[i].SetPosition(100, 16)

        renderers.append(vtk.vtkRenderer())
        renderers[i].AddActor(actors[i])
        renderers[i].AddActor(textactors[i])
        renderers[i].SetBackground(colors.GetColor3d("BkgColor"))

    # Setup the viewports
    xGridDimensions = 4
    yGridDimensions = 4
    rendererSize = 200
    renderWindow = vtk.vtkRenderWindow()
    renderWindow.SetWindowName("Parametric Objects Demonstration")
    renderWindow.SetSize(rendererSize * xGridDimensions, rendererSize * yGridDimensions)
    for row in range(0, yGridDimensions):
        for col in range(0, xGridDimensions):
            index = row * xGridDimensions + col

            # (xmin, ymin, xmax, ymax)
            viewport = [float(col) / xGridDimensions,
                        float(yGridDimensions - (row + 1)) / yGridDimensions,
                        float(col + 1) / xGridDimensions,
                        float(yGridDimensions - row) / yGridDimensions]

            if index > (len(actors) - 1):
                # Add a renderer even if there is no actor.
                # This makes the render window background all the same color.
                ren = vtk.vtkRenderer()
                ren.SetBackground(colors.GetColor3d("BkgColor"))
                ren.SetViewport(viewport)
                renderWindow.AddRenderer(ren)
                continue

            renderers[index].SetViewport(viewport)
            renderers[index].ResetCamera()
            renderers[index].GetActiveCamera().Azimuth(30)
            renderers[index].GetActiveCamera().Elevation(-30)
            renderers[index].GetActiveCamera().Zoom(0.9)
            renderers[index].ResetCameraClippingRange()
            renderWindow.AddRenderer(renderers[index])

    interactor = vtk.vtkRenderWindowInteractor()
    interactor.SetRenderWindow(renderWindow)

    renderWindow.Render()
    interactor.Start()


if __name__ == '__main__':
    main()
