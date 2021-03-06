#include <string>

using namespace std;
// Image size in MNIST database
extern const int width ,height;

// n1 = Number of input neurons
// n2 = Number of hidden neurons
// n3 = Number of output neurons
// epochs = Number of iterations for back-propagation algorithm
// learning_rate = Learing rate
// momentum = Momentum (heuristics to optimize back-propagation algorithm)
// epsilon = Epsilon, no more iterations if the learning error is smaller than epsilon

extern const int n1; // input layer
extern const int n2; // hidden layer
extern const int n3; // output layer - 0 - 9
extern const int epochs;
extern const double learning_rate;
extern const double momentum;
extern const double epsilon;

// Training 
const string training_image = "../mnist/train-images.idx3-ubyte";
const string training_label = "../mnist/train-labels.idx1-ubyte";

// Testing
const string testing_image = "../mnist/t10k-images.idx3-ubyte";
const string testing_label = "../mnist/t10k-labels.idx1-ubyte";

// Numero de exemplos
const int nTraining = 60000;
const int nTesting = 10000;

// Relatório
const string reportTraining = "relatorioTreinamento.log";
const string reportTesting = "relatorioTeste.log";

const string model_fn = "mlp.obj";


// MLP Definition
// input layer
extern double *w1[],*delta1[], *out1;

// hidden layer
extern double *w2[],*delta2[], *in2, *out2, *theta2;

// Output layer
extern double *in3, *out3,*theta3;

double sigmoid(double x);
double squareError();
void processPerceptron();




