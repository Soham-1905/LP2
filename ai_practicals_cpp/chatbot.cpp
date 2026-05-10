#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input;

    cout << "Simple Chatbot\n";

    while(true)
    {
        cout << "You: ";
        getline(cin, input);

        if(input == "hello")
        {
            cout << "Bot: Hi!\n";
        }
        else if(input == "how are you")
        {
            cout << "Bot: I am fine.\n";
        }
        else if(input == "bye")
        {
            cout << "Bot: Goodbye!\n";
            break;
        }
        else
        {
            cout << "Bot: I don't understand.\n";
        }
    }

    return 0;
}
