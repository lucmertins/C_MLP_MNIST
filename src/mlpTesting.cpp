#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>

#include "mlp.h"
#include "mlpTesting.h"

using namespace std;

int *pImage = 0;

void aboutTesting()
{
    // Details
    cout << "*************************************************" << endl;
    cout << "*** Testing Neural Network for MNIST database ***" << endl;
    cout << "*************************************************" << endl;
    cout << endl;
    cout << "No. input neurons: " << n1 << endl;
    cout << "No. hidden neurons: " << n2 << endl;
    cout << "No. output neurons: " << n3 << endl;
    cout << endl;
    cout << "Testing image data: " << testing_image << endl;
    cout << "Testing label data: " << testing_label << endl;
    cout << "No. testing sample: " << nTesting << endl
         << endl;
}

void loadMLP(string file_name)
{
    ifstream file(file_name.c_str(), ios::in);

    // Input layer - Hidden layer
    for (int i = 1; i <= n1; ++i)
    {
        for (int j = 1; j <= n2; ++j)
        {
            file >> w1[i][j];
        }
    }

    // Hidden layer - Output layer
    for (int i = 1; i <= n2; ++i)
    {
        for (int j = 1; j <= n3; ++j)
        {
            file >> w2[i][j];
        }
    }

    file.close();
}

int inputTesting()
{
    // Reading image
    char number;
    if (pImage == 0)
    {
        free(pImage);
    }
    pImage = (int *)malloc((width + 1) * (height + 1) * sizeof(int));

    for (int h = 1; h <= height; ++h)
    {
        for (int w = 1; w <= width; ++w)
        {
            image.read(&number, sizeof(char));
            if (number == 0)
            {
                *(pImage + h * width + w) = 0;
            }
            else
            {
                *(pImage + h * width + w) = 1;
            }
        }
    }

    for (int h = 1; h <= height; ++h)
    {
        for (int w = 1; w <= width; ++w)
        {
            int pos = w + (h - 1) * width;
            out1[pos] = *(pImage + h * width + w);
        }
    }

    // Reading label
    label.read(&number, sizeof(char));
    for (int i = 1; i <= n3; ++i)
    {
        expected[i] = 0.0;
    }
    expected[number + 1] = 1.0;
    return (int)number;
}

void testing()
{
    int nCorrect = 0;
    for (int sample = 1; sample <= nTesting; ++sample)
    {
        cout << "Sample " << sample << endl;

        // Getting (image, label)
        int label = inputTesting();

        processPerceptron();

        // Prediction
        int predict = 1;
        for (int i = 2; i <= n3; ++i)
        {
            if (out3[i] > out3[predict])
            {
                predict = i;
            }
        }
        --predict;

        double error = squareError();
        printf("Error: %0.6lf\n", error);

        if (label == predict)
        {
            ++nCorrect;
            cout << "Classification: YES. Label = " << label << ". Predict = " << predict << endl
                 << endl;
            report << "Sample " << sample << ": YES. Label = " << label << ". Predict = " << predict << ". Error = " << error << endl;
        }
        else
        {
            cout << "Classification: NO.  Label = " << label << ". Predict = " << predict << endl;
            cout << "Image:" << endl;

            for (int h = 1; h <= height; ++h)
            {
                for (int w = 1; w <= width; ++w)
                {
                    cout << *(pImage + h * width + w);
                }
                cout << endl;
            }
            cout << endl;
            report << "Sample " << sample << ": NO.  Label = " << label << ". Predict = " << predict << ". Error = " << error << endl;
        }
    }
    // Summary
    double accuracy = (double)(nCorrect) / nTesting * 100.0;
    cout << "Number of correct samples: " << nCorrect << " / " << nTesting << endl;
    printf("Accuracy: %0.2lf\n", accuracy);
}
