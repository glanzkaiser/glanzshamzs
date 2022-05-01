#include <vtkCubeSource.h>
#include <vtkCylinderSource.h>

#include "vtkPolyDataBooleanFilter.h"

int Point::_tag = 0; // important

int main (int argc, char *argv[]) {
    vtkCubeSource *cu = vtkCubeSource::New();
    cu->SetYLength(.5);

    vtkCylinderSource *cyl = vtkCylinderSource::New();
    cyl->SetResolution(32);
    cyl->SetHeight(.5);
    cyl->SetCenter(0, .5, 0);

    vtkPolyDataBooleanFilter *bf = vtkPolyDataBooleanFilter::New();
    bf->SetInputConnection(0, cu->GetOutputPort());
    bf->SetInputConnection(1, cyl->GetOutputPort());
    bf->SetOperModeToDifference();
    bf->Update();

    bf->Delete();
    cyl->Delete();
    cu->Delete();

    return 0;
}
