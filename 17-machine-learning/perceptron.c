#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct {
    double *weights;
    double bias;
    int num_inputs;
} Perceptron;

// Create perceptron
Perceptron* createPerceptron(int num_inputs) {
    Perceptron *p = (Perceptron*)malloc(sizeof(Perceptron));
    p->num_inputs = num_inputs;
    p->weights = (double*)malloc(num_inputs * sizeof(double));
    
    // Initialize weights randomly
    for (int i = 0; i < num_inputs; i++) {
        p->weights[i] = ((double)rand() / RAND_MAX) * 2 - 1;
    }
    p->bias = ((double)rand() / RAND_MAX) * 2 - 1;
    
    return p;
}

// Activation function
int activate(double sum) {
    return (sum >= 0) ? 1 : 0;
}

// Predict
int predict(Perceptron *p, double *inputs) {
    double sum = p->bias;
    for (int i = 0; i < p->num_inputs; i++) {
        sum += inputs[i] * p->weights[i];
    }
    return activate(sum);
}

// Train
void train(Perceptron *p, double **training_inputs, int *expected_outputs, 
           int num_samples, double learning_rate, int epochs) {
    printf("Training perceptron...\n");
    
    for (int epoch = 0; epoch < epochs; epoch++) {
        int errors = 0;
        
        for (int i = 0; i < num_samples; i++) {
            int prediction = predict(p, training_inputs[i]);
            int error = expected_outputs[i] - prediction;
            
            if (error != 0) {
                errors++;
                for (int j = 0; j < p->num_inputs; j++) {
                    p->weights[j] += learning_rate * error * training_inputs[i][j];
                }
                p->bias += learning_rate * error;
            }
        }
        
        if (epoch % 10 == 0) {
            printf("Epoch %d: %d errors\n", epoch, errors);
        }
        
        // Convergence: when the perceptron makes no classification errors
        // on the training set (perfect separation of classes)
        if (errors == 0) {
            printf("Converged at epoch %d!\n", epoch);
            break;
        }
    }
}

int main() {
    srand(time(NULL));
    
    printf("=== Perceptron Learning AND Gate ===\n\n");
    
    // AND gate training data
    double input1[] = {0, 0};
    double input2[] = {0, 1};
    double input3[] = {1, 0};
    double input4[] = {1, 1};
    
    double *training_inputs[] = {input1, input2, input3, input4};
    int expected_outputs[] = {0, 0, 0, 1};
    
    // Create and train perceptron
    Perceptron *p = createPerceptron(2);
    train(p, training_inputs, expected_outputs, 4, 0.1, 100);
    
    // Test
    printf("\nTesting:\n");
    for (int i = 0; i < 4; i++) {
        int result = predict(p, training_inputs[i]);
        printf("%.0f AND %.0f = %d (expected %d) %s\n", 
               training_inputs[i][0], training_inputs[i][1], 
               result, expected_outputs[i],
               result == expected_outputs[i] ? "✓" : "✗");
    }
    
    // Show learned weights
    printf("\nLearned weights:\n");
    for (int i = 0; i < p->num_inputs; i++) {
        printf("w%d = %.4f\n", i, p->weights[i]);
    }
    printf("bias = %.4f\n", p->bias);
    
    free(p->weights);
    free(p);
    
    return 0;
}
