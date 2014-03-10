#include <string>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <vector>
#include "./assoc.h"
#include <sys/time.h> 

using namespace std;

/*****************/
/* Testing Stuff */
/*****************/

int test_assoc( int trials, int max )
{
  char buf[256];
  int errors = 0;

  int *values = new int[max];
  
  for (int n = 0; n < trials; n++) {
    // construct the table
    assoc<int*> table;
    if (table.n() != 0) {
      cerr << "n() returned nonzero on a newly created table" << endl;
      errors++;
    }

    // initialize the test values
    for (int k = 0; k < max; k++)
      values[k] = 2*(n*max + k) + 1;
        
    for (int k = 0; k < max; k++) {
      // Construct a new key having the form "n:k"
      sprintf(buf, "%d:%d", n, k);
      string key(buf);

      // the key is unique and should not be there
      if (table.contains(key)) {
	cerr << "False positive in containment test of '" << key <<"'" << endl;
	errors++;
      }

      // the value is a pointer to an integer
      int* value = values + k;

      // insert the value, given the key
      table.insert(key, value);

      // the number of elements should now be one more than 'k'
      int n_elem = table.n();
      if (n_elem != k + 1) {
	cerr << "invalid element count\n";
	errors++;
      }

      // the table should now contain 'key'
      if (!table.contains(key)) {
	cerr << "contains() returned false for the key just added" << endl;
	errors++;
      }
      
      // test lookup of what we just inserted
      int* result;
      if (!table.lookup(result, key)) {
	cerr << "Lookup of '" << key << "' failed after insertion" << endl;
      }
      else if (result != value || *result != values[k]) {	
	cerr << "Lookup of '" << key << "' ";
	cerr << "gave wrong value ";
	cerr << "(immediately after insertion)" << endl;
	errors++;
      }      
      
    } // (end of 'k' loop)

    //cerr << "min bucket count: " << table.min_bucket() << "\n";
    //cerr << "max bucket count: " << table.max_bucket() << "\n";
    //table.print(cerr);

    for (int k = 0; k < max; k++) {
      sprintf(buf, "%d:%d", n, k);
      string key(buf);

      // the table should contain 'key'
      if (!table.contains(key)) {
	cerr << "contains() returned false for a known key" << endl;
	errors++;
      }
	
      // test lookup 
      int* result;
      if (!table.lookup(result, key)) {
	cerr << "Lookup of '" << key << "' failed" << endl;
      }      
      if (!result || result != values + k || *result != values[k]) {	
	cerr << "Lookup of '" << key << "' ";
	cerr << "gave wrong value " << endl;
	errors++;
      }      
      
    } // (end of 'k' loop)
    
  }

  // free up the 'values' array
  delete[] values;
  
  cerr << errors << " error" << (errors == 1 ? "" : "s") << " "
       << "(max = " << max << ", trials = " << trials << ")" << endl;

  return errors;
}


// Possible 'main'

// int elapsed( timeval &startTime, timeval &endTime ) {
//     return ( endTime.tv_sec - startTime.tv_sec ) * 1000
//     + ( endTime.tv_usec - startTime.tv_usec );
// }
unsigned long int hash1(const string& key) 
// Helper function for generating a hash value for a key
// Pre: Key should not be empty, else it will generate the
// same value each time
// Post: Returns a hash value for a key
{
    unsigned long int code = 2166136261u; // magic prime number
    const char *ptr = key.c_str();
    while (*ptr) {
        code = (16777619 * code)^(*ptr);
        ptr++;
    }
    return code % 100000000000;
}
int main( int argc, char *argv[] )
{
  // test_assoc(1, 16);
  // test_assoc(1, 1024);
  // struct timeval startTime, endTime;
  // gettimeofday( &startTime, 0 );
  // gettimeofday( &endTime, 0 );
  // cout << "elapsed time: " << elapsed( startTime, endTime ) << endl;
  struct timeval tim;  
  gettimeofday(&tim, NULL);  
  double t1=tim.tv_sec+(tim.tv_usec/1000000.0);  
  // hash1("100000000000");
  test_assoc(1, 1000000);

  gettimeofday(&tim, NULL);  
  double t2=tim.tv_sec+(tim.tv_usec/1000000.0);  
  printf("%.6lf seconds elapsed\n", t2-t1);  

}