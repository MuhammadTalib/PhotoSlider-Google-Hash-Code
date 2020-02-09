#include<iostream>  
using namespace std;

void combinationUtil(string arr[], string data[], int start, int end, int index, int r,string outputString[],int &outindex);
 
void printCombination(string arr[], int n, int r)
{ 
    const int x = r;
    //string outdata[5*4*3*2*1];
    for (int i = 1; i <= n; i++) {
        
        string* outdata = new string[i];
        int *outindex;
        string* data=new string[i];
        combinationUtil(arr, data, 0, n - 1, 0, i, outdata, outindex);

        
        for (int k = 0; k < 1; k++) {
            cout << endl << "outdata  " << outdata[k] << endl;
        }
    }
}

void combinationUtil(string arr[], string data[],int start, int end, int index, int r, string outputString[],int outindex)
{
    if (index == r)
    {
        for (int j = 0; j < r; j++) {
            outputString[*outindex]=(data[j]);
            cout << "data[j]" << data[j]<<" "<<*outindex;
            outindex++;
            cout << "outindex" << *outindex;
            cout <<"||"<< data[j] << "||";
        }
        cout << endl;
        return;
    }
    for (int i = start; i <= end &&
        end - i + 1 >= r - index; i++)
    {
        data[index] = arr[i];
        cout << "outindex" << *outindex;
        combinationUtil(arr, data, i + 1, end, index + 1, r, outputString, outindex);
    }
}

// Driver code  
int main()
{
    string arr[] = { "a", "b", "c", "d", "e" };
    int r = 3;
    int n = sizeof(arr) / sizeof(arr[0]);
    printCombination(arr, n, r);
}