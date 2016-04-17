//
// Created by jakub on 4/3/16.
//

#include <infinity_cad/rendering/scene/object_factory.h>
#include <infinity_cad/rendering/cameras/camera_fps.h>

using namespace ifc;

//-----------------------//
//  CONSTRUCTORS
//-----------------------//

ObjectFactory::ObjectFactory(){

}

ObjectFactory::~ObjectFactory() {

}

//-----------------------//
//  PRIVATE 
//-----------------------//

//-----------------------//
//  PUBLIC
//-----------------------//

ObjectFactory& ObjectFactory::getInstance(){
    static ObjectFactory factory;

    return factory;
}



Point* ObjectFactory::createPoint(std::string name) {
    SceneID id = sceneIDFactory.createNextAvailableID();
    Point* point = new Point(id, name);

    return point;
}

Torus *ObjectFactory::createTorus(std::string name) {
    SceneID id = sceneIDFactory.createNextAvailableID();
    Torus* torus = new Torus(id, name);

    return torus;
}


Cross* ObjectFactory::createCross(std::string name,
                                  const std::vector<RenderObject *>* sceneObjects){
    SceneID id = sceneIDFactory.createNextAvailableID();
    Cross* cross = new Cross(id, name,
                             sceneObjects);

    return cross;
}

AxisNet* ObjectFactory::createAxisNet(std::string name, int netSize){
    SceneID id = sceneIDFactory.createNextAvailableID();

    AxisNet* axisNet = new AxisNet(id, name, netSize);

    return axisNet;
}

Cone* ObjectFactory::createCone(std::string name,
                 float radius, float height, int baseVerticesCount){
    SceneID id = sceneIDFactory.createNextAvailableID();

    Cone* cone = new Cone(id, name,
                          radius, height, baseVerticesCount);

    return cone;
}

Line* ObjectFactory::createLine(std::string name,
                                glm::vec4 v1, glm::vec4 v2){
    SceneID id = sceneIDFactory.createNextAvailableID();

    Line* line = new Line(id, name, v1 ,v2);

    return line;
}

Cloud* ObjectFactory::createCloud(std::string name,
                                  std::vector<glm::vec4>& points){
    SceneID id = sceneIDFactory.createNextAvailableID();

    Cloud* cloud = new Cloud(id, name, points);

    return cloud;
}

BezierSplineC0 * ObjectFactory::createBezier(std::string name){
    SceneID id = sceneIDFactory.createNextAvailableID();

    BezierSplineC0 * bezierCurve = new BezierSplineC0(id, name);

    return bezierCurve;
}

BezierSplineC0 * ObjectFactory::createBezier(std::string name,
                                             std::vector<ifc::Point*>& points){
    SceneID id = sceneIDFactory.createNextAvailableID();

    BezierSplineC0 * bezierCurve = new BezierSplineC0(id, name,
                                                      points);
    return bezierCurve;
}

BezierSplineC2 * ObjectFactory::createBezierSpline(std::string name,
                                                   std::vector<ifc::Point*>&
                                                   points){
    SceneID id = sceneIDFactory.createNextAvailableID();

    BezierSplineC2 * bSpline = new BezierSplineC2(id, name, points);

    return bSpline;
}

BezierSplineC2 * ObjectFactory::createBezierSpline(std::string name){
    SceneID id = sceneIDFactory.createNextAvailableID();

    BezierSplineC2 * bSpline = new BezierSplineC2(id, name);

    return bSpline;
}

BSpline* ObjectFactory::createBSpline(std::string name){
    SceneID id = sceneIDFactory.createNextAvailableID();

    BSpline* bSpline = new BSpline(id, name);

    return bSpline;
}

Camera* ObjectFactory::createCameraFPS(std::string name,
                                       Projection* projection){
    SceneID id = sceneIDFactory.createNextAvailableID();

    Camera* camera = new CameraFPS(id, name, projection);

    return camera;
}