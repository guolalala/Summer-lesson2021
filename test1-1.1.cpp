// test2-arma.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <armadillo>



int main()

{
	using namespace std;
	using namespace arma;

	//arma::mat A = arma::randu<arma::mat>(4, 5) * 10;
	//arma::mat B = arma::randu<arma::mat>(4, 5) * 10;
	//arma::mat C = A % B;
	mat A = randu<mat>(4, 5) * 10;
	mat B = randu<mat>(5, 5) * 10;
	mat C = A * B;
	A.print("A = \n");
	B.print("B = \n");
	C.print("A .* B = \n");


	A << 0.165300 << 0.454037 << 0.995795 << 0.124098 << 0.047084 << endr
		<< 0.688782 << 0.036549 << 0.552848 << 0.937664 << 0.866401 << endr
		<< 0.348740 << 0.479388 << 0.506228 << 0.145673 << 0.491547 << endr
		<< 0.148678 << 0.682258 << 0.571154 << 0.874724 << 0.444632 << endr
		<< 0.245726 << 0.595218 << 0.409327 << 0.367827 << 0.385736 << endr;
	A.print("A:");
	C = A.t();
	C.print("C:");
	mat D1 = max(A);
	D1.print("max(A):");
	mat D2 = max(A, 1);
	D2.print("max(A, 1):");
	double temp = max(max(A));
	cout << "max(max(A)):" << temp << endl;
	temp = accu(A);
	cout << "accu(A):" << temp << endl;
	mat E = eye(4, 4);
	E.print("E:");
	temp = A.max();
	cout << "A.max():" << temp << endl;
	mat F;
	F.ones(2, 5);
	F.print("F:");


	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
