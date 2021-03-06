﻿#include "LDMathUtilTest.h"

namespace live2d
{
//------ EMathUtil.h ------
void LDMathUtilTest::wrapPiTest()
{
	ld_float actual;
	ld_float expected;
	ld_float theta;
	//ld_float delta = 0.00001f;

	// Input : 0.0
	theta    = 0.0f;
	expected = 0.0f;
	actual   = LDMathUtil::wrapPi( theta );
	QCOMPARE( expected, actual );

	// Input : 2PI
	theta    = LDMathUtil::PI2;
	expected = 0.0f;
	actual   = LDMathUtil::wrapPi( theta );
	QCOMPARE( expected, actual );

	// Input : PI, PI±0.01におけるラップテスト
	theta    = LDMathUtil::PI-0.01f;
	expected = LDMathUtil::PI-0.01f;
	actual   = LDMathUtil::wrapPi( theta );
	QCOMPARE( expected, actual );

	theta    = LDMathUtil::PI;
	expected = LDMathUtil::PI;
	actual   = LDMathUtil::wrapPi( theta );
	QCOMPARE( expected, actual );

	theta    = LDMathUtil::PI+0.01f;
	expected = 0.01f - LDMathUtil::PI;
	actual   = LDMathUtil::wrapPi( theta );
	QCOMPARE( expected, actual );

	// Input : -PI, -PI±0.01におけるラップテスト
	theta    = -LDMathUtil::PI-0.01f;
	expected = LDMathUtil::PI-0.01f;
	actual   = LDMathUtil::wrapPi( theta );
	QCOMPARE( expected, actual );

	theta    = -LDMathUtil::PI;
	expected = -LDMathUtil::PI;
	actual   = LDMathUtil::wrapPi( theta );
	QCOMPARE( expected, actual );

	theta    = -LDMathUtil::PI+0.01f;
	expected = -LDMathUtil::PI+0.01f;
	actual   = LDMathUtil::wrapPi( theta );
	QCOMPARE( expected, actual );
}

void LDMathUtilTest::getAngleDiffTest()
{
	ld_float actual;
	ld_float expected;
	ld_float Q1, Q2;
	//ld_float delta = 0.00001f;

	// Input : Q1 = 0.0, Q2 = 0.0
	Q1 = 0.0f;
	Q2 = 0.0f;
	expected = 0.0f;
	actual   = LDMathUtil::getAngleDiff( Q1, Q2 );
	QCOMPARE( expected, actual );

	// Input : Q1 = PI, Q2 = 0.0
	Q1 = LDMathUtil::PI;
	Q2 = 0.0f;
	expected = LDMathUtil::PI;
	actual   = LDMathUtil::getAngleDiff( Q1, Q2 );
	QCOMPARE( expected, actual );

	// Input : Q1 = PI+0.1, Q2 = 0.0
	Q1 = LDMathUtil::PI+0.1f;
	Q2 = 0.0f;
	expected = -LDMathUtil::PI+0.1f;
	actual   = LDMathUtil::getAngleDiff( Q1, Q2 );
	QCOMPARE( expected, actual );

	// Input : Q1 = -PI, Q2 = 0.0
	Q1 = -LDMathUtil::PI;
	Q2 = 0.0f;
	expected = -LDMathUtil::PI;
	actual   = LDMathUtil::getAngleDiff( Q1, Q2 );
	QCOMPARE( expected, actual );

	// Input : Q1 = -PI-0.1, Q2 = 0.0
	Q1 = -LDMathUtil::PI-0.1f;
	Q2 = 0.0f;
	expected = LDMathUtil::PI-0.1f;
	actual   = LDMathUtil::getAngleDiff( Q1, Q2 );
	QCOMPARE( expected, actual );
}

void LDMathUtilTest::safeAcosTest()
{
	ld_float actual;
	ld_float expected;
	ld_float x;
	//ld_float delta = 0.00001f;

	// Input : x = -1.0f
	x = -1.0f;
	expected = LDMathUtil::PI;
	actual = LDMathUtil::safeAcos( x );
	QCOMPARE( expected, actual );

	// Input : x = 1.0f
	x = 1.0f;
	expected = 0.0f;
	actual = LDMathUtil::safeAcos( x );
	QCOMPARE( expected, actual );
}

void LDMathUtilTest::sinCosTest()
{
	// sin(), cos()が呼ばれているだけなので省略します
}
} // namespace live2d
