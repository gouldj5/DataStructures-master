#ifndef LINK_H
#define LINK_H
#include <cstdlib>   // Provides size_t and NULL
#include "node1.h"   // Provides node class
#include <string>

using namespace std;

namespace link
{
    class bag
    {
    public:
    
        typedef size_t size_type;
        typedef node::value_type value_type;
        
        bag( );
        
		bag(const bag& source); //construct & destruct
		
		~bag( ); 
        
		// ALL THE FUNCTIONS YOU WILL EVER NEED
        size_type erase(const value_type& target);
        bool erase_one(const value_type& target);
        void insert(const value_type& entry);
        void operator +=(const bag& addend);
        void operator =(const bag& source);

        size_type size( ) const { return many_nodes; } //may need to define more
        size_type count(const value_type& target) const;
        value_type grab( ) const;
        node *head_ptr;        
        size_type many_nodes; 
    };   
    bag operator +(const bag& b1, const bag& b2);
}
#endif

