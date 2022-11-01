#! /bin/bash

source	colors.sh

function	test()
{
	ARG="$1";

	((TESTS=TESTS+1))
	CHECK=$($PROJECT_LOCATION/$NAME	$ARG | ./checker_Mac $ARG);
	STEPS=$($PROJECT_LOCATION/$NAME	$ARG | wc -l);
	TOTAL=$((STEPS+TOTAL))
	if [ $STEPS -gt $HIGHEST ]; then
		HIGHEST=$((STEPS));
	fi
	printf	"$CC_LINE $C_BOLD %-6s $C_RESET"	"$SIZE"
	printf	"$C_BOLD%-5s $C_RESET"	"#$TESTS"
	if	[ "$CHECK" != "OK" ]; then
		printf	"$C_RED%s$C_RESET\n"	"$CHECK";
		if [ "$SUCCES" == "1" ]; then
			printf	"%s\n"	"$ARG";
		fi
		SUCCES=-1;
	elif	[ $STEPS -gt $LIMIT ]; then
		printf	"$C_RED[KO.%i]$C_RESET\n"	"$STEPS";
		if [ "$SUCCES" == "1" ]; then
			printf	"%s\n"	"$ARG";
		fi
		if [ "$SUCCES" == "1" ]; then
			SUCCES=0;
		fi
	else
		if	[ $STEPS -gt $MID_LIMIT3 ]; then
		printf	"$C_ORANGE";
		elif	[ $STEPS -gt $MID_LIMIT2 ]; then
			printf	"$C_ORANGE1";
		elif	[ $STEPS -gt $MID_LIMIT1 ]; then
			printf	"$C_ORANGE2";
		elif	[ $STEPS -gt $LOW_LIMIT ]; then
			printf	"$C_YELLOW";
		else
			printf	"$C_GREEN";
		fi
		printf	"[%s.%i]$C_RESET"	"$CHECK"	"$STEPS"
	fi
	printf	"$C_RESET"
}

function	test_for_ok
{
	ARG="$1";
	
	CHECK=$($PROJECT_LOCATION/$NAME	$ARG 2> /dev/null | ./$CHECKER $ARG);
	if [ "$CHECK" == "OK" ]; then
		printf	"$C_GREEN[OK] $C_RESET"
	else
		printf	"\n$C_RED[KO]$C_RESET\t"
		printf	"\"$ARG\"\n"
	fi
}

function	test_for_error
{
	ARG="$1";

	PS=$($PROJECT_LOCATION/$NAME	$ARG	2>&1 >/dev/null)
	CHECK=$(./$CHECKER	$ARG	2>&1 >/dev/null)
	if [ "$PS" == "$CHECK" ]; then
		printf	"$C_GREEN[OK] $C_RESET"
	else
		printf	"\n$C_RED[KO]$C_RESET\t"
		printf	"\"$ARG\"\n"
	fi
}

function	set_values()
{
	TESTS=0;
	HIGHEST=0;
	TOTAL=0;
	LOW_LIMIT="$1";
	LIMIT="$2";
	MID_LIMIT1=$((LOW_LIMIT+((LIMIT-LOW_LIMIT)*1)/4));
	MID_LIMIT2=$((LOW_LIMIT+((LIMIT-LOW_LIMIT)*2)/4));
	MID_LIMIT3=$((LOW_LIMIT+((LIMIT-LOW_LIMIT)*3)/4));
	SUCCES=1;
}

function	print_result()
{
	AVG=$((TOTAL/TESTS))
	GRADE_NUM=$(((TOTAL+(HIGHEST*TESTS))/(TESTS*2)))
	printf	"$CC_LINE $C_BOLD %-6s $C_RESET"	"$SIZE"
	printf	"$C_BOLD%-5s $C_RESET"	"#$TESTS"
	printf	"$C_BOLD %7s/%-7i$C_RESET\t"	"$((TOTAL/TESTS))"	"$HIGHEST"
	if  [ "$SUCCES" == "-1" ]; then
		printf	"$C_RED[KO]$C_RESET\n";
	elif [ $HIGHEST -gt $LIMIT ] || [ $GRADE_NUM -gt $LIMIT ] || [ "$CHECK" != "OK" ] || [ "$SUCCES" == "0" ]; then
		printf	"$C_RED%i/5$C_RESET\n"	"0";
	elif [ $GRADE_NUM -gt $MID_LIMIT3 ]; then
		printf	"$C_ORANGE%i/5$C_RESET\n"	"1";
	elif [ $GRADE_NUM -gt $MID_LIMIT2 ]; then
		printf	"$C_ORANGE1%i/5$C_RESET\n"	"2";
	elif [ $GRADE_NUM -gt $MID_LIMIT1 ]; then
		printf	"$C_ORANGE2%i/5$C_RESET\n"	"3";
	elif [ $GRADE_NUM -gt $LOW_LIMIT ]; then
		printf	"$C_YELLOW%i/5$C_RESET\n"	"4";
	else
		printf	"$C_GREEN%i/5$C_RESET\n"	"5";
	fi
}