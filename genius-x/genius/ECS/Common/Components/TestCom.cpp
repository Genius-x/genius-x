/****************************************************************************
Copyright (c) 2014 Elvis Qin
Copyright (c) 2014 Soulgame Inc.

http://www.genius-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#include "TestCom.h"

std::string GX::TestCom::_TYPE="TestCom";

GX::TestCom::TestCom()
	:GX::Com(_TYPE)
{

}

void GX::TestCom::initWithMap(rapidjson::Value& value)
{
	testInt = (int)value["testInt"].GetInt();
	testFloat = (float)value["testFloat"].GetDouble();
	testString=value["testString"].GetString();

	testData.lalala = value["testData"]["lalala"].GetInt();
}

GX::Com* GX::TestCom::cloneEmpty() const
{
	return new GX::TestCom();
}