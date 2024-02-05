#include "dynarr.hpp"

DynArr::DynArr(const int32_t size) {
	Resize(size);
}

float& DynArr::operator[](const int32_t index) {
	if (index >= size_ || index < 0) {
		throw ForbiddenIndex();
	}
	return *(data_ + index);
}

const float& DynArr::operator[](const int32_t index) const {
	if (index >= size_ || index < 0) {
		throw ForbiddenIndex();
	}
	return *(data_ + index);
}

DynArr::DynArr(const DynArr& other) {
	Resize(other.Size());
	for (int i = 0; i < size_; ++i) {
		(*this)[i] = other[i];
	}
}

DynArr::~DynArr() {
	delete[] data_;
	data_ = nullptr;
}


DynArr& DynArr::operator=(const DynArr& other) {
	Resize(other.Size());
	for (int i = 0; i < size_; ++i) {
		(*this)[i] = other[i];
	}
	return *this;
}

void DynArr::Resize(const int32_t new_size) {
	if (new_size <= 0) {
		throw ForbiddenSize();
	}
	if (new_size < size_) {
		size_ = new_size;
	}
	else if (new_size > size_ && new_size <= capacity_) {
		int32_t prev_size = size_;
		size_ = new_size;
		for (int i = prev_size; i < size_; ++i) {
			(*this)[i] = 0;
		}
	}
	else {
		float* new_data = new float[new_size];
		for (int i = 0; i < size_; ++i) {
			*(new_data + i) = (*this)[i];
		}
		for (int i = size_; i < new_size; ++i) {
			*(new_data + i) = 0;
		}

		delete[] data_;
		data_ = new_data;
		size_ = new_size;
		capacity_ = new_size;
	}
}

bool DynArr::Empty() const {
	return (size_ == 0);
}

int32_t DynArr::Size() const {
	return size_;
}

int32_t DynArr::Size(const DynArr& array) {
	return array.size_;
}

int32_t DynArr::Capacity() const {
	return capacity_;
}

int32_t DynArr::Capacity(const DynArr& array) {
	return array.capacity_;
}