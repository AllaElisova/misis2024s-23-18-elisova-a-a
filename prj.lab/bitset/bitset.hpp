#pragma once

#include <cstdint>
#include <vector>
#include <ostream>
#include <istream>
#include <string>


class BitSet {
	// битовые операции только для последовательностей одинакового размера
	// нужно делать ресайз пользователю
	// подумать над квадратными скобками на чтение и запись
	// подумать какие могут быть форматы ввода вывода в текстовом и бинарном формате
public:

	BitSet() = default;
	BitSet(const BitSet& other);
	BitSet(BitSet&& other) noexcept;
	BitSet(const int32_t size);

	BitSet& operator= (const BitSet& other);
	BitSet& operator=(BitSet&& other) noexcept;

	int32_t Size() const noexcept;
	void Resize(const int32_t size);
	bool Get(const int32_t index);  //получить нужный бит значит сделать побитовое и с индексом
	void Set(const int32_t index, const bool bit);  // побитовое или с индексом

	bool operator==(const BitSet& other) const noexcept;
	bool operator!=(const BitSet& other) const noexcept;

	void operator~ ();
	void operator&= (const BitSet& other);
	void operator|= (const BitSet& other);
	void operator^= (const BitSet& other);

	void Fill(const bool bit);

	std::istream& Read(std::istream& istrm);
	std::ostream& Write(std::ostream& ostrm);

	~BitSet() = default;

	std::ostream& FormatOutput(std::ostream& ostrm);
	uint8_t CheckSum();

private:
	int32_t size_ = 0;
	std::vector <uint32_t> data_;

	class BiA {
	public:
		BiA(BitSet& bs, const int32_t index);
		BiA& operator= (const bool value);
		operator bool();
		~BiA() = default;

	private:
		BitSet& bs_;
		int32_t id_;
	};

public:
	BiA operator[] (const int32_t index);

};


BitSet operator& (const BitSet& set1, const BitSet& set2);
BitSet operator| (const BitSet& set1, const BitSet& set2);
BitSet operator^ (const BitSet& set1, const BitSet& set2);

std::ostream& operator <<(std::ostream& ostrm, BitSet& bitset);
std::istream& operator >>(std::istream& istrm, BitSet& bitset);