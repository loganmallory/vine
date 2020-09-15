void assignment_to_constant_test(unsigned int size) {
  if(TEST_DEBUG) printf("\tassignment_to_constant_test()\n");
  //start with already constructed Vine
  Vine<int> vec1(size);
  vec1 = 7;
  for(unsigned int i=0; i < vec1.length; i++) assert(vec1.values[i] == 7);
  //Vine<int> vec2 = 23 does not call operator= method, it calls conversion constructor
}

void assignment_to_vine_test(unsigned int size) {
  if(TEST_DEBUG) printf("\tassignment_to_vine_test()\n");
  //start with already constructed Vines
  Vine<int> vec1(size);
  Vine<int> vec2(size);

  vec1 = 3;
  vec2 = vec1;
  assert(vec1.values != vec2.values);
  //check that values were copied directly
  for(unsigned int i=0; i < vec2.length; i++) assert(vec2.values[i] == 3);

  //change value just for fun
  vec2 = -509;

  //just double check that vec1 and vec2 don't share memory
  for(unsigned int i=0; i < vec2.length; i++) assert(vec1.values[i] == 3);

  //check resizing case
  Vine<int> vec3(size / 2);
  vec3 = vec2;
  //check that deepy copy occurred
  assert(vec3.values != vec2.values);
  //check that vec3.values was resized correctly
  assert(vec3.length == size);
  //check that values were copied
  for(unsigned int i=0; i < vec2.length; i++) assert(vec2.values[i] == -509);
}

void test_assignment(unsigned int size) {
  assignment_to_constant_test(size);
  assignment_to_vine_test(size);
}