#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"  
#include "circle.hpp"
#include "List.hpp"


TEST_CASE("create empty List") {
    List<int> intList;
    List<char> charList;
    REQUIRE(intList.exists());
    REQUIRE(charList.exists());
}

TEST_CASE("create ListNodes && put in List && test empty()"){
    ListNode<int>* one = new ListNode(1);
    List<int> intList(one);
    REQUIRE(intList.empty() == false);
    List<char> charList;
    REQUIRE(charList.empty());
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
    REQUIRE(42 == list.front());
    list.pop_front();
    REQUIRE(43 == list.front());
    list.pop_back();
    REQUIRE(43 == list.front());
    REQUIRE(43 == list.back());
    list.pop_back();
    REQUIRE(list.empty());
    list.push_front(42);
    REQUIRE(42 == list.front());
    REQUIRE(42 == list.back());
    list.pop_front();
    REQUIRE(list.empty());

}

TEST_CASE ("should be empty after clearing "){
    List<int> list ;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);
    //list.clear();
    REQUIRE(list.empty() == false);
}



int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}