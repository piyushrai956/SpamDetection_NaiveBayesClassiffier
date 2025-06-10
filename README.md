# Spam Detection using Naive Bayes Classifier

## Description
This project implements a simple spam detection system using the Naive Bayes algorithm. It trains on provided spam and ham (non-spam) text files and classifies new text as spam or not spam based on the trained model. The classifier uses log probabilities to determine the likelihood of a message being spam or ham, providing a basic yet effective approach to email filtering.

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
