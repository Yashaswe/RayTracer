/*
 * Cone.cpp
 *
 *  Created on: Feb 13, 2025
 *      Author: yash
 */




#include "Cone.h"
#include "Unit.h"
#include "utils.h"

ostream& operator<<(ostream& os, const Cone& cone) {
    os << "Cone: " << cone.center << " " << cone.radiiX << " " << cone.radiiZ << " " << cone.height << " " << cone.color << " " << cone.material;
    return os;
}

istream& operator>>(istream& is, Cone& cone) {
    string type;
    is >> type;
    is >> cone.center;
    is >> type;
    is >> cone.radiiX >> cone.height >> cone.radiiZ;
    is >> type;
    cone.readAppearance(is);
    return is;
}

optional<Hit> Cone::intersect(const Ray& ray) const {
    float dx = ray.dir().x() / radiiX;
    float dy = ray.dir().y() / height;
    float dz = ray.dir().z() / radiiZ;

    Vector D(dx, dy, dz);
    Vector L((ray.origin().x() - center.x()) / radiiX,
             (ray.origin().y() - center.y()) / height,
             (ray.origin().z() - center.z()) / radiiZ);

    float a = D.x() * D.x() - D.y() * D.y() + D.z() * D.z();
    float b = 2 * (D.x() * L.x() - D.y() * L.y() + D.z() * L.z());
    float c = L.x() * L.x() - L.y() * L.y() + L.z() * L.z() ;

    pair<float, float> roots = findRoots(a, b, c);
    float t1 = roots.first;
    float t2 = roots.second;

    optional<Hit> hit = getHit(t1, ray);
    if (hit) return hit;
    return getHit(t2, ray);
}

optional<Hit> Cone::getHit(float t, const Ray& ray) const {
    Point hit_point = ray.point(t);
    if (t < ZERO || hit_point.y() > center.y() || hit_point.y() < center.y() - height) {
        return {};
    }

    float nx = (hit_point.x() - center.x()) / (radiiX * radiiX);
    float ny = - (hit_point.y() - center.y()) / (height * height);
    float nz = (hit_point.z() - center.z()) / (radiiZ * radiiZ);
    Unit normal(nx, ny, nz);

    return Hit{hit_point, normal, color, material, t};
}
