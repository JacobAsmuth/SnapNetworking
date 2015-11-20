#pragma once

#include <cstdio>
using std::sprintf;
#include <cstdlib>
using std::atoi;
using std::size_t;
#include <cstring>
using std::strncat;
#include <string>
using std::string;

class message
{
public:
	enum { header_length = 4 };
	enum { id_length = 4 };
	enum { max_body_length = 512 };
	enum { username_length = 24 };
	 
	message();
	message( const char * buf );

	const char* data() const;
	char* data();

	const char * id() const;
	char * id();

	const char * username() const;
	char * username();

	const char* body() const;
	char* body();

	size_t total_length( bool username_attached ) const;

	size_t body_length() const;
	void body_length( size_t new_length );

	void write( const char * buf );

	bool decode_header();
	void encode_header();

	bool decode_id();
	void encode_id( int id );

	bool decode_username();
	void encode_username( string username );

	int get_id() const;
	string get_username() const;

private:
	char _data[header_length + id_length + username_length + max_body_length];
	size_t _body_length;
	int _id;
	string _username;
};