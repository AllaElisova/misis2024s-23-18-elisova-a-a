#include <vector>
#include <memory>
#include <stdexcept>
#include "bitset.hpp"


BitSet::BitSet(const BitSet& other) {
	Resize(other.size_);

	for (int i = 0; i < data_.size(); ++i) {
		data_[i] = other.data_[i];
	}
}

BitSet::BitSet(BitSet&& other) noexcept {
	std::swap(data_, other.data_);
	std::swap(size_, other.size_);
} 

BitSet::BitSet(const int32_t size) {
	Resize(size);
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
		for (int i = 0; i <= 31; ++i) {
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

int32_t BitSet::Size() const noexcept {
	return size_;
}

void BitSet::Resize(const int32_t size) {
	if (size <= 0) {
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
	if (index < 0) {
		throw std::invalid_argument("negative index");
	}
	else if (index >= size_) {
		throw std::invalid_argument("invalid index");
	}
	else {
		int32_t move = 0;
		move = index / 32;

		uint32_t ind = index % 32;
		uint32_t pos = gpos(ind);
		uint32_t ans = (data_.at(move) & pos);
		return (bool(ans));
	}
}

void BitSet::Set(const int32_t index, const bool bit) {
	if (index < 0) {
		throw std::invalid_argument("negative index");
	}
	else if (index >= size_) {
		throw std::invalid_argument("invalid index");
	}
	else {
		int32_t move = 0;

		
		move = index / 32;

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

uint32_t FillBit(const bool bit) {
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
	uint32_t pos = 0;
	uint32_t diff = 1;
	diff = diff << 31;

	for (int i = 0; i <= ost; ++i) {
		pos += diff;
		diff = diff >> 1;
	}
	
	return pos;
}

void BitSet::Fill(const bool bit) {
	for (int i = 0; i < data_.size(); ++i) {
		if (bit == false) {
			data_.at(i) = data_.at(i) & FillBit(bit);
		}
		else {
			data_.at(i) = data_.at(i) | FillBit(bit);

			uint32_t ost = (size_ - 1) % 32;
			if (ost != 31) {
				data_.at(data_.size() - 1) = data_.at(data_.size() - 1) & CutPos(ost);
			}
		}
	}
}


std::istream& BitSet::Read(std::istream& istrm) {
	std::string marker1 = "";
	std::string marker2 = "";
	int32_t size (0);
	uint8_t checksum (0);
	std::string data = "";
	istrm >> marker1 >> size;
	
	BitSet temp_bitset;
	temp_bitset.Resize(size);

	for (int i = 0; i <= temp_bitset.data_.size(); ++i) {
		int32_t elem = 0;
		istrm >> elem;
		temp_bitset.data_.at(i) = elem;
	}
	 
	istrm >> checksum >> marker2;

	if (istrm.good()) {

		int count = 0;
		for (int i = 0; i < size; ++i) {
			if (temp_bitset[i] == true){
				++count;
			}
		}

		if ((marker1 == "FEFF") && (size >= 0) && (checksum == count) && (marker2 == "FEFF")) {
			size_ = size;
			*this = temp_bitset;
		}
		else {
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
} 

uint8_t BitSet::CheckSum(){
	uint8_t result = 0;

	for (int i = 0; i < size_; ++i) {
		if ((*this).Get(i) == true) {
			result = (result + 1) % 256;
		}
	}

	return result;
}

std::ostream& BitSet::Write(std::ostream& ostrm) {
	ostrm << 'F' << 'E' << 'F' << 'F' << size_;

	for (int i = 0; i < data_.size(); ++i) {
		ostrm << unsigned((data_.at(i)));
	}

	ostrm << unsigned(CheckSum()) << 'F' << 'E' << 'F' << 'F';
	return ostrm;
}


bool BitSet::operator==(const BitSet& other) const noexcept {
	if ((data_ == other.data_) && (size_== other.size_)){
		return true;
  }
	else {
		return false;
	}
}

bool BitSet::operator!=(const BitSet& other) const noexcept {
	if ((data_ == other.data_) && (size_ == other.size_)) {
		return false;
	}
	else {
		return true;
	}
}

void BitSet::operator~() {

	for (int i = 0; i < data_.size(); ++i) {
		data_.at(i) = ~(data_.at(i));
	}

	uint32_t ost = (size_ - 1) % 32;
	if (ost != 31) {
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
	res ^= set2;
	return res;
}

BitSet::BiA::BiA(BitSet& bs, const int32_t index)
	:bs_(bs), id_(index) {}

BitSet::BiA& BitSet::BiA::operator=(const bool value) {
	bs_.Set(id_, value);
	return *this;
}

BitSet::BiA::operator bool() {
	if (bs_.Get(id_) == 1) {
		return true;
	}
	else {
		return false;
	}
}

BitSet::BiA BitSet::operator[] (const int32_t index) {
	BiA temp = BiA(*this, index);
	return temp;
}


std::ostream& BitSet::FormatOutput(std::ostream& ostrm) {
		
	for (int i = 1; i <= size_; ++i) {

		if ((*this).Get(i-1) == false) {
			ostrm << '0';
		}

		else {
			ostrm << '1';
		}

		if (i % 20 == 0) {
			ostrm << " " << unsigned((i - 1) / 20) << "\n";
		}

		else if (i == size_) {
			ostrm << " " << unsigned((i - 1) / 20) << "\n";
		}
	}
	return ostrm;
} 

std::ostream& operator << (std::ostream& ostrm, BitSet& bitset) {
	return (bitset.FormatOutput(ostrm));
}


std::istream& operator >>(std::istream& istrm, BitSet& bitset) {
	return bitset.Read(istrm);
	//uint8_t count = (std::count(data.begin(), data.end(), '1')) % 256;
} 