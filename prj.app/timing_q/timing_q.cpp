#include <chrono>
#include <queuearrt/queuearrt.hpp>
#include <queuelstt/queuelstt.hpp>
#include <complex/complex.hpp>
#include <string>

Complex z1 = Complex(1, 2);

int main() {


	// _______________ctor____________________

	auto arr_start_ctor_s{ std::chrono::steady_clock::now() };
	QueueArrT<std::string> arr_s;
	auto arr_end_ctor_s{ std::chrono::steady_clock::now() };


	auto lst_start_ctor_s{ std::chrono::steady_clock::now() };
	QueueLstT<std::string> lst_s;
	auto lst_end_ctor_s{ std::chrono::steady_clock::now() };


	std::chrono::nanoseconds arr_result_ctor_s{ arr_end_ctor_s - arr_start_ctor_s };
	std::chrono::nanoseconds lst_result_ctor_s{ lst_end_ctor_s - lst_start_ctor_s };


	std::cout << "arr ctor (string): " << arr_result_ctor_s.count() << '\n';
	std::cout << "lst ctor (string): " << lst_result_ctor_s.count() << "\n\n";



	auto arr_start_ctor_c{ std::chrono::steady_clock::now() };
	QueueArrT<Complex> arr_c;
	auto arr_end_ctor_c{ std::chrono::steady_clock::now() };


	auto lst_start_ctor_c{ std::chrono::steady_clock::now() };
	QueueLstT<Complex> lst_c;
	auto lst_end_ctor_c{ std::chrono::steady_clock::now() };


	std::chrono::nanoseconds arr_result_ctor_c{ arr_end_ctor_c - arr_start_ctor_c };
	std::chrono::nanoseconds lst_result_ctor_c{ lst_end_ctor_c - lst_start_ctor_c };


	std::cout << "arr ctor (complex): " << arr_result_ctor_c.count() << '\n';
	std::cout << "lst ctor (complex): " << lst_result_ctor_c.count() << "\n\n";



	// _________________push_______________________


	QueueArrT<Complex> arr_5_c;
	QueueLstT<Complex> lst_5_c;

	auto arr_start_5_c{ std::chrono::steady_clock::now() };
	for (int i = 0; i < 5; ++i) {
		arr_5_c.Push(z1);
	}
	auto arr_end_5_c{ std::chrono::steady_clock::now() };


	auto lst_start_5_c{ std::chrono::steady_clock::now() };
	for (int i = 0; i < 5; ++i) {
		lst_5_c.Push(z1);
	}
	auto lst_end_5_c{ std::chrono::steady_clock::now() };


	std::chrono::nanoseconds arr_result_5_c(arr_end_5_c - arr_start_5_c);
	std::chrono::nanoseconds lst_result_5_c(lst_end_5_c - lst_start_5_c);


	std::cout << "arr push (complex x5): " << arr_result_5_c.count() << '\n';
	std::cout << "lst push (complex x5): " << lst_result_5_c.count() << "\n\n";



	QueueArrT<Complex> arr_10_c;
	QueueLstT<Complex> lst_10_c;

	auto arr_start_10_c{ std::chrono::steady_clock::now() };
	for (int i = 0; i < 10; ++i) {
		arr_10_c.Push(z1);
	}
	auto arr_end_10_c{ std::chrono::steady_clock::now() };


	auto lst_start_10_c{ std::chrono::steady_clock::now() };
	for (int i = 0; i < 10; ++i) {
		lst_10_c.Push(z1);
	}
	auto lst_end_10_c{ std::chrono::steady_clock::now() };


	std::chrono::nanoseconds arr_result_10_c(arr_end_10_c - arr_start_10_c);
	std::chrono::nanoseconds lst_result_10_c(lst_end_10_c - lst_start_10_c);


	std::cout << "arr push (complex x10): " << arr_result_10_c.count() << '\n';
	std::cout << "lst push (complex x10): " << lst_result_10_c.count() << "\n\n";



	QueueArrT<Complex> arr_25_c;
	QueueLstT<Complex> lst_25_c;

	auto arr_start_25_c{ std::chrono::steady_clock::now() };
	for (int i = 0; i < 25; ++i) {
		arr_25_c.Push(z1);
	}
	auto arr_end_25_c{ std::chrono::steady_clock::now() };


	auto lst_start_25_c{ std::chrono::steady_clock::now() };
	for (int i = 0; i < 25; ++i) {
		lst_25_c.Push(z1);
	}
	auto lst_end_25_c{ std::chrono::steady_clock::now() };


	std::chrono::nanoseconds arr_result_25_c(arr_end_25_c - arr_start_25_c);
	std::chrono::nanoseconds lst_result_25_c(lst_end_25_c - lst_start_25_c);


	std::cout << "arr push (complex x25): " << arr_result_25_c.count() << '\n';
	std::cout << "lst push (complex x25): " << lst_result_25_c.count() << "\n\n";



	QueueArrT<Complex> arr_50_c;
	QueueLstT<Complex> lst_50_c;


	auto arr_start_50_c{ std::chrono::steady_clock::now() };
	for (int i = 0; i < 50; ++i) {
		arr_50_c.Push(z1);
	}
	auto arr_end_50_c{ std::chrono::steady_clock::now() };


	auto lst_start_50_c{ std::chrono::steady_clock::now() };
	for (int i = 0; i < 50; ++i) {
		lst_50_c.Push(z1);
	}
	auto lst_end_50_c{ std::chrono::steady_clock::now() };


	std::chrono::nanoseconds arr_result_50_c(arr_end_50_c - arr_start_50_c);
	std::chrono::nanoseconds lst_result_50_c(lst_end_50_c - lst_start_50_c);


	std::cout << "arr push (complex x50): " << arr_result_50_c.count() << '\n';
	std::cout << "lst push (complex x50): " << lst_result_50_c.count() << "\n\n";



	QueueArrT<Complex> arr_100_c;
	QueueLstT<Complex> lst_100_c;


	auto arr_start_100_c{ std::chrono::steady_clock::now() };
	for (int i = 0; i < 100; ++i) {
		arr_100_c.Push(z1);
	}
	auto arr_end_100_c{ std::chrono::steady_clock::now() };


	auto lst_start_100_c{ std::chrono::steady_clock::now() };
	for (int i = 0; i < 100; ++i) {
		lst_100_c.Push(z1);
	}
	auto lst_end_100_c{ std::chrono::steady_clock::now() };


	std::chrono::nanoseconds arr_result_100_c(arr_end_100_c - arr_start_100_c);
	std::chrono::nanoseconds lst_result_100_c(lst_end_100_c - lst_start_100_c);


	std::cout << "arr push (complex x100): " << arr_result_100_c.count() << '\n';
	std::cout << "lst push (complex x100): " << lst_result_100_c.count() << "\n\n";



	QueueArrT<int> arr_25_i;
	QueueLstT<int> lst_25_i;


	auto arr_start_25_i{ std::chrono::steady_clock::now() };
	for (int i = 0; i < 25; ++i) {
		arr_25_i.Push(i);
	}
	auto arr_end_25_i{ std::chrono::steady_clock::now() };


	auto lst_start_25_i{ std::chrono::steady_clock::now() };
	for (int i = 0; i < 25; ++i) {
		lst_25_i.Push(i);
	}
	auto lst_end_25_i{ std::chrono::steady_clock::now() };


	std::chrono::nanoseconds arr_result_25_i(arr_end_25_i - arr_start_25_i);
	std::chrono::nanoseconds lst_result_25_i(lst_end_25_i - lst_start_25_i);


	std::cout << "arr push (int x25): " << arr_result_25_i.count() << '\n';
	std::cout << "lst push (int x25): " << lst_result_25_i.count() << "\n\n";



	QueueArrT<int> arr_50_i;
	QueueLstT<int> lst_50_i;


	auto arr_start_50_i{ std::chrono::steady_clock::now() };
	for (int i = 0; i < 50; ++i) {
		arr_50_i.Push(i);
	}
	auto arr_end_50_i{ std::chrono::steady_clock::now() };


	auto lst_start_50_i{ std::chrono::steady_clock::now() };
	for (int i = 0; i < 50; ++i) {
		lst_50_i.Push(i);
	}
	auto lst_end_50_i{ std::chrono::steady_clock::now() };


	std::chrono::nanoseconds arr_result_50_i(arr_end_50_i - arr_start_50_i);
	std::chrono::nanoseconds lst_result_50_i(lst_end_50_i - lst_start_50_i);


	std::cout << "arr push (int x50): " << arr_result_50_i.count() << '\n';
	std::cout << "lst push (int x50): " << lst_result_50_i.count() << "\n\n";



	QueueArrT<int> arr_100_i;
	QueueLstT<int> lst_100_i;


	auto arr_start_100_i{ std::chrono::steady_clock::now() };
	for (int i = 0; i < 100; ++i) {
		arr_100_i.Push(i);
	}
	auto arr_end_100_i{ std::chrono::steady_clock::now() };


	auto lst_start_100_i{ std::chrono::steady_clock::now() };
	for (int i = 0; i < 100; ++i) {
		lst_100_i.Push(i);
	}
	auto lst_end_100_i{ std::chrono::steady_clock::now() };


	std::chrono::nanoseconds arr_result_100_i(arr_end_100_i - arr_start_100_i);
	std::chrono::nanoseconds lst_result_100_i(lst_end_100_i - lst_start_100_i);


	std::cout << "arr push (int x100): " << arr_result_100_i.count() << '\n';
	std::cout << "lst push (int x100): " << lst_result_100_i.count() << "\n\n";
}
