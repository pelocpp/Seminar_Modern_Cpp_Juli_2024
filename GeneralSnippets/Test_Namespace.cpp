namespace MyProduct {

	class MyImplementation
	{

	};
}

namespace MyProductTestSuite {

	class MyImplementation
	{

	};

}


void test_my_implemenation()
{
	using namespace MyProductTestSuite;
	// using namespace MyProduct;

	MyImplementation impl;

	MyProduct::MyImplementation product;
}