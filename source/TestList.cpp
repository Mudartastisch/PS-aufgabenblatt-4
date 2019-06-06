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

TEST_CASE("add an element with push_front"){
    List<int>list;
    list.push_front(42);
    REQUIRE(42 == list.front());
    REQUIRE(42 == list.back());
    list.push_front(43);
    REQUIRE(43 == list.front());
    REQUIRE(42 == list.back());
}

TEST_CASE("add an element with push_back"){
    List<int>list;
    list.push_back(42);
    REQUIRE(42 == list.front());
    REQUIRE(42 == list.back());
    list.push_back(43);
    REQUIRE(42 == list.front());
    REQUIRE(43 == list.back());
}

TEST_CASE("remove elements with popX"){
    List<int>list;
    list.push_back(42);
    list.push_back(43);
    list.push_back(44);
}



int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}