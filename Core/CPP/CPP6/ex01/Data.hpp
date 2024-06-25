#pragma once

class Data {
private:
    int _data;
	Data();

public:

    Data(int value);
	~Data();
	Data(Data const &Rhs);
	Data& operator=(Data const &Rhs);

    int getData() const;
};
