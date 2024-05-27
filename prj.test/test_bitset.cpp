#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include <bitset/bitset.hpp>
#include "doctest.h"

TEST_CASE("ctor") {
	BitSet b;
	CHECK_EQ(b.Size(), 0);

	b.Resize(16);
	CHECK_EQ(b.Size(), 16);

	for (int i = 0; i < 16; ++i) {
		CHECK_EQ(b.Get(i), false);
	}
	b.Set(15, 1);
	CHECK_EQ(b.Get(15), 1);

	BitSet d = b;
	CHECK_EQ(d.Size(), 16);
	CHECK_EQ(d.Get(15), 1);
	BitSet c(b);
	CHECK_EQ(c.Size(), 16);
	CHECK_EQ(c.Get(15), 1);

	BitSet f;
	CHECK_EQ(f.Size(), 0);
	
	BitSet g;
	CHECK_THROWS(g.Set(1, 1));
	CHECK_THROWS(g.Get(1));
	g = f;
	
	f.Resize(1);
	f.Set(0, 1);

	BitSet ff{ f };
	CHECK_EQ(ff.Size(), 1);
	CHECK_EQ(ff.Get(0), 1);
	ff.Resize(32);
	
	for (int i = 1; i < 32; ++i) {
		CHECK_EQ(ff.Get(i), 0);
		ff.Set(i, 1);
		CHECK_EQ(ff.Get(i), 1);
	} 

	BitSet v;
	BitSet vv(v);
	CHECK(vv.Size() == 0);
}

TEST_CASE("set, get, fill") {
	BitSet b;
	b.Resize(64);
	b.Fill(1);
	for (int i = 0; i < 64; ++i) {
		CHECK_EQ(b.Get(i), 1);
	}
	b.Set(35, 0);
	b.Set(37, 0);
	CHECK_EQ(b.Get(35), 0);
	CHECK_EQ(b.Get(36), 1);
	CHECK_EQ(b.Get(37), 0);

	CHECK_THROWS(b.Get(-1));
	CHECK_THROWS(b.Get(64));
}

TEST_CASE("operator ~") {
	BitSet b;
	b.Resize(32);
	b.Set(16, 1);
	b.Set(17, 1);
	~b;

	CHECK_EQ(b.Get(15), 1);
	CHECK_EQ(b.Get(16), 0);
	CHECK_EQ(b.Get(17), 0);
	CHECK_EQ(b.Get(18), 1);

	BitSet q;
	q.Resize(20);
	q.Set(19, 1);
	~q;
	CHECK_EQ(q.Get(18), 1);
	CHECK_EQ(q.Get(19), 0);
	CHECK_THROWS(q.Get(20));

	BitSet qq = q;
	qq.Resize(21);
	CHECK_EQ(qq.Get(18), 1);
	CHECK_EQ(qq.Get(19), 0);
	CHECK_EQ(qq.Get(20), 0);
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
	for (int i = 0; i < 32; ++i) {
		b[i] = true;
		CHECK_EQ(b.Get(i), 1);
		b[i] = false;
		CHECK_EQ(b.Get(i), 0);
	}
} 

TEST_CASE("BiA[] =, ==, !=") {
	BitSet b1;
	BitSet b2;
	b1.Resize(32);
	b2.Resize(32);
	
	for (int i = 0; i < 32; ++i) {
		b2.Set(i, 1);
		CHECK(b1 != b2);
		CHECK(b1[i] != b2[i]);
		b1[i] = b2[i];
		CHECK(b1 == b2);
		CHECK(b1[i] == b2[i]);
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


TEST_CASE("operator~") {
  BitSet bs;
  bs.Resize(49);
  bs = ~bs;

  bs.Resize(60);
  for (int i = 0; i < 49; ++i) {
    CHECK(bs.Get(i));
  }
  for (int i = 49; i < 60; ++i) {
    CHECK_FALSE(bs.Get(i));
  }
}

TEST_CASE("equal check") {
	BitSet bs1;
	bs1.Resize(4);
	bs1[0] = false;
	bs1[1] = true;
	bs1[2] = false;
	bs1[3] = true;


	BitSet bs2;
	bs2.Resize(4);
	bs2[0] = false;
	bs2[1] = true;
	bs2[2] = false;
	bs2[3] = true;


	BitSet bs3;
	bs3.Resize(4);
	bs3[0] = false;
	bs3[1] = false;
	bs3[2] = true;
	bs3[3] = true;

  CHECK(bs1 == bs2);
  CHECK_FALSE(bs1 != bs2);
  CHECK(bs1 != bs3);
  CHECK_FALSE(bs1 == bs3);
}

TEST_CASE("operator &=") {
	BitSet bs1;
	bs1.Resize(4);
	bs1[0] = false;
	bs1[1] = true;
	bs1[2] = false;
	bs1[3] = true;


	BitSet bs2;
	bs2.Resize(4);
	bs2[0] = false;
	bs2[1] = false;
	bs2[2] = true;
	bs2[3] = true;

  BitSet bs = bs1 & bs2;
  bs1 &= bs2;
	BitSet answer;

	answer.Resize(4);
	answer[0] = false;
	answer[1] = false;
	answer[2] = false;
	answer[3] = true;

  for (int i = 0; i < 4; ++i) {
    CHECK_EQ(answer.Get(i), bs.Get(i));
    CHECK_EQ(answer.Get(i), bs1.Get(i));
  }
}
 
TEST_CASE("operator |=") {
	BitSet bs1;
	bs1.Resize(4);
	bs1[0] = false;
	bs1[1] = true;
	bs1[2] = false;
	bs1[3] = true;


	BitSet bs2;
	bs2.Resize(4);
	bs2[0] = false;
	bs2[1] = false;
	bs2[2] = true;
	bs2[3] = true;

  BitSet bs = bs1 | bs2;
  bs1 |= bs2;

  BitSet answer;
	answer.Resize(4);
	answer[0] = false;
	answer[1] = true;
	answer[2] = true;
	answer[3] = true;

  for (int i = 0; i < 4; ++i) {
    CHECK_EQ(answer.Get(i), bs.Get(i));
    CHECK_EQ(answer.Get(i), bs1.Get(i));
  }
}

TEST_CASE("operator ^=") {
  BitSet bs1;
	bs1.Resize(4);
	bs1[0] = false;
	bs1[1] = true;
	bs1[2] = false;
	bs1[3] = true;


  BitSet bs2;
	bs2.Resize(4);
	bs2[0] = false;
	bs2[1] = false;
	bs2[2] = true;
	bs2[3] = true;

  BitSet bs = bs1 ^ bs2;
  bs1 ^= bs2;

  BitSet answer;
	answer.Resize(4);
	answer[0] = false;
	answer[1] = true;
	answer[2] = true;
	answer[3] = false;

  for (int i = 0; i < 4; ++i) {
    CHECK_EQ(answer.Get(i), bs.Get(i));
    CHECK_EQ(answer.Get(i), bs1.Get(i));
  }
}


TEST_CASE("operator[]") {
	BitSet bs;
	bs.Resize(4);
	bs[0] = false;
	bs[1] = true;
	bs[2] = false;
	bs[3] = true;

  CHECK_FALSE(bs[0]);
  CHECK(bs[1]);
  CHECK_FALSE(bs[2]);
  CHECK(bs[3]);

  bs[0] = true;
  bs[1] = true;
  bs[2] = false;
  bs[3] = false;

  CHECK(bs[0]);
  CHECK(bs[1]);
  CHECK_FALSE(bs[2]);
  CHECK_FALSE(bs[3]);
}

TEST_CASE("==, !=") {
	BitSet b1(130);
	BitSet b2(130);
	b2.Fill(1);
	BitSet b3(b2);
	CHECK(b2 == b3);
	CHECK(b1 != b3);

	for (int i = 0; i < 130; ++i) {
		CHECK(b1 != b2);
		CHECK(b1.Get(i) != b2.Get(i));
		CHECK(b1[i] != b2[i]);
		b2[i] = false;
	}
	CHECK(b1 == b2);
	CHECK(b3 != b2);

	BitSet v;
	BitSet vv(v);
	CHECK(v == vv);

	BitSet v1(1);
	BitSet v11(11);
	CHECK(v1 != v11);
	CHECK(v1[0] == v11[0]);
}
