/*! Implementation of the methods of the class `Heaving`.
 * \file heaving.cpp
 */


#include "heaving.h"


void Heaving::parse(const YAML::Node &node)
{
  amplitude = node["amplitude"].as<double>(0.0);
  frequency = node["frequency"].as<double>(0.0);
  phase = node["phase"].as<double>(0.0);
} // parse


void Heaving::updatePosition(double time, std::vector<double> &y)
{
  for (auto &yi : y)
  {
    yi += amplitude*cos(frequency*time + phase);
  }
} // update


void Heaving::getVelocity(double time, double &vel)
{
  vel = -amplitude*frequency*sin(frequency*time + phase);
} // getVelocity
