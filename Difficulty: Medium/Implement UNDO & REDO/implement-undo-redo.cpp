class Solution {
  public:
    string doc;
    stack<char> redoSt;
    
    void append(char x) {
        // append x into document
        doc.push_back(x);
    }

    void undo() {
        // undo last change
        if(!doc.empty()){
            redoSt.push(doc.back());
            doc.pop_back();
        }
    }

    void redo() {
        // redo changes
        if(!redoSt.empty()){
            doc.push_back(redoSt.top());
            redoSt.pop();
        }
    }

    string read() {
        // read the document
        return doc;
    }
};