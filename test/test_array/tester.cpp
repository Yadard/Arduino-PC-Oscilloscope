#include <containers/Array.h>
#include <unity.h>

struct Foo {
    int x, y;

    Foo() {}
    Foo(int x, int y) : x(x), y(y) {}
};

void setUp(void) {}

void tearDown(void) {}

void init_array(void) {
    AUL::Containers::Array<int, 10> array;

    TEST_ASSERT_TRUE(array.empty());
    TEST_ASSERT_EQUAL(0, array.size());
    TEST_ASSERT_EQUAL(10, array.capacity());
    TEST_ASSERT_EQUAL(nullptr, array.get(0));
    TEST_ASSERT_EQUAL(nullptr, array.getFirst());
    TEST_ASSERT_EQUAL(nullptr, array.getLast());
    TEST_ASSERT_TRUE(array.begin() == array.end());
}

void array_get(void) {
    AUL::Containers::Array<int, 10> array;

    for (size_t i = 0; i < array.capacity(); i++)
        array.endPush(i);

    for (size_t i = 0; i < array.size(); i++) {
        TEST_ASSERT_NOT_EQUAL(nullptr, array.get(i));
        TEST_ASSERT_EQUAL(i, *array.get(i));
    }
}

void array_fillPush(void) {
    AUL::Containers::Array<int, 10> array;
    array.fillPush(1);

    TEST_ASSERT_FALSE(array.empty());

    TEST_ASSERT_EQUAL(array.capacity(), array.size());
    TEST_ASSERT_EQUAL(1, *array.getFirst());
    TEST_ASSERT_EQUAL(1, *array.getLast());
    TEST_ASSERT_TRUE(array.begin() != array.end());

    for (size_t i = 0; i < array.size(); i++)
        TEST_ASSERT_EQUAL(1, *array.get(i));
}

void array_fillEmplace(void) {

    AUL::Containers::Array<Foo, 10> array;
    array.fillEmplace(1, 5);

    TEST_ASSERT_FALSE(array.empty());
    TEST_ASSERT_EQUAL(array.capacity(), array.size());
    TEST_ASSERT_EQUAL(1, array.getFirst()->x);
    TEST_ASSERT_EQUAL(5, array.getFirst()->y);

    TEST_ASSERT_EQUAL(1, array.getLast()->x);
    TEST_ASSERT_EQUAL(5, array.getLast()->y);
    TEST_ASSERT_TRUE(array.begin() != array.end());

    for (size_t i = 0; i < array.size(); i++) {
        TEST_ASSERT_EQUAL(1, array.get(i)->x);
        TEST_ASSERT_EQUAL(5, array.get(i)->y);
    }
}

void array_startPush_and_endPush(void) {
    AUL::Containers::Array<int, 10> array;
    array.endPush(2);
    array.endPush(3);
    array.startPush(1);
    array.startPush(0);

    size_t i = 0;
    for (auto it = array.begin(); it != array.end(); it++, i++) {
        TEST_ASSERT_EQUAL(i, *it);
    }
}

void array_setEmplace_and_setPush(void) {
    AUL::Containers::Array<Foo, 10> array;
    array.fillEmplace(0, 0);
    array.setEmplace(5, 45, 85);
    array.setPush(0, Foo(25, 50));

    TEST_ASSERT_EQUAL(45, array.get(5)->x);
    TEST_ASSERT_EQUAL(85, array.get(5)->y);

    TEST_ASSERT_EQUAL(25, array.get(0)->x);
    TEST_ASSERT_EQUAL(50, array.get(0)->y);
}

void array_startEmplace_and_endEmplace(void) {
    AUL::Containers::Array<Foo, 10> array;

    array.endEmplace(2, 2);
    array.endEmplace(3, 3);
    array.startEmplace(1, 1);
    array.startEmplace(0, 0);

    size_t i = 0;
    for (auto it = array.begin(); it != array.end(); it++, i++) {
        TEST_ASSERT_EQUAL(i, it->x);
        TEST_ASSERT_EQUAL(i, it->y);
    }
}

void array_Iterator(void) {
    AUL::Containers::Array<Foo, 10> array;

    for (size_t i = 1; i <= array.capacity(); i++) {
        array.endEmplace(i * 5, i * 3);
    }

    size_t i = 1;
    for (auto it = array.begin(); it != array.end(); it++, i++) {
        TEST_ASSERT_EQUAL(i * 5, it->x);
        TEST_ASSERT_EQUAL(i * 3, it->y);
    }
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(init_array);
    RUN_TEST(array_get);
    RUN_TEST(array_fillPush);
    RUN_TEST(array_fillEmplace);
    RUN_TEST(array_startPush_and_endPush);
    RUN_TEST(array_startEmplace_and_endEmplace);
    RUN_TEST(array_setEmplace_and_setPush);
    RUN_TEST(array_Iterator);

    UNITY_END();
}