#include <vector>
#include <memory>
#include <stdexcept>
#include "bitset.hpp"


BitSet::BitSet(const BitSet& other) {
	Resize(other.size_);
	data_ = other.data_;
	size_ = other.size_;
}

BitSet::BitSet(BitSet&& other) noexcept {
	std::swap(data_, other.data_);
	std::swap(size_, other.size_);
} 

BitSet& BitSet::operator=(const BitSet& other) {
	if (size_ != other.size_) {
		throw std::logic_error("unequal size");
	}
	else{
		if (other.size_ == 0) {
			data_.clear();
			size_ = 0;
		}
		else{
			data_.clear();
			data_ = other.data_;
			size_ = other.size_;
		}
		return *this;
	}
}

BitSet& BitSet::operator=(BitSet&& other) noexcept{
	std::swap(data_, other.data_);
	std::swap(size_, other.size_);
	return *this;
}

uint32_t gpos(int32_t ind) {
	uint32_t pos = 1;
	pos = pos << (31 - ind);
	return pos;
}

uint32_t spos(int32_t ind, bool bit) {
	uint32_t diff = 1;
	diff = diff << (31 - ind);

	if (bit == false) {
		uint32_t pos = 1;
		uint32_t d = 1;
		for (int i = 0; i < 31; ++i) {
			d = d << 1;
			pos += d;
		}
		pos = pos - diff;
		return pos;
	}

	else {
		uint32_t pos = 0;
		pos = pos | diff;
		return pos;
	}
}

int32_t BitSet::GetSize() const noexcept {
	return size_;
}

void BitSet::Resize(const int32_t size) {
	if (size < 0) {
		throw std::invalid_argument("negative size");
	}

	if (size % 32 == 0) {
		data_.resize(size / 32);
	}
	else {
		data_.resize(size / 32 + 1);
	}
	size_ = size;
}

bool BitSet::Get(const int32_t index) {
	if (index <= 0) {
		throw std::invalid_argument("negative index");
	}
	else if (index > size_) {
		throw std::invalid_argument("invalid index");
	}
	else {
		int32_t move = 0;

		if (index % 32 == 0) {
			move = index / 32 - 1;
		}
		else {
			move = index / 32;
		}

		uint32_t ind = index % 32;
		uint32_t pos = gpos(ind);
		uint32_t ans = (data_.at(move) & pos);
		return (bool(ans));
	}
}

void BitSet::Set(const int32_t index, const bool bit) {
	if (index <= 0) {
		throw std::invalid_argument("negative index");
	}
	else if (index > size_) {
		throw std::invalid_argument("invalid index");
	}
	else {
		int32_t move = 0;

		if (index % 32 == 0) {
			move = index / 32 - 1;
		}
		else {
			move = index / 32;
		}
		uint32_t ind = index % 32;
		uint32_t pos = spos(ind, bit);

		if (bit == false) {
			data_.at(move) = (data_.at(move) & pos);
		}
		else {
			data_.at(move) = (data_.at(move) | pos);
		}
	}
} 

uint32_t FillPos(const bool bit) {
	uint32_t pos = 1;
	uint32_t d = 1;
	if (bit == true) {
		for (int i = 0; i < 31; ++i) {
			d = d << 1;
			pos += d;
		}
	}
	else {
		pos = 0;
	}
	return pos;
}

uint32_t CutPos(uint32_t ost) {
	uint32_t pos = 1;

	if (ost != 0) {

		pos = pos << 31;
		uint32_t diff = 1;
		diff = diff << 31;

		for (int i = 1; i < ost; ++i) {
			diff = diff >> 1;
			pos += diff;
		}
	}
	return pos;
}

void BitSet::Fill(const bool bit) {
	for (int i = 0; i < data_.size(); ++i) {
		if (bit == false) {
			data_.at(i) = data_.at(i) & FillPos(bit);
		}
		else {
			data_.at(i) = data_.at(i) | FillPos(bit);
		}
	}
}


void BitSet::operator~() {

	for (int i = 0; i < data_.size(); ++i) {
		data_.at(i) = ~(data_.at(i));
	}

	uint32_t ost = size_ % 32;
	if (ost != 0) {
		data_.at(data_.size() - 1) = data_.at(data_.size() - 1) & CutPos(ost);
	}
}

void BitSet::operator&= (const BitSet& other) {
	if (size_ != other.size_) {
		throw std::logic_error("unequal size");
	}
	else {
		for (int i = 0; i < data_.size(); ++i) {
			data_.at(i) &= other.data_.at(i);
		}
	}
}

void BitSet::operator|= (const BitSet& other) {
	if (size_ != other.size_) {
		throw std::logic_error("unequal size");
	}
	else {
		for (int i = 0; i < data_.size(); ++i) {
			data_.at(i) |= other.data_.at(i);
		}
	}
}

void BitSet::operator^= (const BitSet& other) {
	if (size_ != other.size_) {
		throw std::logic_error("unequal size");
	}
	else {
		for (int i = 0; i < data_.size(); ++i) {
			data_.at(i) ^= other.data_.at(i);
		}
	}
}

BitSet operator & (const BitSet& set1, const BitSet& set2) {
	BitSet res(set1);
	res &= set2;
	return res;
}

BitSet operator | (const BitSet& set1, const BitSet& set2) {
	BitSet res(set1);
	res |= set2;
	return res;
}

BitSet operator ^ (const BitSet& set1, const BitSet& set2) {
	BitSet res(set1);
	res |= set2;
	return res;
}

