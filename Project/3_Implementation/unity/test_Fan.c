#include "../unity/unity.h"
#include "../unity/unit_testing.h"

void setUp()
{
}
void tearDown()
{
}

void lcd_print_int (unsigned int value, int digits){
TEST_ASSERT_EQUAL_UINT(39,39);
TEST_ASSERT_EQUAL_UINT(58, 58);
TEST_ASSERT_EQUAL_UINT(78, 78);
TEST_ASSERT_EQUAL_UINT(97, 97);
}

int main()
{
  UNITY_BEGIN();

  RUN_TEST(lcd_print_int);

  return UNITY_END();
}