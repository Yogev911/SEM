#pragma once

#include "../Control/Control.h"

class TextBox
{
public:
	TextBox(int width);
	void setValue(string value);
	string getValue();
	~TextBox();
};
