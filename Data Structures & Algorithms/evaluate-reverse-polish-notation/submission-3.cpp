class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(int i = 0; i < tokens.size(); i++) {

            if(isdigit(tokens[i][0]) ||
               (tokens[i][0] == '-' && tokens[i].size() > 1)) {

                st.push(stoi(tokens[i]));
            }
            else {
                int operand1 = st.top();
                st.pop();

                int operand2 = st.top();
                st.pop();

                if(tokens[i] == "+")
                    st.push(operand2 + operand1);

                else if(tokens[i] == "-")
                    st.push(operand2 - operand1);

                else if(tokens[i] == "*")
                    st.push(operand2 * operand1);

                else if(tokens[i] == "/")
                    st.push(operand2 / operand1);
            }
        }

        return st.top();
    }
};
