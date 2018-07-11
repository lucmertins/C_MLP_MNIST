#include <string>

using namespace std;



extern double expected[];
extern ifstream image;
extern ifstream label;
extern ofstream report;

void aboutTraining();
void initLayersRoundWeight();
void saveMLP(string file_name);
void training();
