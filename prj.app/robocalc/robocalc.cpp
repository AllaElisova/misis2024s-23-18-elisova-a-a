#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <vector>

class ICmd {
public:
	ICmd() = default;
	virtual ~ICmd() = default;
};

class ICCmd_add : public ICmd {
public:

};

class ICmd_sub : public ICmd {
public:

};