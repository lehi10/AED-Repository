// binomial heaps, -bds 03Oct,  Reference: CLR chapter 19
#ifndef __BINOMIALHEAP_H
#define __BINOMIALHEAP_H
/***
 This implementation DOES provide constructors and the CLR functions:
Binomial_Heap_Insert(), Binomial_Heap_Minimum(), Binomial_Link(),
Binomial_Heap_Extract_Min(), and Binomial_Heap_Union().

Each of the above functions runs in O(lg(n)) time, for n the size of the 
resulting heap.

This implementation DOES NOT provide:
Binomial_Heap_Decrease_Key() or Binomial_Heap_Delete()
***/

#include <list> 
#define slist list 
// we only pretend we use singly linked lists.  The problem is 
// that slist is a stl library extension not always offered.

#include <functional> // we use unique() and min_element()
using namespace std;

/*** Binomial Trees ***/

		template<class Key> 
struct binomialTree 
    // Key must be ordered with "a < b" defining a strict weak ordering.
{
    binomialTree() {} 
    binomialTree( const Key & k ): key(k) {} // C empty by default.
    Key key; 
    slist< binomialTree > C; // the children, 
    //  C is a reversed full heap.  If the degree is d = C.size(), 
    //  C[i] has degree d-1 - i. 
    //  This reversal makes Binomial_Link() faster on average.
};

/****** Binomial Tree functions ******/

#define BT binomialTree<Key>

		template<class Key> inline
BT& Binomial_Link( BT& S, BT& T)
    // link two trees which must be of equal degree.
{   if ( S.key < T.key )
    {   S.C.push_front(T); return S;    }
    else
    {   T.C.push_front(S); return T;    }
}   // worst case time is Theta(1).

		template<class Key> inline
size_t degree( BT& T) {   return T.C.size();    } 
    // retured value is exactly lg(n), for n the number of keys in T.
    // worst case time is Theta(1).

		template<class Key> inline
bool lessByKey( const BT& A, const BT& B ) {   return A.key < B.key;   }   
    // used for min_element() in Binomial_Heap_Extract_Min()
    // worst case time is Theta(1).

		template<class Key> inline
bool lessByDegree( BT& A, BT& B ) {   return degree( A ) < degree( B );   }
    // used for slist merge() in Binomial_Heap_Union()
    // worst case time is Theta(1).

		template<class Key> inline
bool equalDegree( BT& A, BT& B ) 
{   // special trick used for unique() in Binomial_Heap_Union()
    if ( degree( A ) > degree( B ) )
	// then swap them, which will fully restore order.
    {   swap( A, B ); return false;   }
    else if ( degree( A ) == degree( B ) )
    {   A = Binomial_Link( A, B ); // mess up order just a little.
	return true;   // unique() will delete B now.  
	// The one after B may have degree less than or equal to what A now has.
	// unique() will handle this correctly.
    }
    else 
	return false;
}   // worst case time is Theta(1).

/****** binomialHeap functions. ******/

/***
A binomial heap is just an slist of binomial trees of distinct degrees 
and in increasing order by degree.  

Increasing order is good for Insert.

In the complexity assertions, hw(n) is the Hamming weight of n, which
is the number of 1 bits in the binary expression of n.  For instance
hw(13) = 3, since decimal 13 is binary 1101.
Note that 1 <= hw(n) <= lg(n+1), for positive n.
***/

template< class Key > 
struct binomialHeap: public slist< binomialTree< Key > >
{   binomialHeap(){}

    binomialHeap( const slist< binomialTree< Key > > & B )
    : slist< binomialTree< Key > > ( B ) {}
};  // just an alias for a slist, with a "pass thru" constructor to keep
    // the compiler happy.

#define BH binomialHeap< Key >

		template<class Key> inline 
Key Binomial_Heap_Minimum( const BH& B ) 
    // Return the minimum key from B.  B must be nonempty.
{   
    return min_element( B.begin(), B.end(), lessByKey<Key> )->key;   
}   // worst case time is Theta(hw(n)), for n the number of keys in B.

		template<class Key> inline
void Binomial_Heap_Extract_Min( BH& B )
    // Remove the minimum key (and restore heap properties). B must be nonempty.
{   typename 
    BH::iterator Tp = min_element( B.begin(), B.end(), lessByKey<Key> );   
    BH H( Tp->C ); 
    B.erase( Tp );
    Binomial_Heap_Union( B, H ); 
}   // worst case time is Theta(lg(n)), for n the number of keys in B.

		template<class Key> inline
void Binomial_Heap_Insert( BH& B, Key k )
    // Add a new key to B, restore heap properties
    // Note CLR has a the 2nd argument be a node rather than a key.
    // That is necessary only if Decrease_Key is being provides.
{   BH H;
    H.push_front( *new binomialTree< Key >(k) ); // No memory leak, because of
        // eventual deletion by the erase() in Extract_Min().
    Binomial_Heap_Union( B, H );   
}   // worst case time is Theta(hw(n)), for n the number of keys in B.

		template<class Key> 
void Binomial_Heap_Union( BH& A, BH& B )
    // A becomes ( A U B )
{   A.merge( B, lessByDegree<Key> ); // sorted slist merge
    // A is not currently a valid heap because it may have two in a row
    // of trees with the same size, for some sizes.
    A.unique( equalDegree<Key> ); // side effects of equalDegree make this work.
}   // worst case time is O(lg(n)), for n the resulting number of keys in A.

/***************** dead code 
This indicates that there is some advantage in using unique() 
and equalDegree() in Binomial_Heap_Union!

		template<class Key> 
void bino_HeapListFix( BH::iterator b, BH::iterator e )
    // make a degree ordered list of trees with possibly duplicate degrees
    // into a proper binomial heap (strictly increasing degrees).
{   BH::iterator c = b;
    if ( b == e ) return; 
    c++;
    while ( c != e && lessByDegree( *b, *c ) ) 
	b++, c++; // skip on up to a duplicate pair
    if ( c == e ) return;

    // handle a duplicate pair
    *b = Binomial_Link(*b, *c);
    BH::erase(c);

    // the new linked node can actually be larger than the successor.
    c = b; c++;
    if ( c != e && lessByDegree( *c, *b ) )
    {   swap(*b, *c); bino_HeapListFix( c, e );   }
    else  // or might equal the successor...
	bino_HeapListFix( b, e )

    //...  There's got to be an easier way!
}
*****************/

#endif
#if 0
// test code. 
// To use it, copy file to .cc and change #if value above to 1. 
// To restore as a header, copy file to .h and change #if value above to 0.

#include <iostream>
using namespace std;

int main()
{
    binomialHeap< long > H;
    //slist< binomialTree< long > > H; // binomialHeap< long >

    for (long i = 0; i < 256; ++i) 
	Binomial_Heap_Insert( H, i+100 );

    for (int i = 0; i < 100; ++i) 
    {
	cout << Binomial_Heap_Minimum( H ) << " ";
	Binomial_Heap_Extract_Min( H );
	Binomial_Heap_Insert( H, random()%200 );
    }
    cout << endl;
}
#endif
