

void test_Lambda()
{
	[] () {};

	auto nothing = []() {};

	nothing();

	[] () {} ();

	constexpr auto quasiNothing = []() { return 123; } ();
}