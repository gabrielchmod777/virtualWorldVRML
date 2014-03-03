#include "vector2f.h"
#include <cmath>
#include <vector>
#include <string>

#ifndef PI
#define PI 3.141592653589793
#endif


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

Vec2d::Vec2d( const Vec2d & source )
{
  _x = source.get_x();
  _y = source.get_y();
}

std::string Vec2d::to_string()
{
  std::string representation = std::string("Vec2d(")+std::to_string(_x)+std::string(",")+std::to_string(_y)+std::string(")");
  return representation;
}

float Vec2d::get_x() const
{
  return _x;
}

float Vec2d::get_y() const
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

bool Vec2d::operator==(const Vec2d & other)
{
  return ((_x == other.get_x()) && (_y == other.get_y()));
}

bool Vec2d::operator!=(const Vec2d & other)
{
  return ((_x != other.get_x()) || (_y != other.get_y()));
}

Vec2d& Vec2d::operator=(const Vec2d & other)
{
  _x = other.get_x();
  _y = other.get_y();
  return (*this);
}

bool Vec2d::non_zero()
{
  return ((_x != 0) && (_y != 0));
}

Vec2d Vec2d::operator+(const Vec2d & other)
{
  return Vec2d( (_x+other.get_x()), (_y+other.get_y()) );
}

Vec2d Vec2d::operator-(const Vec2d & other)
{
  return Vec2d( (_x-other.get_x()), (_y-other.get_y()) );
}

Vec2d Vec2d::operator-()
{
  _x = -_x;
  _y = -_y;
  return Vec2d(_x, _y);
}

Vec2d Vec2d::operator*(const Vec2d & other)
{
  return Vec2d( (_x*other.get_x()), (_y*other.get_y()) );
}

Vec2d Vec2d::operator/(const Vec2d & other)
{
  return Vec2d( (_x/other.get_x()), (_y/other.get_y()) );
}

Vec2d * Vec2d::operator&()
{
  return this;
}

Vec2d Vec2d::operator/(int constant)
{
  return Vec2d( (this->_x/constant), (this->_y/constant) );
}

Vec2d Vec2d::operator/(float constant)
{
  return Vec2d( (this->_x/constant), (this->_y/constant) );
}


Vec2d Vec2d::operator*(float constant)
{
  return Vec2d( (this->_x*constant), (this->_y*constant) );
}

Vec2d Vec2d::operator*(int constant)
{
  return Vec2d( (this->_x*constant), (this->_y*constant) );
}

Vec2d Vec2d::operator+(int constant)
{
  return Vec2d( (this->_x+constant), (this->_y+constant) );
}

Vec2d Vec2d::operator+(float constant)
{
  return Vec2d( (this->_x+constant), (this->_y+constant) );
}

Vec2d Vec2d::operator-(int constant)
{
  return Vec2d( (this->_x-constant), (this->_y-constant) );
}

Vec2d Vec2d::operator-(float constant)
{
  return Vec2d( (this->_x-constant), (this->_y-constant) );
}

Vec2d & Vec2d::operator+=(Vec2d other)
{
  _x += other.get_x();
  _y += other.get_y();
  return *this;
}

Vec2d & Vec2d::operator-=(Vec2d other)
{
  _x -= other.get_x();
  _y -= other.get_y();
  return *this;
}

Vec2d & Vec2d::operator*=(Vec2d other)
{
  _x *= other.get_x();
  _y *= other.get_y();
  return *this;
}

Vec2d & Vec2d::operator/=(Vec2d other)
{
  _x /= other.get_x();
  _y /= other.get_y();
  return *this;
}

Vec2d Vec2d::vec2d_abs(const Vec2d & other)
{
  return Vec2d(abs(other.get_x()), abs(other.get_y()));
}

float Vec2d::get_length()
{
  return sqrt(pow(_x,2)+pow(_y,2));
}

float Vec2d::degrees_to_radian(float degrees)
{
  return (degrees*PI/180);
}

float Vec2d::radian_to_degrees(float radians)
{
  return (radians*180/PI);
}

void Vec2d::rotate(float degrees, int system)
{

  float radians = 0.0;

  if(system == Vec2d::DEGREES_360)
    {
      radians = degrees_to_radian(degrees);
    }
  else
    {
      radians = degrees;
    }

  float c = cos(radians);
  float s = sin(radians);
  float x = _x*c - _y*s;
  float y = _x*s - _y*c;
  _x = x;
  _y = y;

}

Vec2d Vec2d::rotated(float degrees, int system)
{

  float radians = 0.0;

  if(system == Vec2d::DEGREES_360)
    {
      radians = degrees_to_radian(degrees);
    }
  else
    {
      radians = degrees;
    }

  float c = cos(radians);
  float s = sin(radians);
  float x = _x*c - _y*s;
  float y = _x*s - _y*c;

  return Vec2d(x,y);
}

float Vec2d::get_angle(int system)
{

  float angle = 0.0;

  if(pow(get_length(),2) == 0)
    {
      angle == 0;
    } 
  else if(system == Vec2d::DEGREES_360)
    {
      angle = radian_to_degrees(atan2(_y,_x));
    }
  else
    {
      angle = atan2(_y,_x);
    }

  return angle;
}

float Vec2d::get_angle_between(Vec2d & other, int system)
{
  float cross = _x*other.get_y() - _y*other.get_x();
  float dot = _x*other.get_x() + _y*other.get_y();
  
  float angle = 0;

  if(system == Vec2d::DEGREES_360)
    {
      angle = radian_to_degrees(atan2(cross, dot));
    }
  else
    {
      angle = atan2(cross, dot);
    }

  return angle;
}

Vec2d Vec2d::normalized()
{

  float length = get_length();
  if(length != 0)
    {
      return Vec2d(*this)/length;
    }
  else
    {
      return Vec2d(*this);
    }
}

float Vec2d::normalize_return_length()
{

  float length = get_length();
  if(length !=0 )
    {
      _x /= length;
      _y /= length;
    }

  return length;
}

Vec2d Vec2d::perpendicular()
{
  return Vec2d(-_y, _x);
}

Vec2d Vec2d::perpendicular_normal()
{
  float length = get_length();
  if( length != 0 )
    {
      return Vec2d(-_y/length, _x/length );
    }
  else
    {
      return Vec2d(*this);
    }
}

float Vec2d::dot(const Vec2d & other)
{
  return ((_x*other.get_x())+(_y*other.get_y()));
}

float Vec2d::cross(const Vec2d & other)
{
  return ((_x*other.get_y())-(_y*other.get_x()));
}

float Vec2d::get_distance(const Vec2d & other)
{
  return sqrt(pow(_x-other.get_x(),2)+pow(_y-other.get_y(),2));
}

void Vec2d::set_angle(float angle, int system)
{
  _x = get_length();
  _y = 0;
  rotate(angle, system);

}
