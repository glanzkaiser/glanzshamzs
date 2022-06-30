#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <chrono>
#include "chrono/utils/ChUtilsSamplers.h"

using namespace chrono;

int main(int argc, char* argv[])
{
    srand(time(NULL));
    float r_particle = 1.;
    float r_cylinder = 20.;
    float z_cylinder = 10.;

    chrono::utils::PDSampler<float> sampler(2 * r_particle);
    std::vector<ChVector<float>> positions;
    auto points = sampler.SampleCylinderZ(ChVector<float>(0.,0.,z_cylinder), r_cylinder, 0.0);
    auto points = sampler.SampleCylinderZ((0.,0.,z_cylinder), r_cylinder, 0.0);
    positions.insert(positions.end(), points.begin(), points.end());

    for (int k = 0; k < positions.size(); k++)
    {
        std::cout << "R: " << sqrt(pow(positions[k][0], 2) + pow(positions[k][1], 2)) << "\t\tZ:" << positions[k][2] << std::endl;
    }
}
