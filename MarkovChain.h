#pragma once
#include <iostream>
#include <vector>
#include <map>


class MarkovChain {
  private:
    std::string key = "";
    std::string value;
    //std::vector<std::string> valueContainer;
    std::map<std::string, std::vector<std::string>> theChain;



  public:
    //constructors 
    MarkovChain();
    MarkovChain(std::string source);


    //accessors
    std::string get_key();

    std::string get_value();

    std::vector<std::string>& get_value_list();

    std::string get_rand_value();

    void read_text(std::ifstream &sourceFile);


    //mutators 
    void set_chain();

    void add_value();

    void make_chain(int length, std::string start);
    
};
