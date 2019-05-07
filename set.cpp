
// Lab Exercise 4.

#include "set.h"


bool set::equal( const std::string& s1, const std::string& s2 )
{
    if( s1.size() == s2.size() )
    {
        for( unsigned int i = 0; i < s1.size(); ++i )
        {
            if( tolower(s1[i])!= tolower(s2[i]) )
                return false;
        }
        return true;
   	} else {
        return false;
   	}
}

bool set::contains( const std::string& el ) const
{
    for( unsigned int i = 0; i < data.size(); ++i )
	{
        if( equal(data[i], el) )
            return true;
	}
	return false;
}

bool set::insert( const std::string& el )
{
	if( contains(el) )
        return false;

	data.push_back(el);
	return true;
}

size_t set::insert( const set& s )
{
	for( unsigned int i = 0; i < s.data.size(); ++i )
	{
		if( !contains(s.data[i]) )
			data.push_back(s.data[i]);
	}
	return data.size();
}

bool set::remove( const std::string& el )
{
	for( unsigned int i = 0; i < data.size(); ++i )
	{
		if( equal(el, data[i]) )
		{
			std::swap( data[i], data.back() );
			data.pop_back();
			return true;
		}
	}
	return false;
}

size_t set::remove( const set& s )
{
	int num = 0;

	for( unsigned int i = 0; i < s.data.size(); ++i )
	{
		if( remove(s.data[i]) )
			num++;
	}
	return num;
}

std::ostream& operator << ( std::ostream& out, const set& s )
{
	out << "{";
	for( auto i = s.begin(); i != s.end(); ++i )
    {
        if (i!= s.begin())
            out << ", ";

        out << *i;
	}
    out << "}";
	return out;
}

bool subset( const set& s1, const set& s2 )
{
	for( auto i : s1 )
    {
		if( !s2.contains(i) )
			return false;
	}
	return true;
}

