/*! Implementation of the class `Kinematics`.
 * \file kinematics.h
 */

#if !defined(KINEMATICS_H)
#define KINEMATICS_H

#include <vector>

#include "yaml-cpp/yaml.h"


/**
 * \class Kinematics
 * \brief Super class for the kinematics.
 */
class Kinematics
{
public:
  virtual ~Kinematics(){ }
  virtual void parse(const YAML::Node &node) = 0;
  virtual void updatePosition(double time, std::vector<double> &y) = 0;
  virtual void getVelocity(double time, double &vel) = 0;

}; // Kinematics

#endif
