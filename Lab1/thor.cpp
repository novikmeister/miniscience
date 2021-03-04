//
// Created by vladislav on 02.03.2021.
//

#include <set>

#include <gmsh.h>

int main(int argc, char **argv)
{
    gmsh::initialize();

    gmsh::model::add("t1");


    double lc = 1e-2;
    gmsh::model::geo::addPoint(0, 0, 0, lc, 1);
    gmsh::model::geo::addPoint(.2, 0, 0, lc, 2);
    gmsh::model::geo::addPoint(-.2, 0, 0, lc, 3);

    gmsh::model::geo::addPoint(0, 0, 0.1, lc, 4);
    gmsh::model::geo::addPoint(.2, 0, 0.1, lc, 5);
    gmsh::model::geo::addPoint(-.2, 0, 0.1, lc, 6);

    gmsh::model::geo::addPoint(0, 0, 0.2, lc, 7);
    gmsh::model::geo::addPoint(.2, 0, 0.2, lc, 8);
    gmsh::model::geo::addPoint(-.2, 0, 0.2, lc, 9);

    gmsh::model::geo::addPoint(-.3, 0, 0.1, lc, 10);
    gmsh::model::geo::addPoint(-.1, 0, 0.1, lc, 11);

    gmsh::model::geo::addPoint(.3, 0, 0.1, lc, 12);
    gmsh::model::geo::addPoint(.1, 0, 0.1, lc, 13);

    gmsh::model::geo::addCircleArc(2, 1, 3, 1);
    gmsh::model::geo::addCircleArc(3, 1, 2, 2);

    gmsh::model::geo::addCircleArc(5, 4, 6, 3);
    gmsh::model::geo::addCircleArc(6, 4, 5, 4);

    gmsh::model::geo::addCircleArc(8, 7, 9, 5);
    gmsh::model::geo::addCircleArc(9, 7, 8, 6);

    gmsh::model::geo::addCircleArc(8,5,13, 7, 0, 1);
    gmsh::model::geo::addCircleArc(13,5,2, 8, 0, 1);

    gmsh::model::geo::addCircleArc(8,5,12, 9, 0, 1);
    gmsh::model::geo::addCircleArc(12,5,2, 10, 0, 1);

    gmsh::model::geo::addCircleArc(9, 6, 10, 11, 0, 1);
    gmsh::model::geo::addCircleArc(10,6,3, 12, 0, 1);

    gmsh::model::geo::addCircleArc(9, 6, 11, 13, 0, 1);
    gmsh::model::geo::addCircleArc(11,6,3, 14, 0, 1);

    gmsh::model::geo::addCircleArc(10, 4, 12, 15);
    gmsh::model::geo::addCircleArc(12,4,10, 16);

    gmsh::model::geo::addCircleArc(11, 4, 13, 17);
    gmsh::model::geo::addCircleArc(13,4,11, 18);


    gmsh::model::geo::addCurveLoop({14, 2, -8, -17}, 1);
    gmsh::model::geo::addSurfaceFilling({1}, 1);

    gmsh::model::geo::addCurveLoop({1, -14, -18, 8}, 2);
    gmsh::model::geo::addSurfaceFilling({2}, 2);

    gmsh::model::geo::addCurveLoop({-7, 5, 13, -18}, 3);
    gmsh::model::geo::addSurfaceFilling({3}, 3);

    gmsh::model::geo::addCurveLoop({-6, 13, 17, -7}, 4);
    gmsh::model::geo::addSurfaceFilling({4}, 4);

    gmsh::model::geo::addCurveLoop({11, 15, -9, -6}, 5);
    gmsh::model::geo::addSurfaceFilling({5}, 5);

    gmsh::model::geo::addCurveLoop({9, 16, -11, -5}, 6);
    gmsh::model::geo::addSurfaceFilling({6}, 6);

    gmsh::model::geo::addCurveLoop({-10, 16, 12, -1}, 7);
    gmsh::model::geo::addSurfaceFilling({7}, 7);

    gmsh::model::geo::addCurveLoop({-12, 15, 10, -2}, 8);
    gmsh::model::geo::addSurfaceFilling({8}, 8);

    gmsh::model::geo::addSurfaceLoop({1, 2, 3, 4, 5, 6, 7, 8}, 1);







    gmsh::model::geo::addPoint(0, 0, 0.05, lc, 100);
    gmsh::model::geo::addPoint(.2, 0, 0.05, lc, 200);
    gmsh::model::geo::addPoint(-.2, 0, 0.05, lc, 300);

    gmsh::model::geo::addPoint(0, 0, 0.1, lc, 400);
    gmsh::model::geo::addPoint(.2, 0, 0.1, lc, 500);
    gmsh::model::geo::addPoint(-.2, 0, 0.1, lc, 600);

    gmsh::model::geo::addPoint(0, 0, 0.15, lc, 700);
    gmsh::model::geo::addPoint(.2, 0, 0.15, lc, 800);
    gmsh::model::geo::addPoint(-.2, 0, 0.15, lc, 900);

    gmsh::model::geo::addPoint(-.25, 0, 0.1, lc, 1000);
    gmsh::model::geo::addPoint(-.15, 0, 0.1, lc, 1100);

    gmsh::model::geo::addPoint(.25, 0, 0.1, lc, 1200);
    gmsh::model::geo::addPoint(.15, 0, 0.1, lc, 1300);

    gmsh::model::geo::addCircleArc(200, 100, 300, 100);
    gmsh::model::geo::addCircleArc(300, 100, 200, 200);

    gmsh::model::geo::addCircleArc(500, 400, 600, 300);
    gmsh::model::geo::addCircleArc(600, 400, 500, 400);

    gmsh::model::geo::addCircleArc(800, 700, 900, 500);
    gmsh::model::geo::addCircleArc(900, 700, 800, 600);

    gmsh::model::geo::addCircleArc(800,500,1300, 700, 0, 1);
    gmsh::model::geo::addCircleArc(1300,500,200, 800, 0, 1);

    gmsh::model::geo::addCircleArc(800,500,1200, 900, 0, 1);
    gmsh::model::geo::addCircleArc(1200,500,200, 1000, 0, 1);

    gmsh::model::geo::addCircleArc(900, 600, 1000, 1100, 0, 1);
    gmsh::model::geo::addCircleArc(1000,600,300, 1200, 0, 1);

    gmsh::model::geo::addCircleArc(900, 600, 1100, 1300, 0, 1);
    gmsh::model::geo::addCircleArc(1100,600,300, 1400, 0, 1);

    gmsh::model::geo::addCircleArc(1000, 400, 1200, 1500);
    gmsh::model::geo::addCircleArc(1200,400,1000, 1600);

    gmsh::model::geo::addCircleArc(1100, 400, 1300, 1700);
    gmsh::model::geo::addCircleArc(1300,400,1100, 1800);


    gmsh::model::geo::addCurveLoop({1400, 200, -800, -1700}, 100);
    gmsh::model::geo::addSurfaceFilling({100}, 100);

    gmsh::model::geo::addCurveLoop({100, -1400, -1800, 800}, 200);
    gmsh::model::geo::addSurfaceFilling({200}, 200);

    gmsh::model::geo::addCurveLoop({-700, 500, 1300, -1800}, 300);
    gmsh::model::geo::addSurfaceFilling({300}, 300);

    gmsh::model::geo::addCurveLoop({-600, 1300, 1700, -700}, 400);
    gmsh::model::geo::addSurfaceFilling({400}, 400);

    gmsh::model::geo::addCurveLoop({1100, 1500, -900, -600}, 500);
    gmsh::model::geo::addSurfaceFilling({500}, 500);

    gmsh::model::geo::addCurveLoop({900, 1600, -1100, -500}, 600);
    gmsh::model::geo::addSurfaceFilling({600}, 600);

    gmsh::model::geo::addCurveLoop({-1000, 1600, 1200, -100}, 700);
    gmsh::model::geo::addSurfaceFilling({700}, 700);

    gmsh::model::geo::addCurveLoop({-1200, 1500, 1000, -200}, 800);
    gmsh::model::geo::addSurfaceFilling({800}, 800);

    gmsh::model::geo::addSurfaceLoop({100, 200, 300, 400, 500, 600, 700, 800}, 100);
    gmsh::model::geo::addVolume({1, -100});
    gmsh::model::geo::synchronize();


    gmsh::model::mesh::generate(3);

    gmsh::write("thor.stl");

    std::set<std::string> args(argv, argv + argc);
    if(!args.count("-nopopup")) gmsh::fltk::run();

    gmsh::finalize();

    return 0;
}