#python 3

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
def sigmoid(x):
    return 1. / (1. + np.exp(-0.005*x))

def sigmoid_derivative(x):
    return 0.005 * x * (1. - x )

def read_and_divide(csv_file): #Reading csv file into a dataframe and splitting it for training and testing
    df = pd.read_csv(csv_file).replace("?", np.NaN).dropna()
    df["Bare_Nuclei"] = df["Bare_Nuclei"].astype(float)
    trainIndex = int(len(df)*0.8)
    training_inputs = np.array(df[:trainIndex].drop(columns = ["Class", "Code_number"]), dtype = float)
    training_labels = np.array(df[:trainIndex]["Class"], dtype = float).reshape(546, 1)
    testing_inputs = np.array(df[trainIndex:].drop(columns = ["Class", "Code_number"]), dtype = float)
    testing_labels = np.array(df[trainIndex:]["Class"], dtype = float)
    return df, training_inputs, training_labels, testing_inputs, testing_labels

def visualize_correlations(DataFrame): # Visualizes every attribute's correlation pairwise, on a heatmap
    hmap_df = DataFrame.replace("?", np.NaN).dropna().drop(columns = ["Code_number", "Class"])
    fig, ax = plt.subplots(figsize = (8,8))
    ax.set_ylim(len(hmap_df.columns)-0.5, -0.5)
    im = ax.imshow(np.array(hmap_df.corr(), dtype = float))
    plt.imshow(hmap_df.corr(), cmap = "Reds")
    plt.colorbar()
    ax.set_xticks(np.arange(len(hmap_df.corr().columns)))
    ax.set_yticks(np.arange(len(hmap_df.corr().columns)))
    ax.set_xticklabels([name for name in hmap_df.corr().columns])
    ax.set_yticklabels([name for name in hmap_df.corr().columns])
    ax.set_title("Pairwise Correlations")
    plt.setp(ax.get_xticklabels(), rotation = 90, ha = "right", rotation_mode = "anchor")
    labels = hmap_df.corr().values
    
    for y in range(len(hmap_df.corr().columns)):
        for x in range(len(hmap_df.corr().columns)):
            plt.text(x, y, '{:.2f}'.format(labels[y,x]), ha = "center", va = "center", fontsize = 9, color = "Black")
    
    ax.set_ylim(len(hmap_df.corr())-0.5, -0.5) 
    fig.tight_layout()
    plt.show()

def run_on_test_set(test_inputs, test_labels, weights):  # This Function Will be Called Every Time weights are updated to track progress
    # Calculating Test Predictions
    test_predictions = sigmoid(np.dot(test_inputs, weights))

    # Mapping each prediction into 1 or 0
    test_predictions = [1. if prediction > 0.5 else 0 for prediction in test_predictions]

    # Calculating number of true predictions
    true_predictions = 0.
    for predicted_val, label in zip(test_predictions, test_labels):
        if predicted_val == label:
            true_predictions += 1
    accuracy = true_predictions / len(test_predictions)

    return accuracy

def plot_loss_and_accuracy(loss_array, accuracy_array):

    fig = plt.figure(figsize = (12,6))

    g1 = fig.add_subplot(121)
    g2 = fig.add_subplot(122)

    g1.set_xlabel("Iterations")
    g1.set_ylabel("Accuracy")
    g1.set_title("Test Accuracy")
    g1.plot([i for i in range(iteration_count)], accuracy_array)

    g2.set_xlabel("Iterations")
    g2.set_ylabel("Loss")
    g2.set_title("Training Loss")
    g2.plot([i for i in range(iteration_count)], [abs(loss) for loss in loss_array]) # since loss values decrease over training they are naturally negative, taking absolute to get a decreasing look on the graph

    plt.show()
    
# Global variables needed for training

df, training_inputs, training_labels, testing_inputs, testing_labels = read_and_divide('breast-cancer-wisconsin.csv')
iteration_count = 2500
np.random.seed(1)
weights = 2. * np.random.random((9, 1)) - 1.
accuracy_array = []
loss_array = []

# Training the neural network

for iteration in range(iteration_count):
    # Calculating outputs
    outputs = sigmoid(np.dot(training_inputs,weights))
    # Calculating loss
    loss = training_labels - outputs
    # Calculating tuning
    tuning = loss * sigmoid_derivative(outputs)
    # Updating weights
    weights += np.dot(training_inputs.T, tuning)
    # run_on_test
    accuracy = run_on_test_set(testing_inputs, testing_labels, weights)
    # adding each accuracy to accuracy array
    accuracy_array.append(accuracy)
    # adding each mean value of loss to loss array
    loss_array.append(loss.mean())

visualize_correlations(df)
plot_loss_and_accuracy(loss_array, accuracy_array)
