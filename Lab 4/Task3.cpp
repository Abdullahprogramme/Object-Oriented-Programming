#include <iostream>
#include <cstring>

using namespace std;

class TextEditor {
    private:
        char** undoStack;
        char** redoStack;
        int undoTop, redoTop;
        int undoCapacity, redoCapacity;
        char* text;
        
        // Function to resize the undo stack
        // Time complexity: O(n) where n is the number of elements in the undo stack
        void resizeUndoStack() {
            int newCapacity = undoCapacity * 2;
            char** newStack = new char*[newCapacity];
            for (int i = 0; i < undoTop; i++) {
                newStack[i] = undoStack[i];
            }
            delete[] undoStack;
            undoStack = newStack;
            undoCapacity = newCapacity;
        }
    
        // Function to resize the redo stack
        // Time complexity: O(n) where n is the number of elements in the redo stack
        void resizeRedoStack() {
            int newCapacity = redoCapacity * 2;
            char** newStack = new char*[newCapacity];
            for (int i = 0; i < redoTop; i++) {
                newStack[i] = redoStack[i];
            }
            delete[] redoStack;
            redoStack = newStack;
            redoCapacity = newCapacity;
        }

    public:
        
        // Constructor
        TextEditor( int undoCapacity = 10, int redoCapacity = 10 ) {
            undoCapacity = undoCapacity;
            redoCapacity = redoCapacity;
            undoStack = new char*[undoCapacity];
            redoStack = new char*[redoCapacity];
            undoTop = redoTop = -1;
            text = new char[1];
            text[0] = '\0';
        }

        // Destructor
        ~TextEditor() {
            for (int i = 0; i < undoTop; i++) delete[] undoStack[i];
            for (int i = 0; i < redoTop; i++) delete[] redoStack[i];
            delete[] undoStack;
            delete[] redoStack;
            delete[] text;
        }

        // Function to insert text
        // Time complexity: O(n) where n is the length of the new text
        void insertText(const char* newText) {
            if (undoTop == undoCapacity) resizeUndoStack();
            undoStack[++undoTop] = strdup(text);

            char* newTextCombined = new char[strlen(text) + strlen(newText) + 1];
            strcpy(newTextCombined, text);
            strcat(newTextCombined, newText);

            delete[] text;
            text = newTextCombined;
            redoTop = 0;
        }

        // Function to delete text
        // Time complexity: O(n) where n is the length of the text to be deleted
        void deleteText(int length) {
            if (undoTop == undoCapacity) resizeUndoStack();
            undoStack[++undoTop] = strdup(text);

            int newLen = strlen(text) - length;
            if (newLen < 0) newLen = 0;

            text[newLen] = '\0';
            redoTop = 0;
        }

        // Function to undo the last operation
        // Time complexity: O(1)
        void undo() {
            if (undoTop > 0) {
                if (redoTop == redoCapacity) resizeRedoStack();
                redoStack[++redoTop] = strdup(text);

                delete[] text;
                text = undoStack[undoTop--];
            } else {
                cout << "Nothing to undo.\n";
            }
        }
    
        // Function to redo the last operation
        // Time complexity: O(1)
        void redo() {
            if (redoTop > 0) {
                if (undoTop == undoCapacity) resizeUndoStack();
                undoStack[++undoTop] = strdup(text);

                delete[] text;
                text = redoStack[redoTop--];
            } else {
                cout << "Nothing to redo.\n";
            }
        }
    
        // Function to display the current text
        // Time complexity: O(1)
        void displayText() const {
            cout << "Current Text: " << text << "\n";
        }

};

int main() {
    TextEditor editor;
    editor.insertText("Hello");
    editor.displayText();
    
    editor.insertText(" World");
    editor.displayText();
    
    editor.undo();
    editor.displayText();
    
    editor.redo();
    editor.displayText();
    
    editor.deleteText(5);
    editor.displayText();
    
    editor.undo();
    editor.displayText();
    
    return 0;
}