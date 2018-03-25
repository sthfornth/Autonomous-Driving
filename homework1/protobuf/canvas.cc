// Copyright @2018 Pony AI Inc. All rights reserved.

#include "homework1/protobuf/canvas.h"

#include <iostream>
#include <glog/logging.h>

namespace homework1 {

using homework1::geometry::Point3D;

void Canvas::Draw() const {
  for (const auto& p : polygon_.point()) {
    std::cout << "Point:" << p.x() << ", " << p.y() << ", " << p.z() << std::endl;
  }
}

void Canvas::AddPoint(double x, double y, double z) {
  Point3D point;
  point.set_x(x);
  point.set_y(y);
  point.set_z(z);  
  AddPoint(point);
}

void Canvas::AddPoint(const Point3D& p) {
  auto* point = polygon_.add_point();
  point->CopyFrom(p);               
}

const Point3D& Canvas::GetPoint(int index) const {
  return polygon_.point(index);
}

void Canvas::ParseFromString(const std::string& serialzation) {
  polygon_.ParseFromString(serialzation);
}

const std::string Canvas::SerializeToString() const {
  std::string serialzation;
  CHECK(polygon_.SerializeToString(&serialzation)) << "Canvas serialization failed.";
  return serialzation;
}

double Canvas::GetPointDist(const Point3D& p1, const Point3D& p2){
  double dist = 0;
  dist += sqrt(pow(p1.x() - p2.x(), 2) + pow(p1.y() - p2.y(), 2) + \
    pow(p1.z() - p2.z(), 2));
  // std::cout << dist << std::endl;
  return dist;
}

//compute the length of a polyline
double Canvas::GetPolyLength(){
  // double length;
  double length = 0;
  int n = polygon_.point_size();
  for (int i = 0; i < n-1; i ++){
    auto p1 = polygon_.point()[i];
    auto p2 = polygon_.point()[i + 1];
    length += this->GetPointDist(p1, p2);
  }
  // std::cout << "length = " << length << std::endl;
  return length;
}


}  // namespace homework1
