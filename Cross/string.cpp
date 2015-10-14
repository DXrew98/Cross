/*************************************************
String Test (ie. string.h)

This is a near feature complete tring class
which allows the user to easily manipulate and
take advatange of strings in their code.

Esmeralda Salamone, esmes@aie.edu.au, 9/23/2015
Modified: Andrew C Ward, drewwardgov@gmail.com,
Last Edit: Oct 12 2015

All rights reserved.
***************************************************/

#include "string.h"
#include <iostream>
#include <cstring>
#include <climits>

//Set defaults
sfw::string::string(void) { m_data = new char[m_size = 1]{ '\0' }; } //g
//set deconstrutor 
sfw::string::~string() { delete[]m_data; } //g

//Call length
size_t sfw::string::length() const { return strlen(m_data); } //g
//call size
size_t sfw::string::size() const { return m_size; } //g

//create empty string
sfw::string::string(size_t size)
{
	// TODO:
	m_size = size;
	if (m_size <= 0) { m_size = 1; }
	m_data = new char[m_size];
	m_data[0] = '\0';
}
//Duplicate data, set size
sfw::string::string(const char * a, size_t size)
{
	// TODO:
	m_size = size;
	m_data = nullptr;
	if (m_size <= 0) { m_size = 1; }
	resize(m_size);
	int copyAmount = strlen(a);
	if (m_size < copyAmount) { copyAmount = m_size; }
	strncpy_s(m_data, m_size, a, _TRUNCATE);
	m_data[m_size - 1] = '\0';
}


//Contructors\\
//duplicate char array
sfw::string::string(const char * a)
{
	// if a is valid, go ahead and accomodate it
	if (a != nullptr)
	{
		m_size = strlen(a) + 1;
		m_data = new char[m_size];
		m_data[0] = '\0';
		strcpy_s(m_data, m_size, a);
	}
	// if not, let's create something blank
	else
	{
		m_size = 1;
		m_data = new char[m_size];
		m_data[0] = '\0';

		// Initialize this string as a null terminated string
		*this = sfw::string();
	}
}
//duplicate string
sfw::string::string(const string & a)
{
	// TODO:
	if (this != &a) {
		m_size = a.m_size;
		m_data = new char[m_size];
		m_data[0] = '\0';
		strcpy_s(m_data, m_size, a.m_data);
	}
	else
	{
		m_size = 1;
		m_data = new char[m_size];
		m_data[0] = '\0';

		// Initialize this string as a null terminated string
		//*this = sfw::string();
	}
}
//steal DM from string
sfw::string::string(string && a)
{
	// TODO:
	m_size = a.m_size;
	m_data = a.m_data;
	a.m_data = new char[a.m_size = 1]{ '\0' };
	a.m_size = 1;
	/*a.m_data = nullptr;
	a = sfw::string();*/
}


// = Assignment Operators \\
//duplicate char array
sfw::string & sfw::string::operator=(const char * a)
{
	delete[] m_data;
	// TODO:
	if (a != nullptr)
	{
		m_size = strlen(a) + 1;
		m_data = new char[m_size];
		m_data[0] = '\0';
		strcpy_s(m_data, m_size, a);
	}
	// return an null terminated string
	else
	{
		*this = sfw::string();
	}
	return *this;
}
//duplicate string
sfw::string & sfw::string::operator=(const string & a)
{
	// TODO:
	if (this != &a) {
		if (m_size < strlen(a.m_data) + 1){
		//resize the array
			delete m_data;
			m_size = strlen(a.m_data) + 1;
			m_data = new char[m_size];
			m_data[0] = '\0';
		}
		strcpy_s(m_data, m_size, a.m_data);
	}
	return *this;
}
//steal DM from string
sfw::string & sfw::string::operator=(string && a)
{
	// TODO:
	if (this != &a)
	{
		if (a.m_data != nullptr) {
			delete[] m_data;
		}
		m_size = a.m_size;
		m_data = a.m_data;

		
		a.m_data = new char[a.m_size = 1]{ '\0' };
	}
	return *this;
}


// += Assignment Operators \\
//add char array
sfw::string & sfw::string::operator+=(const char * a)
{
	// TODO:
	if (a != nullptr)
	{
		resize(length() + strlen(a) + 1);
		strcat_s(m_data, m_size, a);
	}
	return *this;
}
//add string
sfw::string & sfw::string::operator+=(const string & a)
{
	// TODO:
	resize(length() + a.length() + 1);
	strcat_s(m_data, m_size, a.m_data);
	
	return *this;
}
//add char
sfw::string & sfw::string::operator+=(char a)
{
	// TODO:
		resize(length() + 2);
		m_data[m_size - 2] = a;
		m_data[m_size - 1] = '\0';
	return *this;
}


// Array Indexing \\
//access index char
char & sfw::string::operator[](size_t index)
{
	// TODO: Is this finished?
	return this->m_data[index];
}
//read-only index char
const char & sfw::string::operator[](size_t index) const
{
	// TODO: Is this finished?
	return this->m_data[index];
}


//create new array, copy old, clear old
void sfw::string::resize(size_t size)
{
	// TODO:
	if (size <= 0) size = 1;
	if (size > UINT16_MAX) size = UINT16_MAX;
	char * t = new char[size];
	m_size = size;
	if (m_data != nullptr) {
		strncpy_s(t, size, m_data, m_size);
		delete[]m_data;
	}
	m_data = t;
	m_data[m_size-1] = '\0';
}
//set first char to '\0'
void sfw::string::clear()
{
	m_data[0] = '\0';
}

bool sfw::string::empty() const
{
	// TODO:
	if (m_data[0] == '\0') { return true; }
	else return false;
}

//const access to m_data
const char * sfw::string::cstring() const
{
	// TODO:
	return m_data;
}


// Operator Overloads \\
// true if < alphabetical-ascending \\
//string | string
bool sfw::operator<(const string & a, const string & b)
{
	// TODO:
	if (strcmp(a.cstring(), b.cstring()) == -1) { return true; }
	else { return false; }
}
//string | char array
bool sfw::operator<(const string & a, const char * b)
{
	// TODO:
	if (strcmp(a.cstring(), b) == -1) { return true; }
	else { return false; }
}
//char array | string
bool sfw::operator<(const char * a, const string & b)
{
	// TODO:
	if (strcmp(a, b.cstring()) == -1) { return true; }
	else { return false; }
}

//true if <= alphabetical-ascending
//string | string
bool sfw::operator<=(const string & a, const string & b)
{
	// TODO:
	if (a < b || a == b) { return true; }
	else { return false; }
}
//string | char array
bool sfw::operator<=(const string & a, const char * b)
{
	// TODO:
	if (a < b || a == b) { return true; }
	else { return false; }
}
bool sfw::operator<=(const char * a, const string & b)
{
	// TODO:
	if (a < b || a == b) { return true; }
	else { return false; }
}

//true if > alphabetical-descending \\
//string | string
bool sfw::operator>(const string & a, const string & b)
{
	// TODO:
	if (strcmp(a.cstring(), b.cstring()) == 1) { return true; }
	else { return false; }
}
//string | char array
bool sfw::operator>(const string & a, const char * b)
{
	// TODO:
	if (strcmp(a.cstring(), b) == 1) { return true; }
	else { return false; }
}
//char array | string
bool sfw::operator>(const char * a, const string & b)
{
	// TODO:
	if (strcmp(a, b.cstring()) == 1) { return true; }
	else { return false; }
}

//true if >= alphabetical-ascending \\
//string | string
bool sfw::operator>=(const string & a, const string & b)
{
	// TODO:
	if (a > b || a == b) { return true; }
	else { return false; }
}
//string | char array
bool sfw::operator>=(const string & a, const char * b)
{
	// TODO:
	if (a > b || a == b) { return true; }
	else { return false; }
}
//char array | string
bool sfw::operator>=(const char * a, const string & b)
{
	// TODO:
	if (a > b || a == b) { return true; }
	else { return false; }
}

//true if != equal \\
//string | string
bool sfw::operator!=(const string & a, const string & b)
{
	// TODO:
	if (!(a == b)) { return true; }
	else { return false; }
}
//string | char array
bool sfw::operator!=(const string & a, const char * b)
{
	// TODO:
	if (!(a == b)) { return true; }
	else { return false; }
}
//char array | string
bool sfw::operator!=(const char * a, const string & b)
{
	// TODO:
	if (!(a == b)) { return true; }
	else { return false; }
}

//true if equal \\
//string | string
bool sfw::operator==(const string & a, const string & b)
{
	// TODO:
	if (strcmp(a.cstring(), b.cstring()) == 0) { return true; }
	else { return false; }
}
//string | char array
bool sfw::operator==(const string & a, const char * b)
{
	// TODO:
	if (strcmp(a.cstring(), b) == 0) { return true; }
	else { return false; }
}
//char array | string
bool sfw::operator==(const char * a, const string & b)
{
	// TODO:
	if (strcmp(a, b.cstring()) == 0) { return true; }
	else { return false; }
}


// Concatenation Operators \\
//add two strings
sfw::string sfw::operator+(const string & a, const string & b)
{
	// TODO:
	sfw::string temp(a);
	temp += b;
	return temp;
}
//add a string and a char array
sfw::string sfw::operator+(const string & a, const char * b)
{
	// TODO:
	sfw::string temp(a);
	temp += b;
	return temp;
}
//add a char array and a string
sfw::string sfw::operator+(const char * a, const string & b)
{
	// TODO:
	sfw::string temp(a);
	temp += b;
	return temp;
}

//add a string and a char
sfw::string sfw::operator+(const string & a, char b)
{
	// TODO:
	sfw::string temp(a);
	temp += b;
	return temp;
}
//add a char and a string
sfw::string sfw::operator+(char a, const string & b)
{
	// TODO:
	sfw::string temp(2);
	temp[0] = a;
	temp[1] = '\0';
	temp += b;
	return temp;
}


// in / out streaming \\
//outream console
std::ostream & sfw::operator<<(std::ostream & os, const string & p)
{
	// TODO:
	os << p.cstring();
	return os;
}
//instream console
std::istream & sfw::operator>>(std::istream & is, string & p)
{
	// TODO:
	char t[65353];
	is >> t;
	p = t;
	return is;
}

const sfw::string sfw::literals::operator""_sfw(const char * a, size_t len)
{
	// TODO:
	return string(a, len + 1);
}
