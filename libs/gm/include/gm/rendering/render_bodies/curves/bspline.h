//
// Created by jakub on 4/10/16.
//

#ifndef IC_BSPLINE_H
#define IC_BSPLINE_H

#include <gm/rendering/render_body.h>
#include <gm/rendering/render_bodies/curves/spline.h>

class BSpline : public Spline{
private:

protected:
    virtual void initVertices();

    virtual void initEdges();

    virtual void draw(const glm::mat4 &VP, const Color& color) override;

    virtual void buildCurve() override;
public:

    BSpline(SceneID id, std::string name);

    ~BSpline();

    virtual float intersect(const RayCast &ray);

    virtual glm::vec3 getClosestPoint(const glm::vec3 point);

};


#endif //IC_BSPLINE_H