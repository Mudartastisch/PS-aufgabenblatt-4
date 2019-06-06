#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include "vec2.hpp"  
#include "circle.hpp"

  Vec2 vec_zero_zero{};
	Vec2 vec_zero_one{ 0.0,1.0 };
	Vec2 vec_one_zero{ 1.0,0.0 };
	Vec2 vec_one_one{ 1.0,1.0 };
	Vec2 vec_nThree_five{ -3.0,5.0 };
	Vec2 vec_nFour_nFour{ -4.0,-4.0 };
	Vec2 vec_five_two{ 5.0,2.0 };
	Vec2 vec_seven_one{ 7.0,1.0 };
  
TEST_CASE("test_vec2_hpp") {
  Vec2 a = Vec2() ; // requires that 0.0f == a.x and 0.0f == a.y
  REQUIRE(0.0f == a.x);
  REQUIRE(0.0f == a.y);
  Vec2 b {5.1f, -9.3f }; /* requires that 5.1 f == Approx ( b . x ) and -9.3 f == Approx ( b . y ) */
  REQUIRE(5.1f == Approx(b.x));
  REQUIRE(-9.3f == Approx(b.y));

}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
