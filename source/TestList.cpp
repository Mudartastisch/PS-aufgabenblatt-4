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
    list.clear();
    REQUIRE(list.empty());
}

TEST_CASE("Iterator Tests"){
    List<Circle>circle_list;
    Circle one(Vec2(0.0f,0.0f), 1.0f);
    circle_list.push_back(one);
    auto c_it = circle_list.begin();
    REQUIRE(c_it->getRadius() == 1);
    
    Circle two(Vec2(0.0f,0.0f), 2.0f);
    circle_list.push_back(two);
    c_it++;
    REQUIRE(c_it.operator*().getRadius() == 2);

    Circle three(Vec2(0.0f,0.0f), 3.0f);
    circle_list.push_back(three);
    ++c_it;
    REQUIRE(c_it->getRadius() == 3);

    c_it = circle_list.begin();
    auto c_itt = circle_list.begin();
    REQUIRE(c_it.operator==(c_itt));
    c_it++;
    REQUIRE(c_it.operator==(c_itt) == false);
    REQUIRE(c_it.operator!=(c_itt));
}

TEST_CASE("should be an empty range after default construction"){
    List<int> list;
    auto b = list.begin();
    auto e = list.end();
    REQUIRE (b == e);
}

TEST_CASE("provide access to the first element with begin"){
    List<int>list;
    list.push_front(42);
    REQUIRE(42 == *list.begin());
}


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}