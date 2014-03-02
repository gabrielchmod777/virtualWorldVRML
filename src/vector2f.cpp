#include "vector2f.h"
#include <cmath>
#include <vector>
#include <string>

Vec2d::Vec2d()
{
  _x = 0; _y = 0;
}

Vec2d::Vec2d(float x, float y)
{
  _x = x; _y = y;
}

Vec2d::Vec2d(std::vector<float> pair)
{

  if(pair.size() < 2)
    {
      throw Error_InvalidPair();
    }
  else
    {
      _x = pair[0];
      _y = pair[1];
    }

}

int Vec2d::_length()
{
  return 2;
}

std::string Vec2d::_repr()
{
  std::string representation = std::string("Vec2d(")+std::to_string(_x)+std::string(",")+std::to_string(_y)+std::string(")");
  return representation;
}

float Vec2d::get_x()
{
  return _x;
}

float Vec2d::get_y()
{
  return _y;
}

void Vec2d::set_x(float x)
{
  _x = x;
}

void Vec2d::set_y(float y)
{
  _y = y;
}

bool Vec2d::operator==(Vec2d & other)
{
  return ((_x == other.get_x()) && (_y == other.get_y()));
}

bool Vec2d::operator!=(Vec2d & other)
{
  return ((_x != other.get_x()) || (_y != other.get_y()));
}

bool Vec2d::non_zero()
{
  return ((_x != 0) && (_y != 0));
}
