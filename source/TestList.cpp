#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"  
#include "circle.hpp"
#include "List.hpp"


TEST_CASE("create empty List") {
    List<int> intList;
    List<char> charList;
    REQUIRE(intList.exists() == true);
    REQUIRE(charList.exists() == true);
}

TEST_CASE("create ListNodes && put in List && test empty()"){
    ListNode<int>* one = new ListNode(1);
    List<int> intList(one);
    REQUIRE(intList.empty() == false);
    List<char> charList;
    REQUIRE(charList.empty() == true);
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}