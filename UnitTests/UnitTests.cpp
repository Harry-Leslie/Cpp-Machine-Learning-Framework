#include "pch.h"
#include "CppUnitTest.h"
#include "../src/Linker.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:

		TEST_METHOD(TestSimpleLinearRegression)
		{
			ArrayList x({ 1, 2, 3, 4, 5 });
			ArrayList y({ 2, 4, 5, 4, 5 });

			SimpleLinearRegression slr(x, y);
			slr.train();

			// Test expected coefficients (b0 and b1) for a simple linear regression
			Assert::AreEqual(1.1, slr.getb0(), 0.01); // Within a tolerance of 0.01
			Assert::AreEqual(0.6, slr.getb1(), 0.01); // Within a tolerance of 0.01
		}

		TEST_METHOD(TestMultipleLinearRegression)
		{
			m X = {
				{1, 2},
				{2, 4},
				{3, 6},
				{4, 8},
				{5, 10}
			};

			m y = {
				{3},
				{6},
				{9},
				{12},
				{15}
			};

			MultipleLinearRegression mlr(X, y);
			mlr.train();

			// Test expected coefficients (b0, b1, and b2) for multiple linear regression
			// For the provided X and y matrices, we expect B0 = 0, B1 = 1, B2 = 1 (or any parallel vector like B1 = 0.5 and B2 = 0.5)
			Assert::AreEqual(0.0, mlr.getCoefficients()[0], 0.01); // Within a tolerance of 0.01
			Assert::AreEqual(1.0, mlr.getCoefficients()[1], 0.01); // Within a tolerance of 0.01
			Assert::AreEqual(1.0, mlr.getCoefficients()[2], 0.01); // Within a tolerance of 0.01
		}

		TEST_METHOD(TestMatrixInverse)
		{
			m matrix = {
				{1, 2},
				{3, 4}
			};

			Matrix m1(matrix);
			m1.inverse_matrix();

			// Test the inverse of the matrix
			m expectedInverse = {
				{ -2.0, 1.0 },
				{ 1.5, -0.5 }
			};

			m inverse = m1.get_matrix();
			Assert::IsTrue(inverse == expectedInverse);
		}
	};
}