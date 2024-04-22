#include <chrono>
#include <queuearrt/queuearrt.hpp>
#include <queuelstt/queuelstt.hpp>
#include <complex/complex.hpp>

int main() {
	Complex z1 = Complex(1, 2);
	Complex z2 = Complex(2, 3);
	Complex z3 = Complex(3, 4);
	Complex z4 = Complex(4, 5);

	QueueArrT<Complex> qa1;
	auto start_1{ std::chrono::steady_clock::now() };
	for (int i = 0; i < 25; ++i) {
		qa1.Push(z1);
		qa1.Push(z2);
		qa1.Push(z3);
		qa1.Push(z4);
	}
	auto end_1{ std::chrono::steady_clock::now() };


	QueueLstT<Complex> ql1;
	auto start_2{ std::chrono::steady_clock::now() };
	for (int i = 0; i < 25; ++i) {
		ql1.Push(z1);
		ql1.Push(z2);
		ql1.Push(z3);
		ql1.Push(z4);
	}
	auto end_2{ std::chrono::steady_clock::now() };


	std::chrono::nanoseconds arr_result_1(end_1 - start_1);
	std::chrono::nanoseconds lst_result_1(end_2 - start_2);

	std::cout << "arr push complex 25 " << arr_result_1.count() << '\n';
	std::cout << "lst push complex 25 " << lst_result_1.count() << '\n' << '\n';


	QueueArrT<Complex> qa2;
	auto start_3{ std::chrono::steady_clock::now() };
	qa2.Push(z1);
	qa2.Push(z2);
	qa2.Push(z3);
	qa2.Push(z4);
	auto end_3{ std::chrono::steady_clock::now() };

	QueueLstT<Complex> ql2;
	auto start_4{ std::chrono::steady_clock::now() };
	ql2.Push(z1);
	ql2.Push(z2);
	ql2.Push(z3);
	ql2.Push(z4);
	auto end_4{ std::chrono::steady_clock::now() };

	std::chrono::nanoseconds arr_result_2(end_3 - start_3);
	std::chrono::nanoseconds lst_result_2(end_4 - start_4);

	std::cout << "arr push complex 4 " << arr_result_2.count() << '\n';
	std::cout << "lst push complex 4 " << lst_result_2.count() << '\n' << '\n';

	QueueArrT<int> qa_int;
	auto start_5{ std::chrono::steady_clock::now() };
	for (int i = 0; i < 100; ++i) {
		qa_int.Push(i);
	}
	auto end_5{ std::chrono::steady_clock::now() };


	QueueLstT<int> ql_int;
	auto start_6{ std::chrono::steady_clock::now() };
	for (int i = 0; i < 100; ++i) {
		ql_int.Push(i);
	}
	auto end_6{ std::chrono::steady_clock::now() };

	std::chrono::nanoseconds arr_result_3(end_5 - start_5);
	std::chrono::nanoseconds lst_result_3(end_6 - start_6);

	std::cout << "arr push int 100 " << arr_result_3.count() << '\n';
	std::cout << "lst push int 100 " << lst_result_3.count() << '\n';
}
