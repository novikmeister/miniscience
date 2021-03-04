
#include <set>
#include <cmath>
#include <gmsh.h>
#include <iostream>

int main(int argc, char **argv)
{
    gmsh::initialize(argc, argv);

    gmsh::model::add("uploads_files_891717_Arrow");

    try {
        gmsh::merge("uploads_files_891717_Arrow.stl");
    } catch(...) {
        gmsh::logger::write("Could not load STL mesh: bye!");
        gmsh::finalize();
        return 0;
    }

    double angle = 2;

    bool forceParametrizablePatches = false;

    bool includeBoundary = true;

    double curveAngle = 180;

    gmsh::model::mesh::classifySurfaces(angle * M_PI / 180., includeBoundary,
                                        forceParametrizablePatches, curveAngle * M_PI / 180.);

    gmsh::model::mesh::createGeometry();

    std::vector<std::pair<int, int> > s;
    gmsh::model::getEntities(s, 2);
    std::vector<int> sl;
    for(auto surf : s) sl.push_back(surf.second);
    int l = gmsh::model::geo::addSurfaceLoop(sl);
    gmsh::model::geo::addVolume({l});

    gmsh::model::geo::synchronize();
    gmsh::model::mesh::generate(3);

    std::set<std::string> args(argv, argv + argc);
    if(!args.count("-nopopup")) gmsh::fltk::run();

    gmsh::finalize();
    return 0;
}