#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <bitset/bitset.hpp>
#include "doctest.h"

TEST_CASE("ctor") {
	BitSet b;
	CHECK_EQ(b.GetSize(), 0);
	b.Resize(16);
	CHECK_EQ(b.Get(2), 0);
	CHECK_EQ(b.Get(9), 0);
	CHECK_EQ(b.GetSize(), 16);
	b.Set(15, 1);
	CHECK_EQ(b.Get(1), false);
	CHECK_EQ(b.Get(8), 0);
	CHECK_EQ(b.Get(12), 0);
	CHECK_EQ(b.Get(15), 1);
	CHECK_THROWS(b.Get(33));

	BitSet d = b;
	CHECK_EQ(d.Get(15), 1);
	BitSet c(b);
	CHECK_EQ(c.GetSize(), 16);
	CHECK_EQ(c.Get(15), 1); 

	BitSet f;
	CHECK_EQ(f.GetSize(), 0);
	f.Resize(1);
	CHECK_EQ(f.GetSize(), 1);
	f.Set(1, 1);
	CHECK_EQ(f.Get(1), 1);
	BitSet g;
	CHECK_THROWS(g.Set(1, 1));
	CHECK_THROWS(g.Get(1));
	CHECK_THROWS(g = f);
	BitSet ff{ f };
	CHECK_EQ(ff.GetSize(), 1);
	CHECK_EQ(ff.Get(1), 1);
	ff.Resize(32);
	ff.Set(32, 0);
	CHECK_EQ(ff.Get(32), 0);
	ff.Set(32, 1);
	CHECK_EQ(ff.Get(32), 1);
	ff.Set(32, 0);
	CHECK_EQ(ff.Get(32), 0);
}

TEST_CASE("set, get, fill") {
	BitSet b;
	b.Resize(64);
	b.Fill(1);
	CHECK_EQ(b.Get(1), 1);
	CHECK_EQ(b.Get(64), 1);
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
	~b;
	BitSet bb = b;
	CHECK_EQ(bb.Get(15), 1);
	CHECK_EQ(bb.Get(16), 0);
	CHECK_EQ(bb.Get(17), 1);

	BitSet q;
	q.Resize(20);
	q.Set(20, 1);
	~q;
	BitSet qq = q;
	CHECK_EQ(qq.Get(20), 0);
	CHECK_EQ(qq.Get(19), 1);
	CHECK_THROWS(qq.Get(21));

	qq.Resize(21);
	CHECK_EQ(qq.Get(19), 1);
	CHECK_EQ(qq.Get(20), 0);
	CHECK_EQ(qq.Get(21), 0);
}

TEST_CASE("& operator") {
	BitSet b;
	b.Resize(20);
	b.Set(18, 1);
	b.Set(19, 1);
	b.Set(20, 1);

	BitSet c;
	c.Resize(20);
	c.Set(16, 1);
	c.Set(17, 1);
	c.Set(18, 1);

	BitSet r = b & c;
	CHECK_EQ(r.Get(17), 0);
	CHECK_EQ(r.Get(18), 1);
	CHECK_EQ(r.Get(19), 0);
}