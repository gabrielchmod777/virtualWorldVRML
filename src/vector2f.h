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
  Vec2d& operator=(const Vec2d & other); 
  bool non_zero();
  Vec2d operator+(const Vec2d & other);
  Vec2d operator-(const Vec2d & other);
  Vec2d operator-();
  Vec2d operator*(const Vec2d & other);
  Vec2d operator/(const Vec2d & other);
  Vec2d operator/(int constant);
  Vec2d operator/(float constant);
  Vec2d operator* (float constant);
  Vec2d operator* (int constant);
  Vec2d operator+ (float constant);
  Vec2d operator+ (int constant);
  Vec2d operator- (float constant);
  Vec2d operator- (int constant);
  Vec2d & operator+=(Vec2d other);
  Vec2d & operator-=(Vec2d other);
  Vec2d & operator*=(Vec2d other);
  Vec2d & operator/=(Vec2d other);
  Vec2d * operator&();
  static Vec2d vec2d_abs(const Vec2d & other);
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
  void set_angle(float angle, int system);
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

/*

                         PARTIAL TEST -- C++


#include "../vector2f.h"

#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

#include "../vector2f.cpp"

bool closeEnough(float value, float base, float tolerance)
{
  float low = base - tolerance;
  float high = base + tolerance;
  if( (low<= value) && (value<= high) )
    {
      return true;
    }
  else
    return false;
}

int main(void)
{

  cout<<endl<<"Test creation and access";

  Vec2d v1(111,222);
  assert(v1.get_x()==111);
  assert(v1.get_y()==222);
  v1.set_x(5);
  v1.set_y(8);
  assert(v1.get_x()==5);
  assert(v1.get_y()==8);

  vector<float> argV = {111,222};
  Vec2d v2(argV);
  assert(v2.get_x()==111);
  assert(v2.get_y()==222);

  Vec2d v3(v1);
  assert(v3.get_x()==5);
  assert(v3.get_y()==8);
  cout<<"  \t\t\t\t\t\t... OK";

  cout<<endl<<"Test Vec2d comparison ... ";
  assert( v3 == v1);
  assert( v2 != v3);
  cout<<"  \t\t\t\t\t\t... OK";

  cout<<endl<<"Test the assignment operator ...";
  Vec2d asg1(0.3, 0.2);
  Vec2d asg2;
  asg2 = asg1;
  assert(asg1 == asg2);
  cout<<" \t\t\t\t\t\t... OK ";

  cout<<endl<<"Test Vec2d MATH ... ";
  Vec2d v4(111,222);
  v4 = v4+1;
  assert(v4 == Vec2d(112,223));
  v4 = v4-1;
  assert(v4 == Vec2d(111,222));
  v4 = v4*3;
  assert(v4 == Vec2d(333,666));
  Vec2d aaa = v4/3;
  assert(aaa == Vec2d(111,222));
  Vec2d bbb = (aaa / Vec2d(100,100));
  assert(bbb == Vec2d(1.11,2.22));
  bbb = aaa * aaa;
  assert(bbb == Vec2d(12321,49284));
  cout<<"  \t\t\t\t\t\t... OK";

  cout<<endl<<"Test Vec2d Unary ... ";
  aaa = -aaa;
  assert(aaa == Vec2d(-111,-222));
  aaa = Vec2d::vec2d_abs(aaa);
  assert(aaa == Vec2d(111,222));
  cout<<" \t\t\t\t\t\t... OK";

  cout<<endl<<"Test Vec2d test Length ... ";
  Vec2d lenv(3,4);
  assert(lenv.get_length() == 5);
  assert(lenv.normalize_return_length() == 5);
  assert(lenv.get_length() == 1);
  lenv = Vec2d(3,4);
  Vec2d lenv2(10,-2);
  assert(lenv.get_distance(lenv2) == (lenv-lenv2).get_length());
  cout<<" \t\t\t\t\t\t... OK";

  cout<<endl<<"Test ANGLES ";
  Vec2d ang = Vec2d(0,3);
  assert(ang.get_angle(Vec2d::DEGREES_360) == 90);
  Vec2d ang2 = Vec2d(ang);
  ang.rotate(-90, Vec2d::DEGREES_360);
  assert(closeEnough(ang.get_angle_between(ang2, Vec2d::DEGREES_360), 90, 0.0001));
  assert(ang.get_length() == ang2.get_length());
  ang2.set_angle(ang2.get_angle(Vec2d::DEGREES_360)-90, Vec2d::DEGREES_360);
  assert(closeEnough(ang2.get_angle(Vec2d::DEGREES_360), 0, 0.0001));
  assert(ang2 == Vec2d(3,0));
  assert(closeEnough((ang-ang2).get_length(),0,0.0001));
  assert(ang.get_length() == ang2.get_length());
  ang2.rotate(300,Vec2d::DEGREES_360);
  assert(closeEnough(ang.get_angle_between(ang2, Vec2d::DEGREES_360), -60, 0.0001));
  
  ang2.rotate(ang2.get_angle_between(ang, Vec2d::DEGREES_360), Vec2d::DEGREES_360);
  assert(closeEnough(ang.get_angle_between(ang, Vec2d::DEGREES_360), 0, 0.0001));
  
  cout<<" \t\t\t\t\t\t... OK";
  
  cout<<endl;


 
        // def testHighLevel(self):
        //     basis0 = Vec2d(5.0, 0)
        //     basis1 = Vec2d(0, .5)
        //     v = Vec2d(10, 1)
        //     self.assert_(v.convert_to_basis(basis0, basis1) == [2, 2])
        //     self.assert_(v.projection(basis0) == (10, 0))
        //     self.assert_(basis0.dot(basis1) == 0)
 
        // def testCross(self):
        //     lhs = Vec2d(1, .5)
        //     rhs = Vec2d(4,6)
        //     self.assert_(lhs.cross(rhs) == 4)
 
        // def testComparison(self):
        //     int_vec = Vec2d(3, -2)
        //     flt_vec = Vec2d(3.0, -2.0)
        //     zero_vec = Vec2d(0, 0)
        //     self.assert_(int_vec == flt_vec)
        //     self.assert_(int_vec != zero_vec)
        //     self.assert_((flt_vec == zero_vec) == False)
        //     self.assert_((flt_vec != int_vec) == False)
        //     self.assert_(int_vec == (3, -2))
        //     self.assert_(int_vec != [0, 0])
        //     self.assert_(int_vec != 5)
        //     self.assert_(int_vec != [3, -2, -5])
 
        // def testInplace(self):
        //     inplace_vec = Vec2d(5, 13)
        //     inplace_ref = inplace_vec
        //     inplace_src = Vec2d(inplace_vec)
        //     inplace_vec *= .5
        //     inplace_vec += .5
        //     inplace_vec /= (3, 6)
        //     inplace_vec += Vec2d(-1, -1)
        //     self.assertEquals(inplace_vec, inplace_ref)
 
        // def testPickle(self):
        //     testvec = Vec2d(5, .3)
        //     testvec_str = pickle.dumps(testvec)
        //     loaded_vec = pickle.loads(testvec_str)
        //     self.assertEquals(testvec, loaded_vec)

  return 0;
}


*/

