#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include <bitset/bitset.hpp>
#include "doctest.h"
/*
TEST_CASE("ctor") {
	BitSet b;
	CHECK_EQ(b.Size(), 0);
	b.Resize(16);
	CHECK_EQ(b.Get(2), 0);
	CHECK_EQ(b.Get(9), 0);
	CHECK_EQ(b.Size(), 16);
	b.Set(15, 1);
	CHECK_EQ(b.Get(1), false);
	CHECK_EQ(b.Get(8), 0);
	CHECK_EQ(b.Get(12), 0);
	CHECK_EQ(b.Get(15), 1);
	CHECK_THROWS(b.Get(33));

	BitSet d = b;
	CHECK_EQ(d.Get(15), 1);
	BitSet c(b);
	CHECK_EQ(c.Size(), 16);
	CHECK_EQ(c.Get(15), 1);

	BitSet f;
	CHECK_EQ(f.Size(), 0);
	f.Resize(1);
	CHECK_EQ(f.Size(), 1);
	f.Set(0, 1);
	CHECK_EQ(f.Get(0), 1);
	BitSet g;
	CHECK_THROWS(g.Set(1, 1));
	CHECK_THROWS(g.Get(1));
	CHECK_THROWS(g = f);
	BitSet ff{ f };
	CHECK_EQ(ff.Size(), 1);
	CHECK_EQ(ff.Get(0), 1);
	ff.Resize(32);
	ff.Set(31, 0);
	CHECK_EQ(ff.Get(31), 0);
	ff.Set(31, 1);
	CHECK_EQ(ff.Get(31), 1);
	ff.Set(31, 0);
	CHECK_EQ(ff.Get(31), 0);
}

TEST_CASE("set, get, fill") {
	BitSet b;
	b.Resize(64);
	b.Fill(1);
	CHECK_EQ(b.Get(0), 1);
	CHECK_EQ(b.Get(63), 1);
	b.Set(35, 0);
	b.Set(37, 0);
	CHECK_EQ(b.Get(35), 0);
	CHECK_EQ(b.Get(36), 1);
	CHECK_EQ(b.Get(37), 0);
}

TEST_CASE("operator ~") {
	BitSet b;
	b.Resize(32);
	b.Set(16, 1);
	b.Set(17, 1);
	~b;
	BitSet bb = b;
	CHECK_EQ(b.Get(15), 1);
	CHECK_EQ(bb.Get(15), 1);
	CHECK_EQ(bb.Get(16), 0);
	CHECK_EQ(bb.Get(17), 0);

	BitSet q;
	q.Resize(20);
	q.Set(19, 1);
	~q;
	BitSet qq = q;
	CHECK_EQ(qq.Get(18), 1);
	CHECK_EQ(qq.Get(19), 0);
	CHECK_THROWS(qq.Get(20));

	qq.Resize(21);
	CHECK_EQ(qq.Get(18), 1);
	CHECK_EQ(qq.Get(19), 0);
	CHECK_EQ(qq.Get(20), 0);
}


TEST_CASE("fill") {
	BitSet b;
	b.Resize(20);
	b.Fill(1);
	b.Resize(21);
	CHECK_EQ(b.Get(0), 1);
	CHECK_EQ(b.Get(19), 1);
	CHECK_EQ(b.Get(20), 0);
	b.Resize(63);
	b.Fill(1);
	b.Resize(64);
	CHECK_EQ(b.Get(62), 1);
	CHECK_EQ(b.Get(63), 0);
}

TEST_CASE("& operator") {
	BitSet b;
	b.Resize(21);
	b.Set(18, 1);
	b.Set(19, 1);
	b.Set(20, 1);

	BitSet c;
	c.Resize(21);
	c.Set(16, 1);
	c.Set(17, 1);
	c.Set(18, 1);

	BitSet r = b & c;
	CHECK_EQ(r.Get(17), 0);
	CHECK_EQ(r.Get(18), 1);
	CHECK_EQ(r.Get(19), 0);
}

TEST_CASE("| operator") {
	BitSet b;
	b.Resize(21);
	b.Set(18, 1);
	b.Set(19, 1);
	b.Set(20, 1);

	BitSet c;
	c.Resize(21);

	BitSet r = b | c;
	CHECK_EQ(r.Get(18), 1);
	CHECK_EQ(r.Get(19), 1);
	CHECK_EQ(r.Get(20), 1);
}

TEST_CASE("^ operator") {
	BitSet b;
	b.Resize(21);
	b.Set(18, 1);
	b.Set(19, 1);
	b.Set(20, 1);

	BitSet c;
	c.Resize(21);
	c.Set(16, 1);
	c.Set(17, 1);
	c.Set(18, 1);

	BitSet r = b ^ c;
	CHECK_EQ(r.Get(17), 1);
	CHECK_EQ(r.Get(18), 0);
	CHECK_EQ(r.Get(19), 1);
}

TEST_CASE("BiA") {
	BitSet b;
	b.Resize(32);
	b[20] = true;
	CHECK_EQ(b.Get(20), 1);
	b[20] = false;
	CHECK_EQ(b.Get(20), 0);
	b[31] = true;
	CHECK_EQ(b.Get(31), 1);
} */

TEST_CASE("BiA[] = BiA[]") {
	BitSet b1;
	BitSet b2;
	b1.Resize(32);
	b2.Resize(32);
	
	for (int i = 0; i < 32; ++i) {
		b2.Set(i, 1);
		CHECK(b1 != b2);
		b1[i] = b2[i];
		CHECK(b1 == b2);
	}
}
/*

int main() {
	std::cout << "_____unformatted ouput_____" << "\n\n";
	BitSet test1;
	test1.Resize(32);
	test1.Set(16, 1);
	test1.Write(std::cout);

	std::cout << "\n";

	BitSet test2;
	test2.Resize(9);
	test2.Set(2, 1);
	test2.Set(8, 1);
	test2.Write(std::cout);

	std::cout << "\n";

	BitSet test3;
	test3.Resize(65);
	for (int i = 0; i < 65; ++i) {
		if (i % 3 == 0) {
			test3.Set(i, 1);
		}
	}
	test3.Write(std::cout);

	std::cout << "\n\n" << "_____formatted output_____" << "\n\n";

	std::cout << test2 << "\n" << "______________________________" << "\n\n" << test3 << "\n" << "______________________________" << "\n\n";

	BitSet test4;
	test4.Resize(1400);

	for (int i = 0; i < 1400; ++i){
		if (i % 20 == 0) {
			test4.Set(i, 1);
		}
	}
	std::cout << test4 << "\n\n";

	std::cout << "_____formatted input_____" << "\n\n";

	BitSet r;
	std::cin >> r;
	std::cout << r;
} */