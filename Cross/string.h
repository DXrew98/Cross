#pragma once

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

// This header forward declares ostream and istream
// iostream should still be included in the source file
#include <iosfwd>

namespace sfw
{
	class string
	{
	private:
		char *m_data;	
		size_t m_size;	

	public:	

		string(void); 
		~string(); 

		size_t length() const;	
		size_t size() const;	

		string(size_t size); 
		string(const char *a, size_t size);
						

		// Constructors
		string(const char *a);		
		string(const string &a);	
		string(string &&a);			

		// Assignment operators
		string &operator=(const char *a);	
		string &operator=(const string &a); 
		string &operator=(string &&a);		

		// Concatenation assignment
		string &operator+=(const char *a);
		string &operator+=(const string &a);
		string &operator+=(char a);

		// Array indexing
		char &operator[](size_t index);				
		const char &operator[](size_t index) const; 

		void resize(size_t size);
		void clear();				
		bool empty() const;			

		const char *cstring() const;	
	};

	// Relational operator overloads
		// less-than is true if alphabetical-ascending
	bool operator<(const string &a, const string &b);
	bool operator<(const string &a, const char *b); 
	bool operator<(const char *a, const string &b);

	bool operator<=(const string &a, const string &b);
	bool operator<=(const string &a, const char *b);
	bool operator<=(const char *a, const string &b);
		// greater-than is true if alphabetical-descending
	bool operator>(const string &a, const string &b);
	bool operator>(const string &a, const char *b);
	bool operator>(const char *a, const string &b);

	bool operator>=(const string &a, const string &b);
	bool operator>=(const string &a, const char *b);
	bool operator>=(const char *a, const string &b);

	bool operator!=(const string &a, const string &b);
	bool operator!=(const string &a, const char *b);
	bool operator!=(const char *a, const string &b);

	bool operator==(const string &a, const string &b);
	bool operator==(const string &a, const char *b);
	bool operator==(const char *a, const string &b);

	// Concatenation operations
		// should create a new string that is the concatenation of the two passed in.
		// Should support single characters also.
	string operator+(const string &a, const string &b);
	string operator+(const string &a, const char *b);
	string operator+(const char *a, const string &b);

	string operator+(const string &a, char b);
	string operator+(char a, const string &b);

	// Allows us to work with stream processors (cin/cout)
	std::ostream &operator<<(std::ostream &os, const string& p); 
	std::istream &operator>>(std::istream &is, string& p);

	// Literal operator overload, use given char data to create a string
	inline namespace literals {
		const string operator""_sfw(const char *a, size_t len); }


}

