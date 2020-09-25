#include <iostream>
#include <string>
#include <map>
using namespace std;

/* Gets input char, or 'x' if no char left */
char next(string word) {
    static int i = 0;
    if(i == word.length())
        return 'x';
    return word[i++];
}

int main () {
    // Initializing states table
    map<pair<int, char> , int> st;

    // Building up states table, keeping only legal transitions
    st.insert(make_pair(make_pair(0, 'a'), 2));
    st.insert(make_pair(make_pair(0, 'b'), 1));
    st.insert(make_pair(make_pair(0, 'c'), 3));
    st.insert(make_pair(make_pair(1, 'b'), 1));
    st.insert(make_pair(make_pair(1, 'c'), 3));
    st.insert(make_pair(make_pair(2, 'a'), 0));
    st.insert(make_pair(make_pair(2, 'd'), 3));
    
    int state = 0;
    int e;
    char in;

    // Getting sequence word from stdin
    string word;
    cout << "Write down sequence word: ";
    cin >> word;

    while(true) {
        // Getting next char from input stream
        char in = next(word);
        cout << "Next input char is: " << in << "\t" << "Current state is: " << state << endl;
        
        // If input stream is finished
        if (in == 'x') {
            e = -1;
            goto error;
        }

        auto it = st.find(make_pair(state,in));
        // If input sequence is not legal
        if (it == st.end()) {
            e = -2;
            goto error;
        }
        state = it->second;
        cout << "State updated to: " << state << endl;
        
        // If final state is reached exit cycle
        if (state == 3)
            break;
    }
    
    cout << "Input sequence is legal for our Language" << endl;
    return 0;
    
    error:
        switch(e) {
            case -1:
                cout << "ERROR!" << endl;
                cout << "Inputs stream finished - Final state not reached " << endl;
                cout << "State reached is" << state << endl;
                return state;
                break;
            case -2:
                cout << "ERROR!" << endl;
                cout << "Input " << in << " not legal for state " << state << endl;
                return state;
                break;
        }

}