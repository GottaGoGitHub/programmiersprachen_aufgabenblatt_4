#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <iostream>
#include "list.hpp"
#include "circle.hpp"


TEST_CASE("empty")
{
    List<int> list;
    list.push_front(10);
    REQUIRE(list.empty() == false);
}

TEST_CASE("push_front")
{
    List<int> list;
    list.push_front(42);
    REQUIRE(42 == list.front());
}

TEST_CASE("push_back")
{
    List<int> list;
    list.push_back(26);
    REQUIRE(26 == list.back());
}

TEST_CASE("pop_front")
{
    List<int> list;
    list.push_front(26);
    list.push_front(32);
    list.pop_front();
    REQUIRE(26 == list.front());
}

TEST_CASE("pop_back")
{
    List<int> list;
    list.push_back(26);
    list.push_back(32);
    list.pop_back();
    REQUIRE(26 == list.back());
}

TEST_CASE("clear")
{
    List<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);
    list.clear();

    REQUIRE(list.empty());
}

TEST_CASE("ListIterator Operatoren")
{
    List<int> list;
    list.push_front(34);
    list.push_front(18);
    list.push_front(21);
    ListIterator<int> itr = list.begin();
    ListIterator<int> itr2 = list.end();

    REQUIRE(*itr == 21);
    REQUIRE(*itr2 == 34);

    ++itr;
    REQUIRE(*itr == 18);

    itr2++;
    REQUIRE(*itr2 == 34);
}

TEST_CASE("ListIterator == / !=")
{
    List<int> list;
    list.push_front(34);
    list.push_front(18);
    list.push_front(21);
    ListIterator<int> itr = list.begin();
    ListIterator<int> itr2 = list.end();

    REQUIRE(itr != itr2);
    REQUIRE(itr == itr);
}

TEST_CASE("nullptr")
{
    List<int> list;
    auto b = list.begin();
    auto e = list.end();
    REQUIRE(b == e);
}

TEST_CASE("iterator begin")
{
    List<int> list;
    list.push_front(42);
    list.push_front(22);
    REQUIRE(22 == *list.begin());
}

TEST_CASE("compare lists")
{
    List<int> list;
    List<int> list2;
    list.push_front(42);
    list.push_front(23);
    list2.push_front(42);
    list2.push_front(23);

    REQUIRE(list == list2);

    list2.push_front(45);

    REQUIRE(list != list2);
}

TEST_CASE("copy constructor")
{
List<int> list;
list.push_front(1);
list.push_front(2);
list.push_front(3);
list.push_front(4);

List<int> list2{list};
REQUIRE(list == list2);
}

TEST_CASE ("move constructor")
{
    List<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);
    List<int> list2 = std::move(list);
    REQUIRE(0 == list.size());
    REQUIRE(list.empty());
    REQUIRE(4 == list2.size());
}

TEST_CASE("ListIterator", "[circle]"){
    List<Circle> circle_list;
    Vec2 a{250, 200};
    float radius = 100;
    rgb color{0.8, 0.2, 0.2}; 
    Circle c = Circle{a, radius, color};
    circle_list.push_back(c);

    auto c_it = circle_list.begin(); 
    std::cout <<"Der Radius des 1.Circles in der Liste ist: "
              << c_it->getRadius() <<std::endl; 

}

int main(int argc, char * argv [])
{
    return Catch::Session().run(argc, argv);
}