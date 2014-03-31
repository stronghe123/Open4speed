#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "renderers/opengl/gltexture.h"
#include "raycaster/utils.h"

class triangle
{
public:
    AABB reg;           ///< AABB of the object
    glm::vec3 a;
    glm::vec3 b;
    glm::vec3 c;
    glm::ivec2 aID;
    glm::ivec2 bID;
    glm::ivec2 cID;
    glm::vec3 na;
    glm::vec3 nb;
    glm::vec3 nc;
    glm::vec2 ta;
    glm::vec2 tb;
    glm::vec2 tc;
    int dataIndex;
    int lmIndex;
    long tIndex;
    Texture* txt;
    Texture* txtmap;
    std::vector<Point> points;

    triangle(glm::vec3 a, glm::vec3 b, glm::vec3 c,
             glm::vec2 aID, glm::vec2 bID, glm::vec2 cID,
             glm::vec3 na, glm::vec3 nb, glm::vec3 nc,
             glm::vec2 ta, glm::vec2 tb, glm::vec2 tc,
             int lmIndex, long tIndex, Texture* txt, Texture* txtmap);

    void addPointToAABB(glm::vec3 p);

    void addLMPoint(int u, int v, glm::ivec2 t);

    float countDistanceTo(triangle* t);

    PLP* getPointLight(glm::vec3 p);

    bool isIntersectedByRay(glm::vec3 begin, glm::vec3 end);
};

extern triangle* lastIntersectedTriangle;
extern triangle* lastIntersectedTriangle2;

#endif // TRIANGLE_H
