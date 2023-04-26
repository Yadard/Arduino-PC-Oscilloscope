#include <Arduino.h>
#include <containers/Array.h>

struct Foo {
    int x = 0, y = 0;

    Foo() {}
    Foo(int x, int y) : x(x), y(y) {}
};

void setup() {
    Serial.begin(9600);
    AUL::Containers::Array<int, 10> array;
    array.endPush(2);
    for (size_t i = 0; i < array.capacity(); i++) {
        Serial.println(*array.get(i));
    }
    Serial.println("-------------");
    array.endPush(3);
    for (size_t i = 0; i < array.capacity(); i++) {
        Serial.println(*array.get(i));
    }
    Serial.println("-------------");

    array.startPush(1);
    for (size_t i = 0; i < array.capacity(); i++) {
        Serial.println(*array.get(i));
    }
    Serial.println("-------------");

    array.startPush(0);

    for (size_t i = 0; i < array.capacity(); i++) {
        Serial.println(*array.get(i));
    }
    Serial.println("-------------");
}

void loop() {
    // put your main code here, to run repeatedly:
}