#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// defining the weight and bias
double weight=0.8;
double bias=1.2;

// this is the constant alpha - learning rate
double learning_rate=0.01;

// tuning weights and bias according to error difference in prediction
void backward_pass(double value_error,double X){
    double w_loss_func=-2*value_error*X;
    double b_loss_func=-2*value_error;

    weight=weight-learning_rate*w_loss_func;
    bias=bias-learning_rate*b_loss_func;
}
// calculating each data points prediction and checking how much it is wrong with actual one
void calculate_data_point(double X,double Y){
    // making predicttion
    double predicted_value=weight*X+bias;
    // calcualting error or difference between actual and predicted price
    double value_error=Y-predicted_value;
    printf("Predicted value: %.2lf, Actual value: %.2lf -> Error: %.2lf\n",predicted_value,Y,value_error);
    if(value_error==0){
        return;
    }else{
        backward_pass(value_error,X);
    }
}

// program to train model on data
void train_model(double training_feature[],double actual_feature[],int size){
    // running each epoch 300 times.
    int epochs=300;
    for(int e=0;e<epochs;e++){
        for(int i=0;i<size;i++){
            // tuning weight and bias on each operation
            calculate_data_point(training_feature[i],actual_feature[i]);
        }
        // debugging each epoch result
        printf("current weight: %.2lf, current bias: %.2lf\n",weight,bias);
        
    }
}

void predict(){
    double x_input;
    printf("==== Predicting values ====\n");
    printf("Enter a value to predict Y: ");
    scanf("%lf",&x_input);

    double y_output=weight*x_input+bias;

    printf("Predicted value: %.2lf\n",y_output);
}

int main(){
    double training_feature[]={1.0,1.5,2.0,2.5};
    double actual_feature[]={2.0,2.75,3.5,4.25};
    int size=sizeof(training_feature)/sizeof(training_feature[0]);
    
    train_model(training_feature,actual_feature,size);

    printf("-----------------------------------------------\n");
    printf("Weight: %.2lf, Bias: %.2lf\n",weight,bias);
    printf("\n");
    while(1){
        predict();
    }

    return 0;
}