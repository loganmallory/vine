template<typename dtype>
Vine<bool>& Vine<dtype>::operator> (const dtype v) const {
  /*
  Compare every value in this->values to the constant v and store boolean result in a new array which is returned
  Called using:
    vec1 > v;
  */
  if(DEBUG) printf("Vine::operator> (const dtype v)\n");
  Vine<bool>* newvec = new Vine<bool>(this->length);
  switch (OPT_LVL) {
    //cases 1 and 2 are equivalent even with -O0 flag
    case 0:
      //800-1600mic -O3
      for(unsigned int i=0; i < this->length; i++) if(this->values[i] > v) newvec->values[i] = true;
      break;
    case 1:
      //80mic -O3
      for(unsigned int i=0; i < this->length; i++) newvec->values[i] = this->values[i] > v;
      break;
    case 2:
      //80mic -O3
      for(unsigned int i=0; i < this->length; i++) newvec->values[i] = (v - this->values[i]) >> 31;
      break;
  }
  return *newvec;
}

template<typename dtype>
Vine<bool>& Vine<dtype>::operator> (const Vine<dtype>& vec) const {
  /*
  Compare every this->values to vec.values and store boolean result in a new array which is returned
  Called using:
    vec1 > vec2;
  */
  if(DEBUG) printf("Vine::operator> (const Vine<dtype>& vec)\n");
  Vine<bool>* newvec = new Vine<bool>(this->length);
  switch (OPT_LVL) {
    //cases 1 and 2 are equivalent even with -O0 flag
    case 0:
      //1600mic -O3
      for(unsigned int i=0; i < this->length; i++) if(this->values[i] > vec.values[i]) newvec->values[i] = true;
      break;
    case 1:
      //130mic -O3
      for(unsigned int i=0; i < this->length; i++) newvec->values[i] = this->values[i] > vec.values[i];
      break;
    case 2:
      //130mic -O3
      for(unsigned int i=0; i < this->length; i++) newvec->values[i] = (vec.values[i] - this->values[i]) >> 31;
      break;
  }
  return *newvec;
}


template<typename dtype>
Vine<bool>& Vine<dtype>::operator>= (const dtype v) const {
  /*
  Compare every value in this->values to the constant v and store boolean result in a new array which is returned
  Called using:
    vec1 >= v;
  */
  if(DEBUG) printf("Vine::operator>= (const dtype v)\n");
  Vine<bool>* newvec = new Vine<bool>(this->length);
  switch (OPT_LVL) {
    case 0:
      //1200mic -O3
      for(unsigned int i=0; i < this->length; i++) if(this->values[i] >= v) newvec->values[i] = true;
      break;
    case 1:
      //80mic -O3
      for(unsigned int i=0; i < this->length; i++) newvec->values[i] = this->values[i] >= v;
      break;
    case 2:
      //18mic -O3
      for(unsigned int i=0; i < this->length; i++) newvec->values[i] = ((this->values[i] - v) >> 31) ^ 1;
      break;
  }
  return *newvec;
}

template<typename dtype>
Vine<bool>& Vine<dtype>::operator>= (const Vine<dtype>& vec) const {
  /*
  Compare every this->values to vec.values and store boolean result in a new array which is returned
  Called using:
    vec1 >= vec2;
  */
  if(DEBUG) printf("Vine::operator>= (const Vine<dtype>& vec\n");
  Vine<bool>* newvec = new Vine<bool>(this->length);
  switch (OPT_LVL) {
    case 0:
      //1500mic -O3
      for(unsigned int i=0; i < this->length; i++) if(this->values[i] >= vec.values[i]) newvec->values[i] = true;
      break;
    case 1:
      //98mic -O3
      for(unsigned int i=0; i < this->length; i++) newvec->values[i] = this->values[i] >= vec.values[i];
      break;
    case 2:
      //19mic -O3
      for(unsigned int i=0; i < this->length; i++) newvec->values[i] = ((this->values[i] - vec.values[i]) >> 31) ^ 1;
      break;
  }
  return *newvec;
}