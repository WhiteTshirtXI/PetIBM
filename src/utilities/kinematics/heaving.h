/*! Definition of the class `Heaving`.
 * \file heaving.h
 */


#if !defined(HEAVING_H)
#define HEAVING_H

#include "kinematics.h"

#include <vector>

#include "yaml-cpp/yaml.h"


/**
 * \class Heaving.h
 * \brief Contains information about the heaving motion.
 */
class Heaving : public Kinematics
{
public:
  double amplitude;
  double frequency;
  double phase;

  // constructors
  Heaving(){ };
  // destructor
  virtual ~Heaving(){ };

  // parse information using YAML-CPP
  void parse(const YAML::Node &node);
  // update the y-coordinates
  void updatePosition(double time, std::vector<double> &y);
  // update the velocity
  void getVelocity(double time, double &vel);

}; // Heaving

#endif
