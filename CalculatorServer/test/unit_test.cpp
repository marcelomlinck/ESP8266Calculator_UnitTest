#include <calculator.h>
#include <utils.h>
#include <unity.h>

void test_function_calculator_addition(void) {
    TEST_ASSERT_EQUAL(32, Calculator::add(25, 7));
}

void test_function_calculator_subtraction(void) {
    TEST_ASSERT_EQUAL(20, Calculator::sub(23, 3));
}

void test_function_calculator_multiplication(void) {
    TEST_ASSERT_EQUAL(50, Calculator::mul(25, 2));
}

void test_function_calculator_division(void) {
    TEST_ASSERT_EQUAL(32, Calculator::div(96, 3));
}

void test_function_calculator_division_byzero(void) {
    TEST_ASSERT_EQUAL(__INT32_MAX__, Calculator::div(10, 0));
}

void test_function_isnumber_true(void) {
    TEST_ASSERT_TRUE(Utils::IsNumber("1"));
}

void test_function_isnumber_false(void) {
    TEST_ASSERT_FALSE(Utils::IsNumber("a"));
}

void process() {
    UNITY_BEGIN();
    RUN_TEST(test_function_calculator_addition);
    RUN_TEST(test_function_calculator_subtraction);
    RUN_TEST(test_function_calculator_multiplication);
    RUN_TEST(test_function_calculator_division);
    RUN_TEST(test_function_calculator_division_byzero);
    RUN_TEST(test_function_isnumber_true);
    RUN_TEST(test_function_isnumber_false);
    UNITY_END();
}

#ifdef ARDUINO

#include <Arduino.h>
void setup() {
    // NOTE!!! Wait for >2 secs
    // if board doesn't support software reset via Serial.DTR/RTS
    delay(2000);

    process();
}

void loop() {
    delay(1000);
}

#else

int main(int argc, char **argv) {
    process();
    return 0;
}

#endif