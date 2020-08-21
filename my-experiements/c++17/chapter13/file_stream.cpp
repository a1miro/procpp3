#include <iostream>
#include <string_view>
#include <sstream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <array>
#include <string>

using namespace std;

void write_file(string_view fn, vector<string> data) {
  stringstream error;
  ofstream ofs(static_cast<string>(fn), ios_base::trunc);
  if(!ofs.good()) {
    error << "File not found ";
    error << fn;
    throw invalid_argument(error.str());
  }

  for (auto& line : data)
  {
    ofs << line;
  }
}

void read_file(string_view fn, ostream& output) {
  stringstream error;
  ifstream ifs(static_cast<string>(fn), ios_base::in);
  if(!ifs.good()) {
    error << "File not found ";
    error << fn;
    throw invalid_argument(error.str());
  }


  for (string line; getline(ifs, line);) 
  {
    output << line << endl; 
  }

}

int main() {
  vector<string> lines;
  lines.reserve(6);
  
  lines.push_back("Line1\n");
  lines.push_back("Line2\n");
  lines.push_back("Line3\n");
  lines.push_back("Line4\n");
  lines.push_back("Line5\n");
  lines.push_back("Line6\n");

  write_file("data.txt", lines);


  read_file("data.txt", cout);

  return 0;
}
