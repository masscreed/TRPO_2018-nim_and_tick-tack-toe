#include "tick-tack-toe.h"
#include "nim.h"
#include "ctest.h"
#include <stdio.h>


CTEST (mathces_test_true, check_correct_matches)
{
    int value[] = { 1, 1, 1};
	int i = 0, num = 1;
    int result = check_correct_matches (value, i, num);

    const int expected = 1;
    ASSERT_EQUAL (expected, result);
}

CTEST (mathces_test_false, check_correct_matches)
{
    int value[] = { 23, 5, 7};
	int i = 1, num = 6;
    int result = check_correct_matches (value, i, num);

    const int expected = 0;
    ASSERT_EQUAL (expected, result);
}


CTEST (heap_test_false, heap_check)
{
    int value[] = { 23, 5, 7};
	int input = 0;
    int result = heap_check (input, value);

    const int expected = 1;
    ASSERT_EQUAL (expected, result);
}


CTEST (heap_test_true, heap_check)
{
    int value[] = { 23, 5, 7};
	int input = 3;
    int result = heap_check (input, value);

    const int expected = 0;
    ASSERT_EQUAL (expected, result);
}


CTEST (tick_test_true, check_correct_data)
{	
	char ch[const_height][const_length] = {
        " | | ",
        " | | ",
        " | | "		
	};
	char a[] = "11";
    int result = check_correct_data (a, ch);

    const int expected = 1;
    ASSERT_EQUAL (expected, result);
}


CTEST (tick_test_false, check_correct_data)
{	
	char ch[const_height][const_length] = {
        " | | ",
        " | | ",
        " | | "		
	};
	char a[] = "14";
    int result = check_correct_data (a, ch);

    const int expected = 0;
    ASSERT_EQUAL (expected, result);
}


CTEST (tick_test_false_1, check_correct_data)
{	
	char ch[const_height][const_length] = {
        "x| | ",
        " | | ",
        " | | "		
	};
	char a[] = "11";
    int result = check_correct_data (a, ch);

    const int expected = 0;
    ASSERT_EQUAL (expected, result);
}
