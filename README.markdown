# Spam Detection using Naive Bayes Classifier

## Description
This project implements a simple spam detection system using the Naive Bayes algorithm. It trains on provided spam and ham (non-spam) text files and classifies new text as spam or not spam based on the trained model. The classifier uses log probabilities to determine the likelihood of a message being spam or ham, providing a basic yet effective approach to email filtering.

## Usage
Follow these steps to set up and use the project:

1. **Clone the repository**:
   ```bash
   git clone https://github.com/yourusername/spam-detection.git
   ```
2. **Compile the C code**:
   Make sure you have a C compiler installed (e.g., GCC). Compile the source files using:
   ```bash
   gcc -o spam_detector main.c train.c test.c utils.c -lm
   ```
3. **Prepare training data**:
   - Place spam emails in `data/spam.txt`, with each email on a separate line.
   - Place ham emails in `data/ham.txt`, with each email on a separate line.
4. **Run the training phase**:
   ```bash
   ./spam_detector train
   ```
5. **Test the classifier**:
   - Place the email to test in `data/test.txt`.
   - Run the test phase:
     ```bash
     ./spam_detector test
     ```

## Dependencies
- A C compiler (e.g., GCC)
- Standard C libraries (included with most C installations)

## Examples
Below is an example of how the classifier works with sample data.

**Sample Training Data**:
- `data/spam.txt`:
  ```
  buy cheap viagra
  win a million dollars
  ```
- `data/ham.txt`:
  ```
  hello friend
  meeting at 3pm
  ```

**Sample Test Data**:
- `data/test.txt`:
  ```
  cheap viagra offer
  ```

**Expected Output**:
```
Testing line: 
cheap viagra offer

Final Log Probability:
Spam: -12.3456
Ham : -15.6789

Result: SPAM
```

This output shows the log probabilities for spam and ham, with the classifier correctly identifying the test email as spam.

## Project Structure
The project is organized into the following files:

- **`main.c`**: Contains the main function and orchestrates the training and testing phases.
- **`train.c`**: Implements the logic for training the Naive Bayes model using the provided spam and ham data.
- **`test.c`**: Implements the logic for testing new emails and classifying them as spam or ham.
- **`utils.c`**: Contains utility functions used across the project, such as string processing and probability calculations.

## Contributing
Contributions are welcome! If you find any issues or have suggestions for improvements, please submit a bug report or pull request on GitHub. For major changes, please open an issue first to discuss the proposed updates.

## License
This project is licensed under the MIT License. See the `LICENSE` file for more details.