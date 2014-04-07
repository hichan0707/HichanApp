///	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
///	@file		Allocator.cpp
///	@brief		
///	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

#include "Allocator.h"


const unsigned int Hichan::Allocator::SIGNATURE = 0xDEC0DE;

/////////////////////////////////////////////////////////////////////////////////
Hichan::Allocator::Allocator()
{
}


/////////////////////////////////////////////////////////////////////////////////
Hichan::Allocator::~Allocator()
{
}


/////////////////////////////////////////////////////////////////////////////////
void* Hichan::Allocator::_alloc( const size_t size )
{
	return nullptr;
}

/////////////////////////////////////////////////////////////////////////////////
void Hichan::Allocator::_free( unsigned char *ptr )
{

	Header *header = (Header*)(ptr);
	assert( header->_signature == SIGNATURE ); // ƒƒ‚ƒŠ‰ó‚ê‚Æ‚é|:3ƒ~

	if( header->_prev != nullptr ) {
		
	}

	Footer *footer = (Footer*)(ptr+sizeof(Header)+header->_size);
	assert( footer->_signature == SIGNATURE ); // ƒƒ‚ƒŠ‰ó‚ê‚Æ‚é|:3ƒ~
	
	Header *newxt_header = (Header*)(footer+sizeof(Footer));

	assert( newxt_header == (Header*)header->_next );

}