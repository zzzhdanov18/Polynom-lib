#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include<doctest/doctest.h>
#include<poly/poly.h>
#include<limits>
TEST_CASE("operations")
{
	SUBCASE("plus")
	{
		Poly a(2, new double[2]{ 1,2 });
		Poly b(2, new double[2]{ 1,2 });
		Poly check(2, new double[2]{ 2,4 });
		CHECK(a + b == check);
	}
	SUBCASE("minus")
	{
		Poly a(2, new double[2]{ 1,2 });
		Poly b(2, new double[2]{ 2,3 });
		Poly check(2, new double[2]{ 1,1 });
		CHECK(b-a == check);
	}
	SUBCASE("multipl")
	{
		Poly a(2, new double[2]{ 1,2 });
		Poly b(2, new double[2]{ 1,2 });
		Poly check(3, new double[3]{ 1,4,4 });
		CHECK(b * a == check);
	}
	SUBCASE("diff")
	{
		Poly a(3, new double[3]{ 1,4,4 });
		Poly b(2, new double[2]{ 1,2 });
		Poly check(2, new double[2]{ 1,2});
		CHECK(a / b == check);
	}
	SUBCASE("plus=")
	{
		Poly a(2, new double[2]{ 1,2 });
		Poly b(2, new double[2]{ 1,2 });
		Poly check(2, new double[2]{ 2,4 });
		a += b;
		CHECK(a == check);
	}
	SUBCASE("minus=")
	{
		Poly a(2, new double[2]{ 1,2 });
		Poly b(2, new double[2]{ 2,3 });
		Poly check(2, new double[2]{ 1,1 });
		b -= a;
		CHECK(b == check);
	}
	SUBCASE("multipl=")
	{
		Poly a(2, new double[2]{ 1,2 });
		Poly b(2, new double[2]{ 1,2 });
		Poly check(3, new double[3]{ 1,4,4 });
		a *= b;
		CHECK(a == check);
	}
	SUBCASE("diff=")
	{
		Poly a(3, new double[3]{ 1,4,4 });
		Poly b(2, new double[2]{ 1,2 });
		Poly check(2, new double[2]{ 1,2 });
		a /= b;
		CHECK(a == check);
	}
}
TEST_CASE("METHODS")
{
	SUBCASE("method OPTYMIZE")
	{
		Poly a(5, new double[5]{ 1,2,3,0,0 });
		a.Optimize();
		Poly check(3, new double[3]{ 1,2,3 });
		CHECK(a == check);
	}
	SUBCASE("method GRADEUP")
	{
		Poly a(2, new double[2]{ 1,1});
		a.GradeUp(2);
		Poly check(3, new double[3]{ 1,2,1 });
		CHECK(a == check);
	}
	SUBCASE("method GETRANK")
	{
		Poly a(6, new double[6]{ 1,1,3,5,6,7 });
		int check = a.GetRank();
		CHECK(5 == check);
	}
	SUBCASE("method CHANGERARK")
	{
		Poly a(2, new double[2]{ 1,1 });
		a.ChangeRank(3);
		Poly check(3, new double[3]{ 1,1,0 });
		CHECK(a == check);
	}
}
