#ifndef _L3DW_VECT3F_
#define _L3DW_VECT3F_

#include <vector>
#include <string>

class Vec2d 
{
 private:
  
  float _x, _y;

  float degrees_to_radian(float degrees);
  float radian_to_degrees(float radians);

 public:

  enum {DEGREES_360, DEGREES_RADIAN};

  class Error_InvalidPair{};

  Vec2d();
  Vec2d( float x, float y);
  Vec2d( std::vector<float> pair );
  //copy constructor
  Vec2d( const Vec2d & source );

  std::string to_string();
  
  float get_x() const;
  float get_y() const;
  void set_x(float x);
  void set_y(float y);

  bool operator==(const Vec2d & other); 
  bool operator!=(const Vec2d & other); 
  bool non_zero();
  Vec2d operator+(const Vec2d & other);
  Vec2d operator-(const Vec2d & other);
  Vec2d operator*(const Vec2d & other);
  Vec2d operator/(const Vec2d & other);
  Vec2d operator/(int constant);
  Vec2d operator/(float constant);
  Vec2d & operator+=(Vec2d other);
  Vec2d & operator-=(Vec2d other);
  Vec2d & operator*=(Vec2d other);
  Vec2d & operator/=(Vec2d other);
  Vec2d * operator&();
  void operator* (float constant);
  void operator* (int constant);
  float get_length();
  void rotate(float degrees, int system);
  Vec2d rotated(float degrees, int system);
  float get_angle(int system);
  float get_angle_between(Vec2d & other, int system);
  Vec2d normalized();
  float normalize_return_length();
  Vec2d perpendicular();
  Vec2d perpendicular_normal();
  float dot(const Vec2d & other);
  float cross(const Vec2d & other);
  float get_distance(const Vec2d & other);

};

#endif

/*

THE REST OF PYTHON IMPLEMENTATION (MODEL)

 ??????????????????????????????????????????????????????????????????????
    # Generic operator handlers
    def _o2(self, other, f):
        "Any two-operator operation where the left operand is a Vec2d"
        if isinstance(other, Vec2d):
            return Vec2d(f(self.x, other.x),
                         f(self.y, other.y))
        elif (hasattr(other, "__getitem__")):
            return Vec2d(f(self.x, other[0]),
                         f(self.y, other[1]))
        else:
            return Vec2d(f(self.x, other),
                         f(self.y, other))
 
    def _r_o2(self, other, f):
        "Any two-operator operation where the right operand is a Vec2d"
        if (hasattr(other, "__getitem__")):
            return Vec2d(f(other[0], self.x),
                         f(other[1], self.y))
        else:
            return Vec2d(f(other, self.x),
                         f(other, self.y))
 
    def _io(self, other, f):
        "inplace operator"
        if (hasattr(other, "__getitem__")):
            self.x = f(self.x, other[0])
            self.y = f(self.y, other[1])
        else:                                               COPY CONDTRUCTOR ????
            self.x = f(self.x, other)
            self.y = f(self.y, other)
        return self
???????????????????????????????????????????????????????????????????????
*/
/*

 
 
    # Modulo
    def __mod__(self, other):
        return self._o2(other, operator.mod)
    def __rmod__(self, other):
        return self._r_o2(other, operator.mod)
 
    def __divmod__(self, other):
        return self._o2(other, operator.divmod)
    def __rdivmod__(self, other):
        return self._r_o2(other, operator.divmod)
 
    # Exponentation
    def __pow__(self, other):
        return self._o2(other, operator.pow)
    def __rpow__(self, other):
        return self._r_o2(other, operator.pow)
 
    # Bitwise operators
    def __lshift__(self, other):
        return self._o2(other, operator.lshift)
    def __rlshift__(self, other):
        return self._r_o2(other, operator.lshift)
 
    def __rshift__(self, other):
        return self._o2(other, operator.rshift)
    def __rrshift__(self, other):
        return self._r_o2(other, operator.rshift)
 
    def __and__(self, other):
        return self._o2(other, operator.and_)
    __rand__ = __and__
 
    def __or__(self, other):
        return self._o2(other, operator.or_)
    __ror__ = __or__
 
    def __xor__(self, other):
        return self._o2(other, operator.xor)
    __rxor__ = __xor__
 
    # Unary operations
    def __neg__(self):
        return Vec2d(operator.neg(self.x), operator.neg(self.y))
 
    def __pos__(self):
        return Vec2d(operator.pos(self.x), operator.pos(self.y))
 
    def __abs__(self):
        return Vec2d(abs(self.x), abs(self.y))
 
    def __invert__(self):
        return Vec2d(-self.x, -self.y)


 */

/*

    def __setangle(self, angle_degrees):
        self.x = self.length
        self.y = 0
        self.rotate(angle_degrees)
    angle = property(get_angle, __setangle, None, "gets or sets the angle of a vector")
 

 */

/*

    def projection(self, other):
        other_length_sqrd = other[0]*other[0] + other[1]*other[1]
        projected_length_times_other_length = self.dot(other)
        return other*(projected_length_times_other_length/other_length_sqrd)
 
    def interpolate_to(self, other, range):
        return Vec2d(self.x + (other[0] - self.x)*range, self.y + (other[1] - self.y)*range)
 
    def convert_to_basis(self, x_vector, y_vector):
        return Vec2d(self.dot(x_vector)/x_vector.get_length_sqrd(), self.dot(y_vector)/y_vector.get_length_sqrd())
 
    def __getstate__(self):
        return [self.x, self.y]
 
    def __setstate__(self, dict):
        self.x, self.y = dict

 */


