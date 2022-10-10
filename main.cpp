#include "LinkedList.h"

bool isValidNumber(string str)
{
    for (int i = 0; i < (int)str.size(); i++)
        if (isdigit(str[i]) == false)
            return false;
    return true;
}

int main()
{
    int arr[100] = {0};
    string str;
    int cnt = 0, param1 = 0, param2 = 0;
    getline(cin, str);
    stringstream s(str);
    string word, choice;
    bool isNum = false;
    int j = 0;
    while (s >> word)
    {
        if (!isValidNumber(word) || isNum)
        {
            if (j == 0)
            {
                isNum = true;
                choice = word;
                j++;
            }
            else if (j == 1)
            {
                param1 = stoi(word);
                j++;
            }
            else if (j == 2)
            {
                param2 = stoi(word);
                j++;
            }
        }
        else
            arr[cnt++] = stoi(word);
    }
    LinkedList *linkedList = new LinkedList(arr, cnt);
    if (choice == "AF")
        linkedList->addFront(param1);
    else if (choice == "AE")
        linkedList->addEnd(param1);
    else if (choice == "AP")
        linkedList->addAtPosition(param1, param2);
    else if (choice == "S")
        linkedList->search(param1);
    else if (choice == "DF")
        linkedList->deleteFront();
    else if (choice == "DE")
        linkedList->deleteEnd();
    else if (choice == "DP")
        linkedList->deletePosition(param1);
    else if (choice == "GI")
        linkedList->getItem(param1);
    linkedList->printItems();

    return 0;
}