/*#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <vector>


class ICmd {
public:
	ICmd() = default;

	ICmd(double operand)
		: register_{ operand } {};

	virtual ICmd tryInit(ICmd* ptr, std::string& command, double operand) {
		operand_ = operand;
	}

	void Out(double number) {
		for (int i = 0; i < counter_; ++i) {
			std::string command = commands_.at(commands_.size() - counter_);
			double operand = operands_.at(operands_.size() - counter_);
			tryInit(this, command, operand);
			// берём команду из списка с индеком (сайз - каунтер)
			// берём операнд 
			// порождаем что можем
			// при выполнении уменьшаем каунтер 
		}
	}


	std::ifstream& Read(std::ifstream& ifstrm) {
		std::string command{ 3, ' ' };
		double number{ 0 };
		std::string end{ "\n" };

		ifstrm >> command >> number >> end;

		while ((ifstrm.good()) && (command != "OUT") && (end == "\n")) {
			ifstrm >> command >> number >> end;
			if (command == "REV") {
				commands_.erase(commands_.end() - number, commands_.end());
				operands_.erase(operands_.end() - number,operands_.end());
				counter_ -= number;
			}
			else {
				commands_.push_back(command);
				operands_.push_back(number);
				operand_ = number;
				++counter_;
			}
		}

		if (command == "OUT") {
			 Out(number);
		}

		else {
			throw std::runtime_error("wrong format");
		}

		return ifstrm;
	}

	std::ofstream& Write(std::ofstream& ofstrm) {
		ofstrm << register_;
		return ofstrm;
	}

	virtual ~ICmd() = default;

protected:
		std::vector <std::string> commands_;
		double register_ = 0;
		std::ofstream ofstrm_;
		int counter_ = 0;
		double operand_ = 0;
		std::vector < double > operands_;
		std::unique_ptr <ICmd> pointer_ = nullptr;
};


class ICmd_add : public ICmd {
public:
	ICmd_add(double operand)
		: ICmd(register_ + operand){}


	virtual ICmd tryInit(ICmd* ptr, std::string& command, double operand) final {
		if (command == "ADD") {
			delete (ptr);
			ptr = nullptr;
			ptr = *(new ICmd_add(operand));
			--counter_;
			return *ptr;
		}
	}

	virtual ~ICmd_add() = default;
};


class ICmd_sub : public ICmd {
public:
	ICmd_sub(double operand)
		: ICmd(register_ - operand){}


	virtual ICmd tryInit(*Icmd ptr, std::string& command, double operand) final {
		if (command == "SUB") {
			delete (ptr);
			ptr = nullptr;
			ptr = *(new ICmd_sub(operand));
			--counter_;
			return *ptr;
		}
	}

	virtual ~ICmd_sub() = default;
};


class ICmd_mul : public ICmd {
public:
	ICmd_mul(double operand)
		: ICmd(register_ * operand){}

	virtual ICmd tryInit(std::unique_ptr <ICmd> ptr, std::string& command, double operand) final {
		if (command == "MUL") {
			delete (ptr);
			ptr = nullptr;
			ptr = *(new ICmd_mul(operand));
			--counter_;
			return *ptr;
		}
	}

	virtual ~ICmd_mul() = default;
};


class ICmd_div : public ICmd {
public:
	ICmd_div(double operand)
		: ICmd(register_ / operand) {}

	virtual ICmd tryInit(ICmd* ptr, std::string& command, double operand) final {
		if (command == "DIV") {

			if (operand == 0) {
				throw std::logic_error("forbidden: division by zero");
			}
			delete (ptr);
			ptr = nullptr;
			ptr = *(new ICmd_div(operand));
			--counter_;
			return *ptr;
		}
	}

	virtual ~ICmd_div() = default;
};

int msin() {
	ICmd calc;
	std::ifstream in;       // поток для чтения
	in.open("commands.txt");

	std::ofstream out;    // поток для записи
	out.open("result.txt");


	calc.Read(in);
	calc.Write(out);
} */