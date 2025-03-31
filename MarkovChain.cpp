#include "MarkovChain.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <random>

using namespace std;

//constructors 
MarkovChain::MarkovChain(){
  vector <string> emptyVec;
  theChain.emplace(key, emptyVec);
}

MarkovChain::MarkovChain(std::string source){
  cout << "Constructor" << endl;
  ifstream newFile(source);
  cout << "fileopen" << endl;
  read_text(newFile);
  cout << "finish read" << endl;
}


//accessors


vector<string>& MarkovChain::get_value_list(){
  return theChain.at(key);  
}

string MarkovChain::get_rand_value(){
  vector<string> temp = get_value_list();
  int rng = rand() % temp.size();
  return temp.at(rng);
}

void MarkovChain::read_text(std::ifstream &sourceFile){
  while(!sourceFile.eof()){
    string currentLine;
    getline(sourceFile, currentLine);

    int nextW;
    while (currentLine.length() > 0){
      if (currentLine.find(" ") != -1){
        nextW = currentLine.find(" ");
        value = currentLine.substr(0, nextW);
        currentLine = currentLine.substr(nextW+1);
        if (key != ""){
          set_chain();
        }
      } else {
        value = currentLine;
        set_chain();
        currentLine = "";
      }
      key = value;
    }
  }
}


//mutators 
void MarkovChain::set_chain(){
  if (theChain.count(key) == 0){
    vector <string> newVec = {value};
    theChain.emplace(key, newVec);
  } else {
    get_value_list().push_back(value);
  }
}

void MarkovChain::add_value(){
  
}


void MarkovChain::make_chain(int length, string start){
  auto whole = theChain.find(start);
  key = start;
  cout << start;
  for (int i = 0; i < length; i++){
    start = get_rand_value();
    cout << ' ' << start;
    if (theChain.count(start) != 0 ){
      key = start;
    } else {
      break;
    }
  }
}
