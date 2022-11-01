#! /bin/bash

PROJECT_LOCATION=".";
NAME="push_swap";
MKF_CMD="push_swap";
CHECKER="checker_Mac";

source	colors.sh
C_ORANGE1="\x1b[38;2;255;170;0m"
C_ORANGE2="\x1b[38;2;255;213;0m"
CC_LINE="\r\x1b[0J"
source	test_functions.sh
source	test_iterations.sh


if	[ -f "$PROJECT_LOCATION/Makefile" ]; then
	make	-f $PROJECT_LOCATION/Makefile $MKF_CMD;
elif	[ -f "$PROJECT_LOCATION/makefile" ]; then
	make	-f $PROJECT_LOCATION/makefile $MKF_CMD;
else
	printf	"$C_ORANGE%s$C_RED not found...$C_RESET\n"	"Makefile";
	printf	"$C_RED Please check$C_ORANGE PROJECT_LOCACTION=\"\";$C_RESET\n";
	exit;
fi

if [ ! -f "$PROJECT_LOCATION/$NAME" ]; then
	printf	"$C_ORANGE%s$C_RED not found...$C_RESET\n"	"$NAME";
	exit;
fi

if [ ! -f "$PROJECT_LOCATION/$CHECKER" ]; then
	printf	"$C_ORANGE%s$C_RED not found...$C_RESET\n"	"$CHECKER";
	exit;
fi

printf	"\n$C_BOLD%s$C_RESET\n"	"Functionality tests"
test_OK

printf	"\n$C_BOLD%s$C_RESET\n"	"Error handling tests"
test_ERROR

printf	"\n$C_BOLD%5s %7s %14s %8s$C_RESET\n"	"Test"	"Count"	"Avg/High"	"Grade"

SIZE=2;
set_values	"1"	"1"
test_2
print_result

SIZE=3;
set_values	"2"	"3"
test_3
print_result

SIZE=4;
set_values	"4"	"6"
test_4
print_result

SIZE=5;
set_values	"8"	"12"
test_5
print_result

# SIZE=6;
# set_values	"13"	"23"
# test_6
# print_result

SIZE=23;
set_values	"100"	"185"
test_23
print_result

SIZE=42;
set_values	"230"	"423"
test_42
print_result

SIZE=100;
set_values	"700"	"1500"
test_100
print_result

SIZE=500;
set_values	"5500"	"11500"
test_500
print_result
