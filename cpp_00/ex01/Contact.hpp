#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

/*
a class is a blueprint of an object, 
The class definition itself does not allocate memory for data members
the class is by default private, 
we can change it by providing other access specifiers,
like public for outside class access,
*/

/*
here Contact class have 5 private attributes and setters 
getters methods to access this attributes outside the class
and of course default constructor and destructor
*/

class Contact
{

private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

public:
	std::string get_first_name() const;
	std::string get_last_name() const;
	std::string get_nickname() const;
	std::string get_phone_number() const;
	std::string get_darkest_secret() const;

	void set_first_name(std::string value);
	void set_last_name(std::string value);
	void set_nickname(std::string value);
	void set_phone_number(std::string value);
	void set_darkest_secret(std::string value);
	Contact();
	~Contact();
};

#endif