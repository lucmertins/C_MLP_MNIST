#include <string>

using namespace std;



extern double expected[];
extern ifstream image;
extern ifstream label;
extern ofstream report;

void aboutTesting();
void loadMLP(string file_name);
void testing();
