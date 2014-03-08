#define CATCH_CONFIG_MAIN

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "catch.hpp"
#include "./assoc.h"

using namespace std;

string testKeys[] = {
                 "2c57dc6d-b18c-4439-aa9c-0dfb2e52d61d",
                 "696715a9-99de-422f-9971-d6f343fd5a92",
                 "d0e4c41e-cbca-4e72-9967-8eee604472a9",
                 "411cf7ae-ac96-4724-9c6d-53a371ecfbde",
                 "80285bf5-20c3-4b89-a142-5da9ce23768b",
                 "b22ba89c-46c0-4398-9cf6-84991dac7f07",
                 "d3621a77-6b5b-448e-b65f-6d86f68cf190",
                 "a86848df-20b0-430b-8b1e-871dab6b8dcd",
                 "d4ef002b-d1d8-4516-bd92-75cfcb1087da",
                 "d4172221-21cb-4002-815a-8a6e458a2772",
                 "4eaf78cb-c03a-4ad4-b547-5d76e6796736",
                 "29f90aea-279f-4cb7-b424-3b960c0bc44d",
                 "f0603b95-b544-45ee-8c6f-643de63f40de",
                 "147233c1-a85c-4fa5-b66a-cc52fafd7690",
                 "86b38836-1096-42ea-a983-0fa951defe55",
                 "aad1ab5c-8955-4c02-a7da-146d033ed35c",
                 "0310e01a-5733-4056-a2ff-161fe68fabe1",
                 "65cab417-1b26-4281-a31c-2fe8d554d118",
                 "e739a3e8-99ca-4818-a658-2dcd368f1aea",
                 "77824183-79c7-47ca-a326-6411c1933439",
                 "66e81c75-541c-45d9-80ca-25498bd0d5bb",
                 "f80d480b-cd1b-46b5-9b7d-3729f04007d1",
                 "e7ad82bb-2ac4-4d29-9747-c8cac15fc1d2",
                 "445d4824-d3f8-43ed-a898-c5dc959a5699",
                 "f6adc104-3682-45a5-aade-773c067ba539",
                 "d52a698b-bb67-4cea-976d-17761777af3f",
                 "c334d6bd-97d1-4219-bd29-af6d92a618c4",
                 "e804b990-0ffc-42c9-97aa-5e04b2f6725a",
                 "d91113a9-1a25-4!@#$%^&*ca7-95d8-580083b6ae4a",
                 "7a4a02e1-aee9-4db2-9fe0-c219a84b42d6",
                 "1418b959-1c7f-488b-aa4d-ebd044976400",
                 "6112469b-8746-4625-ae31-cdc0361a947c",
                 "efbf4126-4d92-4183-8a25-ae3607256d29",
                 "6ccf7877-e6ac-4467-af73-4531e5ca129e",
                 "6b80c411-6375-49c3-8f15-2515bf0ce7cf",
                 "64768265-7531-4b8d-9a84-018cc84dab03",
                 "637ecf31-2505-4e68-9ac3-846faa142a4d",
                 "cb76067d-3176-41b5-9deb-9288a676600b",
                 "1bb8c415-0b01-48a0-8a2a-1839928ed6d7",
                 "01c3f2c6-ebcd-46b5-8bd5-d0f5åß∂ƒ©˙∆˚¬…Ω≈ç√∫˜µ≤≥÷8cca0b92",
                 "16e3f06b-178e-4a89-b3a5-7eb737afc21f",
                 "9587b8f0-e1e9|}{:\"-4d28-b528-259da235285f",
                 "f7cd1957-acd5-4c0d-bff3-ab881eff947e",
                 "52e1d072-5b78-44bb-955e-a1c1b59dbee2",
                 "5b81ec58-1448-486a}{\":-ad74-17c2936f63a0",
                 "547ea0d2-a2c4-419b-9a09-e0a1ceb9093d",
                 "dabb47a5-fd03-4d1=098:\"?><7e-ab4f-1590ac3786ab",
                 "7acfbcf4-ec95-4d17-8dee-1c5ef8bd85ee",
                 "25c2fc9c-c66a-4'845-a3a∫˜µ˚¬¥¨ˆø¡™£¢∞§¶•ªº–≠f-05da2cf81bb8",
                 "17691c6a-7eaa-476f-a77e-b3ff3c2c402b",
                 "589 Kings Hwy, Dellview, Oklahoma, 444",
                 "883 Gotham Avenue, Fairview, New York, 2743",
                 "988 Garden Place, Bluetown, Virginia, 6355",
                 "979 Raleigh Place, Duryea, Montana, 6463",
                 "650 Ocean Court, Chicopee, Utah, 4635",
                 "(803) 585-2290, Throop Avenue, Ezel, South Dakota, 9400",
                 "(854) 567-2446/ Dunne Court, Terlingua, Oklahoma, 9833",
                 "(802) 426-2420 Eckford Street, Juarez, Alabama, 1901",
                 "(983) 405-3049 Dunne Place, Byrnedale, Missouri, 9240",
                 "(876) 532-2943 Dewey Place, Bellamy, Alaska, 141",
                 "",
                 "",
                 "(876) 532-2943 Dewey Place, Bellamy, Alaska, 141",
                 "(876) 532-2943 Dewey Place, Bellamy, Alaska, 141",
                 "a",
                 "b",
                 "0",
                 "/"
                 };
int testValues[] = {3295,
                7609,
                392,
                9697,
                5940,
                3284,
                3834,
                670,
                5067,
                1948,
                5542,
                9606,
                1527,
                8756,
                984,
                9218,
                7202,
                544,
                7809,
                5617,
                5895,
                4020,
                2078,
                5917,
                145,
                6510,
                644,
                710,
                3072,
                496,
                4443,
                6429,
                4531,
                2051,
                2576,
                1022,
                1346,
                4914,
                1597,
                1253,
                7496,
                8557,
                2178,
                4657,
                2301,
                7101,
                8759,
                1105,
                1044,
                7948,
                9265,
                1934,
                5781,
                2304,
                4840,
                5590,
                7106,
                626,
                8605,
                2001,
                0,
                1,
                2,
                3,
                4,
                5,
                6,
                7};

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

      cout << "key:" << key << endl;
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

TEST_CASE("0-1 insert and lookup", "[assoc]") {
  assoc<int> map(100);
  // int value;
  // int n = 0;
  for (int i = 0; i < 68; i++) {
    map.insert(testKeys[i], testValues[i]);
    // vector<int> v = map.values();
    // cout << v.at(n) << endl;
    if (testKeys[i].size() == 0) {
        REQUIRE(map.contains(testKeys[i]) == false);
    } else {
        REQUIRE(map.contains(testKeys[i]) == true);
    }
    // REQUIRE(map.lookup(value, testKeys[i]) == true);
    // REQUIRE(value == testValues[i]);
    // REQUIRE(map.lookup(value, testKeys[i] + "1231") == false);
  }
}

TEST_CASE("0-1 load factor", "[assoc]") {
  assoc<int> map(100);
  for (int i = 0; i < 68; i++) {
    map.insert(testKeys[i], testValues[i]);
    REQUIRE(map.load_factor() == (i+1)/100);
  }
}

TEST_CASE("0-1 load factor2", "[assoc]") {
    assoc<int> map(10);
    map.set_max_load_factor(0.7);
    for (int i = 0; i < 7; i++) {
        map.insert(testKeys[i], testValues[i]);
        REQUIRE(map.load_factor() == (i+1)/10);
    }
    map.insert(testKeys[7], testValues[7]);
    REQUIRE(map.load_factor() == (8)/10);

    map.insert(testKeys[8], testValues[8]);
    REQUIRE(map.load_factor() == (9)/20);
}

TEST_CASE("0-1 n()", "[assoc]") {
    assoc<int> map(100);
    REQUIRE(map.n() == 0);
    int n = 0;
    for (int i = 0; i < 68; i++) {
        // cout << "testKeys[i].size():" << testKeys[i].size() << endl;
        // cout << "n:" << n << endl;
        // cout << "i:" << i << endl;
        map.insert(testKeys[i], testValues[i]);
        if (testKeys[i].size() != 0) {
            n++;
        }
        REQUIRE(map.n() == (n));
    }
}

TEST_CASE("0-1 max_load_factor", "[assoc]") {
    double factors[] = {0.0, 0.1, 0.3, 0.5, 0.7, 0.9, 1.0};
    assoc<int> map(0);
    for (int i = 0; i < 7; i++) {
        map.set_max_load_factor(factors[i]);
        if (factors[i] == 0.0) {
            REQUIRE(map.get_max_load_factor() == 0.75);
        } else {
            REQUIRE(map.get_max_load_factor() == factors[i]);
        }
    }
}

TEST_CASE("0-1 values", "[assoc]") {
    assoc<int> map(100);
    for (int i = 0; i < 68; i++) {
        map.insert(testKeys[i], testValues[i]);
    }
    vector<int> v = map.values();

    // for (std::vector<int>::iterator it = v.begin(), int i = 0;
    //     it != v.end(); ++it, i++) {
    //     REQUIRE(*it == testValues[i]);
    // }
}
TEST_CASE("0-1 stark's test", "[assoc]") {
  test_assoc(1, 16);
  test_assoc(1, 1024);
}
